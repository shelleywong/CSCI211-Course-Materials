# Testing Assignments

Instructions for testing CSCI 211 Labs and Programming Assignments.<br>

This Guide on Testing Assignments is useful for:
* [Lab Exercises](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Labs)
  * Completing the [Lab 01, Exercise 5 Linux Commands and Testing Quiz](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab01.md#exercise-5-linux-commands-and-testing-quiz)
* [Programming Assignments](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Programs)
* [CURE-E Final Project](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/CURE-E/finalProject.md)<br>

> Note: Tests may have questions on how to test your code, but even more important, learning to efficiently test your code will make it much easier to complete the Lab Exercises and Programming Assignments in this course. Taking some time to understand the available testing mechanisms can save a lot of time in the long run!<br>

## Background

* diff and vimdiff tools
* bash shell scripting
* file redirection
  * `<` standard input (stdin)
  * `>` standard output (stdout)
  * `2>` standard error (stderr)
* exit status
  * return 0;
  * return 1;
  * echo $?

## Manual Testing

A quick review of the basic manual testing options

### Program with Output and No Input
`hello` is an executable (a compiled program). The `>` takes standard output (what was written to the screen) and redirects it to a file (called `t01.myout` in this example):
```
$ ./hello > t01.myout
```

### Program with Input and Output
This program can be tested using the same mechanism described above, except now we will redirect standard input (using <) and standard output (using >). In this case, the executable is called num and standard input comes from t01.in.
```
$ ./num < t01.in > t01.myout
```

### Program with Input, Output, and Error Output
This program can be tested using the same mechanism described above, except this time we include error messages written to standard error (using `cerr <<`  instead of `cout <<`)
```
$ ./videos < t01.in > t01.myout 2> t01.myerr
```

### cat
Use the Linux `cat` utility to view the contents of `t01.myout`:
```
$ cat t01.myout
Hello world!
$
```

### diff
Compare your output (`t01.myout`) to the correct output (`t01.out`) using the  Linux diff utility. If the two files match, the diff prints nothing, and your program produced the correct output:
```
$ diff t01.myout t01.out
$
```

### vimdiff
The tool vimdiff is an alternative to using diff that highlights the differences between two files. You can move around just like in the vim editor. If you don't know the vim editor, exit vimdiff by typing `:qa`, then press `enter`. If you appear to be stuck, try pressing the escape key before the `:qa`
```
$ vimdiff t01.myout t01.out
```

### A full example

In the example below, a `tests` directory was provided that contains standard input files (\*.in) and corresponding output files -- \*.out files contain standard output and \*.err files contain standard error output.<br>

A `results` directory (must be created before you run the following commands) will hold the standard output (\*.myout) and standard error (\*.myerr) produced by your program.<br>

This example runs the `videos` program with input from the t01 input file and redirects output to files in the results directory (standard output in t01.myout and standard error output in t01.myerr). It uses `vimdiff` to visually compare the user's output with the expected output, then uses `diff` to check if there are any differences between the user's error output and the expected error output:
```
$ ./videos < tests/t01.in > results/t01.myout 2> results/t01.myerr
$ vimdiff results/t01.myout tests/t01.out
$ diff results/t01.myerr tests/t01.err
```

## CSCI 211 starter-repo tests directories

Almost every lab and programming assignment directory will contain a `tests` folder containing sets of files for each test (e.g. `t01`). You may see files for input (\*.in), output (\*.out), error output (\*.err), command line input (\*.cmd) and exit status (\*.exit).<br>

Note that the provided tests for programming assignments may not cover every requirement mentioned in the assignment writeup -- you should review the provided tests, learn how everything is tested, and consider creating your own tests.<br>

You can follow the manual testing options listed above for all given test cases or utilize the provided tools listed below to automate and simplify the testing process.

## Tools

It is important that you understand the manual testing options listed above, but when you need to pass a lot of tests, having options that allow you to automatically run multiple tests at a time is VERY useful. The following tools are all available to you:<br>
* run_tests
* vd
* vde
* [INGInious](https://inginious.csuchico.edu/)

`run_tests`, `vd`, and `vde` are bash scripts (programs that the bash shell can execute) that are included in your CSCI211 starter-repo `bin/` directory):
```
$ cd bin
$ ls
run_test vd vde
```

Among other things, bash scripts are useful for running tests, as they allow you to automate command line tasks that you would otherwise have to type out manually (for each test and for each time the tests need to be rerun).<br>

Many of the directories in CSCI211 starter-repo `211/` include a subdirectory called `tests` that contains a set of sample tests. You can use the `run_tests` file to automatically test your program against all of the tests included in the `tests` subdirectory. `run_tests` will produce a `results` directory that will contain the output from your program for each test (standard output in a \*.myout file, standard error output in a \*.myerr file, etc)<br>

If you are working from within your CSCI 211 repo, you can use the run_tests script from the `bin` directory (in this case, using an executable named `myprog`) with the following command (if your directory is set up differently, you may need to update the path to the script):

```
$ ../../bin/run_tests myprog
```

If you get the "Permission denied" message, move to the bin directory and run the command to make the run_tests file executable:

```
$ chmod +x run_tests
```

Alternatively, you could copy each bash script from `bin/` into the directory where you want to use the scripts (this examples is completed from the CSCI211 starter-repo as provided, but your paths may differ based on how you've set up your environment.<br>

This is how you could use `run_tests`, `vd`, and `vde` to test lab02_even (a directory that contains a `tests` subdirectory):<br>
```
$ cp bin/run_tests 211/lab02_even/
$ cp bin/vd 211/lab02_even/
$ cp bin/vde 211/lab02_even/
```

Alternatively, you could copy all of the files from the bin folder into the lab02_even directory at once:
```
$ cp -r bin/. 211/lab02_even/
```

If you would like to have `run_tests`, `vd`, and `vde` available in every lab and programming assignment directory, you can use the following to copy all of the `bin/` scripts into every `211/` subdirectory. From the starter-repo/211 directory, run the following command:
```
$ ls | xargs -n1 cp ../bin/*
```

> Note: learn more about the xargs command by typing `man xargs` in the command line terminal.

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
$ ./vd 02  // shorthand, using the provided script
$ vimdiff tests/t02.out results/t02.myout  // equivalent command
```

The `vde` script shortens the command you have to type to do a vimdiff examining the standard error of a specific test (This example compares the standard error in tests/t03.err with the standard error in results/t03.myerr):
```
$ ./vde 03  // shorthand, using the provided script
$ vimdiff tests/t03.err results/t03.myerr  // equivalent command
```

Using these tools can help you quickly determine if your program is passing or failing all tests, identify which sections of your code might contain bugs, and help make sure the INGInious server stays up and running.<br>

I have described one simple and safe way to use these tools, but you are not required to follow this method. Do what works for you. The main thing I want to emphasize is that these tools are available, and you should use them! The tests won't always catch every edge case, but they can be a great help to you throughout the semester.

## Memory Management

Many of the programming assignments ask you to manage memory. One command line option for detecting if your program contains memory leaks is [Valgrind](https://valgrind.org/docs/manual/quick-start.html). Valgrind does not work on all platforms; I recommend using Valgrind on Linux. Here is an example of valgrind usage (after you've compiled a program called myprog):
```
$ ./myprog      // run your program like normal
$ valgrind --leak-check=yes ./myprog    // test your program with valgrind
$ valgrind --leak-check=yes ./myprog arg1 arg2    // example to test your program with command line arguments on valgrind
$ valgrind --leak-check=yes ./myprog < tests/t01.in  // example to test your program with file input (file redirection) on valgrind
```

> Learn more about Valgrind and the platforms it works on by visiting [valgrind.org](https://valgrind.org/)

[Top of the Page](#testing-assignments)
