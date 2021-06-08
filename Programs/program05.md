# Program 5: Kwik-E-Mart Simulation

CSCI 211: Programming and Algorithms II<br>
Points: 300

## Objectives

* Implement a Priority Queue
* Practice using a struct
* Practice command line arguments
* Practice using file streams
* Practice assert(·)
* Deploy multiple instances of your priority queue

> Note: The priority queue used in this assignment was created in [Lab 9](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab09.md). Follow those instructions to create and test your Pqueue.

## Overview

Write a program to simulate the daily operations of a Kwik-E-Mart.<br>

There are two types of customers, those that buy things (shoppers), and those that steal things and money (robbers).<br>

Your program will:
1. read in a list of customers (name, shopper/robber, arrival time, number of items to buy/steal)
2. run the simulation.<br>

Output will be generated while the simulation is running.<br>

Customers will enter the store at a specified arrival time, spend time shopping for their items, get in line to pay/steal (our robbers are very polite, they wait in line to rob the store), spend some time paying or stealing money, and then leave the store. When a customer performs an action (arrive in store, get in checkout line, start paying/stealing, finish paying/stealing) your program will print a message documenting the customer's action and the current time.<br>

> Note: Start early and make incremental progress. If you think you can finish a programming assignment in one day, finish it the first day it is assigned. Students who put off these assignments tend to have a bad time.

## Program Requirements

### Implementation

Your program must take four command line arguments:  
* number of checkers
* length of checker's break after a robbery
* name of input file
* name of output file<br>

Your program must check that:
* the number of checkers is 1 or greater
* the checker's break length is 0 or greater
* the input file and output files can be opened.<br>  

If there is an error with a command line argument, write to standard error (cerr) the appropriate message from the following list and exit the program with an exit status of 1. Check for errors in the following order. Exit the program after finding a single error (don't look for all possible errors, stop after one):
```
Error: invalid number of command line arguments.
Error: could not open input file <t01>.
Error: could not open output file <t01.out>.
Error: invalid number of checkers specified.
Error: invalid checker break duration specified.
```

>Note: Replace `<t01>` and `<t01.out>` with the appropriate file names based on the given arguments.

Time will be represented by a single integer starting at 1. In the loop below, the variable `clock` is used to store the current time.<br>

The input file will be arbitrarily ordered and will have the format:
```
<name> <shopper/robber> <arrival time> <number of items to purchase/steal>

Homer shopper 3 9
Bart shopper 5 23
Lisa shopper 2 12
Maggie robber 27 1
```

* Names will be a single string without any spaces.
* Type of customer will always be either "shopper" or "robber."
* Arrival time will be an integer greater than 0.
* Number of items will be an integer greater than 0.

### Output

An output message must be printed every time a customer:
* enters the store
* finishes shopping
* starts checkout/stealing
* finishes checkout/stealing<br>

Your output must be identical to the following. Even the order must be the same. This is the output for the sample input given above executed with 2 checkers and a break time of 0. Note that robbers "stole" "from" and shoppers "paid" "to." Also notice that `item` is sometimes plural (`items`) and sometimes singular (`item`):
```
2: Lisa entered store
3: Homer entered store
5: Bart entered store
21: Homer done shopping
21: Homer started checkout with checker 0
26: Lisa done shopping
26: Lisa started checkout with checker 1
27: Maggie entered store
29: Maggie done shopping
30: Homer paid $27 for 9 items to checker 0
30: Maggie started checkout with checker 0
37: Maggie stole $277 and 1 item from checker 0
38: Lisa paid $36 for 12 items to checker 1
51: Bart done shopping
51: Bart started checkout with checker 0
74: Bart paid $69 for 23 items to checker 0
registers[0] = $69
registers[1] = $286
time = 75
```

The `entered/done_shopping/started/done_checkout` messages must be printed in member functions of class `Cust`. This is easy to implement. Create a `print` function for each type of message and pass the `ostream` and clock (and sometimes other information). For example, the following function prints the "entered store" message.
```
void Cust::print_entered(ostream & os, int clock)
{
    assert(clock == m_arrival_time);
    os << clock << ": " << m_name << " entered store" << endl;
}
```
The above `assert` is a great example of using asserts. The only situation that could result in a customer entering the store at a time different than his arrival time is if there is a logic flaw in the program. This assert will point out a logic flaw which otherwise might be very difficult to discover.<br>

After the main loop is over (at the end of the simulation), print the amount of money in each register (see above example for format, the register is part of the `Checker struct`) and print the current time -- the value of the clock (see above example for the format). This time should be one greater than the time the last customer left the store. If the input file is empty, and there are no errors, the clock should be 1.<br>

Use one queue for all the checkers. When taking a customer off of the checker queue, assign the customer to the empty available checker with the lowest number (when a checker is on break he is not available).<br>

All items in the Kwik-E-Mart cost $3. All checkers start the simulation with $250 in their register. When a customer buys items from a checker, increment the checker's balance. When a checker is robbed, she gives all her money to the robber.<br>

Customers must shop 2 time units for each item they buy/steal. For example, if a customer arrives at time 10, and buys 15 items, the customer should not be allowed to start the checkout/steal process until time = 40 (10 + 15*2).  Shopping time IS dependent on the number of items (even for robbers).<br>

During the checkout process, shoppers must spend 1 time unit for each item they are buying. For example, if a shopper is removed from the checker queue and assigned a checker at time = 28 and he is buying 7 items, he won't be done until time = 35 (28 + (1 * 7)). Checkout time IS dependent on the number of items.<br>

Robbers spend 7 time units for the checkout process. For example, if a robber is removed from the checker queue and assigned a checker at time = 40 and he is buying 17 items, he won't be done until time = 47 (40 + 7). Robbing time is NOT dependent on the number of items.<br>

If two (or more) customers arrive at the same time, put them in the arrival queue in the same order they appear in the input file. For example, if Homer arrives at time=10 and Lisa arrives at time=10, if Homer is before Lisa in the input file, Homer should be in front of Lisa in the arrival queue.<br>

Getting robbed is very stressful. Thus the checkers at the Kwick-E-Mart take a break after each time they are robbed. The length of the break (break duration) is a command line argument.<br>

The `Pqueue` class is a priority queue of `Cust` pointers. It must only contain functions related to a priority queue. While you may include a function like `int Pqueue::get_priority_of_first_element()`, do not include any code in `Pqueue` that has to do with the simulation. Ask me if you are not clear on this point. Class `Pqueue` must be implemented using a linked-list.

**Required classes**:
| Class | Purpose |
| --- | --- |
| class Cust | Stores information about a customer |
| class Pqueue | Priority queue of `Cust *` (time will be used as the priority) |

**Required structures (struct)**:

* struct Checker - Stores information about a checker:
  * money in the register
  * time a checker is done serving the current customer OR time checker's break ends (<= clock if not on break, >= clock if on break or serving a customer)
  * a pointer to a Cust (if currently checking out a customer, the Cust pointer will point to that customer, if not serving a customer it will point to NULL)<br>

[C++ Struct Documentation](https://www.cplusplus.com/doc/tutorial/structures/)

## Hints and Best Practices

There are many ways to implement this assignment. The following hints describe the most straightforward solution.<br>

Each customer in the input contains the string "shopper" or the string "robber". It is tempting to store this string in the `Cust` objects, but it is much better to use a boolean value (bool) to store this condition. Consider the following call to the `Cust` constructor. It converts the string role_string into a boolean that is true if role_string == "robber":
```
new Cust(name, (role_string == "robber" ? 1 : 0), arrival_time, num_items);
```
> Note: this is an example of a [conditional ternary operator](https://www.cplusplus.com/doc/tutorial/operators/). It takes three operands, making it possible to write an if/else conditional as an expression.<br>
> (conditional_expression) ? (if_true_do_this) : (if_false_do_this)

The file sim.cpp will contain the functions `main()` and `run_simulation()`.  You may add helper function (such as `legal_int()` from [Lab 8, Exercise 3](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab08.md#exercise-3)).<br>

Perform all the input in `main()`. Read the customers one at a time, create a Cust object for the new customer, and then insert the Cust onto a priority queue ordered by their arrival time (if you use arrival time as the priority, they will be ordered correctly). `arrival_q` would be a good name for this queue. Do not use `getline()` or `eof()` or `EOF`.<br>

Once all the customers have been read and inserted into the arrival queue, call `run_simulation()`. You will need to pass to `run_simulation()`:
* the arrival queue
* the number of checkers
* the checker's break
* an ofstream (to be used for output, all non-error output is written to the file given on the command line).<br>

Checkers can be implemented as an array of `Checker` structs. This struct must contain a pointer to their current `Cust`. If the checker is not serving anyone, its `Cust` pointer should be NULL. Since you don't know how many checkers there are until run time, you cannot create this array until run time:
```
void run_simulation(Pqueue &arrival_queue, int num_checkers, int break_duration, ostream &os)
{
    // create an array of Checker structures
    Checker *checkers = new Checker[num_checkers];

    // now use a loop to initialized all elements of the Checker structures
    ...

}
```

The body of the simulation should proceed as follows. If you don't follow this order, your output may not be in the correct order:
```
initialize num_customers to equal the number of customers in the arrival_queue
for (clock = 1; num_customers > 0; clock++)

    For all customers waiting on the queue to enter the store (i.e. those on the arrival_queue) that have an arrival_time == clock
        * remove them from the arrival_queue
        * print the appropriate message (entering store)
        * calculate what time they will be done shopping (hint: depends on the number of items)
        * place them on the shopping_queue using the time they will be done shopping as the priority

    For all customers on the shopping_queue that are done shopping
        * remove them from the shopping_queue
        * print the appropriate message (done shopping)
        * place them on the checker_queue (don't need a priority, use the same priority for all customers)

        // NOTE: this has to execute before you place customers on checkers,
        // but you will have to implement placing customers on checkers before /// you can test this part of the program

    For all the customers currently being served by a checker that are done at time == clock
        * increment/decrement the checker's total cash
        * print the appropriate message (paid or stole message)
        * decrement the number of customers (this is used in the for loop)
        * if the customer was a robber, update the checker so it will end its break at the correct time
        * delete this customer
        * set the checker's customer pointer to NULL (indicates it has no customer)

    While there is an available checker and there is a customer on the checker_queue
        * remove the customer from the checker_queue and assign it to an available checker (always pick the available checker w/the lowest index)
        * calculate the time the customer will be done checking-out/stealing (store this done time in struct Checker)
        * print the start checkout message
```

> Note: Make sure to follow this order; otherwise, your output may be incorrect

* Make sure that you are correctly managing dynamic memory.
* Start today.

## General Requirements

Programs should be well formatted and consistent so they are easy to read. The [General Requirements](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/README.md#general-requirements) listed in the Programs directory README apply to all programming assignments.<br>

Remember that the first lines of all your files (.h and .cpp) must contain the following comments:
```
// filename
// your name (first and last)
// your Chico Portal/Turnin username
// Short summary of the file contents
```

## Testing Your Program

* Some sample tests and a Makefile are included in 211-starter-pack/211/p5.
* [Lab 2](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab02.md) includes instructions for testing your program using the provided sample tests.
* I will test your program with additional tests not posted in the test directory. It is a very good idea to design and implement your own set of tests.<br>

This program uses command line arguments and file input/output. I will provide a script that handles the command line arguments and the file input/output.  However, when manually testing your program you must provide the command line arguments. Look at the `.cmd` files in the test directory to see the command line arguments of each test.

## Submitting Your Program

You MUST turn in your assignment several times (at least three) during development. Only the last submission has to compile and run and only the last submission will be graded. The submissions should show your progress (e.g. the first submission has a little bit of the program working, the second a little more, etc). When I suspect cheating I will look at these early submissions for a clear development trend; I want to prevent students from copying finished programs from another student and then turning them in.<br>

Turn in the following files using [Turnin](https://turnin.ecst.csuchico.edu):

```
sim.cpp
pqueue.h
pqueue.cpp
cust.h
cust.cpp
```

All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

Assignments can be turned in up to 48 hours late with a 15% penalty.<br>

If you are unable to complete everything on time, you should still turn in whatever work you have. If you turn in nothing, you get a zero. If you turn in something, you receive partial credit.

## Extra Credit

No extra credit points will be given to late assignments (both your regular assignment and the extra credit must be turned in on time).<br>

You must turn in the regular assignment code separately from the extra credit assignment code (I will create a separate assignment on [Turnin](https://turnin.ecst.csuchico.edu)).<br>

You will get 30 points extra credit if your program passes all the extra credit tests (a fraction of 30 points if you pass some of the extra credit tests). You have one extra credit test available to you in 211-starter-pack/211/p5_extra/tests/. I will use additional tests when grading the extra credit.<br>

Instead of having a single checkout queue, give each checker its own queue.<br>

When a customer is done shopping, put the customer on the checker with the fewest number of customers. `The number of customers is: the number of customers in the checker's queue + the customer being served (if there is one)`. Do not consider how many items each customer has or the time the checker will finish with the current customer. Ignore if a checker is on break when you are picking the shortest queue.<br>

If two or more checker queues have the same number of customers, use the checker with the lowest number (same as in the regular P5).<br>

Update the "done shopping" message to include the checker the customer is waiting for:
```
30: Homer done shopping, waiting for checker 2
```
