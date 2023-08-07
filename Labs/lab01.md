# Lab 1

Set up, Intro to Linux, g++ compiler, Git

## Goals

* Get an overview of Linux organization
* Introduce several basic Linux commands
* Set up your environment (GitHub, all the directories for the course assignments)
* Practice creating, compiling, and running C++ programs
* Get experience testing your assignments (before submitting to Inginious)
* Work on Programming Assignment 01
<br>

Lab 01 Exercises:
* [Exercise 1: Setting up your CSCI 211 environment](#exercise-1-setting-up-your-csci-211-environment)
* [Exercise 2: Creating, compiling, and running a CPP program](#exercise-2-creating-compiling-and-running-a-cpp-program) (lab01_hello)
* [Exercise 3: Addition](#exercise-3-addition) (lab01_add)
* [Exercise 4: Say Hello](#exercise-4-say-hello) (lab01_print)
* [Exercise 5: Linux Commands and Testing Quiz](#exercise-5-linux-commands-and-testing-quiz)

> Note: To get full credit for this lab, you must set up a CSUChico-CSCI211 GitHub account (exercise 1), submit 3 files to Inginious (exercises 2, 3, 4), and complete the Google Survey on Linux Commands and Testing (exercise 5).

Lab 01 Extra Credit: Git Basics Survey
* [Extra Credit: Complete the Git Google Survey](#extra-credit-complete-the-git-google-survey)

## Lecture Notes

Use these lecture notes as a quick reference for working with Linux:
* [Linux Beginners Guides](#linux-beginners-guides)
* [Linux Overview](#linux-overview)
* [Linux Command Structure](#linux-command-structure)
* [Linux Keyboard Control Characters](#linux-keyboard-control-characters)
* [File Redirection](#file-redirection)
* [Linux Pipes](#linux-pipes)
* [Common Linux Commands](#common-linux-commands)
* [Linux Editors](#linux-editors)

### Linux Beginners Guides

These are two beginners guides to the Linux command line. Recommended for everyone!
* [Linux Tutorial](https://ryanstutorials.net/linuxtutorial/) -- (Ryan's Tutorials)
* [The Linux command line for beginners](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview) -- (Ubuntu)

### Linux Overview

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

### Linux Command Structure

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

### Linux Keyboard Control Characters

These three control characters are used to interact with processes running in the terminal (e.g. when you are done entering input):

| What you type | What happens |
| --- | --- |
| ^C (CTRL + C) | Send an interrupt signal to terminate a running process |
| ^D (CTRL + D) | Send an EOF (end of file) signal to indicate you've reached the end of input and the process should exit |
| ^Z (CTRL + Z) | Suspend the current process (the process will still exist, but it will be moved to the background). Don't do this until you understand how to restart processes (e.g. use the `fg` to resume the process and bring it back to the foreground) |

### File Redirection

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

### Linux Pipes

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

### Common Linux Commands

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

### Linux Editors

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

## Exercise 1: Setting up your CSCI 211 environment

The goal of this exercise is for you to set up your working directory for CSCI 211. You will start with an existing repository that contains starter code, Makefiles, and test files that are organized based on the lab and programming assignments for this course. Throughout the semester, you will work in this directory, adding your own files and code to complete the assignments.<br/>

> Note: Before completing this exercise, it would be helpful to first make sure you have an environment setup that allows you to use Linux and compile your code with the GNU g++ compiler (see the 211 Getting Started Instructions on Canvas). Mac and Windows users: make sure you can access at least one of the following: ecc-linux (access with ssh), the lab computers, an Ubuntu virtual machine, WSL2 (for Windows), or GitHub codespaces.<br>

The starter repo for this class is available on GitHub in the CSUChico-CSCI211 organization. GitHub is a Git repository manager that provides version control and other features to build and manage software.<br>

After you create a GitHub account, you will use a repo generation tool to generate a **private** version of the starter repo for yourself. Private visibility means that only select individuals (e.g. you and the instructor) will have access to the repo. A public repo would be visible to anyone on the internet, meaning other students could easily see your repo and steal your code -- this constitutes cheating and is a violation of academic integrity. There is **no reason** to make your CSCI 211 code public this semester OR after you have completed the class. Refer to the Honesty and Academic Integrity policy in the syllabus if you have questions about this.

### Git and GitHub Overview

**What is Git?**<br>

[Git](https://git-scm.com/) is a version control system. It helps you keep track of your source code history, allowing you to see any changes and revert back to a previous version if necessary. Git makes it easier to manage both small individual projects and large collaborative projects. It is free and open source software released under the [GNU General Public License version 2.0](https://opensource.org/licenses/GPL-2.0). To use Git, you must have it installed on your local machine.<br>

**What are GitHub, GitLab, and BitBucket?**<br>

GitHub, GitLab, and BitBucket provide tools that help manage and host Git repositories. GitHub, GitLab, and BitBucket utilize a graphical user interface and are accessible on the web.<br>
* [GitHub](https://github.com/)
  * Version control, collaboration on open-source projects (Education accounts are free)
* [GitLab](https://about.gitlab.com/)
  * Version control with baked in CI/CD (Unlimited private/public repos for all)
* [BitBucket](https://bitbucket.org/)
  * Version control host for GIT or MERCURIAL (Education accounts are free)

**Git and GitHub References:**
* Git Cheat Sheets:
  * [GitHub Education Cheat Sheet](https://education.github.com/git-cheat-sheet-education.pdf)
  * [GitLab Cheat Sheet](https://about.gitlab.com/images/press/git-cheat-sheet.pdf)
  * [Atlassian (BitBucket) Cheat Sheet](https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet)
* Refer to the [GitHub docs](https://docs.github.com/en/free-pro-team@latest/github) for additional guidance on working with GitHub.
* Check out [Getting Started with Git](https://docs.github.com/en/github/getting-started-with-github/getting-started-with-git) in the GitHub Docs for instructions on setting up you Git username and password (necessary if cloning GitHub repos with HTTPS) and managing remote repositories.
* [Learn Git Branching](https://learngitbranching.js.org/) is a great interactive web tutorial that covers both basic and more advanced Git commands and techniques. The tutorial goes beyond what is necessary for this class, but it provides good practice and preparation for future classes and industry work.

### Steps for setting up your CSUChico-CSCI211 GitHub repo

>Note: for more details on steps 1 - 3, see the 211 Getting Started Instructions on Canvas.

1. [Sign up for GitHub](https://github.com/)
2. Go to this [GitHub repo generation](https://www.bryancdixon.com/fall/2023/csci/211/repo/) page to generate a CSUChico-CSCI211 GitHub repo
  - Create a GitHub username BEFORE submitting this form. Make sure that the username matches your actual GitHub username.
  - Use the Course Token provided in the 211 Getting Started Instructions
3. After submitting the repo generation form, go to the [CSUChico-CSCI211 GitHub organization](https://github.com/CSUChico-CSCI211) (github.com/CSUChico-CSCI211) and accept the invite -- do this soon after submitting the form, as the invitation will expire after 1 week.
4. Confirm that your repo has been generated
  - The URL for your repo should be similar to the following: `github.com/CSUChico-CSCI211/CSCI211-F23-FirstName-LastName`
  - The repo should contain several files and directories. You will primarily be working in the `211` directory -- confirm that this directory contains subdirectories for lab exercises 1 - 11 and programming assignments 1 - 7.
5. GitHub is a hosting service that can store your files and directories remotely. Now you need a way to interact with GitHub.
  - Determine a location on your local machine and/or your Linux environment to house the local instance of your 211 repository (make sure you know the path to these files so you can easily access this repository).
6. Set up SSH keys (so you can clone with SSH) OR a personal access token (so you can clone with HTTPS).
  - If cloning with SSH: First, [check to see if you already have an existing SSH key](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/checking-for-existing-ssh-keys) – if you do, you may be able to use the same key for GitHub. If you do not have a key, [generate a new SSH key](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent). Then, [add your SSH key to your GitHub account](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account). You will add the public key to your GitHub account. Make sure your private key stays private (the first line of defense is to not let other people have access to your computer). Now you should be able to clone your repo and continue on to the next step.
  - If cloning with HTTPS: You will be asked for your GitHub username and password when completing several git commands. When Git prompts you for your password, you should use your [personal access token](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens). GitHub recommends that you use Fine-grained personal access tokens; however, you will need to use Personal access tokens (classic) to work with the CSUChico-CSCI211 GitHub repo. Follow GitHub's instructions for [creating a personal access token (classic)](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens#creating-a-personal-access-token-classic). Give your token an expiration date after the end of the semester. Now you should be able to clone your repo and continue on to the next step.

> Note: if you are having trouble with one of the options above, ask the instructor about using GitHub Codespaces!

7. Confirm that you have git installed (if installed, `which git` will identify the location of git installed on your machine, while `git version` will display version information)
```
$ which git
$ git --version
```
  - If you do not have Git installed, download and install Git for your operating system:
  * For Windows: [https://windows.github.com](https://windows.github.com)
  * For Mac: [https://mac.github.com](https://mac.github.com)
  * For Linux: use the command, `sudo apt install git` (this command or something similar should be printed to the terminal if you use the `git version` command and git is not installed)
  * For all platforms: [http://git-scm.com](http://git-scm.com)
8. Check your Git settings and confirm that you have set your name and email. Start by viewing your settings. If you see your name and email (e.g `user.name=Your Name` and `user.email=youremail@mail.com`), type `q` to exit and continue to the next step.
```
$ git config --list
```
  - If you do not see your name and email, set them using the following (make sure to use your real name and email in place of the John Doe example below):
```
$ git config --global user.name "John Doe"
$ git config --global user.email johndoe@example.com
```
9. [Clone your repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)
  - Navigate to the main page of your CSUChico-CSCI211 repository
  - Above the list of files, click the green `< > Code` button.
  - Make sure you are on the `Local` tab (it has options to Clone with HTTPS and SSH), and copy the URL for the repository using either HTTPS or SSH (depending on what you set up in step 6).
  - Open a terminal
  - Change the current working directory to the location where you want the cloned directory
  - Type `git clone` and then paste the URL you copied earlier:
```
$ git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY
```
  - Press Enter to create your local clone<br>

Now you should have a local instance of your CSCI211 repository! Complete the next steps to finish Lab 01, Exercise 1.

### Steps for working with a local GitHub repo

1. When you clone the repository, you will not automatically move into the directory. Use the `cd` command to move into the directory (the name should be similar to the following):
```
$ cd CSCI211-F23-FirstName-LastName
```
2. List the contents of the current working directory and confirm that it contains the files in the CSCI211 GitHub repo.
```
$ ls -al
```
3. Open the `README.md` file with the editor of your choice (below, I use vim)
```
$ vim README.md
```
4. Edit the file. The file already contains a couple lines, so below these lines, add the following (your first and last name, the current semester, your GitHub username, and your Chico State portal username) in the format shown below:
```
## FirstName LastName

*Fall 2023*

* GitHub username: my-github-username
* Chico State username: my-chico-username
```
  -  Make sure to include the spacing as shown, so that your README.md file will include a second-level heading (for your name), some styling (italics around the semester), and an unordered list (for your GitHub and Chico State usernames).<br>

> This code uses [GitHub Flavored Markdown](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#lists). Markdown is plain-text formatting syntax that is commonly used in README files.<br>


5. When you are done editing, save your changes and exit the file.<br>
6. Currently, our changes only exist locally, but we want our changes to appear in the remote CSCI211 GitHub repository. First, show the modified files in the working directory and confirm that there are only changes to the `README.md` file:
```
$ git status
```
7. See what has been changed (but not yet staged) in the `README.md` file (this command opens up the README.md file, and you can use vim commands to move around and view the changes (new lines will be highlighted in green and have a '+' sign next to them, while anything removed will be highlighted in red and have a '-' sign) -- type `q` to exit):
```
$ git diff README.md
```
8. If all the changes look good, you can now commit your changes and push them to the remote GitHub repo.
  - Add the `README.md` file as it looks now to the staging area:
```
$ git add README.md
```
  - Commit your staged content to a new commit snapshot (make sure to include a brief but descriptive commit message that explains the changes in the current commit):
```
$ git commit -m "[descriptive message]"
```
  - transmit local branch commits to the remote repository branch:
```
$ git push origin main
```
> Note: "origin" is the default name for a remote repository. You can see the remote repo attached to the current repository with this command: `git remote -v`<br>

> Note: "main" is the default branch name. You may see older versions of git using "master" as the default branch name. For CSCI211, it is fine if you do all of your work on the main branch. For more on branching, refer to the Learn Git Branching tutorial, or complete the Lab 01 Extra Credit.<br>

9. Visit your CSCI211 GitHub repo and confirm that your changes have been added to your remote repo (reload the page if necessary). You should be able to see your changes in the README. You can also click on the "commits" button (below the green "< > Code" button) to see the history of all the commits to this repository, organized by date.<br>

10. At this point, you are done with Lab 01, Exercise 1, and you can complete the rest of Lab 01.<br>

I recommend that you commit and push all of your code for CSCI211 lab exercises and programming assignments to your GitHub repo IN ADDITION to submitting your code to Inginious for grading. Submitting to Inginious is necessary for grading, but committing and pushing to a remote repo is good practice:

* **Git is very widely used in the software development industry** (many of your future employers and professors will want you to know how to use git!)
* If your code has bugs and is not working, you can commit your code to the CSCI211 repo -- **I can easily view your code and help you debug**. (This is one of the easiest ways for me to help, because I can see all of your code in one location). In the future, you can refer back to your commit history and see how you resolved different bugs.
* Working with Git now will give you **more experience with version control** (easily revert to previous versions, compare changes, and collaborate more effectively with others in the future).
* For **code backup and recovery** -- sometimes, your local machine fails or you accidentally delete code. If you make regular commits, you can more easily recover code that would otherwise be lost.
* A **history of commits that shows your progress** is a good indicator to me that you have spent time working on your code and are not cheating (it is not the only indicator, but it is one thing I can refer to if your code is flagged).
* If you are **unable to submit to Inginious for any reason** (e.g. if the VPN is not working), you can commit and push your code to GitHub. Let me know what happened; I can see the time/date that you submitted and refer to your code on GitHub when I am grading.
* The list goes on :grinning:


## Exercise 2: Creating, compiling, and running a CPP program

1. Enter the lab01_hello subdirectory, and create the file `hello.cpp`. The following command starts the vim editor and creates a file with the name `hello.cpp` (you could use a similar command with other editors):
```
$ vim hello.cpp
```
This is another way you could accomplish the same thing -- use `touch` to create the file and then start the editor (this time using Atom) and open up your present working directory:
```
$ touch hello.cpp
$ atom .
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
3. Compile this file using the following command:
```
$ g++ hello.cpp
```
4. The `g++` command should have created a file called `a.out` -- use `$ ls -l` to find out if `a.out` is in your directory. Note that `a.out` automatically has execute protection ("x").  When a file has execute permission you can execute it.
```
$ ls -l
```
5. You can now run the executable `a.out`:
```
$ ./a.out
```
It is possible to [add `./` to the search path](https://stackoverflow.com/questions/27188856/adding-any-current-directory-to-the-search-path-in-linux) in Linux so that you do not have to type `./` before the executable every time, but it is not necessary. In my instructions, I will include `./` before all executables.<br/>

Submit `hello.cpp` to Inginious.

## Exercise 3: Addition

Write a program that reads in two numbers, adds the numbers together, and prints the result.

* Move to your lab01_add directory:
```
$ cd ../lab01_add
```
The two dots mean to go "up" a directory and find the `add` directory. If that did not work, try using cd with the "full directory path" or "full path" (use the `pwd` command to determine the full path to your current directory)

* Create a new file for your program called `add.cpp`.

* When your program is run, it should work like this (the "./a.out" "40" and "2" are typed by the user, the "40 + 2 = 42" is printed by the program, and the "$" sign represents the command prompt):
```
$ ./a.out
40
2
40 + 2 = 42
$
```

* For this exercise you will need to read in an integer.  You can read an integer in C++ using `cin`:
```cpp
int value1;
cin >> value1;
```

* Compile and run your program to make sure it works correctly.  Your output must EXACTLY match my output: `<number><space><+><space><number><space><=><space><number><newline>`
* Some sample input and output are available in `starter-repo/211/lab01_add/tests` directory. In this directory you will find *.in and *.out files. For example, `t01.in` is the input for test 1 and `t01.out` is the expected output for test 1. All of the tests in the directory will be used to grade your program on Inginious. If you pass these tests, you will get full credit.
* An easy way to see the content of a small file is to use the Linux cat command:
```
$ cat tests/t01.in
40 2
$ cat tests/t01.out
40 + 2 = 42
$
```
* See the [Labs directory README](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Labs) for a full description of how to test your assignments. If you understand the described testing mechanism now, it will make your semester much easier. One of the most important aspects of this lab is for you to understand how to test your code!<br>

Once your program is working, submit `add.cpp` to [Inginious]().

## Exercise 4: Say Hello

Write a program that reads in a number and prints "hello" that number of times:
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
* All the characters shown above were printed by the program, except the 5<enter> which was typed by the user. So, at the beginning of each line where you print "hello", there should be a number and a space. The number should start at 0 and count up, representing the number of times "hello" is displayed.

* Move to your `lab01_print` directory.
* Create a new file for your program called `print.cpp`.
* Use a for-loop to implement this program.
* When your program is working, test it with the provided tests (see the testing and turn in instructions for Exercise 3; the only difference is that the tests are in the directory `starter-repo/211/lab01_print/tests`).
* Make sure your program passes all the tests.<br>

Submit `print.cpp` to [Inginious]().

## Exercise 5: Linux Commands and Testing Quiz

One of the main point of these assignments is to familiarize you with the Linux command line interface (refer to the [Lab 01 Lecture Notes on Linux](#lecture-notes)) and introduce you to the [testing mechanism](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/README.md#testing-assignments) (instructions in the Labs directory README).<br/>

Make sure you understand how to:
* navigate the Linux file system
* interact with processes running in the terminal
* add and remove files and directories
* create and run an executable
* use file redirection to test assignments (using < and > to redirect input into a program and redirect output to a file).
* compare your output to the correct output (using `cat`, `diff`, `vimdiff`)<br>

To check your understanding of these concepts and receive credit for Lab 01 Exercise 5, complete this [211 Linux Commands and Testing Google Survey](https://docs.google.com/forms/d/e/1FAIpQLScYYUFPLcTAE7BNwHmT3G98Ityvpeu7e_MNSLF2qC5pS_MXrw/viewform?usp=sf_link). <br>

Note: You will need to be logged in to your \@mail.csuchico email in order to take the Google Survey. If you get a message that you are unable to access the survey, try using your Chico portal username and password to login to Google. If you are not sure how to proceed, feel free to ask for help!<br>

For this exercise, make sure to submit the [211 Linux Commands and Testing Google Survey](https://docs.google.com/forms/d/e/1FAIpQLScYYUFPLcTAE7BNwHmT3G98Ityvpeu7e_MNSLF2qC5pS_MXrw/viewform?usp=sf_link).

## Lab 01 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must set up your CSUChico-CSCI211 GitHub account, submit `hello.cpp`, `add.cpp`, and `print.cpp` to Inginious (there is a separate submission link for each exercise), and complete the 211 Linux Commands and Testing Google Survey. If you are not able to complete all the exercises, turn in your partial work for partial credit (or submit later for late credit!)<br>

Optional but recommended step: add, commit, and push your code to GitHub (the `add` command below adds all changes in the repo):
```
$ git add -A
$ git commit -m "completes lab01 exercises"
$ git push origin main
```

For more information, see [instructions for submitting files]().<br>

If you have time left over, I recommend that you start working on p1. After you've made some progress on the assignment, practice using the different options for testing your code before you submit the code to Inginious.

***

## Extra Credit: Complete the Git Google Survey

Complete the [Git Basics Google Survey](https://docs.google.com/forms/d/e/1FAIpQLSezh266Wzhha6HZtSdUQEX1QyvzDuzgWihREqvRgK6AFdLDjg/viewform?usp=sf_link) for extra credit -- this survey discusses Git when used with GitHub (you would use similar commands when working with any Git repository hosting service). When you provide your answers, make sure that your answers are complete (i.e. include a branch name/file name/message/URL/etc if the command requires it to run successfully).<br>

There are 20 questions in this survey. Many of them can be answered with one Linux Git command, some of which are covered in Exercise 1. Other questions (such as the ones on branching and creating a new repo) are not discussed in Exercise 1 (hint: refer to the Git Cheat Sheets and try to see if you can use the commands and implement each step in a test repo). Let the instructor know if anything is unclear.<br>

* Part 1 (questions 1-6):
  * Create a new GitHub repository (a remote repo)
  * Connect a remote repo with a local repo
  * Initialize a local repo as a Git repository
* Part 2 (questions 7-13):
  * Check the status of your repo
  * Add and stage a commit
  * Push a commit from a local repo to a remote repo
* Part 3 (questions 14-20):
  * Create a branch
  * Move between branches
  * Merge branches
  * View your code on GitHub

The Git commands covered in this survey are very useful for individual projects as well as larger collaborative projects. The focus is on commands that may benefit you on small individual projects, such as making frequent commits and utilizing separate branches to help you organize your work and learn from your commit history.<br>

[Top of the Page](#lab-1)
