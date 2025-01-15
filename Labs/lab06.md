# Lab 6

* Introduction to the GNU gdb debugger<br>
* Exceptions practice<br>

Lab 06 Quiz Exercises:
* [Exercises 1, 2, 3, and 4: GDB Quiz](#exercises-1-2-3-and-4-gdb-quiz) (lab06_gdb)

> Note: All quizzes can be found on Canvas. Lab quiz exercises may be completed any time before the end of the semester for full credit. Multiple attempts are allowed; I will keep your highest score. Lab 04, Exercises 1, 2, 3, and 4 are combined into one quiz (the GDB (GNU Debuggers) Quiz). It is recommended that you complete the GDB Quiz at least once BEFORE completing Lab 06, Exercise 5. If you do not do as well as you'd like on the quiz, feel free to complete the quiz again at a later time.

Lab 06 Exercises:
* [Exercise 5: An Exceptional Program](#exercise-5-an-exceptional-program) (lab06_exceptions)
  * [Part 1: Getting Started](#part-1-getting-started)
  * [Part 2: Loop](#part-2-loop)
  * [Part 3: String Posers](#part-3-string-posers)
  * [Part 4: Bad Numbres](#part-4-bad-numbres)

> Note: To get full credit for this lab, you must complete the GDB Quiz (exercises 1-4) and submit one file to INGInious (exercise 5).

## Goals

Learn the basics of the [GNU Project Debugger](https://www.gnu.org/software/gdb/) (gdb) so you can use it to help identify and resolve errors, bugs, and issues within your C++ programs (also works for many other programming languages). Debugging tools like are essential in the software development process!<br>

Learn about C++ exceptions, which provide a way to react to exceptional circumstances (like runtime errors) that arise during program execution, and allow you to gracefully handle unforeseen conditions without crashing the program.

## Exercises 1, 2, 3, and 4: GDB Quiz

The GDB Quiz is meant to give you some practice and familiarize you with GDB, the GNU project debugger that runs on Unix-like systems. GDB allows you to see what is going on 'inside' a program while it executes, or see what the program is doing at the moment it crashes. GDB can be used to help identify and resolve errors, bugs, and issues within your C++ programs (it also works for many other programming languages). Debugging tools like GDB are essential in the software development process!<br>

It is recommended that you complete the GDB Quiz during the week you are working on Lab 06. If you do not do as well as you'd like on the quiz, feel free to complete the quiz again at a later time. If you want to walk through the lab quiz again, run the command make clean in the `lab06_gdb` directory before progressing through the steps of the lab quiz.<br>

**Note:** You cannot do this lab on macOS or Windows unless you have GNU's g++ and gdb installed. These are no longer part of xcode, so macOS users would need to download and install them using [homebrew](https://brew.sh/). It may take over an hour to install g++ using homebrew. For Windows users, [MinGW](https://rpg.hamsterrepublic.com/ohrrpgce/GDB_on_Windows) is a potential option; however, I have heard reports that it is prone to crashing when certain commands are used. **I recommend you use ecc-linux or a comparable Unix-like system to complete the Lab 06 GDB Quiz**.

### GDB Resources

* [GNU Project Debugger](https://www.sourceware.org/gdb/) - the official homepage for GDB.
* [GDB Guide](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/gdb.md) - My guide for CSCI 211 students learning how to use gdb. There is a lot that you can do with GDB, so this guide focuses on basic gdb usage that you will use in the GDB Quiz. It is a good starting point if you are working on a program and run into common errors (like segfaults).
  * The GDB Guide mentions ddd, which provides a graphical user interface option for running gdb. After you have completed the GDB Quiz with gdb, you may try ddd if you would like; however, ddd has a graphical window interface and therefore will not load via SSH (a text-based protocol). This means you will likely not be able to use ddd on ecc-linux.<br>

### GDB Quiz Overview

The GDB Quiz can be found on Canvas. This quiz contains 4 parts. All parts of this quiz should be completed in the `lab06_gdb` directory. It is recommended that you read the [GDB Guide](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/gdb.md) before completing Lab 06, Exercises 1, 2, 3, and 4 (you may reference the GDB Resources while you are completing the quiz as well). Note that the exercises use sample programs, specifically created for you to practice with the debugger (this means there are some errors built into the examples, and you should NOT necessarily follow these examples in your own code). All of these programs can be found in your CSCI211 repo, in the `211/lab06_gdb/` directory.

* Before beginning the GDB Quiz:
  * Move into the `211/lab06_gdb/` directory.
  * Compile all the programs within the `lab06_gdb` directory with one call to `make`:
```
$ cd ~/211/lab06_gdb
$ make
```
  * `make` should not issue any errors -- let me know if you get errors. After running `make`, you should be able to list the contents of the folder and see that four executables have been generated (named `p1`, `p2`, `p3`, and `p4`).<br>

* Part 1 (questions 1-4):
  * These questions correspond with Lab 06, Exercise 1 and utilize the `p1` program that is inside the `lab06_gdb` directory
* Part 2 (questions 5-14):
  * These questions correspond with Lab 06, Exercise 2 and utilize the `p2` program that is inside the `lab06_gdb` directory
* Part 3 (questions 15-21):
  * These questions correspond with Lab 06, Exercise 3 and utilize the `p3` program that is inside the `lab06_gdb` directory
* Part 4 (questions 22-24):
  * These questions correspond with Lab 06, Exercise 4 and utilize the `p4` program that is inside the `lab06_gdb` directory

After you have completed the GDB Quiz, you have successfully completed Lab 06, Exercises 1, 2, 3, and 4 (Debugging Practice Parts 1-4, using the lab06_gdb directory). Nothing will be submitted to INGInious for Lab 06, Exercises 1-4.

***

## Exercise 5: An Exceptional Program

In this lab exercise, you will practice a common situation involving user input and error checking. You will write a simple program that asks the user to enter a number from 1 to 10. You must catch situations in which the user enters a number out of bounds (greater than 10 or less than 1), a non-integer number (e.g. a double), or a non-numeric value (e.g. a string). Your program is expected to recover and continue, until the user inputs a number that meets the specified criteria.<br>

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

## Lab 06 Submissions

All labs are due at 11:59pm the Friday following lab. For Lab 06, Exercises 1, 2, 3, and 4 you must complete the GDB Survey. For Lab 06, Exercise 5, you must submit `main.cpp` (Parts 1, 2, 3, and 4) to [INGInious](https://inginious.csuchico.edu/).<br>

Optional but recommended submission step: add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git add -A
$ git commit -m "completes lab06 exercises"
$ git push origin main
```

***

After completing the exercises and the survey, you can start working on programming assignment 4. Read the assignment writeup to get an idea of what you need to do. You may want to start on Lab 07 (implement a stack of doubles), as the stack of doubles will be used in P4.

[Top of the Page](#lab-6)
