# Program 3: Linked List of Video Objects

CSCI 211: Programming and Algorithms II<br>
Points: 250

* [Objectives](#objectives)
* [Overview](#overview)
* [Program Requirements](#program-requirements)
* [Helpful Hints](#helpful-hints)
* [Plan of Attack](#plan-of-attack)
* [General Requirements](#general-requirements)
* [Testing Your Program](#testing-your-program)
* [Submitting Your Program](#submitting-your-program)

## Objectives

* Understand abstract data types
* Practice information hiding
* Design a Linked List
* Review dynamic memory allocation and deallocation
* Practice handling errors
* Learn to love pointers

## Overview

Implement a linked-list of pointers to Video objects
> Note: P3 will use the Video class that you used in P2. See [the  writeup](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program02.md) for a description of class Video.

Implement a `main()` that reads and executes commands. Your program must handle the following commands:
1. Insert a new video into the linked list (after each new video is inserted, the list should be ordered alphabetically by title)
2. Print all the videos in the list
3. Lookup a video by title and print it
4. Print the number of videos in the list
5. Remove a video by title
> Note: Start early and make incremental progress. If you think you can finish a programming assignment in one day, finish it the first day it is assigned. Students who put off these assignments tend to have a bad time.

## Program Requirements

### Implementation

Use the `Video` class you created for P2 to store videos. If you did not finish P2, create a `Video` class as specified in P2. You will likely want to add some member functions to the `Video` class (i.e. getters and setters).<br>

Create a linked list class called `Vlist` -- it will be a linked list of `Video *` (pointers to Video objects). Put this class in the files vlist.h and vlist.cpp. The nodes in this list must not be the `Video` objects.  Each `Node` will contain a pointer to a `Video` object and a pointer to the next `Node`.<br>

Put the `main()` function in the file main.cpp
> Note:  You MUST use the file names and variable names dictated by the instructions. This allows any programmer to use your interface. I cannot debug your program if your interface differs from the specifications. Also, your program will not pass the INGInious tests.

The linked list should always be ordered alphabetically by title. The `insert` function should insert videos so that, after each call to insert(), all videos in the list are ordered alphabetically.<br>

All member variables of class `Video` and class `Vlist` must be **private**.<br>

Use dynamic allocation to create and delete `Video` and `Node` objects:
* When reading a new Video, you must use the `new` operator to create a new Video object (just like in P2).
* Create the `new` Video objects in `main()` and pass a pointer to the object using `Vlist::insert()`
* When inserting into the list, you must use the `new` operator to create a `new` Node object (just like in the class linked list examples).
* Create the `new` Node object in `Vlist::insert()`.
* When removing a Video from the list, both the Node object and the Video object must be deleted.<br>

You must provide a correct destructor for class `Vlist` that deletes all Node objects. You also need to make sure to delete all Video objects. This can be completed in the `Vlist` destructor or in a class `Node` destructor.<br>

There must not be any input or output in class `Vlist` (you cannot use cin/cout/cerr in a Vlist member function). However, you can call Video's print function from the Vlist class.<br>

The only input or output allowed in class `Video` is output in the `Video::print()` function. ALL ERROR MESSAGES MUST BE PRINTED FROM `main()`.<br>

Return an exit status of 0 if all the commands were legal. Return an exit status of 1 if any of the commands were illegal.

### Input

Your program must read commands until the end of input (until user presses `^D` or the end of a redirected file is reached, e.g. `$vlist < tests/t01.in`).  When end of input is reached, exit your program with an exit status of 0 (see below for exit status when a bad command is entered).<br>

Your program must handle the following commands. The arguments for the command are always on the next line (or lines). For the `insert` command, the arguments (title, url, comment, length, rating) will be on the five lines following the command (each on its own line just like in P2). For the `lookup` and `remove` commands, the title will be on the next line.<br>

**The commands from input that you will need to handle in main.cpp:**<br>
| Command | Action | Input Arguments** | Error |
| --- | --- | --- | --- |
| insert | Insert a new video into the linked list (videos should be ordered alphabetically by title). | title, url, comment, length, rating | Title is already in the list. See error messages below. |
| print | Print all the videos in the list using the format from P2. | none | none (print nothing if list is empty) |
| length | Print the number of videos in the list as a single integer (don't print anything other than the integer). | none | none (print 0 if the list is empty) |
| lookup | If the given title is in the list, print the video using the format from P2. | title (may contain spaces) | Title is not in list. |
| remove | If the given title is in the list, remove it. | title (may contain spaces) | Title is not in list. |

\*\*These are the arguments that follow each command, they are not the arguments to the list functions. For example, `Vlist::insert(Video *video)` is easier to implement if it takes a pointer to a Video object instead of five separate parameters for all the values read from input.<br>

**This is how I suggest you declare the Vlist member functions to meet the requirements for this assignment:**<br>
| Vlist Member Function | Parameters | Return Value Type |
| --- | --- | --- |
| Vlist Constructor | none | none |
| Vlist Destructor | none | none |
| insert | pointer to a Video object | bool (true for successful insert, false if Video already in the list) |
| print | none | void |
| length | none | integer (number of videos in list) |
| lookup | string (title to lookup) | bool (true if found, false if not in list) |
| remove | string (title to remove) | bool (true if found and removed, false if not in the list and cannot be removed)

### Errors and Error Messages

The input will not contain any errors other than those listed in this section.  For example, the `insert` command will always be followed by a title, url, comment, length, and rating (each on a separate line). **The program should NOT terminate for the following three errors**.<br>

| Command | Error | Error Message (replace XXX with the title entered by user, print the < and >) |
| --- | --- | --- |
| insert | Title already in list. | Could not insert video \<XXX\>, already in list. |
| lookup | Title not in list. | Title \<XXX\> not in list. |
| remove | Title not in list. | Title \<XXX\> not in list, could not delete. |

If the user enters a command other than (insert, print, length, lookup, remove), print the following error message and **terminate the program** with an exit status of 1. Replace the XXX with the command entered (make sure you print `<` and `>` in your error message).
```
<XXX> is not a legal command, giving up.
```

## Helpful Hints

1. It is very helpful to read the entire assignment writeup carefully before you start and review it as you program. You may want to print out the instructions and check off each requirement when you are sure it is correctly implemented. The writeup is long, but it contains a lot of useful information.
2. Program incrementally. Get small parts working before you move on. The next section describes how to break the program into pieces.
3. The linked list examples from class are all linked lists of integers. That means the Nodes contained integers. For this assignment, the list is a list of pointers to `Video` objects, which means the `Node` will contains a `Video *` instead of the integer in the class examples.
4. Use **static memory** in `main()` to instantiate the Vlist object instead of `Vlist *videos = new Vlist()` (you **do not** need to dynamically allocate memory in this instance)
5. `lookup` and `remove` take titles as their arguments. A title may include a space, so `cin >> my_str` will not work here. Use `getline()` in any situation where you need to read a title.
6. Use `getline()` to read all the commands. `getline()` will automatically throw away the newline character at the end of the line.
```cpp
while (getline(cin, command)) {
    // have just read a new command
    if (command == "insert")
    {
        // read the insert arguments (title, url, comment, length, title)
        //...
        cin >> rating;
        // since cin >> rating does not throw away the newline, you need to explicitly ignore it
        cin.ignore();
    }
    else if (command == "remove")
    {
        getline(cin, title);
        // don't have to worry about the newline because getline threw it away
    }
    ...
}
```
7. When reading a `Video`, you can use the same approach you used in P2 (either `cin.peek() != EOF` or `getline` to read the command in the condition of your `while` statement, as in the example above).
8. Since you will be printing error messages in `main()`, several of the `Vlist` functions will have to return the status of the function. For example:
```cpp
bool Vlist::remove(string title)
{
    if the title is in the list and was removed
        return true
    else return false
}
```
In `main()`, the value returned by `remove` can be used to determine if an error message should be printed. Print all error messages from `main()`.<br>
9. You may find it helpful to use `assert` to document what you think should be true or false while debugging. See the [assert documentation](https://www.cplusplus.com/reference/cassert/assert/) for more information.<br>
10. When you make a mistake with a pointer, your program usually terminates with a `Segmentation Fault`. It can take a lot of time to track down these problems. Even if you did P2 at the last minute, it is a good idea to start P3 early.<br>
11. Make sure that you are correctly managing dynamic memory.<br>
12. Start today.

## Plan of Attack

Work step by step:
1. Copy P2's main.cpp, video.h, and video.cpp to your P3 directory (do not use the same directory for both assignments).
2. Create the `Vlist` class without any functions (vlist.h, vlist.cpp).
3. Update `main.cpp` so it includes "vlist.h". About the only code you need from P2's `main()` is the reading of the `Video` fields (title, url, ...) and the declaration of the variables (string title, string url, ...). Delete the rest of the code. (If you prefer, you can start main.cpp from scratch).
4. Make sure your `p3/` directory contains a `Makefile` (if not, create one using the provided examples) and compile the assignment using the `make` utility (`$ make`).
5. Once the "empty" files compile, write the code in `main()` to read the input. Test your code so you are sure it is working. Make sure you handle end of input (^D), illegal commands, and skipping whitespace correctly. What you read will depend on the command. For example, length takes no arguments but insert takes 5 arguments.
6. Once you are certain that your input is working correctly, implement an `insert` function in `Vlist` that inserts the videos at the front of the list.  Eventually you will need to insert so they are sorted, but getting this simple function working first is very helpful.
7. Write the `Vlist::print()` function. This function traverses the list and calls `Video::print()` on all the Video objects in the list.
8. Implement the `insert` and `print` commands in `main()`. Once they are implemented, you will be able to insert any number of videos into the list and print the entire list out. However, the order will not be correct yet because you have a place holder for the insert function. As an example of how to implement the commands, below is my implementation of the `print` command. I called my `Vlist` object `vlist`.
```cpp
if (command == "print")
{
    vlist.print();
}
```
9. Once you are certain that the `print` and `insert` commands work, you can update the `insert` function to insert the video so the list is ordered correctly (alphabetically by title). Test your new `insert` function. If it is correct, your program should pass all tests that only use the `insert` and `print` commands. If you don't pass these tests, fix the problem before you move on.<br>
10. Implement the remainder of the commands one by one. Make sure each works before you move on.
> Note: I recommend implementing `remove` last because if you make a mistake in `remove`, it can be very hard to track down.

11. Write the destructor for `Vlist` and remember to use the `delete` operator on any memory that was allocated with `new`.
12. Read the requirements carefully to make sure your program is complete.

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

* Some sample tests and a Makefile are included in the CSCI211 starter-repo `211/p3/` directory.
* Test your code before submitting it to INGInious -- you can review the instructions for Testing Assignments using the provided sample tests in the [Labs directory README](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Labs).
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
vlist.h
vlist.cpp
main.cpp
```

All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

If you are not able to complete this programming assignment, turn in your partial work for partial credit, or submit later for late credit. If you turn in nothing, you get a zero. If you turn in something, you receive a grade that is higher than zero.

## Extra Challenge (no points, just for fun)

> Note: In general, there is no need to include Extra Challenge code in your programming assignment submission; however, you may include it if it does not impact the output (your code submission should still pass the provided and hidden tests). Make sure you save a copy of your completely working program before you start the extra challenge. The idea behind the extra challenges is to give you the opportunity to figure out how to solve problems on your own. I may discuss extra challenges, but I won't tell you how to solve them.

You can test your Extra Challenge code against the test files available to you in the CSCI211 starter-repo `211/p3_extra/tests/` directory.<br>

* Implement the `print_by_length` command that prints all the videos in the list ordered by length (shortest to longest). If two or more videos have the same length, they should be sorted alphabetically (i.e. if video "a" has the same length as videos "c" and "d", "a" should be first, "c" second, and "d" last).
* Implement the `print_by_rating` command that prints all the videos in the list ordered by rating (highest to lowest). If two or more videos have the same rating, they should be sorted alphabetically.
* Implement the `lookup_expression` command that takes a regular expression and prints all the videos that have titles matching the given regular expression. Use the system functions `regcomp` and `regex` to implement regular expressions. If the regular expression does not match any titles in the list OR if the regular expression is not a correct regular expression, print the following to standard error (replace XXX with the regular expression):
```
Regular expression <XXX> does not match any titles in list.
```
If two or more videos match the regular expression, they should be sorted alphabetically.<br>

[Top of the Page](#program-3-linked-list-of-video-objects)
