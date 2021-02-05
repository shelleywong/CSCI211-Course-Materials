# Lab 6

Introduction to the GNU gdb and ddd debuggers

## Goals

Learn the basics of the [GNU Project Debugger](https://www.gnu.org/software/gdb/) (gdb and ddd) so you can use them to find bugs in your class projects.

## Required Survey

You do not have to turn in any files for this lab, but you do have to complete [this Google survey](https://docs.google.com/forms/d/e/1FAIpQLSc_DOE7Ps-l4ApR8l7KN1y2KIm1OdvnoBKJqaQF9go6P9t_eQ/viewform?usp=sf_link) to get credit for Lab 06.

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

`ddd` is easier to use in that it provides a nice menu and shows the codes being executed. However, it has a lot of features that may seem overwhelming at first. I suggest you try gdb first using the few simple commands listed below.  Once you have a good idea how gdb works, you can use ddd. Once you understand the concepts of debugging, you will probably prefer use ddd to debug your programs.

### Starting gdb (and ddd)

1. Compile your programs with the `-g` option. All .o files and the final linking must have the -g option. The -g option tells the compiler to put extra information (such as variable names) into the executable so a debugger can access them.
2. At the command prompt type `gdb` (or `ddd`) followed by your executable name:
```
$ g++ -g -o p1 p1.cpp
$ gdb p1
GNU gdb (GDB) 7.1
Copyright (C) 2010 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-slackware-linux".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /user/faculty/trhenry/tmp/lab06/p1...done.
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

## Exercise Setup

**Note for Mac users**: You cannot do this lab on a Mac unless you have GNU's g++ and gdb installed. These are no longer part of xcode, you have to download and install them using [homebrew](https://brew.sh/). It takes over an hour to install g++ using homebrew. I recommend you use ecc-linux or a comparable Unix-like system.<br>

I have created several sample programs for you to use with the debugger. They should be in your 211-starter-pack/211/lab06_gdb directory.<br>

You can compile all the programs with one call to `make`:
```
$ cd ~/211/lab06_gdb
$ make
```
`make` should not issue any errors -- let me know if you get errors.<br>

Nothing will be submitted to Turnin for this lab, but you must complete this [google survey](https://docs.google.com/forms/d/e/1FAIpQLSc_DOE7Ps-l4ApR8l7KN1y2KIm1OdvnoBKJqaQF9go6P9t_eQ/viewform?usp=sf_link).

## Exercise 1

* Start gdb with the executable p1:
```
$ gdb p1
```
* Type `run` at the (gdb) to run this program

1. ON SURVEY: What error causes this program to terminate?
2. ON SURVEY: On what line does this program crash?

* Type `list` at the (gdb) to list the source code

3. ON SURVEY: Explain the defect in the program that causes this problem.

* Type `quit` at the (gdb) to quit the debugger

## Exercise 2

* Start gdb with executable p2:
```
$ gdb p2
```
* Type `run` at the (gdb) to run this program

* Type `where` at the (gdb) to see the list of functions that were called

1. ON SURVEY: What error caused this program to terminate?

2. ON SURVEY: What functions were called before the program crashed?

* Notice that the `where` command told you the arguments to the functions f() and g()

* You can use the print (`p`) function to print the values of a variable:
```
(gdb) p b
$1 = 52
```
3. ON SURVEY: What is the address of the variable b?

* gdb is currently pointing to the code in function f().  If you use the `up` command it will be pointing at the code in the function that called f().

* Use the `up` command to go to the function that called f().

4. ON SURVEY: What is the address of the variable a?

## Exercise 3

**Note: ddd has a graphical window interface and therefore will not load via SSH (a text-based protocol). If you cannot complete Exercise 3 on a local machine, complete Exercise 3 using gdb instead of ddd.**
* Start ddd with the executable p3
```
$ ddd p3
```

* Press the run button or type `run` at the (gdb) to run this program

1. ON SURVEY: Explain why this program has a segmentation fault.

* Try printing the different variables:
```
(gdb) p m_values
(gdb) p *m_values
(gdb) p m_values[0]
```
* You can print variables by clicking on the variable in the code window.

## Exercise 4

Program p4 is the same program as p1 but is compiled w/o the -g option

* Start gdb with the executable p4
```
$ gdb p4
```
* Type `run` at the (gdb) to run this program

* Type `where` at the (gdb)

1. ON SURVEY: What is different between running p4 with gdb and running p1 with gdb?

2. ON SURVEY: Is the p1 executable smaller or larger than the p4 executable?

***

After completing the exercises and the survey, you may work on programming assignment 4
