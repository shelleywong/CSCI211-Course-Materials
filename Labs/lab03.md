# Lab 3

* Introducing the Linux make utility<br>
* Practice Creating C++ Objects<br>

Lab 03 Quiz Exercises:
* [Exercises 1 and 2: Make Utility Quiz](#exercises-1-and-2-make-utility-quiz) (lab03_hello, lab03_sentence)

> Note: All quizzes can be found on Canvas. Lab quiz exercises may be completed any time before the end of the semester for full credit. Multiple attempts are allowed; I will keep your highest score. Lab 03, Exercises 1 and 2 are combined into one quiz (the Make Utility Quiz). It is recommended that you complete the Make Utility Quiz at least once BEFORE completing Lab 03, Exercises 3-5. If you do not do as well as you'd like on the quiz, feel free to complete the quiz again at a later time.

Lab 03 Exercises:
* [Exercise 3: Create Your Own Makefile](#exercise-3-create-your-own-makefile) (lab03_makefile)
* [Exercise 4: Create a Course Class](#exercise-4-create-a-course-class) (lab03_object, lab03_course)
* [Exercise 5: Create Class Video for P2](#exercise-5-create-class-video-for-P2) (lab03_video)

> Note: To get full credit for this lab, you must complete a Canvas quiz (for exercises 1 and 2) and submit several files to INGInious (exercises 3, 4, and 5).

## Exercises 1 and 2: Make Utility Quiz

The Make Utility Quiz (Lab 03, Exercises 1 and 2) is meant to give you some practice and familiarize you with the make utility and Makefiles. It is recommended that you complete the Make Utility Quiz at least once BEFORE completing Lab 03, Exercises 3-5. If you do not do as well as you'd like on the quiz, feel free to complete the quiz again at a later time. If you want to walk through the lab quiz again, run the command `make clean` in both the lab03_hello directory and the lab03_sentence directory before progressing through the steps of the lab quiz.

Make Utility Resources:
* Read the [Overview of make](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/make.md) guide before completing the Make Utility Quiz. This quiz will ask you to test out commands yourself. You should run the commands in a Unix shell (e.g. ecc-linux or a Linux VM).<br>

* Section 1 (questions 1 - 4):
  * This section includes general overview questions about the `make` utility and Makefiles. The [Overview of make](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/make.md) should be helpful for this section.
* Section 2 (questions 5 - 9):
  * Complete these questions in the `lab03_hello` directory (type in the commands and follow the prompts in the questions)
  * These questions correspond with Lab 03, Exercise 1 (Simple Makefile)
  * These questions should be completed in order. Ask the instructor if you are getting any output that does not make sense to you.
* Section 3 (questions 10 -17):
  * Complete these questions in the `lab03_sentence` directory (type in the commands and follow the prompts in the questions)
  * These questions correspond with Lab 03, Exercise 2 (Makefile with Object Files)
  * These questions should be completed in order. Ask the instructor if you are getting any output that does not make sense to you.

After you have completed the Make Utility Quiz, you have successfully completed Lab 03, Exercises 1 and 2 (Exercises 1: Simple Makefiles, using the `lab03_hello` directory and Exercise 2: Makefile With Object Files, using the `lab03_sentence` directory).

Reminder: the Make Utility Quiz can be found in Canvas.


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

All labs are due at 11:59pm the Friday following lab. For this lab you must complete the Make Utility Quiz (Exercises 1 and 2) on Canvas and submit your solutions for Exercise 3, 4, and 5 to [INGInious](https://inginious.csuchico.edu/). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit. There is no late penalty for quizzes, but the quiz should still be completed.<br>

Optional but recommended submission step: confirm the changes that have been made to the repo using `git status` and then add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git status
$ git add -A
$ git commit -m "completes lab03 exercises"
$ git push origin main
```

[Top of the Page](#lab-3)
