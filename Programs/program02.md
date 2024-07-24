# Program 2: Video Rating System

CSCI 211: Programming and Algorithms II<br>
Points: 150

* [Objectives](#objectives)
* [Overview](#overview)
* [Program Requirements](#program-requirements)
* [Helpful Hints](#helpful-hints)
* [Plan of Attack](#plan-of-attack)
* [General Requirements](#general-requirements)
* [Testing Your Program](#testing-your-program)
* [Submitting Your Program](#submitting-your-program)

## Objectives

* Practice working with classes, objects, and arrays
* Review reading input from standard input
* Practice comparison of strings
* Practice using pointers and dynamic memory allocation
* Practice writing to standard output
* Practice exit codes
* Introduce sorting algorithms

## Overview

* Read an unordered collection of video descriptions each containing a title, url, comment, length, and rating.
* Allow the user to specify how the videos should be sorted: by rating, by length, or by title.
* After all the descriptions have been read, print them to standard output (using `cout`) sorted using the specified criteria (rating, length, or title).

## Program Requirements

Create a class called `Video`, and use this class to store the video descriptions. You should declare all class member variables and functions in the video.h header file (this is where the class is defined), and implement all class functions in video.cpp. All member variables in class `Video` must be **private**.<br>

Put the `main()` function in the file main.cpp<br>

Allow the user to specify up to 100 videos. If more than 100 videos are specified, print the message "Too many videos, giving up." with a newline (`endl`) to standard error (using `cerr`) and terminate the program.<br>

> Note: 100 is the maximum size of the array. Since you know the maximum size, you can statically allocate the array.

> Note: use a C-style array. C-style arrays are a powerful tool and it is beneficial for you to understand how to work with them. Do **not** use a standard template library (STL) container, such as a vector. STL containers are useful in some cases, but they can require additional memory and overhead that are unnecessary for this assignment. You will get opportunities to use other types of containers in future programs.

> Note: `cerr` is the standard output stream for errors. You can use it in the same way that you would use `cout`.

Return an exit status of `0` if there are no errors, or `1` if there is an error (exit status is the value returned from `main()`).<br>

Use an array of pointers to videos (`Video*`) to store the videos. Use dynamic memory to create a `new Video` object for each description read.<br>

> Note: use the C++ `new` operator to dynamically allocate memory. At the end of the program, use the C++ `delete` operator to release any memory that was dynamically allocated.

The first thing in the input must be the sorting criteria (on its own line).  The valid strings are "rating", "length", and "title."<br>

| Sorting Criteria | Description |
| --- | --- |
| rating | sort the output so the highest ratings come first |
| length | sort the output so the shortest videos come first |
| title | sort the output so the videos titles are in alphabetical order |

If the first line is not one of the above strings, print the message "XXX is not a legal sorting method, giving up." (where XXX is the first string in the input; the illegal sorting method) and a newline (`endl`) to standard error (using `cerr`) and terminate the program.<br>

After the sorting method string (rating, length, title), the input will contain only valid video descriptions (you do not have to worry about errors in the descriptions). Each description will be formatted as follows:

* first line: the title of the video (may contain spaces)
* second line: the URL of the video (may contain spaces)
* third line: a comment (may contain spaces)
* fourth line: a floating point number that is the length of the video
* fifth line: an integer from 1 to 5 that is the rating of the video<br>

Each field of the video description will be on its own line. The `title`, `URL`, and `comment` are strings. The `length` is a floating point number. The `rating` is an integer (it will always be in the range of 1-5). The following is valid input (remember that the first line is the sorting method):
```
rating
United Break Guitars
http://www.youtube.com/watch?v=5YGc4zOqozo
Great example of one person getting a giant company to listen
4.5
3
Spaces Versus Tabs
https://www.youtube.com/watch?v=SsoOG6ZeyUI
Decide for yourself: spaces or tabs?
2.83
4
It's Not About the Nail
https://www.youtube.com/watch?v=-4EDhdAHrOg
Favorite web video
1.68
5
Pet Interviews - Guinea Pig
https://www.youtube.com/watch?v=jW3XtKBlTz0
Best guinea pig interview
1.75
1
```

The following is the correct output for this example (sorted by rating as specified in the above input, with each video output on one line):
```
It's Not About the Nail, https://www.youtube.com/watch?v=-4EDhdAHrOg, Favorite web video, 1.68, *****
Spaces Versus Tabs, https://www.youtube.com/watch?v=SsoOG6ZeyUI, Decide for yourself: spaces or tabs?, 2.83, ****
United Break Guitars, http://www.youtube.com/watch?v=5YGc4zOqozo, Great example of one person getting a giant company to listen, 4.5, ***
Pet Interviews - Guinea Pig, https://www.youtube.com/watch?v=jW3XtKBlTz0, Best guinea pig interview, 1.75, *
```

If two or more Videos have the same values for the current sorting methods (e.g. you are sorting by rating and two or more videos have the same rating), these videos should be sorted in the same order as the input. For example, starting with the input given above, say the following video is input after "Pet Interviews - Guinea Pig":

```
Why Do Cats Purr?
https://www.youtube.com/watch?v=7KowU4tPi7Q
Taking on the adorable mystery of small felines purring
3.21
4
```

Since these videos are being sorted by rating and "Why Do Cats Purr?" has a 4-star rating (just like the "Spaces Versus Tabs" video), then the output should have the "Why Do Cats Purr?" video details printed immediately **after** the "Spaces Versus Tabs" video details.

> Note: If you sort using the bubble sort algorithm, the relative order of records with equal keys is maintained. This is not true of all sorting algorithms, and thus not all sorting algorithms will work for this program -- be aware of this if you decide to try another algorithm in addition to bubble sort.

## Helpful Hints

* Before you start, make sure you understand how the input is ordered and what is required for the output.
* Program incrementally. Get small parts working before you move on. The next section describes how to break the program into pieces.
* `cin >> my_string` will not work for strings with spaces. You will need to use `getline(cin, title)` where `title` is a C++ string. Use getline in any cases where you need to accept string input that may contain spaces.
* Use the call to getline in the while loop:
```cpp
// while there are more video descriptions to read
while (getline(cin, title))
```
* Use `cin >> ` to read both the length and the rating.
* After you read the rating (which is the last element of the description) there will be an extra line feed that you need to get rid of before you can read the next description (getline will read an empty line if you don't get rid of the newline). Use the following statement to get rid of that line feed:
```cpp
cin.ignore();
```
* When sorting the videos you need to be able to determine how two video objects should be ordered. The easiest way to do this is to write member functions to handle the comparisons in class `Video`. For example, this function could be used when sorting the videos by length:
```cpp
// return true if the current video is longer than the given video (other), return false otherwise
bool Video::longer(Video *other)
{
    return m_length > other->m_length;
}
```
* You will need to compare strings alphabetically when sorting by title. If you use C++ style strings (as suggested above) you can compare them using the normal comparison operators:
```cpp
string str1 = "hello";
string str2 = "goodbye";
if (str1 > str2)
{
    // this code is executed if str1 is alphanumerically greater than str2
}
```
* Use the [bubble sort algorithm](https://en.wikipedia.org/wiki/Bubble_sort) to sort the videos. This [Lego Bubble Sort video](https://www.youtube.com/watch?v=XN0saL9ujLE) may help you understand how this algorithm works. The following code uses the `Video::longer()` function above and sorts the array by video length:
```cpp
for (int last = num_videos - 1; last > 0; last--) {
    for (int cur = 0; cur < last; cur++) {
        if (videos[cur]->longer(videos[cur+1])) {
            swap(videos[cur], videos[cur+1]);  // since videos is an array of pointers you can simply swap the addresses at the cur and cur+1 locations.
        }
    }
}
```
> Note: You may use the C++ std::swap function or create your own.

* Make sure that you are correctly managing dynamic memory: at the end of your program, use the `delete` operator to deallocate any memory that was allocated with `new`. You can use [Valgrind](https://www.valgrind.org/docs/manual/quick-start.html) to detect if your program contains any memory leaks. Example with one argument (also works with Linux redirection):
```
$ ./myprog arg1                             // run your program like normal
$ valgrind --leak-check=yes ./myprog arg1   // test your program with valgrind
$ valgrind --leak-check=yes ./myprog < tests/t01.in  // example argument: you might want to include input from a file when you test your program with valgrind
```
* Start today.

## Plan of Attack

Work Step by Step:
1. Create video.h with an empty class definition, using the `#ifndef`/`#endif` construct. [Lab 3](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab03.md#exercise-4-create-a-course-class) and the CSCI211 starter-repo `211/lab03_object/` directory include a good starter example.
2. Create an empty video.cpp that includes video.h
3. Create main.cpp and write an empty `main()` (a main function that does not do anything). main.cpp should also `#include "video.h"`.
4. Make sure your `p2/` directory contains a `Makefile` (if not, create one using the provided examples), and compile the assignment using the `make` utility. If you named the files as specified above, double check that you only include `.h` files (never include a `.cpp` file). You can compile your program simply by typing "make" at the command prompt:
```
$ make
```
5. Once the "empty" files compile, write the code in `main()` to read the input (i.e. the sorting method string and the video descriptions). Write the data to standard output to make sure you are reading it correctly. Make sure you continue reading video descriptions until the end of input.
> Note: `cin` is an instance of class istream. It contains functions such as `ignore` and `getline`, which are used in this project. For P2, you can expect that all input will be well-formatted and you can use `while (getline(cin, title))` to read the video descriptions. If you are working with a program that takes in various types of input and the order of the input is unknown, you should use the `peek` function for your while loop condition. For more information, you may find the [istream documentation](https://www.cplusplus.com/reference/istream/istream/) useful.

6. Implement the `Video` class. Include a constructor and a print function.
7. After you read each description, create a new `Video` object (using the C++ `new` operator). Call the print function for that new object. Make sure the output is in the correct format so you don't have to worry about the print format anymore.
```cpp
// Create the new Video object
Video *temp_video_pointer = new Video( /* the variables that hold the values you just read in go here */ );

// tell the new Video object to print itself
temp_video_pointer->print();
```
8. Use the array of 100 pointers to `Video` objects to hold the videos (instead of the temp_video_pointer above). Instead of printing immediately after each video is read, print all the Videos in the array after you are done reading all the input. The output of your program should be complete except for the order of the videos. Make sure everything is working before you move on.
9. Implement the sorting of the videos. Do not start this step until you have tested your program and are sure all the other components are working.
10. Before exiting main(), use the delete operator to free all dynamically allocated memory.
11. Read the requirements carefully to make sure your program is complete.

## General Requirements

Programs should be well formatted and consistent so they are easy to read. The [General Requirements](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/README.md#general-requirements) listed in the Programs directory README and the [CSCI 211 Style Guide](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/style.md) apply to all programming assignments.<br>

Remember that the first lines of all your files (.h and .cpp) must contain the following comments:
```
// filename
// your name (first and last)
// your Chico Portal/INGInious username
// Short summary of the file contents
```

## Testing Your Program

* Some sample tests and a Makefile are included in the CSCI211 starter-repo `211/p2` directory.
* Test your code before submitting it to INGInious -- review the [Testing Assignments](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/testing.md) Guide for how to test your code using the provided sample tests.
* I will test your program with additional tests not posted in the test directory. It is a very good idea to design and implement your own set of tests.

## Submitting Your Program

You should aim to turn in your assignment several times (at least three) during development. The submissions should show your progress (e.g. the first submission has a little bit of the program working, the second a little more, etc). When I suspect cheating I will look at these early submissions for a clear development trend; I want to prevent students from copying finished programs from another student and then turning them in. Alternatively, you can show your progress by making several commits to your GitHub repo for each program:
```
$ git add -A
$ git commit -m "<descriptive commit message>"
$ git push origin main
```

Your best INGInious submission will be evaluated for grading, so it is fine if some submissions do not pass all the tests. If multiple submissions pass the same number of tests, your last best submission will be used for grading.<br>

Turn in the following files using [INGInious](https://inginious.csuchico.edu/):
```
video.h
video.cpp
main.cpp
```

All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

If you are not able to complete this programming assignment, turn in your partial work for partial credit, or submit later for late credit. If you turn in nothing, you get a zero. If you turn in something, you receive a grade that is higher than zero.

## Extra Challenge (no points, just for fun)

> Note: In general, there is no need to include Extra Challenge code in your programming assignment submission; however, you may include it if it does not impact the output (your code submission should still pass the provided and hidden tests). Make sure you save a copy of your completely working program before you start the extra challenge. The idea behind the extra challenges is to give you the opportunity to figure out how to solve problems on your own. I may discuss extra challenges, but I won't tell you how to solve them.

Implement an additional [sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) of your choice. You MUST implement the bubble sort algorithm at least once (as specified in this assignment); however, you may have multiple functions that sort the videos according to the given criteria.<br>

Note that the bubble sort algorithm is **stable**, meaning that it sorts equal elements in the same order that they appear in the input. If you implement a different sorting algorithm, your output may not match the expected output if the sorting algorithm is not stable.<br>

You likely want to write the sorting algorithms as functions, potentially in such a way that the functions could be easily swapped out for one another. Make sure to call the bubble sort algorithm at least once in your P2 submission.<br>

For each function, include appropriate comments: indicate the sorting algorithm being used and reference any sources (include a link to the sources, if applicable).

[Top of the Page](#program-2-video-rating-system)
