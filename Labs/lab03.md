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

## Exercise 1: Simple Makefile

* Read the [Overview of make](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/make.md) guide before completing Lab 03, Exercises 1, 2, and 3.<br>

\* You must complete this [Google Survey](https://docs.google.com/forms/d/e/1FAIpQLSft0f3fr4rMs0LIK2KWWbEs2EMYqQSBPFYjAcQzJWgQM3eq_A/viewform?usp=sf_link) to get credit for Exercises 1 & 2. Section 1 of the survey includes some general questions about Makefiles and the make utility. Section 2 includes questions corresponding to Lab 03, Exercise 1. Section 3 includes questions corresponding to Lab 03, Exercise 2. \*<br>

Note: You will need to be logged in to your \@mail.csuchico.edu or \@csuchico.edu Google account in order to take the Google Survey. If you get a message that you are unable to access the survey, try using your Chico portal username and password to login to Google. If you are not sure how to proceed, feel free to ask for help!<br>

Go to your CSCI211 repo and open the `211/lab03_hello/` directory (your path may vary):
```
$ cd 211/lab03_hello
```

1. Type the command:
```
$ make
```
ON SURVEY: What happened the first time you typed `make`?

2. Type the command again:
```
$ make    
```
ON SURVEY: What happened the second time you typed `make`? Why?

3. ON SURVEY: The next instruction uses the Linux `touch` command. What does the `touch` command do? Hint: you can type the command `man touch` in the terminal to look at the manual page for `touch`.

4. Look at the dates on the files `hello` and hello.cpp:
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
Type `make` again. Think about what you expect to happen this time<br>
```
$ make
```
ON SURVEY: What happened after you executed `touch hello.cpp` and typed `make`? Why?

5. Now edit the file hello.cpp (using any editor such as vim, atom, or vscode) and make some change (for example: change the text that is printed to say, "Hola, mundo!"<br>

Make sure you save the file<br>

Now type:
```
$ make
```
ON SURVEY: What happened after you edited hello.cpp and then typed `make` again? Why?

## Exercise 2: Makefile With Object Files
\* You must complete the rest of the Google Survey to get credit \*

Go to the lab03_sentence directory. If you're still in the lab03_hello folder, type:

```
$ cd ../lab03_sentence
```

The ".." means the parent directory (the parent of the current directory).  Alternatively you could have used the full path (e.g. ~/211/lab03_sentence)

1. Look at the files in the lab03_sentence directory, including the Makefile and the source code files (main.cpp, sentence.cpp, and sentence.h). You can use the `cat` command to display file contents in the terminal (e.g. `cat main.cpp`) or open up each file using the editor of your choice.<br>s

ON SURVEY: Why does main.o depend on sentence.h?

2. Type:
```
$ make
```

ON SURVEY: What files were created after you typed `make` for the first time? <br>

3. Now type:
```
$ touch sentence.h
```
Then type:
```
$ make
```
ON SURVEY: What commands were run when you typed `make` after typing `touch sentence.h`?

4. ON SURVEY: What files were recreated when you typed `make` after typing `touch sentence.h`?

5. ON SURVEY: Why were these specific commands run (again) and files created (again) when sentence.h was touched/changed? Look carefully at the Makefile.<br>

This is an important aspect of make, ask if you don't understand why!<br>

6. Now type:
```
$ touch main.cpp
```
Then type:
```
$ make
```
ON SURVEY: What files were recreated when you typed `make` after typing `touch main.cpp`?

7. ON SURVEY: Which command did NOT need to be run again when you used the `make` utility after typing `touch main.cpp`?

8. ON SURVEY: Why did a command NOT need to be run again when main.cpp was touched/changed?<br>

\* Remember to submit the Google Form with your responses to Exercise 1 & 2 \*

## Exercise 3: Create Your Own Makefile
The directory `lab03_makefile` (in the CSCI211 starter-repo) contains a program that uses two different objects: class Foo (in foo.h and foo.cpp) and class Bar (in bar.h and bar.cpp).  Create a makefile that compiles this program.<br>

You may start by using the Makefile from Exercise 2.<br>

Test your Makefile by compiling and running the program (the order of the commands may vary, but `make` should carry out four commands and generate a compilation target named `foobar`):
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

For this exercise, you will not be submitting a file. Instead, copy your `Makefile` code into the code form field on [INGInious](https://inginious.csuchico.edu/) for lab03_makefile.<br>

Hint: think carefully about the dependencies (the files listed after the target). For example, foo.cpp includes foo.h and thus foo.o depends on foo.cpp AND foo.h<br>

If your submission returns the message, "An internal error occurred", the issue may be something I can address on the backend, or it may be something that you need to fix in your code -- send me an email describing the issue, and I can let you know if you need to do anything in your situation.<br>

If you receive a compiler error that includes the following message, "*** missing separator.  Stop.", then you are likely using spaces instead of tabs to indent the makefile recipe lines. Remove any spaces used for indentation and replace them with tabs, then try submitting your code again.


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

All labs are due at 11:59pm the Friday following lab. For this lab you must complete the Google Survey (Exercises 1 and 2) and submit your solutions for Exercise 3, 4, and 5 to [INGInious](https://inginious.csuchico.edu/). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.<br>

Optional but recommended submission step: add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git add -A
$ git commit -m "completes lab03 exercises"
$ git push origin main
```

[Top of the Page](#lab-3)
