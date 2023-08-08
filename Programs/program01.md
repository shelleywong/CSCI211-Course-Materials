# Program 1: Chart

CSCI 211: Programming and Algorithms II<br>
Points: 100

* [Objectives](#objectives)
* [Overview](#overview)
* [Program Requirements](#program-requirements)
* [Helpful Hints](#helpful-hints)
* [General Requirements](#general-requirements)
* [Testing Your Program](#testing-your-program)
* [Submitting Your Program](#submitting-your-program)
* [Extra Credit](#extra-credit)

## Objectives

* Give you more experience with C++ and programming in a Linux environment
* Practice text input and output
* Practice arrays
* Practice loops
* Practice functions
* Write a program from scratch

## Overview

This program reads a set of integers from standard input and draws a bar chart to standard output using asterisks and spaces ('*' and ' ').<br>

The user specifies a set of up to 100 integers. The integers may be any value greater than 0. When the user enters a 0, the program will stop reading standard input and print the chart.<br>

For example, if the user entered, `1 2 3 4 3 2 1 10 0`, your program must print:
```
       *
       *
       *
       *
       *
       *
   *   *
  ***  *
 ***** *
********
```
> Note: there are no spaces before the column of the first bar, and there are no spaces after the column of the last bar.

## Program Requirements

The input numbers might be on separate lines. If you read them using `cin >>` you don't have to think about lines, spaces, tabs.<br>

Your program must be able to read up to 100 positive integers (greater than 0) from standard input. You must store these integers in a single array. For this program, do **not** use a standard template library container, such as a vector.

> Note: There are various ways to handle invalid input. For this program, here are two ways you could handle negative numbers, after you extract the input: (1) discard/ignore the input, or (2) print a message to stderr (the standard output stream for errors), e.g. `cerr << input << " is not valid input. Enter a positive integer.\n";`. In both cases, continue accepting input after receiving the invalid input, until the user enters a 0.

After all these numbers are read and you've reached the end of input (i.e. a `0` has been entered), draw the corresponding bar chart. For example consider the following input/output (I use "$" to represent the Linux command prompt):
```
$
$ ./chart
1 4 2 3 0
 *
 * *
 ***
****
$
```

* In the example above, the user typed `./chart` at the Linux command prompt and then pressed enter (this runs the program executable).
* Then the user typed in the following text:
```
<1><space><4><space><2><space><3><space><0><enter>
```
Note: text between a `<` and a `>` is text that the user types. Sometimes it is a single key, sometimes it is a string. `<` and `>` are often used to delineate characters a user types. In the above string, <1> represents the 1 key, and \<space\> represents the space bar.
* Then the program printed the chart (the asterisks and spaces).
* The final "$" is the Linux command prompt (not printed by the program).<br>

Your program must work exactly like this. It must not print any other characters.<br>

> Note: If you think your test looks correct but is not passing some tests, whitespace may not match -- check your spaces and endlines (endl or '\n')

## Helpful Hints

### Use Constants and Avoid Magic Numbers

Since you will not be given more than 100 integers, create an array of 100 integers. It is good programming practice to place the "100" in a single place so that it is easy to change:
```cpp
const int MAX = 100;
int values[MAX];
...
for (int i = 0; i < MAX; i++)
{
    ...
}
```

[Magic numbers](https://en.wikipedia.org/wiki/Magic_number_(programming)) are unique values with unexplained meaning or multiple occurrences which could (preferably) be replaced with named constants (as shown above). The above is better than:
```cpp
int values[100];
...
for (int i = 0; i < 100; i++)
{
    ...
}
```

The use of unnamed magic numbers in code obscures the developers' intent in choosing that number, increases opportunities for subtle errors, and makes it more difficult for the program to be adapted and extended in the future. Replacing magic numbers with named constants (also called explanatory variables) makes programs easier to read, understand and maintain.

### Finding the Largest Number

You will actually be drawing a rectangular grid with a width equal to the number of bars (values entered) and a height equal to the height of the tallest bar. At each spot in the grid you must draw a space or an asterisk.<br>

Since you need to know the height of the tallest bar before you start drawing the bars, in my solution there is a function that finds the largest integer in an array of integers. It looks like this:
```cpp
// return the largest value in the given array of integers
int find_largest(int values[], int size)
{
    int largest = 0;
    // code to actually find the largest goes here
    return largest;
}
```

You would call this function like this:
```cpp
int largest = find_largest(values, size);  // Notice that there are no []
```

In C/C++ you can pass an array without specifying the size of the array. In a couple of weeks I will cover in lecture why this works.

### Some credit is better than no credit

If you don't finish in time, turn in what you have. If you turn nothing in I will give you a zero. If you turn in something I will give you partial credit.  Partial credit is always better than 0.<br>

## General Requirements

Programs should be well formatted and consistent so they are easy to read. The [General Requirements](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/README.md#general-requirements) listed in the Programs directory README apply to all programming assignments.<br>

Remember that the first lines of all your files (.h and .cpp) must contain the following comments:
```
// filename
// your name (first and last)
// your Chico Portal/INGInious username
// Short summary of the file contents
```

## Testing Your Program

* Some sample tests and a Makefile are included in the CSCI211 starter-repo `211/p1/` directory.
* Review the instructions for Testing Assignments using the provided sample tests in the [Labs directory README](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Labs)
* I will test your program with additional tests not posted in the test directory. It is a very good idea to design and implement your own set of tests.

## Submitting Your Program

I will deduct points if your program does not compile using the command `g++ -o chart chart.cpp` on a Linux machine (such as ecc-linux.csuchico.edu). If you submit your program on [INGInious](https://inginious.csuchico.edu/) and you get a message that there are not any errors, your program compiled without any errors.<br>

I will grade your program using another program, so if your program does not work exactly as specified above you will lose points. For example, if you put a space at the end of the line, or a blank line at the end of the output, you will lose points. Test your program using the provided sample tests and `diff`, `vimdiff`, or the `run_tests` script to make sure your output matches exactly.

Turn in the following file using [INGInious](https://inginious.csuchico.edu/).
```
chart.cpp
```
All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

If you are not able to complete this programming assignment, turn in your partial work for partial credit, or submit later for late credit. If you turn in nothing, you get a zero. If you turn in something, you receive a grade that is higher than zero.

## Extra Credit

If you do the extra credit you have to turn in a second `chart.cpp` ("P1_extra" on [INGInious](https://inginious.csuchico.edu/)). Make sure you do not change or delete your original `chart.cpp`. For P1, extra credit is worth 10 points.<br>

No extra credit will be give to late assignments (both the regular assignment and the extra credit must be turned in on time).<br>

In addition to printing the chart pointing "up", also print it pointing down, right, and left. Include a blank line between each chart.<br>

For example, the input `4 3 2 1 2 3 5 0` will create the following output:
```
      *
*     *
**   **
*** ***
*******

*******
*** ***
**   **
*     *
      *

****
***  
**   
*    
**   
***  
*****

 ****
  ***
   **
    *
   **
  ***
*****
```

[Top of the Page](#program-1-chart)
