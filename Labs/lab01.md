# Lab 1

Introduction to Linux and the g++ Compiler

## Goals

* Overview: Linux organization
* Introduce several basic Linux commands
* Provide an example of creating, compiling, and running a c++ program
* Set up all the directories for the course assignments
* Provide practice creating, compiling, and running c++ programs

## Lecture Notes

[Linux Tutorial -- recommended for everyone](https://ryanstutorials.net/linuxtutorial/)<br>

### Linux Overview

* Kernel
* Shell (csh, tsh, ksh, bsh, bash)
* Windowing System (X-windows is the most common)
* Windows Manager (Xfce, KDE, Gnome, etc)

### Linux Command structure

Commands in the Linux environment all have textual names. Instead of opening a window that shows the content of a directory you type a command at a prompt in a window. For example, the command "ls" show the contents of the current directory. A program called the shell will print a prompt (usually a "$" but can be anything you want) to indicate that it is ready for you to type a command.<br>

When you type a command the shell looks for a program with that name to execute.
```
$ ls    // shell looks for an executable file named "ls" in the special collection of directories (called the path)
```

Why is text better than clicking buttons? Consider the problem of editing a group of files. For example, I have a bunch of files with "112" in them and I need to change the "112" to "211". The following command changes 112 to 211 in all the .html files in the current directory:
```
$ for file in *.html; do sed s/112/211/g < $file > tmp; mv tmp $file; done
```
While it may take some time before you can write such complicated commands, once you learn how to use a text based command shell it is much faster than using a point-and-click interface.

### Know What You are Doing

Linux assumes that you really want to do what you say you want to do. In other words, if you use the remove command to delete a file, the file will be deleted. It won't be put into the trash, it will be deleted. Once a file is deleted, it is deleted forever (system backups are done every night, so if the file existed the previous night you can get a copy from the backups).

### Special Keys

| What you type | What happens |
| --- | --- |
| ^C | kill the current process |
| ^D | End of input (end of file) character (When you want to tell a program you are done entering input, type ^D) |
| ^Z | Stop the current process (the process will still exist, but it won't be running). Don't do this until you understand how to restart processes (commands: jobs, fg, bg). |

### File Redirection

Programs usually write to the current window. For example, if your program has the following line: `cout << "hello\n"`, then "hello" will be written to the current window.<br>

You can tell the bash shell to redirect standard output (i.e. cout) to a file:
```
$ ./hello_world > hello_world.myout
```
* The `.` is used to mean the current directory

Now when the program `hello_world` is run, text written to standard output will be place in the file hello_world.myout<br>

Programs usually read from the keyboard. For example, if your program has the following line: `cin >> value;`, the number typed at the keyboard will be placed into the variable `value`.<br>

You can tell the shell to redirect standard input (i.e. cin) from a file:
```
$ ./add < test_1.in
```
Now when the program `add` is run, text read from standard input (cin) will be read from the file: test_1.in

### Linux Pipes

One of the most powerful features of the bash shell is the ability to connect the output of one command to the input of another command. Consider these two commands:
```
$ ls    // this will list all the files in the current directory
$ wc    // this will count all the characters, words, and lines in the input
```
If we take the output of `ls` and connected it to the input of `wc` (we say "pipe the output of ls to the input of wc") we can find out how many files are in the current directory:
```
$ ls | wc
```
The | is usually on the key above the Enter key.<br>

Any number of commands can be pipped together.

### Common Linux commands

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
* `pwd` => show the current directory (called the path)
* `mkdir` => make a new directory

```
$ mkdir 211  // make a new directory in the current directory called "211"
$ mkdir ~/211  // make a new directory in your home directory called "211"
```
* `chmod` => change the protection (access) of a file or directory
  * if you change the protection of your home directory as follows, you (the owner) will have full read and write access to all of your files, but no one else will be able to access any of your files:
```
$ cd  // change to your home directory
$ chmod 600 .  // don't forget the dot (.) t the end of this command
```
  * 6 in binary is 110 (read & write privileges on, execute privileges off)
  * You don't want everything to be executable -- only the executable files. If you try to execute your program and get a message that the file is not executable, you can make it executable:
```
$ chmod +x filename
```

* `rm` => delete (remove) a file
  * `rm -r` allows you to delete a directory and everything in it, use it carefully
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
* Note: the apopos command does the same thing as "man -k"
```
$ apopos copy | less
```
* `which` => tells you which executable is executed when you type a command
```
$ which cp
```

### Linux editors

For 211 we will not be using an integrated development environment (IDE). The reason we are not using an IDE is because I want you to develop a good understanding of the tasks performed by an IDE. Once you have a good understanding of these tasks, you can switch to an IDE.<br>

When writing programs without an IDE you use a stand alone editor to create your program (versus using the editor built in to Visual C++). This means you can pick from hundreds of available editors. Here are some common choices (most are available on the computers in 251):
1. Atom
  * Menu based editor that is easy to use.
  * Similar to Sublime Text.
  * Can [download on your home machine](https://atom.io/).
  * Cannot use over text-based connections (like putty -- actually, there is a way to use it, but it takes work to set up).
2. nano
  * Simple text based editor (no mouse)
  * all the commands are always on the screen (on some platforms a similar editor called pico is available and nano is not).
  * You can use nano via a text-based connection (like putty).
3. gvim
  * Graphical version of vim (see below).  
  * A little harder to learn how to use.
4. vim
  * Powerful and very popular version of the popular vi editor.
  * Works on most Linux and Microsoft platforms.  
  * It is hard to learn how to use but very fast once you learn how to use. (I will talk about it later in the semester.)  
  * [Vim Homepage](https://www.vim.org/)
5. emacs
  * Powerful and very popular editor.  
  * It is hard to learn how to use but provides powerful tools once you learn how to use it.  
  * Works on most Linux and Microsoft platforms [GNU's emacs page](https://www.gnu.org/software/emacs/)<br>

All these editors works from the command line:
```
$ atom hello.cpp
```

All of these are available on Linux and MacOS. Vim and Emacs are hard to learn, so if you don't already know one, I suggest you start using atom. In a couple weeks I will give lab on vim.<br>

If you plan to use Putty (and ssh into ecc-linux) to do your assignments at home, then vim or nano is a better choice (it requires some extra setup to use gvim or atom over putty).<br>

Whatever editor you end up using, become an expert.

## Exercise 1: Setting up your CSCI 211 environment

Taking some time to set up and organize your working directory for CSCI 211 will help prevent turning in the wrong assignment and make it easier to keep track of your files.<br/>

You may want to use a Git repository manager, such as GitHub, that provides version control and other features to build and manage software. It can be a great tool for organizing your source code; HOWEVER, remember that whenever you are creating a directory for a class where everyone is turning in the same assignments (like in this CSCI 211 course), make sure to **make the visibility of this repository private!** If your repo is public, it means other students can see it and easily steal the code from it -- this constitutes cheating and is a violation of academic integrity. There is **no reason** to make a CSCI 211 repo publicly visible this semester OR after you have completed the class. Refer to the [Cheating Policy](http://www.ecst.csuchico.edu/~trhenry/classes/general/cheating.html) or talk to me directly if you are unclear about any of this. Refer to the [GitHub docs](https://docs.github.com/en/free-pro-team@latest/github) for additional guidance on working with GitHub.<br/>

There is no requirement in this course to use GitHub. The following instructions will work on your local Linux/OSX laptop/desktop (with or without a remote repository):<br/>

1. Go to your home directory, or a subdirectory such as "Courses" or "Repos". Create a folder for CSCI 211 using mkdir (make directory):
```
$ mkdir csci211
```
2. Now enter that directory, using cd (change directory):
```
$ cd csci211
```
3. For each lab and programming assignment, you will want to create a subdirectory. If you do not organize your files well, you will potentially regret it later, as it is easy to overwrite or delete files. Create a directory for lab 1 and enter the subdirectory:
```
$ mkdir lab01
$ cd lab01
```
4. Using `lab01` rather than `lab1` will maintain sorted order when viewing the list of directories, since there are 15 labs total. Lab 1 consists of three tasks. Make a subdirectory within the lab01 directory for each task:
```
$ mkdir hello
$ mkdir add
$ mkdir print
```

## Exercise 2: Creating, compiling, and running a C++ program

1. Enter the lab01/hello subdirectory, and create the file `hello.cpp`. Using any editor (e.g. vim or atom), start the editor with `hello.cpp` as the filename:
```
$ atom hello.cpp
```
-or-
```
$ vim hello.cpp
```
2. Now edit the file so it contains the following text. Save the file and exit the editor:
```cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "hello world" << endl;
  return 0;
}
```
3. Compile this file using this command:
```
$ g++ hello.cpp
```
If you get an error, use the editor to fix the error.
4. This should have created the file `a.out` -- use `$ ls -l` to find out if `a.out` is in your directory. Note that `a.out` automatically has execute protection ("x").  When a file has execute permission you can execute it.
```
$ ls -l a.out
```
5. You can now run the executable `a.out`:
```
$ ./a.out
```
It is possible to [add `./` to the search path](https://stackoverflow.com/questions/27188856/adding-any-current-directory-to-the-search-path-in-linux) in Linux so that you do not have to type `./` before the executable every time, but it is not necessary. In my instructions, I will include `./` before all executables.<br/>

You do not need to turn in this exercise, but you may if you want to practice turn-in submissions. You must submit lab exercises 3 and 4 for lab credit.

## Exercise 3: 1 + 1 = 2

Write a program that reads two numbers, adds them together, and prints the result.

* Move to your lab01/add directory:
```
$ cd ../add
```
The two dots mean to go "up" a directory and find the `add` directory. If that did not work, try using the "full directory path" or "full path":
```
$ cd ~/csci211/lab01/add
```

* When your program is run, it should work like this (the "./a.out" "40" and "2" are typed by the user; the "40 + 2 = 42" is printed by the program):
```
$ ./a.out
40
2
40 + 2 = 42
$
```
* For this exercise you will need to read in an integer.  You can read an integer in C++ like this:
```cpp
cin >> value1;
```
Where "value1" has been declared as an integer before this line (C++ integers are declared just like in Java).
* Create a new file called `add.cpp` using an editor.  Write the add program so it reads and adds the two numbers.
* Compile and run your program to make sure it works correctly.  Your output must EXACTLY match my output: `<number><space><+><space><number><space><=><space><number><newline>`
* Some sample input and output are available in `211-starter-pack/211/lab01_add/tests` directory. In this directory you will find *.in and *.out files. For example, `t01.in` is the input for test 1 and `t01.out` is the expected output for test 1. All of the tests in the directory will be used to grade your program on turnin. If you pass these tests, you will get full credit.
* An easy way to see the content of a small file is to use the Linux cat command:
```
$ cat tests/t01.in
40 2
$ cat tests/t01.out
40 + 2 = 42
$
```
* See [Introduction to Testing](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_test.html) for a full description of how to test your assignments. If you understand the described mechanism now, it will make your semester much easier, and will improve your grade. One of the most important aspects of this lab is for you to understand the testing mechanism.

Once your program is working, turn in `add.cpp` on [Turnin](https://turnin.ecst.csuchico.edu/). For more information, see [instructions for turning in files](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_turn_in_assignments.html).

You must pass all the posted tests to get credit for a lab assignment.

Lab exercises are due by 11:59pm the Friday night following lab.

## Exercise 4: Say Hello

Write a program that reads a number and prints "hello" that number of times:
```
$ ./a.out
5
0 hello
1 hello
2 hello
3 hello
4 hello
$
```
* All the characters shown above were printed by the program, except the 5<enter> which was typed by the user.
* Change directory to the `lab01/print` directory.  Create a new file called `print.cpp`.
* Use a for-loop to implement this program.
* When your program is working, test it with the posted tests (see the testing and turn in instructions for exercise 3; the only difference is that the tests are in the directory `211-starter-pack/211/lab01_print/tests`).
* Make sure your program passes all the tests.
* Turn in print.cpp to [Turnin](https://turnin.ecst.csuchico.edu/).

## Exercise 5: Make sure you understand the testing mechanism

The main point of these assignments is to introduce you to the [testing mechanism](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_test.html).<br/>

Students who don't understand how < and > are used to test assignments struggle throughout the semester.

* Reminder: All labs are due at 11:59pm the Friday following lab.  For this lab you must turn in `add.cpp` and `print.cpp`. If you are not able to complete all the exercises, turn in your partial work for partial credit.
