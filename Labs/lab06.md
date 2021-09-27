# Lab 6

Introduction to the GNU gdb and ddd debuggers

Lab 06 Exercises:
* [Exercise 1: Debugging Practice Part 1](#exercise-1-debugging-practice-part-1) (lab06_gdb/p1)
* [Exercise 2: Debugging Practice Part 2](#exercise-2-debugging-practice-part-2) (lab06_gdb/p2)
* [Exercise 3: Debugging Practice Part 3](#exercise-3-debugging-practice-part-3) (lab06_gdb/p3)
* [Exercise 4: Debugging Practice Part 4](#exercise-4-debugging-practice-part-4) (lab06_gdb/p4)

> Note: To get full credit for this lab, you must complete a Google Survey. You do not need to submit any files to Turnin for lab 6.

## Goals

Learn the basics of the [GNU Project Debugger](https://www.gnu.org/software/gdb/) (gdb or ddd) so you can use them to find bugs in your class projects.

## Required Survey

You do not have to turn in any files for this lab, but you do have to complete [this Google survey](https://docs.google.com/forms/d/e/1FAIpQLSdNNjIHgqtmHd_zsGy12nYTealx90JQA_FDU_SFu9Dkrp3awg/viewform?usp=sf_link) to get credit for Lab 06.

## gdb/ddd Lecture Notes

`gdb` is a program debugger. It allows you to examine a program while the program is executing. The interface to gdb is textual (just like the interface to the bash shell is textual). You control gdb by typing textual commands at its prompt (the gdb command prompt is `(gdb)`).<br>

`ddd` provides a graphical user interface for gdb. The user can control gdb by pressing buttons and making menu selections. It also contains the ability to illustrate data structures (such as a linked list) using diagrams.<br>

Both `gdb` and `ddd` are available on Linux, OSX (must install using homebrew, see note below), and Cygwin (sometimes they don't work well on Cygwin).<br>

You can learn about gdb and ddd using the man command
```
$ man gdb
$ man ddd
```
* Complete gdb documentation can be found in the [gdb manual](https://www.gnu.org/software/gdb/documentation/).
* Complete ddd documentation is available on [ddd's homepage](https://www.gnu.org/software/ddd/).<br>

`ddd` is easier to use in that it provides a nice menu and shows the codes being executed. However, it has a lot of features that may seem overwhelming at first. I suggest you try gdb first using the few simple commands listed below.  Once you have a good idea how gdb works, you can try ddd. Once you understand the concepts of debugging, you may prefer using ddd to debug your programs.

### Starting gdb (and ddd)

1. Compile your programs with the `-g` option. All .o files and the final linking must have the -g option. The -g option tells the compiler to put extra information (such as variable names) into the executable so a debugger can access them.
2. At the command prompt type `gdb` (or `ddd`) followed by your executable name:
```
$ g++ -g -o p1 p1.cpp
$ gdb p1
GNU gdb (Ubuntu 9.1-0ubuntu1) 9.1
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from p1...
(gdb)
```
3. `(gdb)` is the prompt for gdb. There are lots of commands that you can type here. For example, if you type `run`, your program will start executing.<br>

The following table lists the most commonly used gdb commands (these are the most basic commands, this is NOT a complete list).
| Command | Shortcut | Description |
| --- | --- | --- |
| quit | q | quit the debugger and exit. If a program is running it will ask you if you still want to quit. |
| help | h | W/o and argument lists help topics. If followed by a command, will describe that command:  e.g. `help run` |
| run | r | Start running the current program. May be followed with command line arguments:  e.g. `run < t01.in` |
| print | p | Print the given variable. For example, if there is a variable i in the current context, `print i` will print the value of i. |
| list | l | List the C++ code for the currently executing instruction. List advances through the code each time it is called. (lowercase L)|
| list 42 | l 42 | Lists the code at line 42 (you may pass any number here) |
| where | where | Prints the current line number and all the functions that were called to get there (prints the run time stack). |
| up | up | Move up to the function that called the current function (move up the run-time stack, see `where` above). For example, if main() calls foo() and gdb is stopped in foo(), the `up` command will move gdb's focus to main() so you can see what was going on in main(). |
| down | d | Move down the run time stack (see `up` and `where`). |
| break | b | Set a breakpoint. Must specify a line number for the current file, or filename:line for another file |
| step | s | Execute one and only one line of code. |
| next | n | Same as step, but skips over function calls. |
| finish | f | Execute until the end of the current function. |
| continue | c | Continue execution until the next breakpoint or until the end of the program. |

You may find this [GDB Cheatsheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf) useful as a quick reference for common gdb commands.<br>

## Exercise Setup

Complete the following exercises with gdb. Then, if you have time and are interested, try completing the same exercises with ddd. This lab writeup includes some additional information and hints that are not shown in the Google survey, so make sure to keep a tab open for this lab while you are taking the survey.<br>

**Note for SSH users**: ddd has a graphical window interface and therefore will not load via SSH (a text-based protocol).<br>

**Note for Mac users**: You cannot do this lab on a Mac unless you have GNU's g++ and gdb installed. These are no longer part of xcode, you have to download and install them using [homebrew](https://brew.sh/). It takes over an hour to install g++ using homebrew. **I recommend you use ecc-linux or a comparable Unix-like system**.<br>

I have created several sample programs for you to use with the debugger. You can find them in your 211-starter-pack/211/lab06_gdb directory.<br>

You can compile all the programs with one call to `make`:
```
$ cd ~/211/lab06_gdb
$ make
```
`make` should not issue any errors -- let me know if you get errors.<br>

Nothing will be submitted to Turnin for this lab, but you must complete [this Google survey](https://docs.google.com/forms/d/e/1FAIpQLSdNNjIHgqtmHd_zsGy12nYTealx90JQA_FDU_SFu9Dkrp3awg/viewform?usp=sf_link).

> Note: The programs in this lab were created to produce errors, so that you can get some practice working with gdb. Don't spend too much time trying to figure out what the program is "supposed" to do -- in some cases, the code is an example of something you should NOT do in your own programs.

## Exercise 1: Debugging Practice Part 1

* Start gdb with the executable p1:
```
$ gdb p1
```
* Type `run` or `r` at the (gdb) to run this program

1. ON SURVEY: What error causes this program to terminate?
2. ON SURVEY: On what line does this program crash?

* Type `list` or `l` at the (gdb) to list the source code

3. ON SURVEY: Explain the defect in the program that causes this problem.

* Type `quit` or `q` at the (gdb) to quit the debugger

## Exercise 2: Debugging Practice Part 2

* Start gdb with executable p2:
```
$ gdb p2
```
* Type `run` at the (gdb) to run this program

* Type `where` at the (gdb) to see the list of functions that were called

1. ON SURVEY: What error caused this program to terminate?

2. ON SURVEY: What functions were called before the program crashed?

* Notice that the `where` command told you the arguments to the functions f() and g()

* You can use the `print` or `p` command to print the value of a variable:
```
(gdb) p b
$1 = 52
```
3. ON SURVEY: What **command** would you type to print the address of the variable b? (Hint: Think about how you would print the address of a variable in normal C++ code).

4. ON SURVEY: What is the **address** of the variable b? (Note: The memory address where a variable is located can change each time a program is run, so everyone won't have the same answer -- the OS is choosing the best location based on the current applications being managed).

5. ON SURVEY: Remember that a pointer is a variable whose value is the address of another variable. What is the **value** of the variable ptr?

6. ON SURVEY: What is the **address** of variable ptr?<br>

* Now try to dereference ptr (get the value of the variable that is located at the memory address pointed to by ptr) and print this value:
```
(gdb) p *ptr
```

7. ON SURVEY: What information is provided when you print *ptr? How does this relate to the error that caused the program to terminate?

8. ON SURVEY: Now try to print the value of the variable a. What gets printed? Note that it the value of a will not be printed at this point, because gdb is currently pointing to the code in function f(). If you use the `up` command, it will be pointing at the code in the function that called f().

* Use the `up` command to go to the function that called f().

9. ON SURVEY: What is the address of the variable a?

## Exercise 3: Debugging Practice Part 3

* Start gdb with the executable p3
```
$ gdb p3
```

* Type `run` at the (gdb) to run this program

1. ON SURVEY: This program has a segmentation fault. In what function does the error occur?

* Quit gdb and then restart gdb with the executable p3. Before you type `run`, set a breakpoint at the entry to the function where the error occurred. This will allow you to walk through the function step-by-step. If you want to, you can set multiple breakpoints. For example, the following command sets a breakpoint at the beginning of `main()`:
```
(gdb) break main
```

2. ON SURVEY: What do you type at the (gdb) prompt to set a breakpoint at the function where the error occurred?

* Now type `run`
```
(gdb) run
```
* The program will run until the first breakpoint it encounters. Then you can use either `next` (`n`) or `step` (`s`) to walk through the program after the breakpoint, one instruction at a time. `step` will dive into any function encountered along the way, while `next` will call functions but not dive into them (unless you've set a breakpoint at the function).
```
(gdb) n
(gdb) s
```

* gdb will stop when it reaches the segmentation fault.

* Try printing the different variables. You can print any variable that is accessible from your current location.
```
(gdb) p i
(gdb) p m_size
(gdb) p m_values
(gdb) p *m_values
(gdb) p m_values[0]
```

* Make sure you understand what information gdb is giving you. You may need to run gdb several times with different breakpoints and different commands. If you are still not sure what's happening, feel free to ask for help.

3. ON SURVEY: Explain why this program has a segmentation fault.

4. ON SURVEY: How can you update the program to get rid of the segmentation fault? (Hint: you only need to change one thing, and it is NOT on the line where the error occurred).

## Exercise 4: Debugging Practice Part 4

Program p4 is the same program as p1 but is compiled w/o the -g option

* Start gdb with the executable p4
```
$ gdb p4
```
* Type `run` at the (gdb) to run this program

* Type `where` at the (gdb)

1. ON SURVEY: What is different between running p4 with gdb and running p1 with gdb?

2. ON SURVEY: Is the p1 executable smaller or larger than the p4 executable? (Hint: in the command line, you can use `ls -l` to list files with the long listing format. The size (in bytes) will be listed after the owner and group names and before the last modification date. You can use `ls -lh` to print more human readable file sizes).

***

After completing the exercises and the survey, you may work on programming assignment 4.

## Lab 06 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must complete the Google Survey (Exercises 1, 2, 3, and 4). You will not submit anything to Turnin for Lab 06. If you are not able to complete all the exercises, turn in your partial work for partial credit.

[Top of the Page](#lab-6)
