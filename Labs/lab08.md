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

Program 5 will require that you use both of these mechanisms.  Completing the exercises will give you two components necessary for p5.

## Command Line Arguments

When you execute a program by typing options and filenames after the executable name, the shell passes these arguments to the program.  Consider the following:
```
$ ls -l calc.cpp
```
The command line arguments include "-l" and "calc.cpp".  When the shell executes the `ls` command it passes the command line argument to the program and they become arguments to `main()`.<br>

In order to use command line arguments in your program you must declare `main()` as follows:
```
int main(int argc, char *argv[])
```
The first argument (`argc`) is the number of arguments that appear on the command line. In the above example `argc` is 3 because the command consists of three arguments: "ls", "-l", and "calc.cpp".<br>

`argv` is an array of C-style strings (recall that a C-style string is an array of char that is terminated with a null character (which is the number 0)). `argv` is actually one larger than `argc` since the last element in the array is a NULL pointer (recall that arrays are really just pointers to the first element).

## File Input and Output (File I/O)

The C++ input/output library contains a mechanism for reading input from files and writing output to files. The mechanism works similarly to `cin` and `cout`, but instead of reading from the standard input (`cin`) and writing to standard output (`cout`) a program can read from a file and/or write to a different file. Note: This is a different mechanism than using the shell's < and > to redirect standard input and standard output.<br>

The following program (mycat.cpp and 211-starter-pack/211/lab08_mycat) assumes the first command line argument is the name of a file containing the input. After the program has been compiled, it can be executed like this:
```
$ ./mycat myfile.cpp
```
It will read every line in the first file (myfile.cpp in this example, but it could be any file) and write it to standard output.

## mycat.cpp
(the version in 211-starter-pack has more comments)
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
        // write to standar error (cerr)
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

Write a program (called `args`) that prints all the command line arguments to standard output. For example:
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

Use the args.cpp file in your 211-starter-pack/211/lab08_args directory as a starting point.<br>

Submit `args.cpp` to Turnin.

## Exercise 2: Handling Input and Output File Command Line Arguments

Start with the mycat.cpp that is in your 211-starter-pack/211/lab08_mycat directory<br>

Edit mycat.cpp so that it takes two command line arguments:
* Argument 1: a filename to be used as the input file
* Argument 2: a filename to be used as the output file<br>

The program should read from the specified input file, and write each line to the output file. For example, given the following input:
```
$ ./mycat data1 data2
```
Your program should read each line in file `data1` and write it to file `data2`.<br>

Use the following when opening a file for writing:
```
ofstream my_ofile(filename, ios::out);  // filename is a string holding the filename
```

If the output file cannot be opened, print the following error message to standard error (modify this message for the input file):
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

Submit `mycat.cpp` to Turnin.

## Exercise 3: Handling Integer Command Line Arguments

Working in your 211-starter-pack/211/lab08_add directory, write a program (add.cpp) that reads any number of command line arguments, assumes all the arguments are integers and prints the sum of all the number:
```
$ ./add 10 20 12
42
$
```
Since each command line argument is a C-style string you will have to convert the strings (such as "10") to an integer (10). Use the function `atoi()` (ascii-to-integer). Do not worry about error checking (that is, assume that `argv[1]` really is an integer).  You need to include a library file before you can use `atoi()`. Try "`$ man atoi`" to see what file you need to include.
```
value = atoi(argv[1]);  // this does not do any error checking
```

The next step is to check for strings that are not legal integers.  Before you move on, make sure your program works w/o error checking.<br>

The `atoi()` function does not do any error checking. That means if you pass it a string like "hello" it will just return some undefined value.<br>

Update the add.cpp program so that it performs error checking.  Specifically, print an error if the user enters any string that is not a legal integer:
```
$ ./add 1 2 hello
Error: illegal integer.
$
$ ./add 1 2xyz
Error: illegal integer.
$
```

Use the `isdigit()` function to check each character in each input string (argv[1], argv[2], etc) to make sure they are legal integers.  You will need to use a loop. Keep in mind that the last element in a C-style string is a zero (not the character '0' but an actual zero). It is best to do this check in a function so you can use that function in your p5:
```
bool legal_int(char *str)
{  
  // return false if the given string has any characters that are NOT digits
  // return true if all the characters in the given string ARE digits
}
```

After your program verifies that all the characters are digits, call `atoi()` to convert the string to an integer and add it to the total (as above).

Submit `add.cpp` to Turnin.

## Lab 08 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit `args.cpp` (Exercise 1), `mycat.cpp` (Exercise 2), and `add.cpp` (Exercise 3) to Turnin. If you are not able to complete all the exercises, turn in your partial work for partial credit.

[Top of the Page](#lab-8)
