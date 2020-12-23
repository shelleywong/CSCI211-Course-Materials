# Lab 2

Detecting End of Input, Using Standard Error, Returning from main()

## Exercise 1: Practice Detecting EOF and Using a Switch Statement

Write a program (`to_text.cpp`) that reads zero or more single digits positive integers (0,1,2,3,...,9), and prints the corresponding text string ("zero", "one", "two", "three", ... , "nine").  When the end of input is reached, exit the program.<br/>

Put this program in your `~/csci211/lab02/totext` directory:
```
$ to_text
1
one
2
two
3
three
^D
$
```

NOTE: when you type ^D (Control + D) you will NOT see it (it is not printed to the terminal). This produces the End of File (EOF) character. I put it in the above example to make it clear that the end of input is signaled by pressing ^D.

To get credit, you must pass the posted tests, and you must use a switch statement.

Submit the file `to_text.cpp` to [Turnin](https://turnin.ecst.csuchico.edu/)

## Exercise 2: Error Output

Starting with the second programming assignment (P2), you will be required to detect and report errors. All errors must be written to standard error. Consider the `error.cpp` example in `~/211-starter-pack/211/lab02_even`:

```cpp
// @file error.cpp
#include <iostream>
using namespace std;

int main()
{
    // write to standard output
    cout << "written to standard output" << endl;

    // write to standard error
   cerr << "written to standard error" << endl;

    // return 0 from main() if there are no errors
    return 0;
}
```

Compile and run this program:

```
$ cd ~/211/lab02_error
$ g++ -o error error.cpp
$ ./error
written to standard output
written to standard error
$
```

Since the default is for both standard output and standard error to be written to the current window, you cannot tell that the first string is written to standard output and the second string is written standard error. However, you can redirect standard output to one file and standard error to a second file:

```
$ ./error > myout 2> myerr
```

Look at the two files created (myout and myerr). What do each of the files contain?

1. Write a program (called `even.cpp`) that reads integers until end of input (just like in exercise 1 above). If you copy your code from exercise 1, update the code so that it does not print out the numbers. <br/>

Put this file in your directory (e.g. `~/csci211/lab02/even`)

2. After reading the integers:

* if all of the integers are even, write "all even" and a newline to standard output.
* else if any of the integers are not even, write "not all even" and a newline to standard error.

When there are no errors (when all the numbers are even) return 0 from main().  The Linux standard is that programs should return 0 from main() if there are no errors.<br/>

When there is an error (one or more numbers are not even) return 1 from main().<br/>

Do not return from main() until after you have printed the appropriate message.<br/>

3. The tests for this exercise (in the directory `~/211-starter-pack/211/lab02_even`) have a `.err` file for each test.  The error files contain the error output (if any) and a `.exit` file that indicates the correct exit status (value returned by main()).<br/>

Read how to test a program that has error output on the [Introduction to Testing](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_test.html#error) page.<br/>

If a program is required to have error output, [Turnin](turnin.ecst.csuchico.edu) will check the value returned by main() (the exit status). It should be 0 if there were no errors, 1 if there were errors. You can see the exit status of the program that just finished executed using the echo command:

```
$ ./even < t01.in  > t01.myout   2> t01.myerr
$ echo $?
0
$
```

This means that the exit status of `even` was 0.

## Hints:

It would be a good idea to spend a little time trying to write this program without reading the rest of this hints section.  However, if you get stuck, go ahead and read this section.<br>

The modulus operator (%) can be used to determine if a number is even or odd. For example, if (value % 2 == 0) then the remainder of dividing value by 2 is 0.  Thus the value must be an even number.<br>

Don't store all the values.  After each value is read, determine if it is odd or even.  If it is odd, set a flag and continue (a flag is a boolean variable)
```
bool all_even = true;  // all_even is called a boolean flag, we start by assuming all the values are going to be even

while there are numbers to read
    if number is odd
        all_even = false;

// now look at the all_even flag to determine what you should write and what value should be returned from main()
```

Make sure you are supporting all numbers, not just single digits.<br>

To get credit, you must pass the posted tests (in the directory `~211-starter-pack/211/lab02_even/tests`)

Turn in the file `even.cpp`

***

If you have time left over, I recommend that you complete exercises 4 and 5 from Lab 3.  Exercise 4 is practice creating an object and exercise 5 is the Video class for the next programming assignment (p2).  It is very helpful to complete exercise 5 before you do any other part of p2.
