# Lab 14

Git Basics

Lab 14 Exercises
* [Exercise 0: Set Up Git and GitHub](#exercise-0-set-up-git-and-github)
* [Exercise 1: Complete the Git Google Survey](#exercise-1-complete-the-git-google-survey)

## Goals

Learn the basics of [Git](https://git-scm.com/). Use Git with a repository hosting service such as [GitHub](https://github.com/). Learn about common Git commands that are helpful for both individual and collaborative projects.<br>

Optional: download, install, and set up Git on your local computer, and set up a GitHub account so you can maintain a remote repository for your work.<br>

> Note: You are not required to set up Git and GitHub for this lab (or for CSCI 211 in general). You get credit for this lab by completing the Google Survey questions. You will get the most benefit from this lab if you test out the Git commands on your own computer, but you can also simply answer the questions using the resources listed in this lab. The use of Git is very common in industry, and the more experience you have with a source control system, the better off you will be.

## Required Survey

You do not have to turn in any files for this lab, but you do have to complete [this Google survey](https://docs.google.com/forms/d/e/1FAIpQLSezh266Wzhha6HZtSdUQEX1QyvzDuzgWihREqvRgK6AFdLDjg/viewform?usp=sf_link) to get credit for Lab 14.

## Overview of Git and Git Repository Hosting Services

### What is Git?

Git is a version control system. It helps you keep track of your source code history, allowing you to see any changes and revert back to a previous version if necessary. Git makes it easier to manage both small individual projects and large collaborative projects. It is free and open source software released under the [GNU General Public License version 2.0](https://opensource.org/licenses/GPL-2.0). To use Git, you must have it installed on your local machine.<br>

### How do I know if I have Git installed?

Git can be installed on most common Linux, Mac, and Windows operating systems. Git is installed by default on many machines. You can use one of the following commands to determine if you have git installed:
```
$ which git         // see where git is located
$ git --version     // see what version of git you have
```

### How do I get Git if I don’t have it installed?

Download Git for your platform:
* [http://git-scm.com](http://git-scm.com) (all platforms)
* [https://mac.github.com](https://mac.github.com) (Mac)
* [https://windows.github.com](https://windows.github.com) (Windows)

### How do I work with Git?

Git is a command-line tool. It can be challenging to remember all of the commands when you’re first starting out, but the best way to learn them is to get practice using them. This lab lists [several resources](#resources-for-learning-more-about-git) that can help you learn common Git commands.<br>

Many companies expect you to understand how to work with Git in the command line; however, there is a good Git GUI available that works with Windows, Mac, and Linux:
* [GitKraken](https://www.gitkraken.com)

### What are GitHub, GitLab, and BitBucket?

GitHub, GitLab, and BitBucket provide tools that help manage and host Git repositories. GitHub, GitLab, and BitBucket utilize a graphical user interface and are accessible on the web.<br>

* [GitHub](https://github.com/)
  * Version control, collaboration on open-source projects (Education accounts are free)
* [GitLab](https://about.gitlab.com/)
  * Version control with baked in CI/CD (Unlimited private/public repos for all)
* [BitBucket](https://bitbucket.org/)
  * Version control host for GIT or MERCURIAL (Education accounts are free)

You are not required to use a Git repository hosting service for CSCI 211, but it is worthwhile for you to understand what they offer and create yourself an account on at least one of the services.

## Resources for Learning More About Git

* Git Cheat Sheet From GitHub Education: [https://education.github.com/git-cheat-sheet-education.pdf](https://education.github.com/git-cheat-sheet-education.pdf)

* Git Cheat Sheet From GitLab: [https://about.gitlab.com/images/press/git-cheat-sheet.pdf](https://about.gitlab.com/images/press/git-cheat-sheet.pdf)

* Git Cheat Sheet From Atlassian (BitBucket): [https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet](https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet)

* For instructions on setting up you Git username and password (necessary if cloning GitHub repos with HTTPS) and managing remote repositories, check out *Getting Started with Git* in the [GitHub Docs](https://docs.github.com/en/github/getting-started-with-github/getting-started-with-git)

* Bryan Dixon's [Git Basics Video](https://www.youtube.com/watch?v=0JgyAJMvZlY&feature=youtu.be) walks through basic Git usage, creating a new repository on GitHub, and creating a secure [RSA key pair](https://www.ssh.com/academy/ssh/keygen) so you can use SSH.

* [Learn Git Branching](https://learngitbranching.js.org/) is a great interactive web tutorial that covers both basic and more advanced Git commands and techniques. The tutorial goes beyond what is necessary for this class, but it provides good practice and preparation for future classes and industry work.

## Exercise 0: Set Up Git and GitHub

Setting up Git and GitHub is optional (but recommended) for Lab 14. If you would like to set up these tools, follow the steps outlined below. If you do not plan on creating a GitHub account, you can use appropriate placeholder names and example messages in your survey responses.<br>

1. [Set up a GitHub account](https://github.com/)
2. Check if you have Git installed already:
```
$ git --version
```
3. If you don't have Git installed, you can download and install:
  * For Windows: [https://windows.github.com](https://windows.github.com)
  * For Mac: [https://mac.github.com](https://mac.github.com)
  * For all platforms: [http://git-scm.com](http://git-scm.com)

4. Check your Git settings:
```
$ git config --list
```
5. If you have never used Git before, you'll likely need to go through [First Time Git Setup](https://git-scm.com/book/en/v2/Getting-Started-First-Time-Git-Setup)

  * If you are planning on cloning with HTTPS, you will need your GitHub username and password for every commit. GitHub suggests using a [personal access token](https://docs.github.com/en/github/authenticating-to-github/keeping-your-account-and-data-secure/creating-a-personal-access-token) in place of a password.

6. If you are planning on cloning with SSH, you will need to generate an SSH key pair on your computer. You will add the public key to your GitHub account. Make sure your private key stays private (the first line of defense is to not let other people have access to your computer). The [Git Basics video](https://www.youtube.com/watch?v=0JgyAJMvZlY&feature=youtu.be) walks through the steps to generate a key pair and associate an SSH key with your GitHub account. You can also look into GitHub Doc's information on [Connecting to GitHub with SSH](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh).

## Exercise 1: Complete the Git Google Survey

The [Google survey](https://docs.google.com/forms/d/e/1FAIpQLSezh266Wzhha6HZtSdUQEX1QyvzDuzgWihREqvRgK6AFdLDjg/viewform?usp=sf_link) for this lab discusses Git when used with GitHub, but you would use similar commands when working with any Git repository hosting service. When you provide your answers, make sure that your answers are complete (i.e. include a branch name/file name/message/URL/etc if the command requires it to run successfully).<br>

There are 17 questions in the [Google survey](https://docs.google.com/forms/d/e/1FAIpQLSezh266Wzhha6HZtSdUQEX1QyvzDuzgWihREqvRgK6AFdLDjg/viewform?usp=sf_link). Many of them can be answered with one Linux Git command. Let the instructor know if anything is unclear.<br>

* Part 1 (questions 1-5):
  * Create a new GitHub repository (a remote repo)
  * Connect a remote repo with a local repo
  * Initialize a local repo as a Git repository
* Part 2 (questions 6-11):
  * Check the status of your repo
  * Add and stage a commit
  * Push a commit from a local repo to a remote repo
* Part 3 (questions 12-17):
  * Create a branch
  * Move between branches
  * Merge branches

The Git commands covered in this survey are very useful for individual projects as well as larger collaborative projects. The focus is on commands that may benefit you on small individual projects, such as making frequent commits and utilizing separate branches to help you organize your work and learn from your commit history.<br>

If you have time and are interested in learning about other Git features that can help you collaborate in a large shared repository, try working through the [Learn Git Branching tutorial](https://learngitbranching.js.org/). Almost everyone in industry uses Git, and the best way to learn Git is by getting practice with it.

## Lab 14 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must complete the Google Survey (Exercise 1). You will not submit anything to Turnin for Lab 14. If you are not able to complete all the exercises, turn in your partial work for partial credit.

[Top of the Page](#lab-14)
