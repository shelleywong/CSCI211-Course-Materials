# Lab 4

* Practice programming a basic Linked List
* Learn the basics of the Vim Editor

Lab 04 Exercises:
* [Exercise 1: Read Input and Put Numbers into a List Object](#exercise-1-read-input-and-put-numbers-into-a-list-object) (lab04_list/main.cpp)
* [Exercise 2: Member Function to Return Sum of List Elements](#exercise-2-member-function-to-return-sum-of-list-elements) (lab04_list)
* [Exercise 3: Member Function to Insert at End of List](#exercise-3-member-function-to-insert-at-end-of-list) (lab04_list)

## Learn the basics of the vim editor

Read the [Vim Guide](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/vim.md) for tips on configuring vim and using common vim commands.<br>

## Practice programming linked lists

For the following exercises, use the files in your CSCI211 starter-repo `211/lab04_list/` directory. This is a multi-part exercise with a single submission to INGInious.<br>

## Exercise 1: Read Input and Put Numbers into a List Object

For this exercise, you are just working in the main.cpp file. Edit `main()` so that it reads numbers from the standard input stream (cin) until end of input. Use a while loop to read the numbers and as you get each number, insert it into a `List` object.<br>

When the end of input is reached, have the list object print all the numbers.<br>

Your program should work like this:
```
$ ./list
1 2 3 4 5
^D
5
4
3
2
1
$
```

## Exercise 2: Member Function to Return Sum of List Elements

Add a new member function (`int List::sum()`) to the `List` class that returns the sum of elements in the list. In `main()` print the sum of elements after printing the list. Do not sum the elements in `main()`. The sum must be calculated in the List sum() member function.

Your program should work like this:
```
$ ./list
1 2 3 4 5
^D
5
4
3
2
1
sum = 15
$
```

## Exercise 3: Member Function to Insert at End of List

Add a new member function (`List::insert_at_end(int value)`) to the List class and implement the function so it inserts at the end of the linked list. Update your `main()` so it calls `insert_at_end()` instead of `insert()`. On the midterm, you will be asked to implement functions for a linked list class, so it would be best if you try to write this function without looking at notes from class.<br>

When you run your program it should work like this:
```
$ ./list
1 2 3 4 5
^D
1
2
3
4
5
sum = 15
$
```

Turn in your new versions of `list.h`, `list.cpp`, and `main.cpp`.
(You only have to turn in files for the last exercise -- the last exercise builds on the first exercises. Since this is a multi-part exercise, this single submission will be worth points for 3 exercises.)

***

If you finish the exercises early you could:

1. Get started on P3 (or finish working on P2)<br>
-and/or-
2.  Look at the [exams from previous semesters](http://www.ecst.csuchico.edu/~trhenry/classes/211.s17/exams.html) and try writing solutions to the linked list questions

## Lab 04 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit `list.h`, `list.cpp`, and `main.cpp` to [INGInious](https://inginious.csuchico.edu/), after you have completed Exercises 1, 2, and 3. If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.<br>

Optional but recommended submission step: add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git add -A
$ git commit -m "completes lab04 exercises"
$ git push origin main
```

[Top of the Page](#lab-4)
