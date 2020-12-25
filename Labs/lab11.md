# Lab 11

Exceptions (try/catch, throw)

## An "Exceptional" Programming

In this lab you will practice a common situation involving user input and error checking. You will write a simple program that asks the user to enter a number from 1 to 10. You must catch situations in which the user enters a number out of bounds, a non-integer number (e.g., double), or a non-numeric value (e.g., string). Your program is expected to recover and continue, until the user inputs a number that meets the specified criteria, or until the end of input is detected.<br>

Read the sections below to guide your solution.<br>

**Usage Example**
```
$ ./main
Pick a number between 1 and 10.
-1
You entered an illegal value of -1. Please try again.
Pick a number between 1 and 10.
11
You entered an illegal value of 11. Please try again.
Pick a number between 1 and 10.
four
This is not an integer. Please enter a number.
Pick a number between 1 and 10.
3.14
Non-integer value. You entered something after 3.
Pick a number between 1 and 10.
7
You picked 7.
$
```

## Step 1: Getting Started

You will prompt the user to enter a number (see usage example). You will then print out the number. Write this code in a main.cpp file. Test out this simple use case.
```
$ ./main
Pick a number between 1 and 10.
3
You picked 3.
$
```

## Step 2: Loop

First, let's restrict the input to our desired range 1 to 10. If the value is out of range, print an error message and prompt again.<br>

Not all problems require throwing and catching exceptions. This one is best handled by an if statement within a loop.<br>

Since we are basing the iteration on user input and we need the user to always enter at least once, which type of loop should you use? Please **do** consider this **while** designing your program.

```
$ ./main
Pick a number between 1 and 10.
-1
You entered an illegal value of -1. Please try again.
Pick a number between 1 and 10.
11
You entered an illegal value of 11. Please try again.
Pick a number between 1 and 10.
9
You picked 9.
$
```

## Step 3: String Posers
What happens if the user enters a string (e.g., "four") instead of an integer?  Try it out on your program.<br>

By default, C++ does not throw an exception when there is a problem with the I/O. We can change that by activating exception-throwing for this situation. Add this line at the beginning of your `main`.
```
cin.exceptions(iostream::failbit);
```

Run your `main` again and test using a string. Now what happens?<br>

Your `cin` line now throws an exception if something goes wrong. We need to handle it. Surround your `cin` line (and lines that depend on that statement) within a `try` block. Add this `catch` block:

```
catch(iostream::failure& iof)
{
    cout<<"This is not an integer. Please enter a number."<<endl;
    cin.clear(); // reset error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
}
```

You will need to include a library to support `numeric_limits`. Search the Internet to determine which one.

## Step 4: Bad Numbres

What happens if you enter a double value instead of an integer? Try it out.<br>

We need to identify this situation, throw an error, and catch it.<br>

Within your try block and after you read your number, add a check to "peek" ahead at the next character. If it is anything but `'\n'` (newline), then it is a bad number.  In that case, throw an error. Consider the provided catch block. What should you throw?<br>
```
catch(int pnum)
{
    cout<<"Non-integer value. You entered something after "<<pnum<<"."<<endl;
    cin.clear();  // reset error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear buffer
    pnum = 0;  // reset num to its initial value
}
```

Once you are finished, submit your main.cpp to Turnin.

***

After you have completed the exercises, work on the Kwik-E-Mart Simulation (p5). 
