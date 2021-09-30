# Lab 9

Priority Queue

Lab 09 Exercises
* [Exercise 1: Create a Cust Class](#exercise-1-create-a-cust-class) (lab09_cust)
* [Exercise 2: Create a Priority Queue that works with Class Cust](#exercise-2-create-a-priority-queue-that-works-with-class-cust) (lab09_pqueue)

## Goals

* Provide an overview of the concept of a priority queue.
* For students to implement class `Cust` and class `Pqueue` (a priority queue of pointer to `Cust`) to be used in the Kwik-E-Mart Simulation (P5)

## Class Cust

Customers in the Kwik-E-Mart simulation (P5) will be represented by a simple object (called `Cust`). This object will hold four pieces of information about the customer:
1. name (a string)
2. if they are a robber or shopper (a boolean: true == robber, false == shopper) (a bool -- MAKE SURE YOU MAKE IT A bool)
3. arrival time (an integer)
4. number of items (an integer)<br>

The `Cust` constructor should take these four variables as parameters:
```cpp
new Cust("Homer", false, 42, 12);
```

Class Cust will print to a specific ostream (instead of always using `cout`). Its print function should look like this:
```cpp
void Cust::print(ostream &os)
{
    os <<   // put output here
}
```

In this function `os` is used instead of `cout`

## Exercise 1: Create a Cust Class

Working in your 211-starter-pack/211/lab09_cust directory, create class `Cust` that includes a constructor (as shown above) and a print function that prints in this format:
```
Homer shopper 42 12
Bart robber 86 2
```
Your class must work with the given `test_cust.cpp` and `Makefile`.<br>

Turn in `cust.h` and `cust.cpp`.

## Priority Queue Implementation

Use a linked list to store the elements in the queue. Each Node must hold:
1. A pointer to a Cust object
2. The priority (an integer)
3. A pointer to the next Node<br>

Since elements are usually inserted into the middle of a priority queue, having a tail pointer will not help.<br>

You need to decide how the queue will be ordered (i.e. remove from front -or- remove from back)<br>

## Function arguments and return types for a priority queue

Consider a queue of integers. The `dequeue` function needs to return two pieces of information: did the dequeue succeed? and what value was removed? Typically this is done by using a bool return type and a reference parameter:
```cpp
// example dequeue function for a queue of integers
bool Iqueue::dequeue(int &value_removed)
```

The reason we need both is because there is no integer value that we can return to indicate the queue was empty. For example, if we decide that returning 0 means the queue was empty, what would happen if there was a 0 in the queue? There is no integer that we can use because it is valid for any integer to be inserted into the queue.<br>

Now consider a queue of pointers to `Cust`. Since NULL is not a "valid" pointer we can use it to indicate the queue was empty (i.e. we don't need both a return value and a reference parameter in this case):
```cpp
// example dequeue function for a queue of pointers to Cust objects
Cust *Pqueue::dequeue()
```
This function returns a non-null pointer if the queue was not empty (a pointer to the `Cust` that was removed) and the dequeue succeeded. It returns NULL if the queue was empty. A priority queue dequeue function should remove the highest priority node and return a pointer to the customer that was in the highest priority location in the queue.<br>

The enqueue function should take:
1. A pointer to a Cust object
2. An integer priority
```cpp
void Pqueue::enqueue(Cust *cust, int priority);
```

Class Pqueue must also have an empty function that returns true if the queue is empty, false if it is not empty
```cpp
bool Pqueue::empty()
```

A Pqueue length function will return an integer representing the number of nodes currently in the queue.
```cpp
int Pqueue::length()
```

## Exercise 2: Create a Priority Queue that works with Class Cust

Working in your 211-starter-pack/211/lab09_pqueue directory, create class `Pqueue`. Each Node in the Pqueue class will contain a pointer to the Cust class you created in exercise 1.<br>

Pqueue must include empty(), length(), first_priority(), enqueue(), and dequeue() functions (as shown above). You do not need to implement a Pqueue destructor for lab 09, but in P5, you should make sure to include a destructor that deletes all Node objects.<br>

`int Pqueue::first_priority()` should return the priority of the first element without removing the element. Return -1 if the queue is empty.<br>

Your class must work with the given `test_queue.cpp`.<br>

Turn in `pqueue.h`, `pqueue.cpp`, `cust.h` and `cust.cpp`.

## Lab 09 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit `cust.h` and `cust.cpp` fo Exercise 1, and `pqueue.h`, `pqueue.cpp`, `cust.h` and `cust.cpp` for Exercise 2 to [Turnin](https://turnin.ecst.csuchico.edu/). If you are not able to complete all the exercises, turn in your partial work for partial credit.

[Top of the Page](#lab-9)
