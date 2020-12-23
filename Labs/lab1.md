# Lab 1

Introduction to Linux and the g++ Compiler

## Exercise 1 - Setting up your CSCI 211 environment

Taking some time to set up and organize your working directory for CSCI 211 will help prevent turning in the wrong assignment and make it easier to keep track of your files.<br/>

You may want to use a Git repository manager, such as GitHub, that provides version control and other features to build and manage software. It can be a great tool for organizing your source code; HOWEVER, remember that whenever you are creating a directory for a class where everyone is turning in the same assignments (like in this CSCI 211 course), make sure to make the visibility of this repository **private!** If your repo is public, it means other students can see it and easily steal the code from it -- this constitutes cheating and is a violation of academic integrity. There is no reason to make a CSCI 211 repo publicly visible this semester or after you have completed the class. Refer to the [Cheating Policy](http://www.ecst.csuchico.edu/~trhenry/classes/general/cheating.html) or talk to me directly if you are unclear about any of this. Refer to the [GitHub docs](https://docs.github.com/en/free-pro-team@latest/github) for additional guidance on working with GitHub.<br/>

There is no requirement in this course to use GitHub. The following instructions will work on your local Linux/OSX laptop/desktop (with or without a remote repository):<br/>

1. Go to your home directory, or a subdirectory such as "Courses" or "Repos". Create a folder for CSCI 211 using mkdir (make directory)
```
$ mkdir csci211
```
2. Now enter that directory, using cd (change directory)
```
$ cd csci211
```
3. For each lab and programming assignment, you will want to create a subdirectory. If you do not organize your files well, you will potentially regret it later, as it is easy to overwrite or delete files. Create a directory for lab 1 and enter the subdirectory
```
$ mkdir lab01
$ cd lab01
```
4. Using `lab01` rather than `lab1` will maintain sorted order when viewing the list of directories, since there are 15 labs total. Lab 1 consists of three tasks. Make a subdirectory within the lab01 directory for each task.
```
$ mkdir hello
$ mkdir add
$ mkdir print
```
