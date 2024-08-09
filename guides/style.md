# CSCI 211 Style Guide

This style guide highlights key practices from the Google C++ Style Guide that you should follow when writing code for CSCI 211.

[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html):<br>
“Google C++ Style Guide,” Accessed on: Jun. 4, 2021. [Online]. Available: [https://google.github.io/styleguide/cppguide.html](https://google.github.io/styleguide/cppguide.html)<br>

Plan on following the CSCI 211 Style Guide for all [Programming Assignments](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Programs) and the [CURE-E Final Project](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/CURE-E/finalProject.md) (your grade on these assignments may be impacted if you do not follow the CSCI 211 Style Guide).<br>

You are not required to follow the CSCI 211 Style Guide for [Lab Exercises](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Labs); however, it is generally good practice to follow a style guide, as doing so can make your code easier to reference, modify, and update in the future.<br>

## Style Guide Overview

Your program should be neatly organized, consistently indented, and have informative comments throughout. Avoid surprising or dangerous constructs that an average C++ programmer would find tricky or difficult to maintain. Since the Google C++ Style Guide is quite comprehensive, so the CSCI 211 Style Guide focuses on some of the most fundamental rules that will have the biggest impact on writing clean, readable, and maintainable code:
* [Variables](#variables)
* [Classes](#classes)
* [Functions](#functions)
* [Naming](#naming)
* [Comments](#comments)
* [Formatting](#formatting)
<br>

Following these guidelines will make your code more readable, more understandable, easier to maintain, and easier to debug (not to mention future instructors and employers may expect it).

### Variables

* Place a function's variables in the narrowest scope possible
  * Declare variables close to where they are used
* Initialize variables when they are declared
  * In C++, you cannot assume that variables will be initialized automatically
* Only use global variables if necessary or helpful
* Use `const` whenever it makes sense and is meaningful and accurate
  * This helps signify how the variable is used so that contributors can more easily understand how to work with the variable correctly, while also helping prevent unintended modifications.
  * Placing a constant value in a single location makes it easier to change if necessary.
* Avoid using "magic numbers" (unique values with unexplained meaning). Instead, use named constants (also called explanatory variables) to clarify what values represent and make your programs easier to read, understand and maintain.

### Classes

* Class declarations and function prototypes are put in the header file (the .h file)
* Class function definitions are put into the implementation file (the .cpp file)
* In the class header file:
  * Group similar declarations together
  * Do **not** implement large methods in the header
  * Think about **access control**:
    * In most cases, all member variables should be `private`
    * Only make members `public` if you want them to be accessible outside of the class



### Functions

* Create small functions that have a single, clear, focused responsibility.
  * Consider how your program could be divided into separate modules that each solve a specific task, and put each subtask into its own function.
  * Even if your long function works perfectly now, any modifications later may add new behavior, which could result in bugs that are hard to find.
  *  Keeping your functions short and simple makes it easier to read and modify your code in the future. Small functions are also easier to test.
* Rule of thumb: keep functions to 40 lines or fewer.
  * This is not a hard and fast rule, but if a function is longer than 40 lines, you should consider whether there are any ways that the function could be broken down into smaller tasks.
* Be thoughtful about how you use parameters and return values
  * Don't use more parameters than necessary, and make sure each parameter is there for a reason.<br>

Note that these rules apply to all functions, including `main()`, the first function that's called when a C++ program begins execution. While it is possible to write an entire program in `main()`, you should try to separate the functionality of a program into independent modules, and `main()` should just be used as a driver to call other functions.<br>

Define your function prototypes near the top of your program and write the functions after your `main()`.

### Naming

* Use names that would be clear to people other than yourself
* Use names that describe the purpose or intent of the:
  * type (e.g. classes, structs)
  * object (instances of classes)
  * variable (includes function parameters, class member variables)
  * function
* Optimize for readability: avoid ambiguity and minimize the use of abbreviations
  * It is fine to use certain universally-known abbreviations, such as `i` for a loop iterator
* For files, make sure your file names match those listed in the writeup (in some cases, your code will not compile on INGInious if the file names do not match)
* Be consistent. For example, you could use:
  * snake_case for variables (words separated by underscores): `a_local_variable`
  * PascalCase for types (each new word begins with a capital letter): `MyExcitingClass`
  * camelCase for functions (each words begins with a capital letter, except the first word): `addTableEntry()`
  * all lowercase, no underscores for file names: `myusefulclass.cpp`

> Note: In this course, file names should be all lowercase (e.g. "chart.cpp"). When a program uses classes, the class .h and .cpp files will use lowercase names, but the classes themselves should be named with a capital letter (e.g. `Video`)<br>

### Comments

* Comments are vital for keeping code readable!
  * Your comments should focus on explaining **why** something is done, rather than what the code is doing. Good comments explain the reasoning behind decisions.
* When writing comments, write as if there are other contributors who will need to understand your code.
  * Be generous -- remember that even if Future You is the only person who will look at your code, there are things that are clear to you now that will not be clear to Future You later.

* Use either `//` or `/* */` syntax -- just try to stay consistent
* You must include file header comments at the beginning of each file that you submit.

The first lines of all your files (.h and .cpp) must contain the following comments (use either `//` or `/* */` syntax):
```
// filename
// your name (first and last)
// your Chico Portal/INGInious username
// Short summary of the contents of the file
```

* Throughout your program, you should have brief comments describing how sections of code work. Consider including comments:
  * Before each **function** declaration and/or implementation: describe what the function does and how it is used. For trivial functions that are named appropriately, it's ok to skip the comment.
  * At the beginning of each **class**: describe what the class is for and how it is used.
  * Alongside **variable declarations** (if necessary -- it's better to have variable names that are descriptive enough to not require additional comments)
  * Alongside any code **implementation** that is tricky, non-obvious, interesting, or important -- anything that will help the next person who needs to read your code.<br>

**Things to look out for when adding comments**<br>

* Do NOT add comments to every line of code!
  * Try not to be unnecessarily verbose or state the obvious -- redundant and excessive comments can make your code MORE difficult to read.
  * A couple examples of comments that are unnecessary and unhelpful:
    * `i++;  // increment i by 1` :thumbsdown:
    * `x = y + z; // Set x to the sum of y and z` :thumbsdown:
* Comments that are unclear, vague, or poorly written are not helpful -- read the comments you have written to make sure you understand them.
  * If a comment does not relate to the actual code behavior, consider rewriting or removing it.

> Reminder: Comments are very important, but the best code is self-documenting. Giving sensible names to types and variables is much better than using obscure names that you must then explain through comments.

#### Formatting

* **Use consistent indentation** throughout your entire program.
  * Each level of indentation should be uniform, using either spaces or tabs, but not both.
    * It is recommended that you use spaces for indentation instead of tabs -- you may use 2, 4, or 8 spaces, but the important thing is to be consistent
  * All code blocks (e.g. loops, conditionals, functions) should be indented to clearly show their structure and hierarchy.
* The more code that fits on one screen, the easier it is to follow and understand the control flow of the program.
  * Be intentional with your usage of vertical and horizontal whitespace -- use whitespace purposefully to provide separation in that flow.
  * Try to limit line length to 80 characters or fewer in most cases
* Avoid use of non-ASCII characters
* **Always use braces around control flow statements** (including if-else, switch, and nested if-statements, for loops, while loops, etc).
  * One exception: if the entire statement appears on either a single line or on two lines. (This exception does not apply to multi-keyword statements like if ... else).

Using spaces instead of tabs helps ensure that your code is consistently indented, because tab size may vary depending on the environment. In Vim, you can change the settings and [convert all tabs to spaces](https://vim.fandom.com/wiki/Converting_tabs_to_spaces) by adding a line to your `~/.vimrc` file:
```
:set tabstop=4 shiftwidth=4 expandtab
```
In this case, all tabs are 4 space characters, but you could set the tab key to be a different number of spaces (most common: 2, 4, or 8 spaces).
* The `~/.vimrc` file should be in your home folder: `$ cd ~`
* You can see if the file exists: `$ ls -a`
* If it exists, add the line mentioned above. If it doesn't exist, you can create it: `$ vim .vimrc`
* For the new settings to be applied, close the terminal and open a new one.<br>

Other editors should have an option to set the tab size as well. The important thing is that you stay consistent. Other editors may have a different default value for tabs, so if you intermix tabs and spaces for indentation, the alignment may be off.<br>

### Parting Words

Use common sense and be consistent.<br>

The point of having style guidelines is to have a common vocabulary of coding so all contributors can concentrate on what the code is doing, rather than how the code is written. Consistency should not be used as an excuse to avoid making changes that improve your code. These global style rules help make sure everyone is on the same page; however, local style is also important.<br>

In CSCI 211, you may choose and develop your own style in some cases. With regards to naming and formatting, several options have been mentioned -- decide what works for you, then strive for readability and consistency. You are not required to follow a specific commenting structure, but you should be providing enough documentation so that another person (or Future You) can easily understand what your code is doing. <br>

Points may be deducted from your programming assignments if they do not follow the CSCI 211 Style Guide -- make sure to ask the instructor if you are unclear what is expected of you for this requirement.<br>

Remember to start early, take breaks, and ask for help if you're stuck. Writing code can be frustrating and stressful at times, but it can also be a really fun and enjoyable challenge!

[Top of the Page](#csci-211-style-guide)
