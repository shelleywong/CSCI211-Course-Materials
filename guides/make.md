# Overview of make

These notes are particularly useful for completing [Lab 03](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab03.md), Exercises 1, 2, and 3.<br>

The job of the `make` utility is to create executables and other non-source files of a program from the program's source files. When you run `make`, it looks for a makefile in the directory called `makefile` or `Makefile`. The `Makefile` contains rules that tell the `make` utility how to execute a series of commands in order to build a target file from source files.<br>

A benefit of using `make` is that it automatically figures out which files it needs to update, based on which source files have changed. The `make` utility also automatically determines the proper order for updating files, in case one non-source file depends on another non-source file.

## Example
Suppose you have a file called hello.cpp and you want to create the executable called `hello`. You would type the command:
```
$ g++ -o hello hello.cpp
```
and g++ would generate `hello` for you.<br>

Each time you change hello.cpp, you have to recompile it (using `$ g++ -o hello hello.cpp`) to see if your changes work.<br>

It can get very tiring typing `$ g++ -o hello hello.cpp` every time you want to compile your hello.cpp program.<br>

If you use the `make` utility, instead of typing `$ g++ -o hello hello.cpp` to compile you would simply type:
```
$ make
```

## Steps for using make

1. Create a file called `makefile` or `Makefile` (most people use Makefile so it appears first in directory using ls)
2. Using an editor (such as atom, vim, nano) edit the file `Makefile`
3. Insert the rules for creating the files (for making the files)
4. Run the make utility by typing `make` at the bash command prompt

## Advantages of make

1. You only have to type the compilation command(s) once. After you have put them in the makefile, you only have to type `make` to run all the compilation commands.
2. Make will only compile the files that have changed since the last time you compiled (this is really important in large projects where complete compilation may take several hours).
3. Make automatically determines the proper order for updating files, which is useful when a non-source file depends on another non-source file.<br>

These are surprisingly big advantages.

## Anatomy of a Makefile:

This is a simple and complete makefile:
```makefile
hello: hello.cpp
	g++ -o hello hello.cpp
```

NOTE: for most versions of `make` (including the one standard on Linux), the second line must start with a \<tab\> so it is a good habit to always use a \<tab\>. If vim does not automatically turn the \<tab\> key into an actual tab, you can insert a tab by typing (while in insert mode) `control-V` followed by a `tab` -OR- you can program vim to understand that Makefiles want tabs by adding the following line to your ~/.vimrc file:
```
autocmd FileType make set noexpandtab|set autoindent
```

This simple makefile contains a single rule that you can read like this:

> If the file hello is older than the file hello.cpp then execute the command "g++ -o hello hello.cpp"

Basic format of rules in makefiles:
```
target_file : list_of_dependency_files
<tab>command_to_build_target_file
```

## Multi-file make

In C++ programs it is common to put each class in its own two files,  class_name.h for the class header, class_name.cpp for the class's member functions. The next example (lab03_sentence) contains three files:

| File |   |
| --- | --- |
| main.cpp | the file containing the main() function |
| sentence.h | the file containing the definition of class Sentence (class Sentence { .... };) |
| sentence.cpp | the file containing the source code for class Sentence (the bodies of the member functions) |

The most efficient way to compile such program is to compile each component into an object file (.o) and then combine the object files into an executable (the combination of .o files is called linking):<br>

* `g++ -c main.cpp` will create the object file main.o
* `g++ -c sentence.cpp` will create the object file sentence.o
* `g++ -o sentence main.o sentence.o` will create the executable sentence (will link main.o and sentence.o into sentence)

## simple makefile
```makefile
# This rule tells make how to "make" the executable sentence
sentence: main.o sentence.o
	g++ -Wall -pedantic -std=c++11 -g -o sentence main.o sentence.o

# This rule tells make how to "make" the object file main.o
main.o: main.cpp sentence.h
	g++ -Wall -pedantic -std=c++11 -g -c main.cpp

# This rule tells make how to "make" the object file sentence.o
sentence.o: sentence.cpp sentence.h
	g++ -Wall -pedantic -std=c++11 -g -c sentence.cpp


# This rule tells make what to delete when the user type "make clean"
# The files are deleted -- BE VERY CAREFUL to only put generated files here
clean:
	rm -f main.o sentence.o sentence
```

## Compiler Options

The above Makefile uses the following gcc command-line options for the g++ compiler:
| Option &nbsp; |    |
| --- | --- |
| `-c` | Compile or assemble the source files, but do not link: create an object (-o) file, do not create an executable (such as a.out) |
| `-o filename` | Give a name to the output file (such as `filename`) instead of using the default a.out |
| `-g` | Put some extra information in the output files (.o and executables) so the GDB debugger will give more friendly output (debuggers are discussed in a future lab) |
| `-Wall` | Show all warnings about constructions that some users consider questionable, and that are easy to avoid (these illuminate problems in your program -- you should be able to easily fix your code so there are no warnings) |
| `-pedantic` | Issue all the warnings demanded by strict ISO C and ISO C++ (i.e. issue warnings if your program does not follow the standard exactly) |
| `-std=c++11` | Compile with C++ ISO standard version C++11. Newer standards exist, but this is how all of your code will be compiled and tested on INGInious. |

## Default Rules

There are many default rules built into various versions of make. Thus in a large project the makefile would not contain a rule for every single source file.<br>

When learning how to use make it is best to avoid the default rules and put in explicit rules for each file.

[Top of the Page](#overview-of-make)