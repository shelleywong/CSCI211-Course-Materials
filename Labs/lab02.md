# Lab 2

Detecting End of Input, Using Standard Error, Returning from main()

## Goals

* Review of how to test assignments (run_tests, vd, vde)
* Learn how to detect end of input (also known as end of file or EOF)
* Learn the syntax of the C++ switch statement
* Learn how to write to standard error and learn the shell syntax for redirecting standard error to a file (described in exercise 2)
* Learn how to ask the bash shell for the exit status of the last program executed<br>

Lab 02 Exercises:
* [Exercise 1: Practice Detecting EOF and Using a Switch Statement](#exercise-1-practice-detecting-eof-and-using-a-switch-statement) (lab02_totext)
* [Exercise 2: Error Output](#exercise-2-error-output) (lab02_even)

## Testing Assignments

> Note: Exams may have questions on this material

### Background

* diff and vimdiff tools
* bash shell scripting
* file redirection
  * `<` standard input (stdin)
  * `>` standard output (stdout)
  * `2>` standard error (stderr) (see Exercise 2 below)
* exit status
  * return 0;
  * return 1;
  * echo $?

### Manual Testing

A quick review of the basic manual testing options

#### Program with Output and No Input
`hello` is an executable (a compiled program). The `>` takes standard output (what was written to the screen) and redirects it to a file (called `t01.myout` in this example):
```
$ ./hello > t01.myout
```

#### Program with Input and Output
This program can be tested using the same mechanism described above, except now we will redirect standard input (using <) and standard output (using >). In this case, the executable is called num and standard input comes from t01.in.
```
$ ./num < t01.in > t01.myout
```

#### Program with Input, Output, and Error Output
This program can be tested using the same mechanism described above, except this time we include error messages written to standard error (using `cerr <<`  instead of `cout <<`)
```
$ ./videos < t01.in > t01.myout 2> t01.myerr
```

#### cat
Use the Linux `cat` utility to view the contents of `t01.myout`:
```
$ cat t01.myout
Hello world!
$
```

#### diff
Compare your output (`t01.myout`) to the correct output (`t01.out`) using the  Linux diff utility. If the two files match, the diff prints nothing, and your program produced the correct output:
```
$ diff t01.myout t01.out
$
```

#### vimdiff
The tool vimdiff is an alternative to using diff that highlights the differences between two files. You can move around just like in the vim editor. If you don't know the vim editor, exit vimdiff by typing `:qa`, then press `enter`. If you appear to be stuck, try pressing the escape key before the `:qa`
```
$ vimdiff t01.myout t01.out
```

#### A full example
A full example -- in this case, a `tests` directory was provided that contains standard input files (\*.in), with the correct standard output files (\*.out) and standard error files (\*.err). A `results` directory (created before the following commands) will hold the standard output (\*.myout) and standard error (\*.myerr) produced by your program.
```
$ ./videos < tests/t01.in > results/t01.myout 2> results/t01.myerr
$ vimdiff results/t01.myout tests/t01.out
$ diff results/t01.myerr tests/t01.err
```

### Tools

It is important that you understand the manual testing options listed above, but when you need to pass a lot of tests, having options that allow you to automatically run multiple tests at a time is VERY useful. The following tools are all available to you:<br>
* run_tests
* vd
* vde
* [Turnin](https://turnin.ecst.csuchico.edu/)

`run_tests`, `vd`, and `vde` are bash scripts (programs that the bash shell can execute) that should be included in your ~211-starter-pack/bin directory that you downloaded (211-starter-pack.tar):
```
$ cd
$ cd bin
$ ls run_tests vd vde
run_test vd vde
```

Among other things, bash scripts are useful for running tests, as they allow you to automate command line tasks that you would otherwise have to type out manually (for each test and for each time the tests need to be rerun).<br>

Many of the directories in 211-starter-pack/211 include a subdirectory called `tests` that contains a set of sample tests. You can use the `run_tests` file to automatically test your program against all of the tests included in the `tests` subdirectory.<br>

This is how you could use `run_tests`, `vd`, and `vde` to test lab02_even (a directory that contains a `tests` subdirectory):<br>

Copy each bash script from 211-starter-pack/bin into the lab02_even directory (this examples is completed from the 211-starter-pack directory as downloaded, but your paths may differ based on how you've set up your environment):
```
$ cp bin/run_tests 211/lab02_even/
$ cp bin/vd 211/lab02_even/
$ cp bin/vde 211/lab02_even/
```

Change to the lab02_even directory. You should see all of the bash scripts listed there, along with the other files that were already in the directory. Exercise 2 includes directions for writing a program that reads integers and checks if they are even or not.<br>

After you have successfully compiled even.cpp, you will have an executable called `even` and can use `run_tests` to check to see if your program passes all of the provided tests. (For other programs, substitute the appropriate executable in place of `even`):
```
$ ./run_tests even
Executing tests for <./even>
Passed t01
Passed t02
Passed t03
Passed t04
Passed 4 out of 4 tests.
Failed 0 out of 4 tests.
$
```

If one or more tests fail, you will get output that indicates which test(s) failed. In this example, t01 and t04 passed, while t02 and t03 both failed with stdout, stderr, and exit_status errors.<br>

They allow you to automate command line tasks, which can be very useful when you have long commands that you would otherwise have to type manually, over and over.
```
$ ./run_tests even
Executing tests for <./even>
Passed t01
Failed t02  (stdout incorrect) (stderr incorrect) (exit_status incorrect)
Failed t03  (stdout incorrect) (stderr incorrect) (exit_status incorrect)
Passed t04
Passed 2 out of 4 tests.
Failed 2 out of 4 tests.
```

The `vd` script shortens the command you have to type to do a vimdiff examining the standard output of a specified test (This example compares the standard output in tests/t02.out with the standard output in results/t02.myout):
```
$ vd 02
```

The `vde` script shortens the command you have to type to do a vimdiff examining the standard error of a specific test (This example compares the standard error in tests/t03.err with the standard error in results/t03.myerr):
```
$ vde 03
```

Using these tools can help you quickly determine if your program is passing or failing all tests, identify which sections of your code might contain bugs, and help make sure the Turnin server stays up and running.<br>

I have described one simple and safe way to use these tools, but you are not required to follow this method. Do what works for you. The main thing I want to emphasize is that these tools are available, and you should use them! The tests won't always catch every edge case, but they can be a great help to you throughout the semester.

### Detecting the end of input (often called EOF for "end of file")

You must use this mechanism in Exercise 1 below. You will also use it in most of the assignments this semester.

When you read using cin (e.g. `cin >> my_integer`) you can use the value returned from "cin >>" to detect the end of input. Consider the following program:
```cpp
// @file echo_ints.cpp
#include <iostream>
using namespace std;

int main()
{
    int value;

    // as long as we can read an integer from standard input (cin)
    // when the user enters control-D the "cin >> value" will return false
    while (cin >> value)
    {
        // write the integer just read to standard output
        cout << "value = " << value << endl;
    }

    // return 0 from main() if there are no errors
    return 0;
}
```

When the user enters an integer, the `cin >> value` expression returns true (recall that true is any non-zero value) and the body of the loop is executed.<br>

When the user enters `^D` (I use ^D to mean control-D), the `cin >> value` expression returns 0 and the loop is terminated (while loops terminate as soon as the expression is false).<br>

Make a directory called `lab02_echoints` (In this example, it is a subdirectory of 211-starter-pack/211/), then move into the `lab02_echoints` directory and create a file called echo_ints.cpp. Here, I am using vim, but you can use a different editor if you'd prefer.
```
$ mkdir lab02_echoints
$ cd lab02_echoints
$ vim echoints.cpp
```
Copy the echo_ints code (included above) into echo_ints.cpp<br>

Compile and run the program (make note of what happens when you include the -o option):
```
$ g++ -o echo_ints echo_ints.cpp
$ ./echo_ints
```
Now type some integers (each followed by pressing the enter key).<br>

Now type ^D  (hold the control key and press the D key)<br>

What did the ^D do?<br>

When typing values at the command prompt you need to explicitly mark the end of input with a ^D. When redirecting a file into a program, the ^D is automatic.<br>

Create a file with some numbers in it. An easy way to do this is to use the cat utility and file redirection. The following creates a new file called "nums" with the values 1,2,3, and 4:
```
$ cat > nums
1
2
3
4
^D
$
```

Now run echo_ints and redirect the file you just created as input.
```
$ ./echo_ints < nums
```
What happens?  Why does the program stop executing?<br>

How would you redirect the output of this program to another file? Hint: it is very similar to redirecting the input above.<br>

At this point you should be able to do all the above tasks (compile a program, run a program, create a file using cat, and run a program using file redirection (the < filename and > filename)). If you can't do all of these tasks without notes, go over the above commands (you will do these tasks all semester; it is important you can do them without notes).

## Exercise 1: Practice Detecting EOF and Using a Switch Statement

Write a program (`to_text.cpp`) that reads zero or more single digits positive integers (0,1,2,3,...,9), and prints the corresponding text string ("zero", "one", "two", "three", ... , "nine").  When the end of input is reached, exit the program.<br/>

Put this program in your `~/csci211/lab02/totext` directory:
```
$ ./to_text
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

Starting with the second programming assignment (p2), you will be required to detect and report errors. All errors must be written to standard error. Consider the `error.cpp` example in `~/211-starter-pack/211/lab02_even`:

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

You can compile even.cpp using the provided `Makefile`.
```
$ make
```
Note that after the program has been successfully compiled, an executable called `even` was created.<br>

Read how to test a program that has error output on the [Introduction to Testing](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_test.html#error) page.<br/>

If a program is required to have error output, Turnin will check the value returned by main() (the exit status). It should be 0 if there were no errors, 1 if there were errors. You can see the exit status of the program that just finished executed using the echo command:

```
$ ./even < t01.in > t01.myout 2> t01.myerr
$ echo $?
0
$
```

This means that the exit status of `even` was 0.

## Hints:

It would be a good idea to spend a little time trying to write this program without reading the rest of this hints section. However, if you get stuck, go ahead and read this section.<br>

The modulus operator (%) can be used to determine if a number is even or odd. For example, if (value % 2 == 0) then the remainder of dividing value by 2 is 0. Thus the value must be an even number.<br>

Don't store all the values. After each value is read, determine if it is odd or even. If it is odd, set a flag and continue (a flag is a boolean variable)
```
bool all_even = true;  // all_even is called a boolean flag, we start by assuming all the values are going to be even

while there are numbers to read
    if number is odd
        all_even = false;

// now look at the all_even flag to determine what you should write and what value should be returned from main()
```

Make sure you are supporting all numbers, not just single digits.<br>

To get credit, you must pass the posted tests (in the directory `~211-starter-pack/211/lab02_even/tests`)

Turn in the file `even.cpp` to [Turnin](turnin.ecst.csuchico.edu)

***

If you have time left over, I recommend that you complete exercises 4 and 5 from Lab 3.  Exercise 4 is practice creating an object and exercise 5 is the Video class for the next programming assignment (p2).  It is very helpful to complete exercise 5 before you do any other part of p2.

## Lab 02 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must turn in `to_text.cpp` and `even.cpp`. There is a separate submission link for each exercise on Turnin. If you are not able to complete all the exercises, turn in your partial work for partial credit.

[Top of the Page](#lab-2)
