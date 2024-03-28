# CURE-E Final Project

Based on **Cultivating a Culture of Entrepreneurship Mindset and Undergraduate Research – CEMUR**<br>
Funded by The National Science Foundation’s Improving Undergraduate STEM Education: Hispanic-Serving Institutions (HSI Program) Award # 1953751<br>

# Project Objectives

* Use [scientific practices](https://undsci.berkeley.edu/lessons/pdfs/complex_flow_handout.pdf) and work on a problem that does not have a known solution
* Apply knowledge and experience gained from classroom assignments to real-world data
* Potentially make a discovery that is relevant to stakeholders beyond the classroom
* Cultivate [entrepreneurial mindset](https://nfte.com/entrepreneurial-mindset/) skills and develop the ability to recognize opportunity, take initiative, and innovate in the face of challenges

## Project Requirements

* [Your Computer Program](#your-computer-program)
* [Your README Guide](#your-readme-guide)
* [Your Visual Representation](#your-visual-representation)
* [Presentation Part 1: Your Elevator Pitch Presentation](#presentation-part-1-your-elevator-pitch-presentation)
* [Presentation Part 2: Your Demonstration Recording](#presentation-part-2-your-demonstration-recording)
* [Your Self-Assessment](#your-self-assessment)

## Project Overview

The goal of the CURE-E Research Project is to give you an opportunity to apply concepts covered in class toward solving a problem with a real-world dataset. Students will create a data management program that uses data structures and algorithms to organize, analyze, and provide insight on publicly available weather data for Chico, CA. Data can be sourced from the National Oceanic and Atmospheric Administration (NOAA), which provides a large database of historical data related to weather, precipitation, and climate. Students will develop research questions that can be explored and answered with the data and identify relevant community members or groups who would benefit from this information.<br>

Assignments will include one final project, several collaborative work and discussion sessions (stem entrepreneurial mindset, question formulation, lab time), a presentation, and a reflection survey. The final project will require a README guide that explains how the program works and how others can use the program. The work and discussion sessions will be completed during class in small groups. Students will present their work to the class on the day of the final. Presentations will include a visual representation to help others understand the project results (e.g. a poster or infographic).<br>

## Introduction

The lab exercises and programming assignments in this class allow you to develop your understanding of fundamental data structures and algorithms, improve your programming ability, and practice your problem-solving skills, but they are all relatively small problems that have well-defined boundaries. You are given detailed guidelines and nicely organized input, and everyone is expected to get the exact same output.<br>

The goal of the CURE-E Project is to give you an opportunity to apply what you have learned to a real-world dataset and address some problems with unknown solutions. This project takes ideas from [authentic learning](https://www.edglossary.org/authentic-learning/) experiences, which focus on connecting what students are taught in school to real-world issues, problems, and applications.<br>

CURE-E projects are opportunities for learning! You may not end up with your expected outcome, or you may need to try various approaches before finding one that works. When it comes to research and projects with unknown outcomes, this is normal -- you will be faced with failure and the need for iteration all the time in the real world (if you aren't already familiar...). In academic research, all results can contribute new knowledge and insight, even if they are not the results you wanted or expected. In software development, a project is rarely ever "finished" -- it is a continuous process of refining, enhancing, and adapting to meet evolving requirements, and regular improvements are key to providing the best possible user experience.<br>

With that in mind, your grade for this project will not be based on your results matching an expected or predetermined outcome. Rather, your grade will be based on a variety of final deliverables (a working program, a README guide, presentation (part 1 and 2), visual representation, and self-assessment), as well as your iterative work in the process of completing the project (entrepreneurial mindset discussion response, in-class QFT activity, your proposal, and regular git commits to your CSCI211 git repo). I will consider your ability to generate innovative ideas, adapt to challenges, and write a program to solve a problem that you have not encountered before.

## Attitude

Entrepreneurial Mindset: Flexible and Adaptable, Creative and Innovative, Initiative and Self Reliance, Communicate and Collaborate, Critical Thinking and Problem Solving, Opportunity Recognition, Comfort with Risk, Future Orientation

## Preparation

* Come to this project with an Entrepreneurial Mindset
* (Optional) Form a group of 3-4 students: have everyone in the group aim to provide insights for a specific stakeholder, with each individual answering a different question for that stakeholder.
* Obtain a dataset, determine a stakeholder, and develop questions for each individual (the QFT activity was meant to help you complete this step)

## Process

Note: All files and folders related to your project (the code for your program, your README guide, the dataset files, Makefiles, scripts to run your code, etc) should be in a single directory located directly inside your CSUChico-CSCI211 repo -- you should give the directory a name that clearly indicates that it contains your CURE-E Final Project, e.g. `CSCI211-S24-FirstName-LastName/final-project/` or `CSCI211-S24-FirstName-LastName/cure-e/`).

## Final Project Components

### Your Computer Program

You will write a program that provides insight on Your Question (developed during the QFT activity). Your program must:
* Include an object-oriented C++ implementation of an abstract data type (ADT) discussed in CSCI 211 (linked list or array-based stack, queue, priority queue (or ordered list), or binary tree).
  * You may use Standard Template Library containers in conjunction with your ADT implementation (e.g. a std::vector of linked lists); however, you should **not** just rely on a Standard Template Library container for your ADT. Using a STL vector, queue, stack, list, map, etc is not the same as you implementing an ADT with a linked list or array-based data structure.
* Include a class or struct for your input data (e.g. to represent a single day of data, at a single station).
* Get input from the dataset or converted input file, add all entries to your ADT, and have the ability to print all entries in a readable format.
  * Code that reads and parses data from the chosen dataset should be correct, able to handle different data types and formats, and able to handle any empty entries appropriately, depending on the data type.
  * If you have default output, you do not need to print all entries in the default output; however, you should provide a way for users to easily print all entries (i.e. provide a `print()` function in the ADT class)
  * The printed output should make it clear what different values represent (e.g. if you are printing a numeric value like temperature, don't just print the number -- include some information that indicates that it is (for example) the max temperature measured in degrees Fahrenheit or Celsius)
* Include at least one unique algorithm that provides insight on Your Question and prints out that information
  * Prints results to the terminal or output file in a clear and effective manner
  * Algorithm is correct and effective at providing insight and addressing the research question (Recall that an algorithm is just a sequence of instructions to perform a task -- I am looking for your program to perform a task that helps provide accurate insight on Your Question)
  * Creativity and originality (there should be some functionality that goes beyond basic searching, sorting, traversal-type algorithms)
* Use well-organized classes and/or structs:
  * The class or struct has a clear and concise purpose, and its responsibilities align with a single, well-defined concept
  * Appropriate use of member access specifiers (e.g. private member variables, private member functions (if not used outside the class), public member functions to allow for external interaction)
  * Class declaration and function prototypes in .h file, and class implementation in a separate .cpp file (makes it easier for external code to understand the class structure without exposing implementation details)
  * Only use a data structure if you are simply representing a group of data elements grouped together under one name (in general, if you have functions/behavior, you should use a class)
* Use dynamically allocated memory and properly manage that memory
  * You should either use `new` and `delete` or smart pointers and ensure that there are no memory leaks
* Follow the [CSCI 211 Style Guide](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/README.md#style-guide-overview)
  * This includes: good variable and function names, appropriate use of different types of variables, use of functions, appropriate scope for variables and functions, consistent indentation, etc
* Include comments/documentation
  * File headers (filename, your name (first and last), your Chico Portal/INGInious username, and a short summary of the contents of the file)
  * Descriptive and helpful comments in the body of the code<br>

I will be testing your code in an environment where you can compile code with the GNU g++ compiler (similar to what we have used all semester on INGInious, ecc-linux, WSL2, or an Ubuntu (Linux) virtual machine). You will lose points if your code does not compile, or if your code compiles but terminates unexpectedly when executed (e.g. segmentation fault, aborted (core dumped) error).<br>

Move into your CSCI211 repo and create a new directory for your project (you can give the project any name that you choose, as long as it is clear that the directory contains your CURE-E final project):
```
$ mkdir cure-e-project
```

Move into this directory and add any project-related files to this directory. At the end of the semester, I will expect to see (at minimum) the class files for your ADT implementation (.h and .cpp files), a main.cpp file for running your program, an input file, and a README.md file. You will likely also have class files for your data entries (e.g. each instance represents the data from one day). You may have a separate file for the original dataset (e.g. a CSV file) as well as an input file for the data (e.g. in the format used in CSCI 211). You may have another input file with commands that I can use to run your program. You may have a Makefile and/or a script to run your program, or you may just include instructions/commands for running your program in the README.md file. Other files may be necessary depending on your project; feel free to ask if you have questions about how to set up your project directory. Since everyone's output will be different, there will be no test output files, but if you create output files in your program, you can leave them in the directory as a reference.<br>

I will have an example program that converts data from a CSV file to the format used in the CSCI 211 programming assignments. You can get the data directly from the dataset (.csv file or other format), or you can use something similar to my program to create an input file that looks like the input you have used throughout the semester.<br>

You must use your CSCI211 git repository for your CURE-E Final Project computer program and have at least 5 commits made to the repository for your program's source code. You are not required to have commits for each of the following, but these are all points at which it would be a good idea to make a commit:
* **Initial commit** that includes the project's initial setup (e.g. a new directory, setting up the project structure, adding any necessary project files).
* **Creation of a C++ class or struct for your data entries** (e.g. every Node in your ADT may contain pointers to instances of this class)
* **Creation of a C++ class for your ADT** (define the class and its methods; doesn't need to be complete, but can include some basic implementation)
* **Input file parsing** (successfully read input data from a file -- either add data to your ADT or simply print it out to confirm that you are parsing the data as desired for your program)
* **ADT populating** (if you haven't already, make sure to insert entries made up of the parsed data into your ADT. The input data may have empty entries -- make sure you handle these entries appropriately, depending on the data type).
* **Basic output** to print the contents of your ADT in a readable format (make sure you can successfully interact with your data structure). This requires the creation of a method in your ADT class - how the entries are organized is up to you, but you should be able to explain why the entries are organized in the way you have chosen.
* **Algorithm implementation** (complete your unique algorithm that provides insight on Your Question (requires the creation of at least one method that implements your algorithm in your ADT class)
* **Insightful output** (display the results of your algorithm in a way that is clear and informative)
* **Testing and debugging** (remember to make commits to resolve bugs and other issues throughout your development process)
* **Final commit** (once your project is complete and ready for submission, make a final commit and ensure that your code is well-organized, commented, and adheres to good coding practices)
<br>

Your program must be submitted through your CSUChico-CSCI211 GitHub repo on your default branch (usually called the `main` branch). Remember to make at least 5 commits for the source code of your program, and at least 1 more commit for the README guide. Also remember that the same style and readability guidelines that we have used throughout the semester apply to this project!

Each time you commit your code to GitHub, you should be completing the following steps (the `add` command with the `-A` option updates all files in the working tree):
```
$ git add -A
$ git commit -m "<descriptive commit message>"
$ git push origin main
```

After you have made this commit (or multiple commits for this task), submit to Canvas one of the following:

* a text entry that contains the date of the commit(s) and the commit message(s)
* a website URL -- a link to the commit in your git repo (let me know if you are not sure what I mean by this)

### Your README Guide

In the git repository for your program, you should have a README.md file in the root of your project directory that contains information about your project. Use GitHub's [Basic writing and formatting syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax). You should have at least one commit for your README guide (in addition to the commits made for your program's source code). At minimum, your README.md file should include:

* **Your full name**
* **Your Chico State/INGInious username**
* **Course and section information** (e.g. CSCI 211 Programming and Algorithms II, Spring 2024)
* **A list of the files/directories in the repo** and a brief description of what each file/directory contains
* **An overview of your project**
  - A brief description of your project (Include any descriptive background details that can help explain the thinking behind your research question and project)
  - Your research question(s)
  - Stakeholders (who could benefit from this information and insight?)
* **A brief explanation of your problem-solving approach**
  - Briefly describe how you approached the problem
  - What were some key variables/inputs that were relevant to the problem?
  - Which ADT did you choose, and why did you choose it?
* **Explain how a user can use your program**
  - You should include details about how a user can run your program once they have access to your repo:
    - What specific command(s) should a user use to compile your program and create an executable? If you have a makefile or script, you should say so and make sure that it is clear how to use it.
    - What specific command(s) should a user use to run/execute your program? You might have an input file that users can run to see how your code works, or you might provide a list of commands (or other detailed instructions) that users can run to see how your code works.<br>

Remember to commit your changes so I can see your README guide in the repo (this process is just like how you commit the rest of your code):
```
$ git add -A
$ git commit -m "<descriptive commit message>"
$ git push origin main
```

After you have made this commit (or multiple commits for this task), submit to Canvas one of the following:

* a text entry that contains the date of the commit(s) and the commit message(s)
* a website URL -- a link to the commit in your git repo (let me know if you are not sure what I mean by this)

### Your Visual Representation

Create a visual that can help represent your work and aid you during your presentation. Your visual can be similar to a [research poster](https://guides.nyu.edu/posters), but simpler (fewer words and sections) and smaller (just a normal slide -- I should NOT need to zoom in to read your text, it should be visible clearly when the slide is shared from a computer screen). When you are thinking about what to include on your visual, you should consider the following questions:<br>

* What is the most important/interesting/astounding finding from my project?
* How can I visually share my research with the audience? Would charts, graphs, photos, images, key pieces of data, or something else be the best way to share my results?
<br>

Focus on creating a visual that helps you share your findings and any insight gained from working on the research question. You might include a small amount of text (e.g. your research question, some text to help interpret the visual or highlight a statistic or other finding), but all information should be readable from the audience.<br>

Some other things that make for a good poster (or any academic presentation visual):
* Any graphs/charts included are well-labeled and accurate -- they should play a clear role in helping visualize your results
* Text is clear and to the point
* Use of bullets, numbering, and headlines (make it easy to read)
* Effective use of graphics, color, and fonts
* Consistent and clean layout<br>

Probably the easiest option for creating your visual representation (e.g. poster, image, or infographic), is to use a single presentation slide (e.g. PowerPoint or Google Slides). The visual can be shared online, or you can bring a physical copy of it to the presentation.<br>

### Presentation Part 1: Your Elevator Pitch Presentation

During the time of the scheduled final for this class, we will have elevator pitch presentations for your projects. You will use your visual representation during your elevator pitch to help enhance understanding, clarify concepts, and engage the audience. Elevator pitch presentations should be about 1-3 minutes.<br>

An [elevator pitch](https://drive.google.com/file/d/16yYhMlI2md_-bMGilXNKFnMZabcY-tuc/view) is a short speech or introduction that describes who you are and what you do and leaves the listener wanting to know more or take action. In addition to the traditional elevator pitch details, you will need to provide a brief description of your findings.<br>

**Prepare**: Think about your project. Write notes on what value it adds to people or the customer. What impact does it or will it have? Who is most interested in what you are offering?<br>

Your elevator pitch project presentation should include:
1. One sentence about who you are.<br>
2. One or two sentences providing some context about your project's research/design challenge and the problem you are trying to help solve or provide insight about.<br>
3. One or two sentences describing who will benefit from the solution and what value you are offering.<br>
4. One or two sentences that explains your approach. If there is anything different or unique about your approach that sets you apart, make sure to mention it.<br>
5. Now ask your research question -- engage your audience and bring them into your conversation, so they share your passion or pain.<br>
6. Give a sneak peak of your findings (whether or not your findings match your expectations, they can still provide useful information!) Don't worry about explaining your findings, just let everyone know your results and how they can find out more about your project.<br>

You do not need to explain every detail. Including a couple technical details may be useful, but your presentation should be understandable for a non-technical audience. Keep it short, memorable, and impactful. For the most part, I will not be grading you on how good you are at giving presentations, but I recommend practicing a bit so that your transitions flow well and your presentation is conversational and engaging.<br>

Note: if you will not be able to attend in-person during the time of our scheduled final, you may (a) attend the final virtually and synchronously, giving your elevator pitch presentation through Zoom, or (b) record your elevator pitch presentation and submit it to Canvas (in this case, you will be submitting two recordings to Canvas).

### Presentation Part 2: Your Demonstration Recording

The presentation has been split into two parts to make sure everyone has time to present their project. This portion of the presentation should be recorded, and the recording should be submitted to Canvas. The goal of this part of the presentation is for you to demonstrate how to use your program, show that your program is working and getting results, provide some context about your work, and discuss any personal insights. I am expecting this recording to be about 1-5 minutes.

Your demonstration recording should include:
* A demonstration of yourself compiling and executing your program. If needed, provide some explanation about how I should interpret your output.
* Some context about your work and your experience developing this project, e.g. a brief discussion of any challenges you faced and how those challenges were resolved.
* Any personal insight, e.g. What did you find most interesting or rewarding about working on this project? Have you identified any additional questions, next steps, or avenues for future research or projects?<br>

Just like with the elevator pitch, you do not need to explain every detail. Including a couple technical details may be useful, but your presentation should be understandable for a non-technical audience. Keep it short, memorable, and impactful. Your recording does not have to look professional, but you should speak clearly and any visuals (code, text output, images, etc) should actually be visible.<br>

### Your Self-Assessment

Near the end of the semester, you will be asked to complete a self-assessment survey. Self-assessment at the end of a project is an important way for you to take stock of your journey, learn from your experiences, and apply those lessons to future endeavors. Self-assessments contribute to a cycle of continuous improvement, skill development, and personal growth. You will receive full credit for completing the survey (you will not be graded on your responses). The survey will be made available later in the semester on Canvas.
