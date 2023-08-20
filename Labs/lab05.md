# Lab 5

Practice Midterm Exam questions<br>

Lab 05 Exercises:
* [Exercise 1: Compare Value to List Elements](#exercise-1-compare-value-to-list-elements) (lab05_compare)
* [Exercise 2: Find Largest Value in List](#exercise-2-find-largest-value-in-list) (lab05_largest)
* [Exercise 3: Convert List to Array](#exercise-3-convert-list-to-array) (lab05_convert)
* [Exercise 4: Remove Duplicates from List](#exercise-4-remove-duplicates-from-list) (lab05_removedup)

## Goal

* Practice writing linked list functions similar to those you have to write on the midterm.
* Each exercise has a directory in your CSCI211 starter-repo `211/` folder (lab05_*). This folder contains everything except the missing function. All you have to do is write the function, compile, and test your solution.
  * Exercise 1:  211/lab05_compare
  * Exercise 2:  211/lab05_largest
  * Exercise 3:  211/lab05_convert
  * Exercise 4:  211/lab05_removedup<br>

You will submit a separate list.cpp to INGInious for each exercise.

> Note: You will ONLY submit the list.cpp file -- your solution needs to work with the provided files, or else your code may not pass the tests on INGInious.

## Exercise 1: Compare Value to List Elements

Write the function `void List::compare(int target, int &less_than, int &equal, int &greater_than)` that compares the given value to each element in the list and counts the numbers in the list that are `less_than`, `equal` to, and `greater_than` the value. Note: this function uses reference parameters, and your implementation needs to take into account the possibility that the parameters were not initialized, or that they were initialized with any integer value (thus, you will need to initialize the counts in your function).<br>

For example, if the list contained {1,2,3,4} and the number 3 was passed as the value parameter to `compare()`, `compare()` would find that 2 numbers in the list are less than 3, 1 number is equal to 3, and 1 number is greater than 3.<br>

Modify the three reference parameters so they contain the correct counts (e.g. `less_than` should contain the number of elements less than value).  Assume the list is not sorted.

## Exercise 2: Find Largest Value in List

Write the function `bool List::largest_value(int &largest)`. If the list is not empty, put the largest value in the largest parameter and return true. If the list is empty, return false.

## Exercise 3: Convert List to Array

Write the function `int *List::convert_to_array(int &size)` that:
1. dynamically allocates an array of integers the exact size of the list,
2. copies all the list's values into the array,
3. assigns the size of the array (which is also the length of the list) to the reference parameter size, and
4. returns the array.<br>

Assume there exists a function you can call that returns the number of elements in the list: `int List::length()`. If the list is empty, return NULL. This function should NOT change the list. Hint: you can dynamically allocate an array of integers large enough to hold all the elements in the linked list using the following statement:
```
int *array = new int[length()];
```

## Exercise 4: Remove Duplicates from List

Write a function that removes all duplicate entries in the list. Assume that the list is ordered from smallest to largest, thus all duplicates will be next to each other. For example, if the list contained {1,2,2,2,3,3,4,5,5,5,5,5,6} before calling `void List::remove_duplicates()`, it should contain {1,2,3,4,5,6} after. Do nothing if the list is empty or contains no duplicates.

***

If you finish early and would like more practice implementing linked list methods, you can review the linked list questions from [previous semester exams](http://www.ecst.csuchico.edu/~trhenry/classes/211.s17/exams.html), and try writing solutions to these problems.

## Lab 05 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit separate `list.cpp` files to [INGInious](https://inginious.csuchico.edu/) for each of the Lab 05 Exercises (4 exercises total). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.<br>

Optional but recommended submission step: add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git add -A
$ git commit -m "completes lab05 exercises"
$ git push origin main
```

[Top of the Page](#lab-5)
