# Linux Lecture Notes

These notes are particularly useful for completing [Lab 01](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab01.md):
  * [Exercise 5: Linux Commands and Testing Quiz](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab01.md#exercise-5-linux-commands-and-testing-quiz)

Feel free to reference these lecture notes as a quick reference anytime you are working with Linux:
* [Linux Beginners Guides](#linux-beginners-guides)
* [Linux Overview](#linux-overview)
* [Linux Command Structure](#linux-command-structure)
* [Linux Keyboard Control Characters](#linux-keyboard-control-characters)
* [File Redirection](#file-redirection)
* [Linux Pipes](#linux-pipes)
* [Common Linux Commands](#common-linux-commands)
* [Linux Editors](#linux-editors)

## Linux Beginners Guides

These are two beginners guides to the Linux command line. Recommended for everyone!
* [Linux Tutorial](https://ryanstutorials.net/linuxtutorial/) -- (Ryan's Tutorials)
* [The Linux command line for beginners](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview) -- (Ubuntu)

## Linux Overview

* Linux:
  * A family of open source Unix-like operating systems based on the Linux kernel
* Kernel:
  * The computer program at the core of a computer's operating system
  * Main jobs: scheduling processes, communication between the hardware and user processes, management of memory, I/O, and other resources
* Shell:
  * Command line interface (CLI) that gives users the ability to interact with the computer's operating system through a terminal.
  * Common Linux shells: bash, zsh, fish, ksh, tcsh, ...
  * See what shell you are using: `echo $0`
* GUI:
  * Linux is flexible and customizable: many users work with the operating system through the command-line terminal, but installing and using a Graphical User Interface is another option
* More information on [Linux User Interface](https://en.wikipedia.org/wiki/Linux#User_interface) options

> Note: For CSCI 211, I recommend you work with a Linux CLI. Proficiency with shell-based interaction will benefit you in future classes, but feel free to look into the available options and determine what works best for you.

## Linux Command Structure

Commands in the Linux environment all have textual names. Instead of opening a window that shows the content of a directory you type a command at a prompt in a window. For example, the command `ls` show the contents of the current directory. A program called the shell will print a prompt (usually a "$" but can be anything you want) to indicate that it is ready for you to type a command.<br>

When you type a command the shell looks for a program with that name to execute.
```
$ ls    // shell looks for an executable file named "ls" in the special collection of directories (called the path)
```

Why is text better than clicking buttons? Consider the problem of editing a group of files. For example, I have a bunch of files with "112" in them and I need to change the "112" to "211". The following command changes 112 to 211 in all the .html files in the current directory:
```
$ for file in *.html; do sed s/112/211/g < $file > tmp; mv tmp $file; done
```
While it may take some time before you can write such complicated commands, once you learn how to use a text based command shell it is much faster than using a point-and-click interface.<br>

**A word of caution:** Linux assumes that you really want to carry out the commands you execute, e.g. if you use the remove command to delete a file, the file will be deleted. It won't be put into the trash, it will be deleted. Sometimes you can recover the file from a system backup; however, it's crucial to handle files and directories with caution and have a backup strategy in place to protect against data loss.

## Linux Keyboard Control Characters

These three control characters are used to interact with processes running in the terminal (e.g. when you are done entering input):

| What you type | What happens |
| --- | --- |
| ^C (CTRL + C) | Send an interrupt signal to terminate a running process |
| ^D (CTRL + D) | Send an EOF (end of file) signal to indicate you've reached the end of input and the process should exit |
| ^Z (CTRL + Z) | Suspend the current process (the process will still exist, but it will be moved to the background). Don't do this until you understand how to restart processes (e.g. use the `fg` to resume the process and bring it back to the foreground) |

## File Redirection

By default, programs write to the current window. For example, say your program has this line of code: `cout << "hello\n"`. If you create a `hello_world` executable and run the following command, "hello" will be written to the current terminal window:
```
$ ./hello_world
```
* The `.` is used to mean the current directory

Alternatively, you can run the `hello_world` program and tell the shell to redirect standard output (i.e. cout) to a specified file:
```
$ ./hello_world > hello_world.myout
```
* In this case, "hello" will be written to a file called hello_world.myout<br>

By default, programs read from the keyboard. For example, say your program has the following line of code: `cin >> value;`. If you create an `add` executable and run the following command, the number typed at the keyboard will be placed into the variable `value`.<br>
```
$ ./add
```

Alternatively, you can tell the shell to redirect standard input (i.e. cin) to your `add` program from a specified file:
```
$ ./add < test01.in
```
* In this case, text read from standard input (cin) will be read from the file called test01.in

## Linux Pipes

One of the most powerful features of the bash shell is the ability to connect the output of one command to the input of another command. Consider these two commands:
```
$ ls    // list all the files in the current directory
$ wc    // count all the characters, words, and lines in the input
```
If we take the output of `ls` and connected it to the input of `wc` (we say "pipe the output of ls to the input of wc") we can find out how many files are in the current directory:
```
$ ls | wc
```
* The `|` is usually on the key above the Enter/Return key.<br>
* Any number of commands can be piped together!

## Common Linux Commands

* `cd` => change directory
  * `~` is used to mean your home directory
  * `..` is used to mean the parent of current directory
```
$ cd  // change to your home directory
$ cd ~user  // change to specified user's home directory (e.g. $ cd ~trhenry)
$ cd ..  // change to the parent of the current directory (the directory above the current directory)
$ cd 211  // if "211" is a sub-directory of the current directory, change to it
```
* `ls` => list the files in the current directory
* `pwd` => print the current working directory (called the path)
* `mkdir` => make a new directory

```
$ mkdir 211  // make a new directory in the current directory called "211"
$ mkdir ~/211  // make a new directory in your home directory called "211"
```
* `chmod` => change the access permissions of a file or directory
  * 3 distinct classes
    * `u`: user (person who owns the files & directories)
    * `g`: group (users who are members of a specified group)
    * `o`: others (not the owner or member of a group)
  * 3 Permissions that apply to each class
    * `r`: read permission (numerical value of 4 or 100)
    * `w`: write permission (numerical value of 2 or 010)
    * `x`: execute permission (numerical value of 1 or 001)

  * The following example changes the file permissions for a file named `myprog.cpp` such that you (the owner) will have full read and write access to the file, and all others will **not** have access to the file (`myprog.cpp` is in the current working directory):
```
$ chmod 600 myprog.cpp  
```
  * The following example changes the directory permissions for a directory named `mydir` such that you (the owner) will have full read, write, and execute access to the directory, and others will only be able to read and execute within the directory (`mydir` is in the current working directory):
```
$ chmod 755 mydir  
```
  * 7 in binary is 111 (read, write, & execute privileges on)
  * 6 in binary is 110 (read & write privileges on, execute privileges off)
  * 5 in binary is 101 (read & execute privileges on, write privileges off)
  * 4 in binary is 100 (read privileges on, write & execute privileges off)
  * Generally, directories should be executable, but files should only have execute privileges turned on if they are executable (e.g. shell scripts, compiled output).
  * Any file can be executable. If you try to execute your program and get a message that the file is not executable, you can make it executable:
```
$ chmod +x filename
```
  * You can see the permissions that are currently set in any directory, along with other information (owner, size of the file, date modified) -- this example shows how a file would look with read and write privileges for the owner and read access only for groups and others (chmod 644):
```
$ ls -al  // list all files in the directory with a long listing format
...
-rw-r--r--   1 shelleywong  staff  12142 Jun 14 09:34 README.md
```

* `rm` => delete (remove) a file
  * `rm -r` allows you to delete a directory and everything in it -- use it carefully
* `cp` => copy a file
* `man` => show the manual page for a command
```
$ man cp
```
  * the -k option searches for keywords in all man pages (useful if you forget the name of a command)
```
$ man -k copy
```
  * usually this produces too many matches and they scroll by too fast to read
```
$ man -k copy | less
```
* `which` => tells you which executable is executed when you type a command
```
$ which cp
```

## Linux Editors

For 211 we will not be using an integrated development environment (IDE). The reason we are not using an IDE is because I want you to develop a good understanding of the tasks performed by an IDE. Once you have a good understanding of these tasks, you can switch to an IDE.<br>

When writing programs without an IDE, you use a stand alone editor to create your program. Feel free to pick from hundreds of available editors! Here are some common choices (some are available on the computers in the lab):
1. [Vim](https://www.vim.org/)
  * Powerful and very popular version of Vi (de-facto Unix editor).
  * Works on most Linux and Microsoft platforms.
  * It is hard to learn how to use but very fast once you learn how to use. (Will discuss more later in the semester.)
  * The gvim editor is a graphical version of vim (runs inside a GUI window; a little harder to learn)
2. [Atom](https://atom.io/)
  * Menu based editor that is easy to use (from GitHub).
  * Can download on your home machine.
  * Cannot use over text-based connections (like putty -- actually, there is a way to use it, but it takes work to set up).
3. [VSCode](https://code.visualstudio.com/)
  * Another easy to use editor (from Microsoft).
  * Includes support for things like debugging and syntax highlighting.
  * Note: VSCode (Visual Studio Code) is different than Visual Studio IDE
4. [Sublime Text](https://www.sublimetext.com/)
  * Similar to Atom, but better performance and more lightweight
  * Free trials, but there is no free version
5. [nano](https://www.nano-editor.org/)
  * Simple text based editor (no mouse)
  * all the commands are always on the screen (on some platforms a similar editor called pico is available and nano is not).
  * You can use nano via a text-based connection (like putty).
6. [emacs](https://www.gnu.org/software/emacs/)
  * Powerful and very popular editor (from GNU).
  * It is hard to learn how to use but provides powerful tools once you learn how to use it.  
  * Works on most Linux and Microsoft platforms.<br>

All of these are available on Linux. Vim and Emacs are hard to learn, so if you don't already know one, I'd suggest starting with Atom or VSCode. If you are interested in working with Vim, you may want to review [Lab 4](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab04.md).<br>

If you plan to use Putty or another SSH client to connect to ecc-linux to do your assignments, then vim or nano is a better choice.<br>

Become familiar with at least one editor of your choice -- it will be beneficial to you in the long run. Learning how to work with a variety of editors can also be helpful to prepare you for future jobs.

[Top of the Page](#linux-lecture-notes)
