# Lab 1

Set up, Intro to Linux, g++ compiler, Git

## Goals

* Set up your environment (CSCI211 GitHub repo, all the directories for the course assignments)
* Get an overview of Linux organization
* Introduce several basic Linux commands
* Practice creating, compiling, and running C++ programs
* Get experience testing your assignments (before submitting to INGInious)
* Get an overview of basic Git commands
* Work on Programming Assignment 01
<br>

Lab 01 Exercises:
* [Exercise 1: Setting up your CSCI 211 environment](#exercise-1-setting-up-your-csci-211-environment)
* [Exercise 2: Creating, compiling, and running a CPP program](#exercise-2-creating-compiling-and-running-a-cpp-program) (lab01_hello)
* [Exercise 3: Addition](#exercise-3-addition) (lab01_add)
* [Exercise 4: Say Hello](#exercise-4-say-hello) (lab01_print)

> Note: To get full credit for this lab, you must set up a CSUChico-CSCI211 GitHub account and update the README.md file (exercise 1), submit 3 files to INGInious (exercises 2, 3, 4), and complete the following two quizzes.

Lab 01 Quiz Exercises:
* [Exercise 5: Linux Commands and Testing Quiz](#exercise-5-linux-commands-and-testing-quiz)
* [Exercise 6: Git Basics Quiz](#exercise-6-git-basics-quiz)

> Note: All quizzes can be found on Canvas. Lab quiz exercises may be completed any time before the end of the semester for full credit. Multiple attempts are allowed; I will keep your highest score. It is recommended that you complete the Linux Commands and Testing Quiz and the Git Basics Quiz soon after you have completed the Lab 01 Exercises; however, if you are feeling overwhelmed, it is alright if you wait to complete these quizzes at a later time.

## Exercise 1: Setting up your CSCI 211 environment

* [Before you begin Exercise 1](#before-you-begin-exercise-1)
* [Steps for setting up your CSCI211 GitHub repo](#steps-for-setting-up-your-csci211-github-repo)
  - Sign up for GitHub and Set up Two-Factor Authentication
  - Generate a repo in the CSUChico-CSCI211 GitHub organization
  - Set up SSH keys (OR a personal access token) so you can clone your repo
  - Install and configure git
  - Clone your CSCI211 starter repo
* [Steps for working with a local git repo and editing the README file](#steps-for-working-with-a-local-git-repo-and-editing-the-readme-file)
  - Practice using basic Linux commands (cd, ls)
  - Edit the README.md file (add your full name, current semester, GitHub username, and Chico State username, using GitHub Flavored Markdown as specified)
  - Practice using basic Git commands (git status, git diff, git add, git commit, git push)

Make sure you update the README.md file in your CSUChico-CSCI211 GitHub repo to complete Lab 01, Exercise 1.

### Before you begin Exercise 1

The goal of this exercise is for you to set up your working directory for CSCI 211. You will start with an existing repository that contains starter code, Makefiles, and test files that are organized based on the lab and programming assignments for this course. Throughout the semester, you will work in this directory, adding your own files and code to complete the assignments.<br/>

> Note: Before completing this exercise, it would be helpful to first make sure you have an environment setup that allows you to use Linux and compile your code with the GNU g++ compiler (see the 211 Getting Started Instructions on Canvas). Mac and Windows users: make sure you can access at least one of the following: ecc-linux (access with ssh), the lab computers, an Ubuntu virtual machine, WSL2 (for Windows), or GitHub codespaces.<br>

The starter repo for this class is available on GitHub in the CSUChico-CSCI211 organization. GitHub is a Git repository manager that provides version control and other features to build and manage software.<br>

After you create a GitHub account, you will use a repo generation tool to generate a **private** version of the starter repo for yourself. Private visibility means that only select individuals (e.g. you and the instructor) will have access to the repo. A public repo would be visible to anyone on the internet, meaning other students could easily see your repo and steal your code -- this constitutes cheating and is a violation of academic integrity. There is **no reason** to make your CSCI 211 code public this semester OR after you have completed the class. Refer to the Honesty and Academic Integrity policy in the syllabus if you have questions about this.<br>

For more Git information and resources, check out the [Git Overview](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/git.md).<br>

### Steps for setting up your CSCI211 GitHub repo

> Note: for more details on steps 1 - 3, see the 211 Getting Started Instructions on Canvas.

> Note: Two-Factor Authentication (2FA) is now [officially required](https://github.blog/2023-03-09-raising-the-bar-for-software-security-github-2fa-begins-march-13/) for all developers who contribute code on GitHub.com.

1. [Sign up for GitHub](https://github.com/) and Enable Two-Factor Authentication
  - GitHub now officially requires developers to increase their account security by enabling two-factor authentication (2FA). Go to your account settings and select the `Password and authentication` option from the left sidebar. Configure at least one **Two-factor method** for authentication.
  - For two-factor authentication, you can use an **authenticator app** (such as Duo Mobile, Authy, Google Authenticator, etc) or set up **Security keys** (e.g. a hardware device such as a YubiKey).
  - You should already have Duo Mobile for campus authentication -- if you set up Duo for GitHub, note that you may not get a push notification (like you do when signing in to campus apps). You can look for a 6 digit passcode (hidden by default) in the app (note that the passcode will get refreshed frequently).
2. Go to this [GitHub repo generation](https://repo.bryandixon.phd/) page to generate a CSUChico-CSCI211 GitHub repo
  - Create a GitHub username BEFORE submitting this form. Make sure that the username matches your actual GitHub username.
  - Use the Course Token provided in the 211 Getting Started Instructions (link in Canvas) to generate your repo. (In the 211 Getting Started Instructions, look for **GitHub account** > **Sign up and generate a CSCI211 repo**)
3. After submitting the repo generation form, go to the [CSUChico-CSCI211 GitHub organization](https://github.com/CSUChico-CSCI211) (github.com/CSUChico-CSCI211) and accept the invite -- do this soon after submitting the form, as the invitation will expire after 1 week.
4. Confirm that your repo has been generated
  - The URL for your repo should be similar to the following: `github.com/CSUChico-CSCI211/CSCI211-F23-FirstName-LastName`
  - The repo should contain several files and directories. You will primarily be working in the `211` directory -- confirm that this directory contains subdirectories for lab exercises 1 - 11 and programming assignments 1 - 7.
5. GitHub is a hosting service that can store your files and directories remotely. Now you need a way to interact with GitHub.
  - Determine a location on your local machine and/or your Linux environment to house the local instance of your 211 repository (make sure you know the path to these files so you can easily access this repository).
6. Set up SSH keys (so you can clone with SSH) OR a personal access token (so you can clone with HTTPS).
  - If cloning with SSH:
    - First, [check to see if you already have an existing SSH key](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/checking-for-existing-ssh-keys) – if you do, you may be able to use the same key for GitHub. Windows users: make sure to generate the key in a Linux terminal (e.g. WSL2, ecc-linux) -- this should be the terminal where you plan to do all (or at least the majority) of your development for CSCI211.
    - If you do not have a key, generate a new SSH key (note: Ed25519 signatures are elliptical curve signatures, which are fast and very secure; however, some legacy systems do not support the Ed25519 algorithm, so if the ed25519 key is not working for you, create and use an RSA key):
      - Go to a Terminal (Linux or Mac)
      - Paste one of the options below into the terminal, replacing the email used in the example with your GitHub email address:
        - `ssh-keygen -t ed25519 -C "your_email@example.com"`
        - `ssh-keygen -t rsa -b 8192`
      - When you get the prompt to "Enter a file in which to save the key", press Enter to accept the default file location. Please note that if you previously created an SSH key of the same type, ssh-keygen may ask you to rewrite the key or create a custom-named SSH key. It is easy to run into problems when doing this, so I suggest avoiding custom-named SSH keys. It is safe to reuse an existing SSH key, just make sure that no one is able to steal your private key.
      - When you get the prompt to "Enter passphrase (empty for no passphrase)", you may simply press Enter (and press Enter again when you get the prompt to "Enter same passphrase again"). You can enter a passphrase to make your account a little more secure; however, make sure you remember the passphrase, as you will not be able to interact with GitHub without it.
      - The key may take a little while to generate, but once it does, you should be able to see the public/private key pair in the .ssh directory (look for id_rsa (private) and id_rsa.pub(public)):
        - `cd ~/.ssh`
        - `ls`
      - Then, [add your SSH key to your GitHub account](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account). These instructions walk you through how to add your public key to your GitHub account. Make sure your private key stays private (the first line of defense is to not let other people have access to your computer). Now you should be able to clone your repo and continue on to the next step.
  - If cloning with HTTPS:
    - You will be asked for your GitHub username and password in order to complete several git commands. When Git prompts you for your password, you should use your [personal access token](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens). GitHub recommends that you use Fine-grained personal access tokens; however, you will need to use Personal access tokens (classic) to work with your GitHub repo in the CSUChico-CSCI211 organization.
    - Follow GitHub's instructions for [creating a personal access token (classic)](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens#creating-a-personal-access-token-classic). Give your token an expiration date after the end of the semester. Now you should be able to clone your repo and continue on to the next step.

> Note: if you are having trouble with one of the options above, ask the instructor about using GitHub Codespaces!

7. Confirm that you have git installed (if installed, `which git` will identify the location of git installed on your machine, while `git version` will display version information)
```
$ which git
$ git --version
```
  - * If you do not have Git installed, [download and install Git for your operating system](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
8. Check your Git settings and confirm that you have set your name and email. Start by viewing your settings. If you see your name and email (e.g `user.name=Your Name` and `user.email=youremail@mail.com`), type `q` to exit and continue to the next step.
```
$ git config --list
```
  - If you do not see your name and email, set them using the following (make sure to use your real name and email in place of the John Doe example below):
```
$ git config --global user.name "John Doe"
$ git config --global user.email johndoe@example.com
```
  - You can confirm that your name and email have been set by running the `git config --list` command again.
9. [Clone your repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)
  - Navigate to the main page of your CSUChico-CSCI211 repository
  - Above the list of files, click the green `< > Code` button.
  - Make sure you are on the `Local` tab (it has options to Clone with HTTPS and SSH), and copy the URL for the repository using either HTTPS or SSH (depending on what you set up in step 6).
    - If you created an SSH Key, make sure you clone with SSH.
  - Open a terminal.
  - Change the current working directory to the location where you want the cloned directory to exist on your local machine.
  - Type `git clone`, paste the URL you copied earlier, and press Enter:
```
$ git clone git@github.com:CSUChico-CSCI211/CSCI211-Semester-FirstName-LastName.git
```

Now you should have a local instance of your CSCI211 repository! You can use the `ls` command to see the CSCI211 repo in your current directory. Complete the next steps to finish Lab 01, Exercise 1.<br>


### Steps for working with a local git repo and editing the README file

1. When you clone the repository, you will not automatically move into the directory. Use the `cd` command to move into the directory (the name should be similar to the following):
```
$ cd CSCI211-F23-FirstName-LastName
```
2. List the contents of the current working directory and confirm that it contains the files in the CSCI211 GitHub repo.
```
$ ls -al
```
3. Open the `README.md` file with the editor of your choice (below, I use vim)
```
$ vim README.md
```
4. Edit the file. The file already contains a couple lines, so below these lines, add the following (your first and last name, the current semester, your GitHub username, and your Chico State portal username) in the format shown below:
```
## FirstName LastName

*Fall 2023*

* GitHub username: my-github-username
* Chico State username: my-chico-username
```
  -  Make sure to include the spacing and symbols as shown (pay special attention to the '#' and '*' characters), so that your README.md file will include a second-level heading (for your name), some styling (italics around the semester), and an unordered list (for your GitHub and Chico State usernames).<br>

> This code uses [GitHub Flavored Markdown](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#lists). Markdown is plain-text formatting syntax that is commonly used in README files.<br>


5. When you are done editing, save your changes and exit the file.<br>
6. Currently, our changes only exist locally, but we want our changes to appear in the remote CSCI211 GitHub repository. First, show the modified files in the working directory and confirm that there are only changes to the `README.md` file:
```
$ git status
```
7. See what has been changed (but not yet staged) in the `README.md` file (this command opens up the README.md file, and you can use vim commands to move around and view the changes (new lines will be highlighted in green and have a '+' sign next to them, while anything removed will be highlighted in red and have a '-' sign) -- type `q` to exit):
```
$ git diff README.md
```
8. If all the changes look good, you can now add, commit, and push your changes to the remote GitHub repo.
  - Add the `README.md` file as it looks now to the staging area:
```
$ git add README.md
```
  - Commit your staged content to a new commit snapshot (make sure to include a brief but descriptive commit message that explains the changes in the current commit):
```
$ git commit -m "[descriptive message]"
```
  - transmit local branch commits to the remote repository branch:
```
$ git push origin main
```
> Note: "origin" is the default name for a remote repository. You can see the remote repo attached to the current repository with this command: `git remote -v`<br>

> Note: "main" is the default branch name. You may see older versions of git using "master" as the default branch name. For CSCI211, it is fine if you do all of your work on the main branch.<br>

9. Visit your CSCI211 GitHub repo in a web browser and confirm that your changes have been added to your remote repo (reload the page if necessary). You should be able to see your changes in the README.md file. You can also click on the "commits" button (below the green "< > Code" button) to see the history of all the commits to this repository, organized by date.<br>

10. After you have updated the README.md file in your repo, you are done with Lab 01, Exercise 1, and you can complete the rest of Lab 01.<br>

I recommend that you commit and push all of your code for CSCI211 lab exercises and programming assignments to your GitHub repo IN ADDITION to submitting your code to INGInious for grading. Submitting to INGInious is necessary for grading, but committing and pushing to a remote repo is good practice:

* **Git is very widely used in the software development industry** (many of your future employers and professors will want you to know how to use git!)
* If your code has bugs and is not working, you can commit your code to the CSCI211 repo -- **I can easily view your code and help you debug**. (This is one of the easiest ways for me to help, because I can see all of your code in one location). In the future, you can refer back to your commit history and see how you resolved different bugs.
* Working with Git now will give you **more experience with version control** (easily revert to previous versions, compare changes, and collaborate more effectively with others in the future).
* For **code backup and recovery** -- sometimes, your local machine fails or you accidentally delete code. If you make regular commits, you can more easily recover code that would otherwise be lost.
* A **history of commits that shows your progress** is a good indicator to me that you have spent time working on your code and are not cheating (it is not the only indicator, but it is one thing I can refer to if your code is flagged).
* If you are **unable to submit to INGInious for any reason** (e.g. if the VPN is not working), you can commit and push your code to GitHub. Let me know what happened; I can see the time/date that you submitted and refer to your code on GitHub when I am grading.
* The list goes on :grinning:


## Exercise 2: Creating, compiling, and running a CPP program

1. Enter the lab01_hello subdirectory, and create the file `hello.cpp`. The following command starts the vim editor and creates a file with the name `hello.cpp` (you could use a similar command with other editors):
```
$ vim hello.cpp
```
This is another way you could accomplish the same thing -- use `touch` to create the file and then start the editor (this time using Atom) and open up your present working directory:
```
$ touch hello.cpp
$ atom .
```
2. Now edit the file so it contains the following text. Save the file and exit the editor:
```cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "hello world" << endl;
  return 0;
}
```
3. Compile this file using the following command:
```
$ g++ hello.cpp
```
4. The `g++` command should have created a file called `a.out` -- use `$ ls -l` to find out if `a.out` is in your directory. Note that `a.out` automatically has execute protection ("x").  When a file has execute permission you can execute it.
```
$ ls -l
```
5. You can now run the executable `a.out`:
```
$ ./a.out
```
It is possible to [add `./` to the search path](https://stackoverflow.com/questions/27188856/adding-any-current-directory-to-the-search-path-in-linux) in Linux so that you do not have to type `./` before the executable every time, but it is not necessary. In my instructions, I will include `./` before all executables.<br/>

Submit `hello.cpp` to [INGInious](https://inginious.csuchico.edu/). One of the main goals with this exercise is to make sure you can successfully submit your code to INGInious.

## Exercise 3: Addition

Write a program that reads in two numbers, adds the numbers together, and prints the result.

* Move to your lab01_add directory:
```
$ cd ../lab01_add
```
The two dots mean to go "up" a directory and find the `add` directory. If that did not work, try using cd with the "full directory path" or "full path" (use the `pwd` command to determine the full path to your current directory)

* Create a new file for your program called `add.cpp`.

* When your program is run, it should work like this (the "./a.out" "40" and "2" are typed by the user, the "40 + 2 = 42" is printed by the program, and the "$" sign represents the command prompt):
```
$ ./a.out
40
2
40 + 2 = 42
$
```

* For this exercise you will need to read in an integer.  You can read an integer in C++ using `cin`:
```cpp
int value1;
cin >> value1;
```

* Compile and run your program to make sure it works correctly.  Your output must EXACTLY match my output: `<number><space><+><space><number><space><=><space><number><newline>`
* Some sample input and output are available in `starter-repo/211/lab01_add/tests` directory. In this directory you will find *.in and *.out files. For example, `t01.in` is the input for test 1 and `t01.out` is the expected output for test 1. All of the tests in the directory will be used to grade your program on INGInious. If you pass these tests, you will get full credit.
* An easy way to see the content of a small file is to use the Linux cat command:
```
$ cat tests/t01.in
40 2
$ cat tests/t01.out
40 + 2 = 42
$
```
* See the [Testing Assignments](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/testing.md) Guide for a full description of how to test your assignments. If you understand the described testing mechanism now, it will make your semester much easier. One of the most important aspects of this lab is for you to understand how to test your code!<br>

Once your program is working, submit `add.cpp` to [INGInious](https://inginious.csuchico.edu/).

## Exercise 4: Say Hello

Write a program that reads in a number and prints "hello" that number of times:
```
$ ./a.out
5
0 hello
1 hello
2 hello
3 hello
4 hello
$
```
* All the characters shown above were printed by the program, except the 5<enter> which was typed by the user. So, at the beginning of each line where you print "hello", there should be a number and a space. The number should start at 0 and count up, representing the number of times "hello" is displayed.

* Move to your `lab01_print` directory.
* Create a new file for your program called `print.cpp`.
* Use a for-loop to implement this program.
* When your program is working, test it with the provided tests (see the testing and turn in instructions for Exercise 3; the only difference is that the tests are in the directory `starter-repo/211/lab01_print/tests`).
* Make sure your program passes all the tests.<br>

Submit `print.cpp` to [INGInious](https://inginious.csuchico.edu/).

***

## Exercise 5: Linux Commands and Testing Quiz

The Linux Commands and Testing Quiz, along with the lab exercises for the first few weeks, are meant to familiarize you with the Linux command line interface and introduce you to the testing mechanisms used in this class.

It is recommended that you complete the Linux Commands and Testing Quiz (in Canvas) soon after you have completed the Lab 01 exercises.

Read or refer to the following guides to complete the Linux Commands and Testing Quiz:

* [Linux Lecture Notes](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/linux.md)
* [Testing Assignments](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/testing.md) Guide<br>

In addition to reading these guides, it is recommended that you try running the commands in your class repo or a test repo.<br>

This quiz covers various aspects of using a Linux command line interface, focusing on commands that will help you in this class. In particular, note the commands used for testing (running an executable and comparing files), as these provide some insight into how your code is tested in INGInious. Make sure you understand how to:<br>
* navigate the Linux file system
* interact with processes running in the terminal
* add and remove files and directories
* create and run an executable
* use file redirection to test assignments (using < and > to redirect input into a program and redirect output to a file).
* compare your output to the correct output (using `cat`, `diff`, `vimdiff`)
* use the provided `run_tests` script to test your code (which utilizes file redirection and Linux commands to compare your output against expected output)<br>

Reminder: the Linux Commands and Testing Quiz can be found in Canvas.

***

## Exercise 6: Git Basics Quiz

This Git Basics Quiz covers some basic Git commands and how you can use git with a git repository hosting service (GitHub in this case).

It is recommended that you complete the Git Basics Quiz soon after you have completed the Lab 01 exercises. Alternatively, if you are feeling overwhelmed at the beginning of the semester, it would also be useful to complete the Git Basics Quiz on or before Week 12 (sometime before you start working on the CURE-E Final Project).

> Note: It is possible to complete the Git survey without running any commands and just looking at the cheat sheets; however, it can be helpful to walk through the steps yourself. If you do choose to run the commands, I recommend running them in a practice repo (not in your CSCI211 repo that contains the starter code files) -- some git commands can cause problems and impact your repo in unwanted ways if you are not careful.

Git Resources:

If you are unfamiliar with git, you can watch my [Git Basics video](https://csuchico-my.sharepoint.com/:v:/g/personal/swong26_csuchico_edu/EYw6N7y3X0VDo6yKbOnHzfsBTDhmEr5w02mHp0ASko7Jiw) that provides an overview of Git and git source code hosting services, walks through basic Git commands, and provides a little more context about git and how it can be used. The video does not go through the survey question by question; however, it does aim to cover all of the topics in the survey.<br>

You may also find it helpful to refer to the [Git Overview](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/guides/git.md) guide. Feel free to use one of the Git Cheat Sheets to complete the Git survey.<br>

There are 24 questions in this survey. Some questions cover Git commands that are used in other Lab 01 exercises, while other questions (such as the ones on branching and creating a new repo) have not previously been discussed. As you complete the survey, I recommend that you open up a terminal and try running the commands in a test repo, and open up a browser to explore github.com and potentially search for any commands that are unfamiliar to you. Let the instructor know if anything is unclear -- the goal of this survey is for you to learn and get some experience with Git, so questions are expected!<br>

* Part 1 (questions 1-8):
  * Things to know before using Git and GitHub
  * Create a new GitHub repository (a remote repo)
  * Connect a remote repo with a local repo
  * Initialize a local repo as a Git repository
* Part 2 (questions 9-15):
  * Check the status of your repo
  * Add and stage a commit
  * Push a commit from a local repo to a remote repo
* Part 3 (questions 16-24):
  * Create a branch
  * Move between branches
  * Merge branches
  * View your code on GitHub

The Git commands covered in this survey are very useful for individual projects as well as larger collaborative projects. The focus is on commands that may benefit you on small individual projects, such as making frequent commits and utilizing separate branches to help you organize your work and learn from your commit history.<br>

Reminder: the Git Basics Quiz can be found in Canvas.

***

## Lab 01 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must set up your CSUChico-CSCI211 GitHub account, and submit `hello.cpp`, `add.cpp`, and `print.cpp` to [INGInious](https://inginious.csuchico.edu/) (there is a separate submission link for each exercise). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit. You should also aim to complete the two Lab 01 quiz exercises at least once: the 211 Linux Commands and Testing Quiz and the Git Basics Quiz, both on Canvas. There is no late penalty for quizzes, but the quizzes should still be completed.<br>

Optional but recommended submission step: add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git add -A
$ git commit -m "completes lab01 exercises"
$ git push origin main
```

If you have time left over, I recommend that you start working on p1. After you've made some progress on the assignment, practice using the different options for testing your code before you submit the code to INGInious.


[Top of the Page](#lab-1)
