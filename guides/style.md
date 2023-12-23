# CSCI 211 Style Guide

This guideline borrow heavily from the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html):<br>
“Google C++ Style Guide,” Accessed on: Jun. 4, 2021. [Online]. Available: [https://google.github.io/styleguide/cppguide.html](https://google.github.io/styleguide/cppguide.html)<br>

Plan on following the CSCI 211 Style Guide for all [Programming Assignments](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Programs) and the [CURE-E Final Project](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/CURE-E/finalProject.md) (your grade on these assignments may be impacted if you do not follow the CSCI 211 Style Guide).<br>

You are not required to follow the CSCI 211 Style Guide for [Lab Exercises](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Labs); however, it is generally good practice to follow a style guide, as doing so can make your code easier to reference, modify, and update in the future.<br>

### Style Guide Overview

Your program should be neatly organized, consistently indented, and have informative comments throughout. Avoid surprising or dangerous constructs that an average C++ programmer would find tricky or difficult to maintain. Refer to the [Google Docs version of the CSCI 211 Style Guide](https://docs.google.com/document/d/1ZPHlwQv9SmTB-gbYWcXqM_1tL3d5jyS02PZnAXpJgYI/edit?usp=sharing) for more details on each of these categories. Things to focus on include:
* [Variables](#variables)
* [Classes](#classes)
* [Functions](#functions)
* [Naming](#naming)
* [Comments](#comments)
* [Formatting](#formatting)
<br>

Following these guidelines will make your code more readable, more understandable, easier to maintain, and easier to debug (not to mention future instructors and employers may expect it).

### Variables

* Use the most local scope possible
* Only use global variables if necessary or helpful
* Remember to initialize all variables
* Use `const` whenever it makes sense and is meaningful and accurate
  * This helps signify how the variable is used so that contributors can more easily understand how to work with the variable correctly.
  * Placing a constant value in a single location makes it easier to change if necessary.
* Avoid using "magic numbers" (unique values with unexplained meaning). Instead, use named constants (also called explanatory variables) to clarify what values represent and make your programs easier to read, understand and maintain.

### Classes

* Think about **access control**:
  * member variables are usually `private`
  * only make members `public` if you want them to be accessible outside of the class
* Group similar declarations together
* Do **not** implement large methods in the class definition

### Functions

* Create small and focused functions
  * Consider how your program could be divided into separate modules that each solve a specific task, and put each subtask into its own function.
* Rule of thumb: keep functions to 40 lines or fewer.
  * This is not a hard and fast rule, but if a function is longer than 40 lines, you should consider whether there are any ways that the function could be broken down into smaller tasks.
* Be thoughtful about how you use parameters and return values
  * Don't use more parameters than necessary, and make sure each parameter is there for a reason.<br>

Note that these rules apply to all functions, including `main()`, the first function that's called when a C++ program begins execution. While it is possible to write an entire program in `main()`, you should try to separate the functionality of a program into independent modules, and `main()` should just be used as a driver to call other functions.<br>

Define your function prototypes near the top of your program and write the functions after your `main()`.

### Naming

* Use descriptive and sensible names for:
  * files
  * types (e.g. classes, structs)
  * variables (includes function parameters, class member variables)
  * functions
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

* Comments are vital for keeping code readable, but the best code is self-documenting (this is why naming is so important)
* Write comments for an audience/the next contributor/Future You
* Use either `//` or `/* */` syntax -- just try to stay consistent
* Don't be unnecessarily verbose or state the obvious; however, remember to think about the next contributor (something that seems obvious to you right now may not be clear to the next person who looks at your code).
* You must include comments at the beginning of each file that you submit.

The first lines of all your files (.h and .cpp) must contain the following comments (use either `//` or `/* */` syntax):
```
// filename
// your name (first and last)
// your Chico Portal/INGInious username
// Short summary of the contents of the file
```

* Throughout your program, you should have brief comments describing how sections of code work. You shouldn't need a comment on every line, but consider including comments:
  * Before each **function** declaration and/or implementation: describe what the function does and how it is used. For trivial functions that are named appropriately, it's ok to skip the comment.
  * At the beginning of each **class**: describe what the class is for and how it is used.
  * Alongside **variable declarations** (if necessary -- it's better to have variable names that are descriptive enough to not require additional comments)
  * Alongside any code **implementation** that is tricky, non-obvious, interesting, or important -- anything that will help the next person who needs to read your code.<br>

#### Formatting

* Use spaces for indentation instead of tabs -- you may use 2, 4, or 8 spaces, but the important thing is to be consistent
* Consider line length (80 characters or fewer in most cases)
* Avoid use of non-ASCII characters
* Be intentional with your usage of vertical and horizontal whitespace

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

Use common sense and BE CONSISTENT.<br>

The point of having style guidelines is to have a common vocabulary of coding so all contributors can concentrate on what the code is doing, rather than how the code is written. Consistency should not be used as an excuse to avoid making changes that improve your code. These global style rules help make sure everyone is on the same page; however, local style is also important.<br>

To an extent, you can choose your own style (you don't need to exactly match the Google C++ Style Guide specifications); however, remember to strive for readability, consistency, and providing enough documentation so that another person (or Future You) can easily understand what your code is doing. <br>

I will deduct points if your program is not well-formatted or you don't have sufficient and useful comments -- make sure to ask the instructor if you are unclear what is expected of you for this requirement.<br>

Remember to start early, take breaks, and ask for help if you're stuck. Writing code can be frustrating and stressful at times, but it can also be a really fun and enjoyable challenge!

[Top of the Page](#csci-211-style-guide)
