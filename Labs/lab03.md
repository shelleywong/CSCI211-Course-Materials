# Lab 3

Introducing the Linux make utility<br>
Practice Creating C++ Objects<br>

## Exercise 1: The make utility
\* You must complete this [Google Survey](https://docs.google.com/forms/d/e/1FAIpQLSft0f3fr4rMs0LIK2KWWbEs2EMYqQSBPFYjAcQzJWgQM3eq_A/viewform?usp=sf_link) to get credit \*

You will need to be logged in to your \@mail.csuchico email in order to take the Google Survey.<br>

You will need the 211 Starter Pack for this assignment, so if you haven't already, download 211-starter-pack.tar and extract (unpack) the archive file.<br>

Once you have the starter code, change to the `lab03_hello` directory (your path may vary):
```
$ cd ~/211/lab03_hello
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
What happened? Why? (Answer on the google survey)

3. Look at the dates on the files `hello` and `hello.cpp`:
```
$ ls -l
```
When `hello` is newer than `hello.cpp`, make does not try to recreate it<br>

Change the date on `hello.cpp` using the touch command:
```
$ touch hello.cpp
```
Touch just updates the last date changed to the current time<br>

Now look at the dates again:
```
$ ls -l
```
What do you think will happen when you type make ?<br>

Type:
```
$ make
```
What happened? Why? (Answer on the google survey)

4. Now edit the file `hello.cpp` (using any editor such as atom) and make some change (for example: change the text that is printed)<br>

Make sure you save the file<br>

Now type:
```
$ make
```
What happened? Why? (Answer on the google survey)

## Exercise 2
\* You must complete the rest of the Google Survey to get credit) \*

1. Go to the `lab03_sentence` directory. If you're still in the lab03_hello folder, type:

```
$ cd ../lab03_sentence
```

The ".." means the parent directory (the parent of the current directory).  Alternatively you could have used the full path (e.g. `~/211/lab03_sentence`)

1. Why does `main.o` depend on `sentence.h`? (Answer on the google survey)

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

3. Why were these files recompiled when `sentence.h` was changed? Look carefully at the Makefile. (Answer on the google survey)<br>

This is an important aspect of make, ask if you don't understand why!<br>

Remember to submit the Google Form with your responses to Exercise 1 & 2

## Exercise 3: (must turn in a Makefile)
The directory `lab03_makefile` contains a program that uses two different objects: class Foo (in foo.h and foo.cpp) and class Bar (in bar.h and bar.cpp).  Create a makefile that compiles this program.

You may start by using the Makefile from Exercise 2.

Test your Makefile by compiling and running the program (the make order is not important as long as you can run the program):

$ make
g++ -Wall -pedantic -g -std=c++11 -c main.cpp
g++ -Wall -pedantic -g -std=c++11 -c foo.cpp
g++ -Wall -pedantic -g -std=c++11 -c bar.cpp
g++ -Wall -pedantic -o foobar main.o foo.o bar.o
$ foobar
Foo(1,2)
Bar(3,4)
$


Turn in your Makefile.  turnin.ecst will not test your Makefile, I will grade them by reading them.  Since a Makefile can do anything (such as deleting all the files on a computer) turnin.ecst never runs Makefiles that have been turned in.

Hint: think carefully about the dependencies (the files listed after the target). For example, foo.cpp includes foo.h and thus foo.o depends on foo.cpp AND foo.h
Exercise 4: Create a Course class

Create a new class called Course (that is, create course.h and course.cpp).  You may start with this example (on lab computers, copy it from ~trhenry/211/example_src/object_start_here).

The Course class should have a single constructor and a print function

Course(string dept, int number, int time);
void print();

You need to figure out what member variables are required by class Course.

Create a new file called schedule.cpp that contains a main() function to test your course class.  In your main() you should be able to use the Course class like this:

Course programming("CSCI", 211, 1000);
Course english("ENGL", 130, 1400);
Course physics("PHYS", 204, 800);

programming.print();
english.print();
physics.print();

The above calls should result in the following output (this output is in the tests/lab03_course directory in the file t01.out).

CSCI 211 at 1000
ENGL 130 at 1400
PHYS 204 at 800

You can compile this program using this command (lab 4 explains a tool for compiling programs with multiple files):

$ g++ -Wall -o schedule schedule.cpp course.cpp

Or you could use the Makefile provided in your ~/211/lab03_course directory:

$ make

REMEMBER:  only include .h files (schedule.cpp must include course.h and course.cpp must include course.h).  NEVER INCLUDE .cpp FILES.

To get credit, you must pass the posted tests (in your directory ~/211/lab03_course, and on the web at ~trhenry/211/src/lab03_course/tests).

Turn in the files schedule.cpp, course.h, and course.cpp

Exercise 5: Create class Video for p2.

Create the Video class you need for p2 and either create a simple main() or use my simple main() to test it.

If you have finished p2, all you have to do is compile your video.h and video.cpp with my main.cpp to make sure it works (or create your own main.cpp).  Then turn in your video.h and video.cpp for this lab (be careful not to delete your 'real' p2 main.cpp).

The sample main() should be similar or identical to the following (you will have to add some other code before the main):

int main()
{
    Video video1("Title One", "www.youtube.com/one", "Comment ONE", 1.1, 1);
    Video video2("Title Two", "www.youtube.com/two", "Comment TWO", 2.2, 2);

    video1.print();
    video2.print();
    return 0;
}

If you have already written the constructor (Video::Video(...)) and your arguments are different than those listed above, your main() should use the arguments you are already using.

If you have not started p2, look at the Plan of Attack section and implement Steps 1-6.

You will need to implement the class Video constructor (Video::Video(...)) and the print member function (void Video::print()).

The output of your program (using the main() above) should exactly match the following (~trhenry/211/tests/lab03_video/t01.out). This is the test used by turnin.ecst.csuchico.edu:

Title One, www.youtube.com/one, Comment ONE, 1.1, *
Title Two, www.youtube.com/two, Comment TWO, 2.2, **

The single test will expect this output.

To get credit, you must pass the posted tests (in yoru directory ~/211/lab03_video/tests and on the web at ~trhenry/211/src/lab03_video/tests).

Turn in  main.cpp, video.h, and video.cpp.  Turn in all three files even if you have completed p2.
If you finish the lab exercises, you can work on your video (p2) assignment.  If you have finished the exercises and have finished (and turned in a working version) of the video assignment, you may leave early.  Check with me before you leave so I can verify that you have everything turned in.
