# Lab 10

Practice Midterm Recursion Problems

## Plan:

You will practice solving recursive problems similar to problems that will be on the second midterm exam.<br>

If you finish early, work on p5.<br>

## Sample Recursion Problems:

You may work on paper or you may work on-line. Driver programs that call these functions are available in the 211-starter-pack/211/lab10* directories:
* lab10_equal
* lab10_largest
* lab10_sorted
* lab10_isint<br>

## Steps for creating a recursive solution:
1. Define the problem in terms of a smaller problem of the same type.
2. Create an algorithm that reduced the size of the problem at each step (on each recursive call).
3. Identify a stopping condition (called a base case).
4. Make sure you reach the base case.

## Problem 1
Write a recursive function that returns true if two C-style strings are equal. Return false if they are not equal:
```
bool equal_strings(const char str1[], const char str2[])
{


}
```

## Problem 2
Write a recursive function that finds the largest number in an array of integers. Assume the array contains at least 1 number. You may write a helper function (it will simplify the code).
```
int largest_in_array(int values[], int size)
{


}
```

# Problem 3
Write a recursive function that takes an array of integers and returns true if the array is sorted from smallest value to largest value and false if the array is not sorted. Don't forget any special cases.
```
bool is_array_sorted(int values[], int size)
{


}
```

## Problem 4
(12 points) Write the recursive function `isint(char str[])` that takes a C-style string and returns true if the string in an integer (only digits) and false if the string is not an integer (contains characters other than digits). If the string is empty, return false (an empty string is not an integer).
```
bool isint(char str[])
{


}
```
