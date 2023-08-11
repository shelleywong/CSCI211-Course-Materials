# Lab 3

* Introducing the Linux make utility<br>
* Practice Creating C++ Objects<br>

Lab 03 Exercises:
* [Exercise 1: Simple Makefile](#exercise-1-simple-makefile) (lab03_hello)
* [Exercise 2: Makefile With Object Files](#exercise-2-makefile-with-object-files) (lab03_sentence)
* [Exercise 3: Create Your Own Makefile](#exercise-3-create-your-own-makefile) (lab03_makefile)
* [Exercise 4: Create a Course Class](#exercise-4-create-a-course-class) (lab03_object, lab03_course)
* [Exercise 5: Create Class Video for P2](#exercise-5-create-class-video-for-P2) (lab03_video)

> Note: To get full credit for this lab, you must complete a Google Survey (for exercises 1 and 2) and submit several files to INGInious (exercises 3, 4, and 5).

## Overview of make
The job of `make` is to create files

### Example
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

### Steps for using make

1. Create a file called `makefile` or `Makefile` (most people use Makefile so it appears first in directory using ls)
2. Using an editor (such as atom, vim, nano) edit the file `Makefile`
3. Insert the rules for creating the files (for making the files)
4. Run the make utility by typing `make` at the bash command prompt

### Advantages of make

1. You only have to type the compilation command(s) once (that is, put them in the makefile)
2. Make will only compile the files that have changed since the last time you compiled (this is really important in large projects where complete compilation may take several hours).<br>

These are surprisingly big advantages.

### Anatomy of a Makefile:

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

### Multi-file make

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

### simple makefile
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

### Compiler Options

The above Makefile uses the following command-line options for the g++ compiler:
| Option &nbsp; |    |
| --- | --- |
| `-c` | Compile only: create an object file (a .o file); do not create an executable (such as a.out) |
| `-o filename` | Give a name to the output file (such as `filename`) instead of using the default a.out |
| `-g` | Put some extra information in the output files (.o and executables) so the GDB debugger will give more friendly output (debuggers are discussed in a future lab) |
| `-Wall` | Show all warnings (warnings help illuminate problems in your program, you should fix your code so there are no warnings) |
| `-pedantic` | Issue all the warnings demanded by strict ISO C and ISO C++ (i.e. issue warnings if your program does not follow the standard exactly) |
| `-std=c++11` | Compile with C++ ISO standard version C++11. Newer standards exist, but this is how all of your code will be compiled and tested on INGInious. |

### Default Rules

There are many default rules built into various versions of make. Thus in a large project the makefile would not contain a rule for every single source file.<br>

When learning how to use make it is best to avoid the default rules and put in explicit rules for each file.

## Exercise 1: Simple Makefile
\* You must complete this [Google Survey](https://docs.google.com/forms/d/e/1FAIpQLSft0f3fr4rMs0LIK2KWWbEs2EMYqQSBPFYjAcQzJWgQM3eq_A/viewform?usp=sf_link) to get credit for Exercises 1 & 2 \*<br>

Note: You will need to be logged in to your \@mail.csuchico email in order to take the Google Survey. If you get a message that you are unable to access the survey, try using your Chico portal username and password to login to Google. If you are not sure how to proceed, feel free to ask for help!<br>

Go to your CSCI211 repo and open the `211/lab03_hello/` directory (your path may vary):
```
$ cd 211/lab03_hello
```

1. Type the command:
```
$ make
```
What happened? (Answer on the google survey)

2. Type the command again:
```
$ make    
```
What happened this time? Why? (Answer on the google survey)

3. Look at the dates on the files `hello` and hello.cpp:
```
$ ls -l
```
When `hello` is newer than hello.cpp, make does not try to recreate it<br>

Change the date on hello.cpp using the touch command:
```
$ touch hello.cpp
```
Touch just updates the last date changed to the current time<br>

Now look at the dates again:
```
$ ls -l
```
Type `make` again. What do you think will happen this time?<br>
```
$ make
```
What happened? Why? (Answer on the google survey)

4. Now edit the file hello.cpp (using any editor such as atom) and make some change (for example: change the text that is printed)<br>

Make sure you save the file<br>

Now type:
```
$ make
```
What happened? Why? (Answer on the google survey)

## Exercise 2: Makefile With Object Files
\* You must complete the rest of the Google Survey to get credit \*

1. Go to the lab03_sentence directory. If you're still in the lab03_hello folder, type:

```
$ cd ../lab03_sentence
```

The ".." means the parent directory (the parent of the current directory).  Alternatively you could have used the full path (e.g. ~/211/lab03_sentence)

1. Why does main.o depend on sentence.h? (Answer on the google survey)

2. Type:
```
$ make
```
Type:
```
$ touch sentence.h
```
Type:
```
$ make
```
Which files were recompiled? (Answer on the google survey)

3. Why were these files recompiled when sentence.h was changed? Look carefully at the Makefile. (Answer on the google survey)<br>

This is an important aspect of make, ask if you don't understand why!<br>

\* Remember to submit the Google Form with your responses to Exercise 1 & 2 \*

## Exercise 3: Create Your Own Makefile
The directory `lab03_makefile` (in the CSCI211 starter-repo) contains a program that uses two different objects: class Foo (in foo.h and foo.cpp) and class Bar (in bar.h and bar.cpp).  Create a makefile that compiles this program.<br>

You may start by using the Makefile from Exercise 2.<br>

Test your Makefile by compiling and running the program (the make order is not important as long as you can run the program):
```
$ make
g++ -Wall -pedantic -g -std=c++11 -c main.cpp
g++ -Wall -pedantic -g -std=c++11 -c foo.cpp
g++ -Wall -pedantic -g -std=c++11 -c bar.cpp
g++ -Wall -pedantic -o foobar main.o foo.o bar.o
$ ./foobar
Foo(1,2)
Bar(3,4)
$
```

For this exercise, you will not be submitting a file. Instead, copy your `Makefile` code into the code form field on [INGInious](https://inginious.csuchico.edu/) for lab03_makefile. INGInious will not test your Makefile; I will grade it by reading it. Since a Makefile can do anything (such as deleting all the files on a computer) INGInious never runs Makefiles that have been turned in.<br>

Hint: think carefully about the dependencies (the files listed after the target). For example, foo.cpp includes foo.h and thus foo.o depends on foo.cpp AND foo.h

## Exercise 4: Create a Course Class

Create a new class called `Course` (that is, create course.h and course.cpp) in the `lab03_course` directory.  You may start with the example code available in `lab03_object` (both available in the CSCI211 starter-repo) <br>

The `Course` class should have a single constructor and a print function:
```cpp
Course(string dept, int number, int time);
void print();
```
You need to figure out what member variables are required by class Course.<br>

Create a new file called schedule.cpp that contains a `main()` function to test your course class.  In your `main()` you should be able to use the Course class like this:
```cpp
Course programming("CSCI", 211, 1000);
Course english("ENGL", 130, 1400);
Course physics("PHYS", 204, 800);

programming.print();
english.print();
physics.print();
```
The above calls should result in the following output (this output is in the lab03_course/tests directory in the file t01.out).
```
CSCI 211 at 1000
ENGL 130 at 1400
PHYS 204 at 800
```
You can compile and complete the necessary linking for this program using the following command:
```
$ g++ -Wall -o schedule schedule.cpp course.cpp
```
One problem with the above command is that, if you make changes in any of the files, this command makes the compiler do extra unnecessary work -- the compiler will recompile everything, even if some files do not need to be recompiled. An alternative is to use a Makefile, such as the Makefile provided in your ~/211/lab03_course directory. Then, you simply have to type the following command:
```
$ make
```
The `make` command will only compile what needs to be compiled (not to mention how `make` is a very short and easy to remember command).<br>

REMEMBER: If you `#include` a file in your source code, you should only `#include *.h` files (schedule.cpp must include course.h and course.cpp must include course.h). **NEVER #INCLUDE .cpp FILES**.<br>

To get credit, you must pass the tests provided in the CSCI211 starter-repo `211/lab03_course/tests` directory).<br>

Turn in the files `schedule.cpp`, `course.h`, and `course.cpp`

## Exercise 5: Create Class Video for P2

Create the `Video` class you need for P2 and either create a simple `main()` or use my simple `main()` to test it (my example is available in the CSCI211 starter-repo `lab03_video` directory).<br>

If you have finished P2, all you have to do is compile your video.h and video.cpp with my main.cpp to make sure it works (or create your own main.cpp). Then turn in your video.h and video.cpp for this lab (be careful not to delete your 'real' P2 main.cpp).<br>

The sample `main()` should be similar or identical to the following (you will have to add some other code before the main):
```cpp
int main()
{
    Video video1("Title One", "www.youtube.com/one", "Comment ONE", 1.1, 1);
    Video video2("Title Two", "www.youtube.com/two", "Comment TWO", 2.2, 2);

    video1.print();
    video2.print();
    return 0;
}
```
If you have already written the constructor (`Video::Video(...)`) and your arguments are different than those listed above, your `main()` should use the arguments you are already using.<br>

If you have not started P2, look at the Plan of Attack section and implement Steps 1-6.<br>

You will need to implement the class `Video` constructor (`Video::Video(...)`) and the `print` member function (`void Video::print()`).<br>

The output of your program (using the `main()` above) should exactly match the following (CSCI211 starter-repo `211/lab03_video/tests/t01.out`). This is the test used by INGInious:
```
Title One, www.youtube.com/one, Comment ONE, 1.1, *
Title Two, www.youtube.com/two, Comment TWO, 2.2, **
```
The single test will expect this output.<br>

To get credit, you must pass the tests provided in the CSCI211 starter-repo `211/lab03_video/tests` directory).<br>

Turn in `main.cpp`, `video.h`, and `video.cpp`. Turn in all three files even if you have completed P2.

***

If you finish the lab exercises, you can work on your Video (P2) assignment.  If you have finished the exercises and have finished (and turned in a working version) of the Video assignment, you may leave early. Check with me before you leave so I can verify that you have everything turned in.

## Lab 03 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must complete the Google Survey (Exercises 1 and 2) and submit your solutions for Exercise 3, 4, and 5 to [INGInious](https://inginious.csuchico.edu/). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.

[Top of the Page](#lab-3)
