# Lab 6

Introduction to the GNU gdb debugger

Lab 06 Exercises:
* [Exercise 1: Debugging Practice Part 1](#exercise-1-debugging-practice-part-1) (lab06_gdb/p1)
* [Exercise 2: Debugging Practice Part 2](#exercise-2-debugging-practice-part-2) (lab06_gdb/p2)
* [Exercise 3: Debugging Practice Part 3](#exercise-3-debugging-practice-part-3) (lab06_gdb/p3)
* [Exercise 4: Debugging Practice Part 4](#exercise-4-debugging-practice-part-4) (lab06_gdb/p4)

> Note: To get full credit for this lab, you must complete a Google Survey. You do not need to submit any files to INGInious for the Lab 6 GDB exercises.

Lab 06 Extra Credit: Exceptions (try/catch, throw)
* [Extra Credit: An Exceptional Program](#extra-credit-an-exceptional-program) (lab11_exceptions)
  * [Part 1: Getting Started](#part-1-getting-started)
  * [Part 2: Loop](#part-2-loop)
  * [Part 3: String Posers](#part-3-string-posers)
  * [Part 4: Bad Numbres](#part-4-bad-numbres)

## Goals

Learn the basics of the [GNU Project Debugger](https://www.gnu.org/software/gdb/) (gdb) so you can use it to find bugs in your C++ programs (also works for many other programming languages).

## Required Survey

You do not have to turn in any files for this lab, but you do have to complete [this Google survey](https://docs.google.com/forms/d/e/1FAIpQLSdNNjIHgqtmHd_zsGy12nYTealx90JQA_FDU_SFu9Dkrp3awg/viewform?usp=sf_link) to get credit for Lab 06.<br>

Note: You will need to be logged in to your \@mail.csuchico email in order to take the Google Survey. If you get a message that you are unable to access the survey, try using your Chico portal username and password to login to Google. If you are not sure how to proceed, feel free to ask for help!<br>

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

### Starting gdb

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

## Exercise Setup

Complete the following exercises with gdb. Then, if you have time and are interested, try completing the same exercises with ddd. This lab writeup includes some additional information and hints that are not shown in the Google survey, so make sure to keep a tab open for this lab while you are taking the survey.<br>

**Note for SSH users**: ddd has a graphical window interface and therefore will not load via SSH (a text-based protocol).<br>

**Note for Mac users**: You cannot do this lab on a Mac unless you have GNU's g++ and gdb installed. These are no longer part of xcode, you have to download and install them using [homebrew](https://brew.sh/). It takes over an hour to install g++ using homebrew. **I recommend you use ecc-linux or a comparable Unix-like system** to complete Lab 06.<br>

I have created several sample programs for you to use with the debugger. You can find them in your 211-starter-pack/211/lab06_gdb directory.<br>

You can compile all the programs with one call to `make`:
```
$ cd ~/211/lab06_gdb
$ make
```
`make` should not issue any errors -- let me know if you get errors.<br>

Nothing will be submitted to INGInious for this lab, but you must complete [this Google survey](https://docs.google.com/forms/d/e/1FAIpQLSdNNjIHgqtmHd_zsGy12nYTealx90JQA_FDU_SFu9Dkrp3awg/viewform?usp=sf_link).

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

After completing the exercises and the survey, you can start working on programming assignment 4. Read the assignment writeup to get an idea of what you need to do. You may want to start on Lab 07 (implement a stack of doubles), as the stack of doubles will be used in P4.

## Lab 06 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must complete the Google Survey (Exercises 1, 2, 3, and 4). You will not submit anything to INGInious for the Lab 06 GDB exercises (there is an INGInious submisssion for the Lab 06 Extra Credit). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.

***

## Extra Credit: An Exceptional Program

In this lab you will practice a common situation involving user input and error checking. You will write a simple program that asks the user to enter a number from 1 to 10. You must catch situations in which the user enters a number out of bounds (greater than 10 or less than 1), a non-integer number (e.g. a double), or a non-numeric value (e.g. a string). Your program is expected to recover and continue, until the user inputs a number that meets the specified criteria.<br>

This program uses [exceptions](https://www.cplusplus.com/doc/tutorial/exceptions/), which force the calling code to recognize an error condition and handle it. Exceptions are useful for catching runtime errors (errors that happen while the program is running, after the program has been successfully compiled).<br>

In a program, a block of code is executed from within a *try-block*. If a problem shows up, the *throw* keyword is used to throw an exception, and the program can then *catch* the exception to handle the problem. Before terminating or continuing the program, we want to provide a useful error message that identifies the error so we know what issue caused the problem. Exceptions are similar to the [assert](https://www.cplusplus.com/reference/cassert/assert/) macro, as they both provide a way to test and identify if certain assumptions are being met by a program.<br>

Read the sections below to guide your solution.<br>

**Usage example (after completing all 4 parts)**
```
$ ./main
Pick a number between 1 and 10.
-1
You entered an illegal value of -1. Please try again.
Pick a number between 1 and 10.
11
You entered an illegal value of 11. Please try again.
Pick a number between 1 and 10.
four
This is not an integer. Please enter a number.
Pick a number between 1 and 10.
3.14
Non-integer value. You entered something after 3.
Pick a number between 1 and 10.
7
You picked 7.
$
```

> Note: All of the exercises build on one another and work within the same main.cpp file.

### Part 1: Getting Started

You will prompt the user to enter a number (see usage example). You will then print out the number. Write this code in a main.cpp file. Compile using `make` or the following command:
```
$ g++ -Wall -pedantic -g -std=c++11 -o main main.cpp
```

Then test your program with this simple use case (no error checking yet).
```
$ ./main
Pick a number between 1 and 10.
3
You picked 3.
$
```

### Part 2: Loop

Now, let's restrict the input to our desired range 1 to 10. If the value is out of range, print an error message and prompt again.<br>

Not all problems require throwing and catching exceptions. This one is best handled by an if-statement within a loop.<br>

Since we are basing the iteration on user input and we need the user to always enter at least once, which type of loop should you use? Please **do** consider this **while** designing your program. When the user enters a number between 1 and 10, print "You picked XX." (replacing XX with the user's numeric input). For this program, print all output to the standard output stream (cout).

```
$ ./main
Pick a number between 1 and 10.
-1
You entered an illegal value of -1. Please try again.
Pick a number between 1 and 10.
11
You entered an illegal value of 11. Please try again.
Pick a number between 1 and 10.
9
You picked 9.
$
```

## Part 3: String Posers
What happens if the user enters a string (e.g., "four") instead of an integer?  Try it out on your program.<br>

By default, C++ does not throw an exception when there is a problem with the I/O. We can change that by activating exception-throwing for this situation. Add this line at the beginning of your `main`, before the program loop.
```cpp
cin.exceptions(iostream::failbit);
```

Run your `main` again and test using a string. Now what happens?<br>

Your `cin` line now throws an exception if something is wrong with the input. In this case, `cin` received string input when it was expecting integer input, and the program aborted due to the error. We want to update the program to handle the error instead of immediately terminating. Surround your `cin` line (and lines that depend on that statement) within a `try` block. Add this `catch` block to catch the iostream failure, print an appropriate error message, reset the cin error flags, and clear the input sequence buffer:

```cpp
try
{
  cin >> input;
  // Conditional statements to check numeric input
  ...
}
catch(iostream::failure& iof)
{
  cout<<"This is not an integer. Please enter a number."<<endl;
  cin.clear(); // reset error flags
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
}
```

You will need to include a library to support `numeric_limits`. Search the Internet to determine which one. You can see some additional examples of try/catch in the [C++ documentation on Exceptions](https://www.cplusplus.com/doc/tutorial/exceptions/).

## Part 4: Bad Numbres

What happens if you enter a double value instead of an integer? Try it out.<br>

We need to identify this situation, throw an error, and catch it.<br>

Inside your `try` block, after you read in numeric input, add another nested `try-catch` block. Inside of the nested `try` block, include a condition that "peeks" ahead at the next character. If it is anything but `'\n'` (newline), then it is a bad number (not an integer). In that case, throw an error. Consider the provided catch block. What should you throw?<br>
```cpp
// after program gets input from the standard input stream
try
{
  // condition to peek at next character:
  // if next char is a newline, the input is an integer, and we can check if the input is in the range 1-10;
  // otherwise, the next char is anything but a newline -- throw <expression> to the corresponding catch block
}
catch(int pnum)
{
  cout<<"Non-integer value. You entered something after "<<pnum<<"."<<endl;
  cin.clear();  // reset error flags
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear buffer
  pnum = 0;  // reset num to its initial value
}
```

We use the catch-block to catch the problem number `pnum`, print an appropriate error message, reset the error flags, clear the buffer, and reset pnum. Notice that we are expecting integer input from `cin`, so the input that is thrown is an integer, not the entire invalid problem input.<br>

Once you are finished, submit your `main.cpp` to INGInious.

## Lab 06 Extra Credit Submission

All labs are due at 11:59pm the Friday following lab. For this lab extra credit, you must submit `main.cpp` (Parts 1, 2, 3, and 4) to [INGInious](https://inginious.csuchico.edu/). There is no late credit for extra credit.

[Top of the Page](#lab-6)
