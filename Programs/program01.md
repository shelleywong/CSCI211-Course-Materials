# Program 1: Chart

CSCI 211: Programming and Algorithms II<br>
Points: 100

## Objectives

* Give you more experience with C++ and programming in a Linux environment
* Practice text input and output
* Practice arrays
* Practice loops
* Practice functions
* Write a program from scratch

## Overview

This program reads a set of integers from standard input and draws a bar chart to standard output using asterisks and spaces ('*' and ' ').<br>

The user specifies a set of up to 100 integers greater than 0. When the user enters a 0, the program will stop reading standard input and print the chart.<br>

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

Your program must be able to read up to 100 positive integers (greater than 0) from standard input. You must store these integers in a single array. For this program, do **not** use a vector.

> Note: Did you remember to handle negative numbers?

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

## Tips & Best Practices

### Use Constants

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

The above is better than:
```cpp
int values[100];
...
for (int i = 0; i < 100; i++)
{
    ...
}
```

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

### Comments, Formatting, and Style

Your program should:
* Be neatly organized
* Be consistently indented (make sure your code blocks align)
* Have informative comments throughout<br>

Doing these things will make your code more readable, more understandable, easier to maintain, and easier to debug (not to mention future instructors and employers may expect it).<br>

The first lines of all your files (.h and .cpp) must contain the following comments (use either `//` or `/* */` syntax):
```
// filename
// your name (first and last)
// your Chico Portal/Turnin username
// Short summary of the contents of the file (this part is optional, but useful)
```
Throughout your program, you should have brief comments describing how a line or section of code works. You shouldn't need a comment on every line, but consider including a comment before each function or for any nontrivial piece of code.<br>

Use descriptive variable names. Avoid ambiguous or short variable names, with the exception of loop counters (e.g., i, j, k).<br>

Use all lowercase for your file names (e.g. "chart.cpp"). We will start using classes in future programs -- use a capital letter to name classes in your code (e.g. `Video`)<br>

To ensure your code is consistently indented, you may want to [use spaces instead of tabs](http://www.ecst.csuchico.edu/~trhenry/classes/general/code_formatting.html))<br>

I don't have a style guide preference, but you should strive for readability, consistency, and providing enough documentation so that another person (or Future You) can easily understand what your code is doing. <br>

I will deduct points if your program is not well-formatted or you don't have sufficient and useful comments -- make sure to ask the instructor if you are unclear what is expected of you for this requirement.<br>

### Use Functions

The `main()` function is the first function that's called when a C++ program begins execution. While it is possible to write an entire program in `main()`, you should try to separate the functionality of a program into independent modules (think of each module/function as a small program that executes a specific task). The `main()` should just be used as a driver to call other functions.<br>

Consider how your program could be divided into subtasks, and put each subtask into its own function. Define your function prototypes near the top of your program and write the functions after your `main()`.

## Testing Your Program

* Some sample tests and a Makefile are included in 211-starter-pack/211/p1.
* [Lab 2](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab02.md) includes instructions for testing your program using the provided sample tests.
* I will test your program with additional tests not posted in the test directory. It is a very good idea to design and implement your own set of tests.

## Submitting Your Program

I will deduct points if your program does not compile using the command `g++ -o chart chart.cpp` on a Linux machine (such as ecc-linux.csuchico.edu). If you submit your program on [Turnin](https://turnin.ecst.csuchico.edu/) and you get the message "Make did not report any errors", your program compiled without any errors.<br>

I will grade your program using another program, so if your program does not work exactly as specified above you will lose points. For example, if you put a space at the end of the line, or a blank line at the end of the output, you will lose points. Test your program using the provided sample tests and `diff`, `vimdiff`, or the `run_tests` script to make sure your output matches exactly.

Turn in the following file using [Turnin](https://turnin.ecst.csuchico.edu).
```
chart.cpp
```
All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

Assignments can be turned in up to 48 hours late with a 15% penalty.<br>

If you are unable to complete everything on time, you should still turn in whatever work you have. If you turn in nothing, you get a zero. If you turn in something, you receive partial credit.

## Extra Credit: (10 points)

If you do the extra credit you have to turn in a second `chart.cpp` ("p1 extra" on [Turnin](https://turnin.ecst.csuchico.edu/)). Make sure you do not change or delete your original `chart.cpp`.<br>

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
