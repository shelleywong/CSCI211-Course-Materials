# Lab 6

Introduction to the GNU gdb and ddd debuggers

## Goals

Learn the basics of the [GNU Project Debugger](https://www.gnu.org/software/gdb/) (gdb and ddd) so you can use them to find bugs in your class projects.

## Required Survey

You do not have to turn in any files for this lab, but you do have to complete this survey. The survey is worth 3 points.

## Exercise Setup

**Note for Mac users**: You cannot do this lab on a Mac unless you have GNU's g++ and gdb installed. These are no longer part of xcode, you have to download and install them using [homebrew](https://brew.sh/). It takes over an hour to install g++ using homebrew. I recommend you use ecc-linux or a comparable Unix-like system.<br>

I have created several sample programs for you to use with the debugger. They should be in your 211-starter-pack/211/lab06_gdb directory.<br>

You can compile all the programs with one call to `make`:
```
$ cd ~/211/lab06_gdb
$ make
```
`make` should not issue any errors -- let me know if you get errors.<br>

Nothing will be submitted to Turnin for this lab, but you must complete this [google survey](https://docs.google.com/forms/d/e/1FAIpQLSc_DOE7Ps-l4ApR8l7KN1y2KIm1OdvnoBKJqaQF9go6P9t_eQ/viewform?usp=sf_link).

## Exercise 1

* Start gdb with the executable p1:
```
$ gdb p1
```
* Type `run` at the (gdb) to run this program

1. ON SURVEY: What error causes this program to terminate?
2. ON SURVEY: On what line does this program crash?

* Type `list` at the (gdb) to list the source code

3. ON SURVEY: Explain the defect in the program that causes this problem.

* Type `quit` at the (gdb) to quit the debugger

## Exercise 2

* Start gdb with executable p2:
```
$ gdb p2
```
* Type `run` at the (gdb) to run this program

* Type `where` at the (gdb) to see the list of functions that were called

1. ON SURVEY: What error caused this program to terminate?

2. ON SURVEY: What functions were called before the program crashed?

* Notice that the `where` command told you the arguments to the functions f() and g()

* You can use the print (`p`) function to print the values of a variable:
```
(gdb) p b
$1 = 52
```
3. ON SURVEY: What is the address of the variable b?

* gdb is currently pointing to the code in function f().  If you use the `up` command it will be pointing at the code in the function that called f().

* Use the `up` command to go to the function that called f().

4. ON SURVEY: What is the address of the variable a?

## Exercise 3

**Note: ddd has a graphical window interface and therefore will not load via SSH (a text-based protocol). If you cannot complete Exercise 3 on a local machine, complete Exercise 3 using gdb instead of ddd.**
* Start ddd with the executable p3
```
$ ddd p3
```

* Press the run button or type `run` at the (gdb) to run this program

1. ON SURVEY: Explain why this program has a segmentation fault.

* Try printing the different variables:
```
(gdb) p m_values
(gdb) p *m_values
(gdb) p m_values[0]
```
* You can print variables by clicking on the variable in the code window.

## Exercise 4

Program p4 is the same program as p1 but is compiled w/o the -g option

* Start gdb with the executable p4
```
$ gdb p4
```
* Type `run` at the (gdb) to run this program

* Type `where` at the (gdb)

1. ON SURVEY: What is different between running p4 with gdb and running p1 with gdb?

2. ON SURVEY: Is the p1 executable smaller or larger than the p4 executable?

***

After completing the exercises and the survey, you may work on programming assignment 4
