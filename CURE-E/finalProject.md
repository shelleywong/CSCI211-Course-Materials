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

The lab exercises and programming assignments in this class allow you to develop your understanding of fundamental data structures and algorithms, improve your programming ability, and practice your problem-solving skills, but they all are relatively small examples that have well-defined boundaries. You are given detailed guidelines and nicely organized input, and everyone is expected to get the exact same output. The goal of the CURE-E Project is to give you an opportunity to apply what you have learned to a real-world dataset and address some problems with unknown solutions. This project takes ideas from [authentic learning](https://www.edglossary.org/authentic-learning/) experiences, which focus on connecting what students are taught in school to real-world issues, problems, and applications.<br>

CURE-E projects are opportunities for learning! Failure and repetition are normal and expected components of research and other projects with unknown outcomes. Similarly, software development is a continuous process of refining, enhancing, and adapting to meet evolving requirements. Regular iterations and improvements are important for providing the best possible user experience.<br>

Your grade for this project will not be based on your results matching an expected or predetermined outcome. Rather, your grade will be based on your final deliverables (a working program, documentation, presentation, visual representation, and self-assessment) and completion of each steps of the process. I will consider your ability to generate innovative ideas, adapt to challenges, and write a program to solve a problem that you have not encountered before.

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
* [Your Presentation](#your-presentation)
* [Your Self-Assessment](#your-self-assessment)

## Process

### Your Computer Program

You will write a computer program that provides insight on Your Question (developed during the QFT activity). Your program must utilize an abstract data type (ADT) discussed in CSCI 211 (linked list, stack, queue, priority queue, or binary tree), and you must implement a C++ class for your ADT. Your program should get input from a file, add all entries to your ADT, print all entries in a readable format, and include at least one unique algorithm that provides insight on Your Question and prints out that information.<br>

Move into your CSCI211 repo and create a new directory for your project (you can give the project any name that you choose):
```
$ mkdir cure-e-project
```

Move into this directory and add any project-related files to this directory. At the end of the semester, I will expect to see (at minimum) the class files for your ADT implementation (.h and .cpp files), a main.cpp file for running your program, an input file, and a README.md file. You may have a separate file for the original dataset (e.g. a CSV file) as well as an input file for the data (e.g. in the format used in CSCI 211). You may have another input file with commands that I can use to run your program. You may have a Makefile and/or a script to run your program, or you may just include instructions/commands for running your program in the README.md file. Other files may be necessary depending on your project; feel free to ask if you have questions about how to set up your project directory. Since everyone's output will be different, there will be no test output files, but if you create output files in your program, you can leave them in the directory as a reference.<br>

I will have an example program that converts data from a CSV file to the format used in the CSCI 211 programming assignments. You can get the data directly from the dataset (.csv file or other format), or you can use something similar to my program to create an input file that is similar to the input you have used throughout the semester.<br>

You must create a git repository for your program and have at least 4 commits made to the repository for the following steps:
* Creation of a C++ class for your ADT
* Program successfully gets input from a file
* Program successfully adds entries to your ADT
* Program successfully prints all entries in a readable format (requires the creation of a method in your ADT class)
* Program successfully prints out insight on Your Question (requires the creation of at least one method that implements your algorithm in your ADT class)<br>

Your computer program will be submitted through your GitHub repo. Remember to make at least 4 commits for the program, and at least 1 more commit for the documentation.

### Your Documentation

In the git repository for your program, you should have a README.md file in the root of your directory that contains information about your project. Use GitHub's [Basic writing and formatting syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax). You should have at least one commit for your documentation. At minimum, your README.md file should include:

* Your full name
* Your Chico State/INGInious username
* Course and section information (e.g. CSCI 211 Programming and Algorithms II, Fall 2023)
* A list of the files/directories in the repo and a brief description of what the files/directories contain
* An overview of your project
  - Any descriptive background details
  - Your research question(s)
  - Stakeholders (who could benefit from this information and insight?)
* An explanation of your problem-solving approach
  - Briefly describe how you approached the problem
  - What were some key variables/inputs that were relevant to the problem?
  - Which ADT did you choose, and why did you choose it?
* Describe the process
  - Did you run into any challenges? Did you need to do any debugging or troubleshooting? Did you need to create several iterations of your algorithm before landing on one that worked?
  - Discuss any issues you ran into and how you resolved them (any tools, techniques, or strategies you employed).
* Explain how a user can use your program
  - You should include details about how a user can run your program once they have access to your repo (How do I execute your program? Do you have a makefile? Do you have a script? Is there a specific command I should run?)
  - You should either (1) create an input file that I can run to see how your code works or (2) provide detailed instructions for the commands I can run to see how your code works.<br>

Remember to commit your changes so I can see your documentation in the repo.

### Your Visual Representation

Create a visual that can help represent your work and aid you during your presentation. Your visual can be similar to a [research poster](https://guides.nyu.edu/posters), but simpler and smaller (fewer words and sections). When you are thinking about what to include on your visual, you should consider the following questions:<br>

* What is the most important/interesting/astounding finding from my project?
* How can I visually share my research with the audience? Should I use charts, graphs, photos, images?
* What kind of information can I convey during my presentation that will complement my poster?<br>

Some other things that make for a good poster (or any academic presentation visual):
* Important information is readable from the audience
* Text is clear and to the point
* Use of bullets, numbering, and headlines (make it easy to read)
* Effective use of graphics, color and fonts
* Consistent and clean layout<br>

Probably the easiest option for creating your visual representation (e.g. poster or infographic), is to use one presentation slide (e.g. PowerPoint or Google Slides). The visual can be shared online, or you can bring a physical copy of it to the presentation.<br>

### Your Presentation

On the day of the final, everyone will give short presentations about their project to the class. You will use your visual representation to help enhance understanding, clarify concepts, and engage the audience. Presentations (including Q&A time) should be no more than 5 minutes.<br>

Your presentation will start in the style of an [elevator pitch](https://drive.google.com/file/d/16yYhMlI2md_-bMGilXNKFnMZabcY-tuc/view): a short speech or introduction that describes who you are and what you do and leaves the listener wanting to know more or take action.<br>

After your elevator pitch (about 30-90 seconds of your presentation), there will be a couple more minutes for you to discuss your contribution and respond to any questions.<br>

**Prepare**: Think about your project. Write notes on what value it adds to people or the customer. What impact does it or will it have? Who is most interested in what you are offering?<br>

Your elevator pitch should include:
1. One sentence about who you are<br>
2. One or two sentences describing your research question or project design challenge.<br>
3. One or two sentences describing the problem you are trying to help solve or provide insight about. Describe who will benefit from the solution and what value you are offering.<br>
4. One or two sentences that describes your approach and how it is different or sets you apart from other approaches.<br>
5. A question that engages your audience and brings them into your conversation, so they share your passion or pain.<br>

Normally, an elevator pitch ends with a call to action (one or two sentences about how they can learn more or get involved). In your case, you will finish with the following information:
* A brief description of your findings (whether or not your findings match your expectations, they can still provide useful information!)
* Some context about your work, e.g. a brief discussion of any challenges you faced and how those challenges were resolved.
* Any personal insight, e.g. What did you find most interesting or rewarding about working on this project? Do you see any next steps or future direction for your project?<br>

Don’t be tempted to explain every detail. Including a couple technical details may be useful, but your presentation should be understandable for a non-technical audience. Keep it short, memorable, and impactful. For the most part, I will not be grading you on how good you are at giving presentations, but I recommend practicing a bit so that your transitions flow well and your presentation is conversational and engaging.<br>

### Your Self-Assessment

Near the end of the semester, you will be asked to complete a self-assessment survey. Self-assessment at the end of a project is an important way for you to take stock of your journey, learn from your experiences, and apply those lessons to future endeavors. Self-assessments contribute to a cycle of continuous improvement, skill development, and personal growth. You will receive full credit for completing the survey (you will not be graded on your responses). The survey will be made available later in the semester on Canvas.