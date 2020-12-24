# Lab 7

Stack of Doubles

## Goal

For students to finish implementing the stack of doubles for the Calculator programming assignment (p4)

## The post-fix calculator

The post-fix calculator assignment requires that you implement a stack of doubles (called class Dstack). The stack must be implemented using a linked list. The stack must provide at least the following functions (you can use different arguments if you would like):
| Function |  |
| --- | --- |
| `void push(double value)` | Push given value onto the stack. |
| `bool pop(double &value)` | Remove the top value from the stack and return it using the reference parameter. Return true if the stack was not empty, false if it was empty. |
| `int size()` | Return the number of elements in the stack. |
| `bool empty()` | Return true if the stack is empty, false otherwise. |
| `~Dstack()` | A correct destructor that deletes all the Nodes objects (you DO NOT have to complete this for the lab, but p4 requires it). |

* Your lab assignment for this week is to implement the `Dstack` class and use your class to reverse some numbers.
* Put your `Dstack` in the files dstack.h and dstack.cpp
* Put your `main()` (which reads the values and uses the stack to print them in reverse) in reverse.cpp. You can use my reverse.cpp, a modified version of my reverse.cpp, or you can write your own reverse.cpp (it would be a good exercise to write your own version w/o looking at my version). My version of reverse.cpp along with a `Makefile` are in your 211-starter-pack/211/lab07_dstack directory.<br>

The program should work like this:
```
$ ./reverse
1.1
2.2
3.3
^D
3.3
2.2
1.1
$
```

```
As long as there are numbers to read  (using cin >> my_double)

    read the value
    push the value on to the stack

After All the values have been read (when cin >> my_double returns false)

    As long as the stack is not empty

        remove a value from the stack
        print the value (on it's own line)
```

## Testing

Check your results against the three test cases that are available in your 211-starter-pack/211/lab07_dstack/tests directory.

## Turning In

Submit dstack.h, dstack.cpp, and reverse.cpp to Turnin (turn in reverse.cpp even if you use my version -- this allows you to change it if you want to). 
