# Lab 6

* Introduction to the GNU gdb debugger<br>
* Exceptions practice<br>

Lab 06 Exercises:
* [Exercise 1: Debugging Practice Part 1](#exercise-1-debugging-practice-part-1) (lab06_gdb/p1)
* [Exercise 2: Debugging Practice Part 2](#exercise-2-debugging-practice-part-2) (lab06_gdb/p2)
* [Exercise 3: Debugging Practice Part 3](#exercise-3-debugging-practice-part-3) (lab06_gdb/p3)
* [Exercise 4: Debugging Practice Part 4](#exercise-4-debugging-practice-part-4) (lab06_gdb/p4)
* [Exercise 5: An Exceptional Program](#exercise-5-an-exceptional-program) (lab06_exceptions)
  * [Part 1: Getting Started](#part-1-getting-started)
  * [Part 2: Loop](#part-2-loop)
  * [Part 3: String Posers](#part-3-string-posers)
  * [Part 4: Bad Numbres](#part-4-bad-numbres)

> Note: To get full credit for this lab, you must complete the GDB Survey (exercises 1-4) and submit one file to INGInious (exercise 5).

## Goals

Learn the basics of the [GNU Project Debugger](https://www.gnu.org/software/gdb/) (gdb) so you can use it to help identify and resolve errors, bugs, and issues within your C++ programs (also works for many other programming languages). Debugging tools like are essential in the software development process!<br>

Learn about C++ exceptions, which provide a way to react to exceptional circumstances (like runtime errors) that arise during program execution, and allow you to gracefully handle unforeseen conditions without crashing the program.

> Note: You will need to be logged in to your \@mail.csuchico.edu Google account in order to take the Google Survey. If you get a message that you are unable to access the survey, try using your Chico portal username and password to login to Google. If you are not sure how to proceed, feel free to ask for help!<br>

## Exercise Setup

* Read the [GDB Guide](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/gdb.md) before completing Lab 06, Exercises 1, 2, 3, and 4.<br>

Complete the following exercises with gdb. Then, if you have time and are interested, you can try completing the same exercises with ddd. This lab writeup includes some additional information and hints that are not shown in the Google survey, so make sure to keep a tab open for this lab while you are taking the survey.<br>

**Note for SSH users**: ddd has a graphical window interface and therefore will not load via SSH (a text-based protocol).<br>

**Note for Mac users**: You cannot do this lab on a Mac unless you have GNU's g++ and gdb installed. These are no longer part of xcode, you have to download and install them using [homebrew](https://brew.sh/). It takes over an hour to install g++ using homebrew. **I recommend you use ecc-linux or a comparable Unix-like system** to complete Lab 06.<br>

I have created several sample programs for you to use with the debugger. You can find them in your CSCI211 starter-repo `211/lab06_gdb/` directory.<br>

You can compile all the programs within the lab06_gdb directory with one call to `make`:
```
$ cd ~/211/lab06_gdb
$ make
```
`make` should not issue any errors -- let me know if you get errors. After running `make`, you should be able to list the contents of the folder and see that four executables have been generated (named `p1`, `p2`, `p3`, and `p4`).<br>

Nothing will be submitted to INGInious for Lab 06, Exercises 1-4, but you must complete [this GDB survey](https://docs.google.com/forms/d/e/1FAIpQLSdNNjIHgqtmHd_zsGy12nYTealx90JQA_FDU_SFu9Dkrp3awg/viewform?usp=sf_link).

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

4. ON SURVEY: What would you need to do to avoid this error?

* Note: the general solution to avoiding this error applies to any program where you need to dereference pointers, not just to a simple and mostly pointless program like p1.cpp.

## Exercise 2: Debugging Practice Part 2

* Start gdb with executable p2:
```
$ gdb p2
```
* Type `run` at the (gdb) to run this program

1. ON SURVEY: What error caused this program to terminate?

* Type `where` at the (gdb) to see the list of functions that were called

2. ON SURVEY: What functions were called before the program crashed?

* Notice that the `where` command told you the arguments to the functions f() and g()

* You can use the `print` or `p` command to print the value of a variable:
```
(gdb) p b
$1 = 52
```
3. ON SURVEY: What **GDB command** would you type to print the address of the variable b? (Hint: Think about how you would print the address of a variable in normal C++ code, and combine that with a GDB command for printing variables).

4. ON SURVEY: What is the **address** of the variable b? (Note: The memory address where a variable is located can change each time a program is run, so your address may not be exactly the same as mine -- the OS is choosing the best location based on the current applications being managed).

5. ON SURVEY: Remember that a pointer is a variable whose value is the address of another variable. What GDB command would you type to print the **value** of the variable ptr?

6. ON SURVEY: What is the **value** of the variable ptr?

7. ON SURVEY: What GDB command would you type to print the **address** of the variable ptr?

* Now try to dereference ptr (get the value of the variable that is located at the memory address pointed to by ptr) and print this value:
```
(gdb) p *ptr
```

8. ON SURVEY: What information is provided when you try to print *ptr? How does this relate to the error that caused the program to terminate?

9. ON SURVEY: Now type `print a` to try to print the value of the variable `a`. What gets printed?

* Note that it the value of a will not be printed at this point, because gdb is currently pointing to the code in function f(). If you use the `up` command, it will be pointing at the code in the function that called f().<br>

Type `up` at the (gdb), then type `print a`<br>

10. ON SURVEY: What gets printed when you type `print a` after using the `up` command to move up to the function that called f()?


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

3. ON SURVEY: What gets printed when you try to print the value of the variable `i`?

4. ON SURVEY: Now type `print m_values[0]` to try to print the value at the 0 index of the m_values array. What gets printed?

5. ON SURVEY: Now type `print *m_values[0]` to try to print the value at the 0 index of the m_values array. What gets printed?

6. ON SURVEY: Now that you have printed several different variables, can you explain why this program has a segmentation fault?

7. ON SURVEY: How can you update the program to get rid of the segmentation fault? (Hint: you only need to change one thing, and it is NOT on the line where the error occurred).

## Exercise 4: Debugging Practice Part 4

* Start gdb with the executable p4
```
$ gdb p4
```
* Type `run` at the (gdb) to run this program

* Type `where` at the (gdb)

1. ON SURVEY: What is different between running p4 with gdb and running p1 with gdb?

* If you have not already done so, quit gdb (type `q` at the (gdb), followed by `y`).

* List the contents of the lab06_gdb directory, using the `-h` and `-l` options to use a long listing, human-readable format:
```
$ ls -hl
```

* You should see a detailed listing of files and directories. Look for the sizes of the `p1` and `p4` executables. The size will be listed after the owner and group names and before the last modification date. If you just use `ls -l`, you will see the size in bytes; using `-hl` prints the size in a more human readable format (e.g. `1K`, `234M`, `2G`, etc).

2. ON SURVEY: Is the p1 executable smaller or larger than the p4 executable?

3. ON SURVEY: Look at the `Makefile` in the `lab06_gdb` directory. How is the recipe for generating the `p4` executable different from the recipe for generating the `p1` executable?

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
