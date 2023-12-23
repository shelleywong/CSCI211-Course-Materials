# GDB Guide

These notes are particularly useful for completing [Lab 06](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab06.md), Exercises 1, 2, 3, and 4.

## gdb Lecture Notes

`gdb` is a program debugger. It allows you to examine a program while the program is executing. The interface to gdb is textual (just like the interface to the bash shell is textual). You control gdb by typing textual commands at its prompt (the gdb command prompt is `(gdb)`).<br>

`gdb` is available on Linux, OSX (must install using homebrew, see Exercise Setup instructions below), and Cygwin (sometimes it doesn't work well on Cygwin).<br>

You can learn about gdb using the man command
```
$ man gdb
```
* Complete gdb documentation can be found in the [gdb manual](https://www.gnu.org/software/gdb/documentation/).

### Other options for debugging

`ddd` provides a graphical user interface for gdb. The user can control gdb by pressing buttons and making menu selections. It also contains the ability to illustrate data structures (such as a linked list) using diagrams.<br>

> Note: You may not be able to use `ddd` on ecc-linux.<br>

You can learn about ddd using the man command
```
$ man ddd
```

* Complete ddd documentation is available on [ddd's homepage](https://www.gnu.org/software/ddd/).<br>

`ddd` provides a nice menu and shows the codes being executed. However, it has a lot of features that may seem overwhelming at first. I suggest you try gdb first using the few simple commands listed below. Once you have a good idea how gdb works, you can try ddd. Once you understand the concepts of debugging, you may prefer using ddd to debug your programs.

> Note: If you have VSCode installed, you can get the C/C++ extension, which includes debugging features.

## Using gdb

1. Compile your programs with the `-g` option. All .o files and the final linking must have the -g option. The -g option tells the compiler to put extra information (such as variable names) into the executable so a debugger can access them.
```
$ g++ -g -o p1 p1.cpp
```
2. At the command prompt type `gdb` (or `ddd`) followed by the name of your executable:
```
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

[Top of the Page](#gdb-guide)
