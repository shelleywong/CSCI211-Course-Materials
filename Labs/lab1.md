# Lab 1

Introduction to Linux and the g++ Compiler

## Exercise 1: Setting up your CSCI 211 environment

Taking some time to set up and organize your working directory for CSCI 211 will help prevent turning in the wrong assignment and make it easier to keep track of your files.<br/>

You may want to use a Git repository manager, such as GitHub, that provides version control and other features to build and manage software. It can be a great tool for organizing your source code; HOWEVER, remember that whenever you are creating a directory for a class where everyone is turning in the same assignments (like in this CSCI 211 course), make sure to make the visibility of this repository **private!** If your repo is public, it means other students can see it and easily steal the code from it -- this constitutes cheating and is a violation of academic integrity. There is no reason to make a CSCI 211 repo publicly visible this semester or after you have completed the class. Refer to the [Cheating Policy](http://www.ecst.csuchico.edu/~trhenry/classes/general/cheating.html) or talk to me directly if you are unclear about any of this. Refer to the [GitHub docs](https://docs.github.com/en/free-pro-team@latest/github) for additional guidance on working with GitHub.<br/>

There is no requirement in this course to use GitHub. The following instructions will work on your local Linux/OSX laptop/desktop (with or without a remote repository):<br/>

1. Go to your home directory, or a subdirectory such as "Courses" or "Repos". Create a folder for CSCI 211 using mkdir (make directory):
```
$ mkdir csci211
```
2. Now enter that directory, using cd (change directory):
```
$ cd csci211
```
3. For each lab and programming assignment, you will want to create a subdirectory. If you do not organize your files well, you will potentially regret it later, as it is easy to overwrite or delete files. Create a directory for lab 1 and enter the subdirectory:
```
$ mkdir lab01
$ cd lab01
```
4. Using `lab01` rather than `lab1` will maintain sorted order when viewing the list of directories, since there are 15 labs total. Lab 1 consists of three tasks. Make a subdirectory within the lab01 directory for each task:
```
$ mkdir hello
$ mkdir add
$ mkdir print
```

## Exercise 2: Creating, compiling, and running a C++ program

1. Enter the lab01/hello subdirectory, and create the file `hello.cpp`. Using any editor (e.g. vim or atom), start the editor with `hello.cpp` as the filename:
```
$ atom hello.cpp
```
-or-
```
$ vim hello.cpp
```
2. Now edit the file so it contains the following text. Save the file and exit the editor:
```cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "hello world" << endl;
  return 0;
}
```
3. Compile this file using this command:
```
$ g++ hello.cpp
```
If you get an error, use the editor to fix the error.
4. This should have created the file `a.out` -- use `$ ls -l` to find out if `a.out` is in your directory. Note that `a.out` automatically has execute protection ("x").  When a file has execute permission you can execute it.
```
$ ls -l a.out
```
5. You can now run the executable `a.out`:
```
$ ./a.out
```
Some people choose to [add `./` to the search path](https://stackoverflow.com/questions/27188856/adding-any-current-directory-to-the-search-path-in-linux) for executables in Linux, but it is not necessary. In my instructions, I will include `./` before all executables.<br/>

You do not need to turn in this exercise, but you may if you want to practice turn-in submissions. You must submit lab exercises 3 and 4 for lab credit.

## Exercise 3: 1 + 1 = 2

Write a program that reads two numbers, adds them together, and prints the result.

* Move to your lab01/add directory:
```
$ cd ../add
```
The two dots mean to go "up" a directory and find the `add` directory. If that did not work, try using the "full directory path" or "full path":
```
$ cd ~/csci211/lab01/add
```

* When your program is run, it should work like this (the "./a.out" "40" and "2" are typed by the user; the "40 + 2 = 42" is printed by the program):
```
$ ./a.out
40
2
40 + 2 = 42
$
```
* For this exercise you will need to read in an integer.  You can read an integer in C++ like this:
```cpp
cin >> value1;
```
Where "value1" has been declared as an integer before this line (C++ integers are declared just like in Java).
* Create a new file called `add.cpp` using an editor.  Write the add program so it reads and adds the two numbers.
* Compile and run your program to make sure it works correctly.  Your output must EXACTLY match my output: `<number><space><+><space><number><space><=><space><number><newline>`
* Some sample input and output are available in `211-starter-pack/211/lab01_add/tests` directory. In this directory you will find *.in and *.out files. For example, `t01.in` is the input for test 1 and `t01.out` is the expected output for test 1. All of the tests in the directory will be used to grade your program on turnin. If you pass these tests, you will get full credit.
* An easy way to see the content of a small file is to use the Linux cat command:
```
$ cat tests/t01.in
40 2
$ cat tests/t01.out
40 + 2 = 42
$
```
* See [Introduction to Testing](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_test.html) for a full description of how to test your assignments. If you understand the described mechanism now, it will make your semester much easier, and will improve your grade. One of the most important aspects of this lab is for you to understand the testing mechanism.

Once your program is working, turn `add.cpp` in on [Turnin](https://turnin.ecst.csuchico.edu/). For more information, see [instructions for turning in files](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_turn_in_assignments.html).

You must pass all the posted tests to get credit for a lab assignment.

Lab exercises are due by 11:59pm the Friday night following lab.

## Exercise 4: Say Hello

Write a program that reads a number and prints "hello" that number of times:
```
$ a.out
5
0 hello
1 hello
2 hello
3 hello
4 hello
$
```
* All the characters shown above were printed by the program, except the 5<enter> which was typed by the user.
* Change directory to the `lab01/print` directory.  Create a new file called `print.cpp`.
* Use a for-loop to implement this program.
* When your program is working, test it with the posted tests (see the testing and turn in instructions for exercise 3; the only difference is that the tests are in the directory `211-starter-pack/211/lab01_print/tests`).
* Make sure your program passes all the tests.
* Turn in print.cpp to [Turnin](https://turnin.ecst.csuchico.edu/).

## Exercise 5: Make sure you understand the testing mechanism

The main point of these assignments is to introduce you to the [testing mechanism](http://www.ecst.csuchico.edu/~trhenry/classes/general/how_to_test.html).<br/>

Students who don't understand how < and > are used to test assignments struggle throughout the semester.

* Reminder: All labs are due at 11:59pm the Friday following lab.  For this lab you must turn in `add.cpp` and `print.cpp`. If you are not able to complete all the exercises, turn in your partial work for partial credit.
