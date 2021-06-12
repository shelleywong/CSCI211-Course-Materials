# Programming Assignments

Over the course of the semester, there will be 7 programming assignments. All programs must be completed individually. Each assignment contains program-specific requirements. All assignments should follow the General Requirements listed below. You may be asked to explain your code to the instructor or a lab assistant during lab time or office hours, and if you are unable to adequately do so, a percentage may be taken off your grade for that assignment. Programming assignments must be turned in to [Turnin](https://turnin.ecst.csuchico.edu/) by the due date (check Turnin or Blackboard to confirm).

* [Program 1: Chart](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program01.md)
* [Program 2: Video Rating System](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program02.md)
* [Program 3: Linked List of Video Objects](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program03.md)
* [Program 4: Post-fix Calculator](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program04.md)
* [Program 5: Kwik-E-Mart Simulation](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program05.md)
* [Program 6: Shapes Drawing Program](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program06.md)
* [Program 7: Binary Search Tree](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program07.md)

## General Requirements

Your first goal is to make sure your code is correct and passes all tests; however, it is also important to think about writing code that is readable and easy to maintain. The projects in this course are relatively small individual assignments. In the real world, you will most likely be contributing to a large codebase with many contributors. Thus, it is good practice to follow style guidelines, be consistent, and write code that other engineers can easily understand.<br>

These guidelines borrow heavily from the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html):<br>
“Google C++ Style Guide,” Accessed on: Jun. 4, 2021. [Online]. Available: [https://google.github.io/styleguide/cppguide.html](https://google.github.io/styleguide/cppguide.html)

### C++ Version

Currently, your code should target C++11 (your code will be compiled with the C++11 standard: `-std=c++11`). All assignments in this course can be completed with C++11 features. Outside of this class, you are likely to use newer versions of C++, but even then, you should consider portability to other environments before using features from C++14, C++17 and newer versions in your projects.

### Reminder

Getting your program to pass the provided tests is only one component of the programming assignments. Other grading components include:
* **Does your program pass the hidden tests?** The provided tests may not cover all of the project specifications; it's your job to consider all potential cases.
* **Does your program follow the instructions?** If the instructions say to use a particular data structure, make sure to use that data structure. If the instructions require the use of dynamic memory, make sure you've managed memory correctly.
* **Have you included sufficient and useful comments?** You don't need to be overly verbose or have comments on every line, but you are expected to have file, function, class, variable, and/or implementation comments in every file you submit.
* **Is your program well-formatted and organized?** Things to consider include proper and consistent indentation, descriptive variable names, and usage of functions.

### Style Guide Overview

Your program should be neatly organized, consistently indented, and have informative comments throughout. Avoid surprising or dangerous constructs that an average C++ programmer would find tricky or difficult to maintain. Refer to the CSCI 211 Style Guide (on Blackboard) for more details on each of these categories. Things to focus on include:
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

### Classes

* Think about **access control**:
  * member variables are usually `private`
  * only make members `public` if you want them to be accessible outside of the class
* Group similar declarations together
* Do **not** implement large methods in the class definition

### Functions

* Create small and focused functions to solve specific tasks
* Be thoughtful about how you use parameters and return values<br>

The `main()` function is the first function that's called when a C++ program begins execution. While it is possible to write an entire program in `main()`, you should try to separate the functionality of a program into independent modules (think of each module/function as a small program that executes a specific task). The `main()` should just be used as a driver to call other functions.<br>

Consider how your program could be divided into subtasks, and put each subtask into its own function. Define your function prototypes near the top of your program and write the functions after your `main()`.

### Naming

* Be consistent
* Use descriptive and sensible names for:
  * files
  * types (e.g. classes, structs)
  * variables (includes function parameters, class member variables)
  * functions
* Optimize for readability, avoid ambiguity, and minimize the use of abbreviations
* it is fine to use certain universally-known abbreviations, such as `i` for a loop iterator
* For files, make sure your file names match those listed in the writeup
* For example, you could use:
  * snake_case for variables (words separated by underscores): `a_local_variable`
  * PascalCase for types (each new word begins with a capital letter): `MyExcitingClass`
  * camelCase for functions (each words begins with a capital letter, except the first word): `addTableEntry()`
  * all lowercase, no underscores for file names: `myusefulclass.cpp`

> Note: In this course, file names should be all lowercase (e.g. "chart.cpp"). When a program uses classes, the class .h and .cpp files will use lowercase names, but the classes themselves should be named with a capital letter (e.g. `Video`)<br>

### Comments

* Comments are vital for keeping code readable, but the best code is self-documenting (this is why naming is so important)
* Write comments for an audience/the next contributor/Future You
* Use either `//` or `/* */` syntax, as long as you are consistent
* Don't be unnecessarily verbose or state the obvious; however, remember to think about the next contributor.
* You must include comments at the beginning of each files.

The first lines of all your files (.h and .cpp) must contain the following comments (use either `//` or `/* */` syntax):
```
// filename
// your name (first and last)
// your Chico Portal/Turnin username
// Short summary of the contents of the file
```

* Throughout your program, you should have brief comments describing how sections of code work. You shouldn't need a comment on every line, but consider including comments:
  * Before each **function** declaration and/or implementation: describe what the function does and how it is used. For trivial functions that are named appropriately, it's ok to skip the comment.
  * At the beginning of each **class**: describe what the class is for and how it is used.
  * Alongside **variable declarations** (if necessary -- it's better to have variable names that are descriptive enough to not require additional comments)
  * Alongside any code **implementation** that is tricky, non-obvious, interesting, or important -- anything that will help the next person who needs to read your code.<br>

#### Formatting

* Use spaces for indentation instead of tabs -- you may use 2, 4, 6, or 8 spaces, but the important thing is to be consistent
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

The point of having style guidelines is to have a common vocabulary of coding so all contributors can concentrate on what the code is doing, rather than how the code is written. These global style rules help make sure everyone is on the same page; however, local style is also important.<br>

To an extent, you can choose your own style (you don't need to exactly match the Google C++ Style Guide specifications); however, remember to strive for readability, consistency, and providing enough documentation so that another person (or Future You) can easily understand what your code is doing. <br>

I will deduct points if your program is not well-formatted or you don't have sufficient and useful comments -- make sure to ask the instructor if you are unclear what is expected of you for this requirement.<br>

Remember to start early, take breaks, and ask for help if you're stuck. Writing code can be frustrating and stressful at times, but it can also be a really fun and enjoyable challenge!
