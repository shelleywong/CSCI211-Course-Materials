# Lab 5

Practice Midterm Exam questions

## Goal

* Practice writing linked list functions similar to those you have to write on the midterm.
* Each exercise has a directory in your 211-starter-pack/211 folder (lab05_*). This folder contains everything except the missing function.  All you have to do is write the function, compile, and test your solution.
  * Exercise 1:  211/lab05_compare
  * Exercise 2:  211/lab05_largest
  * Exercise 3:  211/lab05_convert
  * Exercise 4:  211/lab05_removedup

## Exercise 1

Write the function `void List::compare()` that compares the given value to each element in the list and counts the numbers in the list that are `less_than`, `equal` to, and `greater_than` the value.<br>

For example, if the list contained {1,2,3,4} and the number 3 was passed as the value parameter to `compare()`, `compare()` would find that 2 numbers in the list are less than 3, 1 number is equal to 3, and 1 number is greater than 3.<br>

Modify the three reference parameters so they contain the correct counts (e.g. `less_than` should contain the number of elements less than value).  Assume the list is not sorted.

## Exercise 2

Write the function `bool List::largest_value(int &largest)`. If the list is not empty, put the largest value in the largest parameter and return true. If the list is empty, return false.

## Exercise 3

Write a function that:
1. dynamically allocates an array of integers the exact size of the list,
2. copies all the list's values into the array,
3. assigns the size of the array (which is also the length of the list) to the reference parameter size, and
4. returns the array.<br>

Assume there exists a function you can call that returns the number of elements in the list: `int List::length()`. If the list is empty, return NULL. This function should NOT change the list. Hint: you can dynamically allocate an array of integers large enough to hold all the elements in the linked list using the following statement:
```
int *array = new int[length()];
```

## Exercise 4

Write a function that removes all duplicate entries in the list. Assume that the list is ordered from smallest to largest, thus all duplicates will be next to each other. For example, if the list contained {1,2,2,2,3,3,4,5,5,5,5,5,6} before calling `remove_duplicates()`, it should contain {1,2,3,4,5,6} after. Do nothing if the list is empty or contains no duplicates.
