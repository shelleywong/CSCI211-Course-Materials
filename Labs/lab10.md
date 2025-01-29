# Lab 10

Practice writing recursive functions

Lab 10 Exercises
* [Exercise 1: Recursive Equal Strings](#exercise-1-recursive-equal-strings) (lab10_equal)
* [Exercise 2: Recursive Find Largest](#exercise-2-recursive-find-largest) (lab10_largest)
* [Exercise 3: Recursive Check If Sorted](#exercise-3-recursive-check-if-sorted) (lab10_sorted)
* [Exercise 4: Recursive Is String An Integer](#exercise-4-recursive-is-string-an-integer) (lab10_isint)

## Plan:

You will practice solving recursive problems similar to problems that will be on the tests. Often, there is a way to solve recursive functions without using recursion; however, if you want to receive credit on these problems, you must use recursion.<br>

If you finish early, work on P5.<br>

## Sample Recursion Problems:

You may want to start by trying to solve these problems on paper, as this is what you will need to do on tests; however, make sure to complete a version of each function that can be submitted to INGInious so that you can get credit for this lab. Driver programs that call these functions are available in the CSCI211 starter-repo `211/lab10_*` directories:
* lab10_equal
* lab10_largest
* lab10_sorted
* lab10_isint<br>

## Steps for creating a recursive solution:
1. Define the problem in terms of a smaller problem of the same type.
2. Create an algorithm that reduced the size of the problem at each step (on each recursive call).
3. Identify a stopping condition (called a base case).
4. Make sure you reach the base case.

## Exercise 1: Recursive Equal Strings
Write a recursive function that returns true if two C-style strings are equal. Return false if they are not equal:
```cpp
bool equal_strings(const char str1[], const char str2[])
{


}
```

Submit `equal.cpp` to INGInious.

## Exercise 2: Recursive Find Largest
Write a recursive function that finds the largest number in an array of integers. Assume the array contains at least 1 number. You may write a helper function (it will simplify the code).
```cpp
int largest_in_array(int values[], int size)
{


}
```

Submit `largest.cpp` to INGInious.

## Exercise 3: Recursive Check If Sorted
Write a recursive function that takes an array of integers and returns true if the array is sorted from smallest value to largest value and false if the array is not sorted. Don't forget any special cases.
```cpp
bool is_array_sorted(int values[], int size)
{


}
```

Submit `sorted.cpp` to INGInious.

## Exercise 4: Recursive Is String An Integer
Write the recursive function `isint(char str[])` that takes a C-style string and returns true if the string in an integer (only digits) and false if the string is not an integer (contains characters other than digits). If the string is empty, return false (an empty string is not an integer).
```cpp
bool isint(char str[])
{


}
```

Submit `isint.cpp` to INGInious.<br>

If you finish early and would like more practice implementing recursive methods, you can review the recursion-focused questions from [previous semester exams](http://www.ecst.csuchico.edu/~trhenry/classes/211.s17/exams.html), and try writing solutions to these problems.

## Lab 10 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit `equal.cpp` (Exercise 1), `largest.cpp` (Exercise 2), `sorted.cpp` (Exercise 3), and `isint.cpp` (Exercise 4) to [INGInious](https://inginious.csuchico.edu/). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.<br>

Optional but recommended submission step: confirm the changes that have been made to the repo using `git status` and then add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git status
$ git add -A
$ git commit -m "completes lab10 exercises"
$ git push origin main
```

[Top of the Page](#lab-10)
