# CURE-E Final Project

Based on **Cultivating a Culture of Entrepreneurship Mindset and Undergraduate Research – CEMUR**<br>
Funded by The National Science Foundation’s Improving Undergraduate STEM Education: Hispanic-Serving Institutions (HSI Program) Award # 1953751<br>

# Project Objectives

* Use [scientific practices](https://undsci.berkeley.edu/lessons/pdfs/complex_flow_handout.pdf) and work on a problem that does not have a known solution
* Apply knowledge and experience gained from classroom assignments to real-world data
* Potentially make a discovery that is relevant to stakeholders beyond the classroom
* Collaborate with peers and practice communication skills
* Cultivate flexibility, adaptability, creativity, and innovation skills

## Project Overview

The goal of the CURE-E Research Project is to give you an opportunity to apply concepts covered in class toward solving a problem with a real-world dataset. Students will create a data management program that uses data structures and algorithms to organize, analyze, and provide insight on publicly available weather data for Chico, CA. Data can be sourced from the National Oceanic and Atmospheric Administration (NOAA), which provides a large database of historical data related to weather, precipitation, and climate. Students will develop research questions that can be explored and answered with the data and identify relevant community members or groups who would benefit from this information.<br>

Assignments will include one final project, several collaborative work and discussion sessions, and a presentation. The final project will require documentation that explains how the program works and how others can use the program. The work and discussion sessions will be completed during class in small groups. Students will present their work to the class on the day of the final. Presentations will include a visual representation to help others understand the project results (e.g. a poster or infographic).<br>

## Introduction

The lab exercises and programming assignments in this class allow you to develop your understanding of fundamental data structures and algorithms, improve your programming ability, and practice your problem-solving skills, but they are all relatively small problems that have well-defined boundaries. You are given detailed guidelines and nicely organized input, and everyone is expected to get the exact same output.<br>

The goal of the CURE-E Project is to give you an opportunity to apply what you have learned to a real-world dataset and address some problems with unknown solutions. This project takes ideas from [authentic learning](https://www.edglossary.org/authentic-learning/) experiences, which focus on connecting what students are taught in school to real-world issues, problems, and applications.<br>

CURE-E projects are opportunities for learning! You may not end up with your expected outcome, or you may need to try various approaches before finding one that works. When it comes to research and projects with unknown outcomes, this is normal -- you will be faced with failure and the need for iteration all the time in the real world (if you aren't already familiar...). In academic research, all results can contribute new knowledge and insight, even if they are not the results you wanted or expected. In software development, a project is rarely ever "finished" -- it is a continuous process of refining, enhancing, and adapting to meet evolving requirements, and regular improvements are key to providing the best possible user experience.<br>

With that in mind, your grade for this project will not be based on your results matching an expected or predetermined outcome. Rather, your grade will be based on a variety of final deliverables (a working program, documentation, presentation (part 1 and 2), visual representation, and self-assessment), as well as your iterative work in the process of completing the project (entrepreneurial mindset discussion response, in-class QFT activity, your proposal, and regular commits to your CSCI211 git repo). I will consider your ability to generate innovative ideas, adapt to challenges, and write a program to solve a problem that you have not encountered before.

## Attitude

Entrepreneurial Mindset: Flexible and Adaptable, Creative and Innovative, Initiative and Self Reliance, Communicate and Collaborate, Critical Thinking and Problem Solving, Opportunity Recognition, Comfort with Risk, Future Orientation

## Preparation

* Come to this project with an Entrepreneurial Mindset
* Form a group of 3-4 students: you will work from the same dataset and focus on the same stakeholder, but you will each have your own question to focus on.
* Obtain a dataset, determine a stakeholder, and develop questions for each group member (the QFT activity was meant to help you complete this step)

## Project Requirements

* [Your Computer Program](#your-computer-program)
* [Your Documentation](#your-documentation)
* [Your Visual Representation](#your-visual-representation)
* [Presentation Part 1: Your Elevator Pitch Presentation](#presentation-part-1-your-elevator-pitch-presentation)
* [Presentation Part 2: Your Demonstration Recording](#presentation-part-2-your-demonstration-recording)
* [Your Self-Assessment](#your-self-assessment)

## Process

Note: All files and folders related to your project (the code for your program, your documentation, the dataset files, Makefiles, scripts to run your code, etc) should be in a single directory located directly inside your CSUChico-CSCI211 repo -- you should give the directory a name that clearly indicates that it contains your CURE-E Final Project, e.g. `CSCI211-F23-FirstName-LastName/final-project/` or `CSCI211-F23-FirstName-LastName/cure-e/`).

### Your Computer Program

You will write a program that provides insight on Your Question (developed during the QFT activity). Your program must utilize an abstract data type (ADT) discussed in CSCI 211 (linked list, stack, queue, priority queue, or binary tree), and you must implement a C++ class for your ADT. Your program should get input from a file, add all entries to your ADT, print all entries in a readable format, and include at least one unique algorithm that provides insight on Your Question and prints out that information.<br>

Move into your CSCI211 repo and create a new directory for your project (you can give the project any name that you choose):
```
$ mkdir cure-e-project
```

Move into this directory and add any project-related files to this directory. At the end of the semester, I will expect to see (at minimum) the class files for your ADT implementation (.h and .cpp files), a main.cpp file for running your program, an input file, and a README.md file. You may have a separate file for the original dataset (e.g. a CSV file) as well as an input file for the data (e.g. in the format used in CSCI 211). You may have another input file with commands that I can use to run your program. You may have a Makefile and/or a script to run your program, or you may just include instructions/commands for running your program in the README.md file. Other files may be necessary depending on your project; feel free to ask if you have questions about how to set up your project directory. Since everyone's output will be different, there will be no test output files, but if you create output files in your program, you can leave them in the directory as a reference.<br>

I will have an example program that converts data from a CSV file to the format used in the CSCI 211 programming assignments. You can get the data directly from the dataset (.csv file or other format), or you can use something similar to my program to create an input file that looks like the input you have used throughout the semester.<br>

You must create a git repository for your program and have at least 5 commits made to the repository for your program's source code. You are not required to have commits for each of the following, but these are all points at which it would be a good idea to make a commit:
* **Initial commit** that includes the project's initial setup (e.g. a new directory, setting up the project structure, adding any necessary project files).
* **Creation of a C++ class or struct for your data entries** (e.g. every Node in your ADT may contain pointers to instances of this class)
* **Creation of a C++ class for your ADT** (define the class and its methods; doesn't need to be complete, but can include some basic implementation)
* **Input file parsing** (successfully read input data from a file -- either add data to your ADT or simply print it out to confirm that you are parsing the data as desired for your program)
* **ADT populating** (if you haven't already, make sure to insert entries made up of the parsed data into your ADT)
* **Basic output** to print the contents of your ADT in a readable format (make sure you can successfully interact with your data structure). This requires the creation of a method in your ADT class - how the entries are organized is up to you, but you should be able to explain why the entries are organized in the way you have chosen.
* **Algorithm implementation** (complete your unique algorithm that provides insight on Your Question (requires the creation of at least one method that implements your algorithm in your ADT class)
* **Insightful output** (display the results of your algorithm in a way that is clear and informative)
* **Testing and debugging** (remember to make commits to resolve bugs and other issues throughout your development process)
* **Final commit** (once your project is complete and ready for submission, make a final commit and ensure that your code is well-organized, commented, and adheres to good coding practices)
<br>

Your program must be submitted through your CSUChico-CSCI211 GitHub repo on your default branch (usually called the `main` branch). Remember to make at least 4-5 commits for the program, and at least 1 more commit for the documentation. Also remember that the same style and readability guidelines that we have used throughout the semester apply to this project!

Each time you commit your code to GitHub, you should be completing the following steps (the `add` command with the `-A` option updates all files in the working tree):
```
$ git add -A
$ git commit -m "<descriptive commit message>"
$ git push origin main
```

### Your Documentation

In the git repository for your program, you should have a README.md file in the root of your directory that contains information about your project. Use GitHub's [Basic writing and formatting syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax). You should have at least one commit for your documentation (in addition to the commits made for your program's source code). At minimum, your README.md file should include:

* **Your full name**
* **Your Chico State/INGInious username**
* **Course and section information** (e.g. CSCI 211 Programming and Algorithms II, Fall 2023)
* **A list of the files/directories in the repo** and a brief description of what each file/directory contains
* **An overview of your project**
  - Any descriptive background details
  - Your research question(s)
  - Stakeholders (who could benefit from this information and insight?)
* **A brief explanation of your problem-solving approach**
  - Briefly describe how you approached the problem
  - What were some key variables/inputs that were relevant to the problem?
  - Which ADT did you choose, and why did you choose it?
* **An overview of your experience developing this project**
  - Did you run into any challenges? Did you need to do any debugging or troubleshooting? Did you need to create several iterations of your algorithm before landing on one that worked?
  - Briefly explain any issues you ran into and how you resolved them (any tools, techniques, or strategies you employed).
* **Explain how a user can use your program**
  - You should include details about how a user can run your program once they have access to your repo (How do I execute your program? Do you have a makefile? Do you have a script? Is there a specific command I should run?)
  - You should either (1) create an input file that I can run to see how your code works or (2) provide detailed instructions for the commands I can run to see how your code works.<br>

Remember to commit your changes so I can see your documentation in the repo (this process is just like how you commit the rest of your code):
```
$ git add -A
$ git commit -m "<descriptive commit message>"
$ git push origin main
```

### Your Visual Representation

Create a visual that can help represent your work and aid you during your presentation. Your visual can be similar to a [research poster](https://guides.nyu.edu/posters), but simpler and smaller (fewer words and sections). When you are thinking about what to include on your visual, you should consider the following questions:<br>

* What is the most important/interesting/astounding finding from my project?
* How can I visually share my research with the audience? Should I use charts, graphs, photos, images, key pieces of data, or something else?
* What kind of information can I convey during my presentation that will complement my poster?<br>

Some other things that make for a good poster (or any academic presentation visual):
* Important information is readable from the audience
* Text is clear and to the point
* Use of bullets, numbering, and headlines (make it easy to read)
* Effective use of graphics, color and fonts
* Consistent and clean layout<br>

Probably the easiest option for creating your visual representation (e.g. poster or infographic), is to use one presentation slide (e.g. PowerPoint or Google Slides). The visual can be shared online, or you can bring a physical copy of it to the presentation.<br>

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

The presentation has been split into two parts to make sure everyone has time to briefly present about their project. This portion of the presentation should be recorded, and the recording should be submitted to Canvas. The goal of this part of the presentation is for you to demonstrate how to use your program, show that your program is working and getting results, provide some context about your work, and discuss any personal insights. I am expecting this recording to be about 1-5 minutes.

Your demonstration recording should include:
* A demonstration of yourself compiling and executing your program. If needed, provide some explanation about how I should interpret your output.
* Some context about your work, e.g. a brief discussion of any challenges you faced and how those challenges were resolved.
* Any personal insight, e.g. What did you find most interesting or rewarding about working on this project? Do you see any next steps or future direction for your project?<br>

Just like with the elevator pitch, you do not need to explain every detail. Including a couple technical details may be useful, but your presentation should be understandable for a non-technical audience. Keep it short, memorable, and impactful. Your recording does not have to look professional, but you should speak clearly and any visuals (code, text output, images, etc) should actually be visible.<br>

### Your Self-Assessment

Near the end of the semester, you will be asked to complete a self-assessment survey. Self-assessment at the end of a project is an important way for you to take stock of your journey, learn from your experiences, and apply those lessons to future endeavors. Self-assessments contribute to a cycle of continuous improvement, skill development, and personal growth. You will receive full credit for completing the survey (you will not be graded on your responses). The survey will be made available later in the semester on Canvas.
