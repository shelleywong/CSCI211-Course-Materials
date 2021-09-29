# Lab 7

Stack of Doubles

Lab 07 Exercises
* [Exercise 1: Stack of Doubles](#exercise-1-stack-of-doubles) (lab07_dstack)

## Goal

For students to implement the stack of doubles for the Calculator programming assignment (P4)

## The post-fix calculator

The post-fix calculator assignment requires that you implement a stack of doubles (called class Dstack). The stack must be implemented using a linked list. The stack must provide at least the following functions (you can use different arguments if you would like):
| Dstack Member Function |  |
| --- | --- |
| `void push(double value)` | Push given value onto the stack. |
| `bool pop(double &value)` | Remove the top value from the stack and return it using the reference parameter. Return true if the stack was not empty, false if the stack was empty. |
| `int size()` | Return the number of elements in the stack. |
| `bool empty()` | Return true if the stack is empty, false otherwise. |
| `~Dstack()` | A correct destructor that deletes all the Nodes objects (you don't have to complete the destructor for lab 7, but P4 requires it). |
| `Dstack()` | A constructor that initializes an empty stack. |

## Exercise 1: Stack of Doubles

* Your lab assignment for this week is to implement the `Dstack` class and use your class to reverse some numbers.
* Put your `Dstack` in the files dstack.h and dstack.cpp
* Put your `main()` (which reads the values and uses the stack to print them in reverse) in the reverse.cpp file. You can use my reverse.cpp, a modified version of my reverse.cpp, or you can write your own reverse.cpp (it would be a good exercise to write your own version w/o looking at my version). My version of reverse.cpp along with a `Makefile` are in your 211-starter-pack/211/lab07_dstack directory.<br>

The program should work like this:
```
$ ./reverse
1.1
2.2
3.3
^D
There are 3 numbers in the stack.
3.3
2.2
1.1
There are 0 numbers in the stack.
$
```

The main() function (in reverse.cpp), should include code that works like this:
```
As long as there are numbers to read  (using cin >> my_double)

    Read the value
    Push the value on to the stack

// After all the values have been read (when cin >> my_double returns false)
Print out the number of elements currently in the stack

As long as the stack is not empty

    Remove a value from the stack
    Print the value (on its own line)

Print out the number of elements currently in the stack
```

## Testing

Check your results against the three test cases that are available in your 211-starter-pack/211/lab07_dstack/tests directory.

## Lab 07 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit `dstack.h`, `dstack.cpp`, and `reverse.cpp` to Turnin (turn in reverse.cpp even if you use my version -- this allows you to change it if you want to). If you are not able to complete all the exercises, turn in your partial work for partial credit.

[Top of the Page](#lab-7)
