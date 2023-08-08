# Lab 8

* Command line arguments
* File Input/Output

Lab 08 Exercises
* [Exercise 1: Print Command Line Arguments](#exercise-1-print-command-line-arguments) (lab08_args)
* [Exercise 2: Handling Input and Output File Command Line Arguments](#exercise-2-handling-input-and-output-file-command-line-arguments) (lab08_mycat)
* [Exercise 3: Handling Integer Command Line Arguments](#exercise-3-handling-integer-command-line-arguments) (lab08_add)

## Goals

* Introduce how command line arguments are handled in C++.
* Introduce C++ file input/output.<br>

Program 5 will require that you use both of these mechanisms. Completing the exercises will give you two components necessary for P5.

## Command Line Arguments

When you execute a program by typing options and filenames after the executable name, the shell passes these arguments to the program. Consider the following:
```
$ ls -l calc.cpp
```
The command line arguments include `-l` and `calc.cpp`.  When the shell executes the `ls` command it passes the command line argument to the program and they become arguments to `main()`.<br>

In order to use command line arguments in your program you must declare `main()` as follows:
```
int main(int argc, char *argv[])
```
The first argument (`argc`) is the number of arguments that appear on the command line. In the above example `argc` is 3 because the command consists of three arguments: `ls`, `-l`, and `calc.cpp`.<br>

`argv` is an array of C-style strings (recall that a C-style string is an array of char that is terminated with a null character (the number 0)). `argv` is actually one larger than `argc` since the last element in the array is a NULL pointer (recall that arrays are really just pointers to the first element).

> Reminder: `char **argv` is the same as `char *argv[]`

## File Input and Output (File I/O)

The C++ input/output library contains a mechanism for reading input from files and writing output to files. The mechanism works similarly to `cin` and `cout`, but instead of reading from standard input (`cin`) and writing to standard output (`cout`), a program can read from an input file and write to an output file. Note: This is a different mechanism than using the shell's < and > to redirect standard input and standard output.<br>

The following program (mycat.cpp, provided in the CSCI211 starter-repo `211/lab08_mycat/` directory) expects the executable to be followed by one command line argument that holds the name of a file containing input. After the program has been compiled, it can be executed like this:
```
$ ./mycat myfile.in
```
This program reads every line from the myfile.in file and writes it to standard output. In this case, argc is 2, argv[0] is `./mycat`, and argv[1] is `myfile.in`.

## mycat.cpp
(the version in CSCI211 starter-repo has more comments)
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

// in order to access the command line arguments, declare main() like this
int main(int argc, char *argv[])
{
    // make sure a filename was specified on the command line
    // argc tells us how many command line arguments were given
    // "2" means that no command line arguments were given
    // (the first argument is the name of the executable)
    if (argc < 2)
    {
        // write to standard error (cerr)
        cerr << "No filename specified." << endl;
        return 1; // 1 is error condition
    }
    if (argc > 2)
    {
        cerr << "Too many command line arguments specified." << endl;
        return 1;
    }

    // open the file specified in argv[1].  
    ifstream my_ifile(argv[1]);
    // the above line is the same as the following two statements
    //     ifstream ifile;
    //     ifile.open(argv[1]);

    // my_ifile is an ifstream object connected with the given filename
    // if the contructor failed (could not open file) then !my_file returns true
    // THE ! OPERATOR HAS BEEN OVER WRITTEN FOR THE IFSTREAM CLASS
    if (!my_ifile)
    {
        cerr << "Could not open input file <" << argv[1] << ">." << endl;
        return 1; // error
    }

    // buffer to hold input line
    string buffer;

    // as long as there is more input (not end of file), read a line
    while (getline(my_ifile, buffer, '\n'))
    {
        // write the line to standard output
        cout << buffer << endl;
    }

    return 0; // everything is ok
}
```

> Note: You may find the [C++ Input/output with files](https://www.cplusplus.com/doc/tutorial/files/) documentation useful

## Exercise 1: Print Command Line Arguments

Write a program (called `args`) that prints all the command line arguments to standard output (everything after the executable). Use the args.cpp file in your CSCI211 starter-repo `211/lab08_args/` directory as a starting point. For example:
```
$ ./args one two
one
two
$
$ ./args four five six
four
five
six
$
```

Submit `args.cpp` to INGInious.

## Exercise 2: Handling Input and Output File Command Line Arguments

Start with the mycat.cpp that is in your CSCI211 starter-repo `211/lab08_mycat/` directory<br>

You will need to edit mycat.cpp. The program should be updated to expect three command line arguments:
* Argument 0: the mycat executable
* Argument 1: a filename to be used as the input file
* Argument 2: a filename to be used as the output file<br>

The program should read from the specified input file, and write each line to the output file. For example, given the following input:
```
$ ./mycat data1 data2
```
Your program should read each line in file `data1` and write it to file `data2`.<br>

The code for opening a file is provided for you. If the input file cannot be opened, print the following error message to standard error:
```
cerr << "Could not open input file <" << filename << ">." << endl;
```

> Note: To successfully open and read an input file, the file needs to exist. If the input file does not exist or you did not provide the correct path to the file, the operation to open a file will fail, and you will receive an error.

Use the following to open a file for writing:
```
ofstream my_ofile(filename, ios::out);  // filename is a string holding the filename
```

This code creates a file with the name that you have provided. However, there are several cases when you still might receive an error (e.g. if the file does not exist, and you do not have permission to create files in the directory). If the output file cannot be opened, print the following error message to standard error:
```
cerr << "Could not open output file <" << filename << ">." << endl;
```

If the user provides too few command line arguments, print the following error message to standard error:
```
cerr << "Must specify input and output file." << endl;
```

If the user provides too many command line arguments, print the following error message to standard error:
```
cerr << "Too many command line arguments specified." << endl;
```

Submit `mycat.cpp` to INGInious.

## Exercise 3: Handling Integer Command Line Arguments

Working in your CSCI211 starter-repo `211/lab08_add/` directory, write a program (add.cpp) that reads any number of command line arguments, checks that all the arguments (besides the executable) are integers, and prints the sum of all the numbers:
```
$ ./add 10 20 12
42
$
```
Since each command line argument is a C-style string, you will have to convert each string (such as "10") to an integer (10). Use the function `atoi()` (ascii-to-integer). At this step, do not worry about error checking (that is, assume that `argv[1]` really is an integer). You need to include a library file before you can use `atoi()`. Try "`$ man atoi`" to see what file you need to include.
```
value = atoi(argv[1]);  // this does not do any error checking
```

The next step is to check for strings that are not legal integers. Before you move on, make sure your program works without error checking.<br>

The `atoi()` function does not do any error checking. That means if you pass it a string like "hello" it will just return some undefined value.<br>

Update the add.cpp program so that it performs error checking. Specifically, print an error if the user enters any string that is not a legal integer:
```
$ ./add 1 2 hello
Error: illegal integer.
$
$ ./add 1 2xyz
Error: illegal integer.
$
```

Use the `isdigit()` function to check each character in each input string (argv[1], argv[2], etc) to make sure that all characters in a given character array are legal integers.<br>

You will need to use a loop that ends when it reaches the last element in a C-style string. The last element in a C-style string is always the null terminator `'\0'`. If the current character in the C-style string is `'\0'` or zero (not the character '0' but an actual zero `0`), you've reached the end of the string. It is best to do this check in a function so you can use that function in your P5:
```
bool legal_int(char *str)
{  
  // return false if the str char array has any characters that are NOT digits
  // return true if all the characters in the str char array ARE digits
}
```

Update your program so that it calls `atoi()` to convert the string to an integer and adds it to the total (as above) -- this step should be completed **after** your program verifies that all the characters in a given string are digits (legal integers).<br>

Submit `add.cpp` to INGInious.

## Lab 08 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit `args.cpp` (Exercise 1), `mycat.cpp` (Exercise 2), and `add.cpp` (Exercise 3) to [INGInious](https://inginious.csuchico.edu/). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.

[Top of the Page](#lab-8)
