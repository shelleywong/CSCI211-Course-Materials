# Programming Assignments

Over the course of the semester, there will be 7 programming assignments. All programs must be completed individually. Each assignment contains program-specific requirements. All assignments should follow the General Requirements listed below. You may be asked to explain your code to the instructor or a lab assistant during lab time or office hours, and if you are unable to adequately do so, a percentage may be taken off your grade for that assignment. Programming assignments must be turned in to [INGInious](https://inginious.csuchico.edu/) by the due date (check INGInious or Canvas to confirm).

* [Program 1: Chart](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program01.md)
* [Program 2: Video Rating System](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program02.md)
* [Program 3: Linked List of Video Objects](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program03.md)
* [Program 4: Post-fix Calculator](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program04.md)
* [Program 5: Kwik-E-Mart Simulation](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program05.md)
* [Program 6: Shapes Drawing Program](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program06.md)
* [Program 7: Binary Search Tree](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program07.md)

## General Requirements

Your first goal is to make sure your code is correct and passes all tests; however, it is also important to think about writing code that is readable and easy to maintain. The projects in this course are relatively small individual assignments. In the real world, you will most likely be contributing to a large codebase with many contributors. Thus, it is good practice to follow style guidelines, be consistent, and write code that other engineers can easily understand.<br>

### Compiler

All programming assignments must be submitted to [INGInious](https://inginious.csuchico.edu/). Programs are expected to successfully compile and run in the INGInious environment. For CSCI 211, the INGInious grading environment uses GCC 11, from the [GNU Compiler Collection](https://gcc.gnu.org/). The [Docker container](https://hub.docker.com/r/javawolfpack/inginious-c-gcc11/tags) used by INGInious is also built into the Codespaces development environments available to repos in the CSUChico-CSCI211 organization.

### C++ Version

Currently, your code should target C++11 (your code will be compiled with the C++11 standard: `-std=c++11`). All assignments in this course can be completed with C++11 features. Outside of this class, you are likely to use newer versions of C++, but even then, you should consider portability to other environments before using features from C++14, C++17, C++20 and newer versions in your projects.

### Warnings

Programming assignments are compiled with the `-Wall` and `-pedantic` compiler options. `-Wall` enables all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning), while `-pedantic` issues all the warnings demanded by strict ISO C and ISO C++ (warnings print when non-standard C++ is used). If you receive a warning when your code compiles, you should address the warning, even if your code still runs. Ask the instructor if you have questions about how to address the warning.

### General Grading Criteria

Points vary for each program, but passing the tests is generally worth about 70% of each programming assignment grade while following instructions, including comments, and organizing your work is worth about 30% of the grade. Total points vary based on the difficulty of each programming assignment.

Getting your program to pass the provided tests is only one component of the programming assignments. Other grading components include:
* **Does your program pass the hidden tests?**
  * The provided tests may not cover all of the project specifications; it's your job to consider all potential cases.
  * It is helpful to create your own tests to address any additional cases.
* **Does your program follow the instructions?**
  * If the instructions say to use a particular data structure, make sure to use that data structure. If the instructions require the use of dynamic memory, make sure you've managed memory correctly.
  * There's a lot of information included in each assignment write-up, but all of it is there for a reason, and it is provided to help you succeed.
* **Have you included sufficient and useful comments?**
  * You are expected to have a file header (with brief file or class comments) in every file you submit.
  * You should also have comments for any non-trivial function and tricky/non-obvious/important code implementation.
* **Is your program well-formatted and organized?**
  * Refer to the [CSCI 211 Style Guide](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/style.md) for more details.<br>

> Note: The specific instructions may vary a bit for each programming assignment, but the following table shows a general example of how programs will be graded. For specific assignment grading criteria, look at the rubrics in Canvas.

| General Grading Criteria | Criteria Description |
| --- | --- |
| Tests | Program passes the tests:<br> :heavy_check_mark: You've addressed the Program Requirements (all requirements necessary to pass both the provided and hidden tests).<br> :heavy_check_mark: Program produces output that matches the expected standard output, standard error output, and exit status.<br> :heavy_check_mark: Program submitted to INGInious; successfully compiles. |
| Instructions | Program follows program instructions:<br> :heavy_check_mark: Your program fulfills all requirements outlined in the assignment, including those not explicitly tested by the testing script.<br> :heavy_check_mark: Implements the required data structures as outlined in the instructions.<br> :heavy_check_mark: Appropriate member access control – member variables are private, member functions are only public if they need to be used outside the class).<br> :heavy_check_mark: Uses dynamically allocated memory (new and delete), and memory is managed correctly.<br> :heavy_check_mark: Appropriate location for different requirements (e.g. error messages printed from main(), not from a class, because the error messages are not part of the class), etc.<br> :heavy_check_mark: Specific instructions vary based on the assignment. |
| Comments | Program includes comments and file headers:<br> :heavy_check_mark: You’ve included a complete file header in each file that includes the name of the file, your full name, your INGInious username, and a brief description of the contents of the file.<br> :heavy_check_mark: You’ve included sufficient, useful, and accurate comments for non-trivial functions and any implementation of code that may not be obvious to another person looking at the code (or you in the future).<br> :heavy_check_mark: Comments should help explain the reasoning behind decisions (comments that just repeat what the code does have limited usefulness).<br> :heavy_check_mark: Excessive comments can make your code more difficult to read – do not add comments to every line. |
| Organization | Program follows style guidelines:<br> :heavy_check_mark: Names for variables, functions, types, and objects should clearly convey their purpose or intent.<br> :heavy_check_mark: Variables declared in the proper scope (close to where they are used).<br> :heavy_check_mark: Avoid using magic numbers; use ‘const’ for variables that will not be modified.<br> :heavy_check_mark: Class declarations and function prototypes are put in the .h header file, and class function definitions are put into the .cpp implementation file.<br> :heavy_check_mark: Functions are used (entire program is not in main()), and functions have a single, clear, focused responsibility (in general, try to keep functions to 40 lines or fewer).<br> :heavy_check_mark: Consistent indentation throughout entire program (use either spaces or tabs; use the same number of spaces for indentation throughout).<br> :heavy_check_mark: Uses braces around control flow statements. |

Ask the instructor if you have questions about any programming assignment expectations.

[Top of the Page](#programming-assignments)
