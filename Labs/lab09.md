# Lab 9

Priority Queue

## Goals

* Provide an overview of the concept of a priority queue.
* For students to implement class `Cust` and class `Pqueue` (a priority queue of pointer to `Cust`) to be used in the Kwik-E-Mart Simulation (p5)

## Class Cust

Customers in the Kwik-E-Mart simulation (p5) will be represented by a simple object (called `Cust`). This object will hold four pieces of information about the customer:
1. name (a string)
2. if they are a robber or shopper (a boolean: true == robber, false == shopper) (a bool -- MAKE SURE YOU MAKE IT A bool)
3. arrival time (an integer)
4. number of items (an integer)<br>

The `Cust` constructor should take these four variables as parameters:
```
new Cust("Homer", false, 42, 12);
```

Class Cust will print to a specific ostream (instead of always using cout). Its print function should look like this:
```
void Cust::print(ostream &os)
{
    os <<   // put output here
}
```

In this function "os" is used instead of "cout"

## Exercise 1

Working in your 211-starter-pack/211/lab09_cust directory, create class `Cust` that includes a constructor (as shown above) and a print function that prints in this format:
```
Homer shopper 42 12
Bart robber 86 2
```
Your class must work with the given test_cust.cpp and `Makefile`.<br>

Turn in cust.h and cust.cpp.

## Priority Queue Implementation

Use a linked list to store the elements in the queue. Each Node must hold:
1. A pointer to a Cust object
2. The priority (an integer)
3. A pointer to the next Node<br>

Since elements are usually inserted into the middle of a priority queue, having a tail pointer will not help.<br>

You need to decide how the queue will be ordered (i.e. remove from front -or- remove from back)<br>

## Function arguments and return types

Consider a queue of integers. The `dequeue` function needs to return two pieces of information: did the dequeue succeed? and what value was removed? Typically this is done by using a bool return type and a reference parameter:
```
bool Iqueue::dequeue(int & value_removed)
```

The reason we need both is because there is no integer value that we can return to indicate the queue was empty. For example, if we decide that returning 0 means the queue was empty, what would happen if there was a 0 in the queue? There is no integer that we can use because it is valid for any integer to be inserted into the queue.<br>

Now consider a queue of pointers to `Cust`. Since NULL is not a "valid" pointer we can use it to indicate the queue was empty:
```
Cust *Pqueue::dequeue()
```
This function returns a non-null pointer if the queue was not empty (a pointer to the `Cust` that was removed) and the dequeue succeeded. It returns NULL if the queue was empty.<br>

The enqueue function should take:
1. A pointer to a Cust object
2. An integer priority
```
void Pqueue::enqueue(Cust *cust, int priority);
```

class Pqueue must also have an empty function that returns true if the queue is empty, false if it is not empty
```
bool Pqueue::empty()
```

## Exercise 2:

Working in your 211-starter-pack/211/lab09_pqueue directory, create class `Pqueue`. Each Node in the Pqueue class will contain a pointer to the Cust class you created in exercise 1.<br>

Pqueue must include empty(), length(), first_priority(), enqueue(), and dequeue() functions (as shown above).<br>

`int Pqueue::first_priority()` should return the priority of the first element without removing the element. Return -1 if the queue is empty.<br>

Your  class must work with the given test_queue.cpp.<br>

Turn in pqueue.h, pqueue.cpp, cust.h and cust.cpp.
