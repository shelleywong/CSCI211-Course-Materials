# Vim Guide

## vim/gvim Editor

You do not need to learn or use vim/gvim for this class; however, using an advanced editor (such as vim/gvim) can save you lots of time in the long run.<br>

Vim is very readily available -- installed by default on Linux and Mac, and easily installed on Windows. Companies may use an IDE or editor that you are unfamiliar with, but in almost any situation, you will be able to use Vim.

## Configure vim

You can [configure vim with a vimrc file](https://linuxhint.com/configure_vim_vimrc/).<br>

I usually stick with creating a .vimrc file for your login user (reminder: the dot at the beginning indicates that this is a hidden file -- use `ls -a` to see hidden files in the current directory):
```
$ touch ~/.vimrc
```

The following is an example of a .vimrc file with configurations for setting tab size to 4 spaces, enabling auto indentation, and replacing tabs with whitespace:
```
set tabstop=4
set autoindent
expandtab
```

## vim/gvim References

Online version of Steve Oualline's [vim book](http://www.truth.sk/vim/vimbook-OPL.pdf).<br>

If vim was correctly installed on your computer, you can run the command vimtutor:
```
$ vimtutor
```
This should take about 30 minutes and provides the basic commands.<br>

An excellent [vi tutorial](https://engineering.purdue.edu/ECN/Support/KB/Docs/ViTextEditorTutorial) from Purdue (vim is a superset of vi, so learning vi is a great way to start learning vim)<br>

[vim-adventures.com](https://vim-adventures.com/) allows you to learn vim commands while playing a game.  It has been highly recommended.

## vi/vim/gvim
| Editor |  |
| --- | --- |
| vi | the original Unix editor (does not have as many features as vim) |
| vim | a "New and iMproved" version of vi |
| gvim | a version of vim with a graphical user interface (a little easier to learn, but will lead to bad habits) |

* All three version use the same basic commands and have the same basic structure.
* vim/gvim are available on most operating systems (Windows, Linux, OSX, etc).
* Since gvim opens a new window, it does not always work when logging in remotely (e.g. ssh, putty.org)

 How to start editing a file with vi, vim, or gvim:  
```
$ vi filename
$ vim filename
$ gvim filename
```
## Modal interface
For new users, the most difficult thing to get use to is vim's modal interface.<br>

Unlike "normal" editors where everything you type is inserted into the document, gvim has two modes:
* **Insert mode**: the keys you type are inserted into the file. Type an h and an h will be inserted into your file. (This is the mode most other editors are always in.)
  * \<esc\> key stops the current insert and moves back to command mode
* **Command mode**: the keys you type are commands. Type an h and the cursor will move to the left (the h key is the move to left command).
  * When you open up a file with vim, you start in command mode. There are several ways to enter insert mode (see below)

## Moving around (while in command mode)

| What you type | How the cursor moves |
| --- | --- |
| h | left |
| j | down |
| k | up |
| l | right (lowercase L) |
| /pattern | searches for pattern |
| n | search next |
| ? | search back |
| G | move to last line of the page |
| gg | move to the first line of the page |
| :42 | move to line 42 |
| 0 | jump to the start of the line |
| $ | jump to the end of the line |

## Inserting text (must be in command mode to start inserting)

| What you type | How the insert occurs |
| --- | --- |
| i | insert before cursor |
| a | insert after cursor |
| I | insert at start of line (capital i)|
| A | insert at end of line |
| C | delete from cursor to end of line, start inserting |

## For editing text (while in command mode)

| What you type | Editing action |
| --- | --- |
| yy | yank (copy) a line |
| 2yy | yank (copy) 2 lines |
| p | put (paste) the clipboard after the cursor |
| dd | delete (cut) a line |
| x | delete (cut) a character |

> Reminder: to exit insert mode or visual mode, use the \<esc\> key

## The command line editor

* When vi was created, editors did not display the text being edited on the screen. The vi stands for visual.
* vi was built on top of the line editor called ed. A line editor allows you to edit a single line at a time.
* The line editor provides lots of vi's functionality (read file, write file, substitute).
* When in command mode, ":" allows you to enter a command that is passed to the line editor.

For example, if you wanted to change all occurrence of foo to bar you could use the s (for substitute) command:
```
: 1,$ s/foo/bar/g
```
You read this command as follows:
* When using the line editor, you must first tell it what lines you want to edit.
* In the above example, the "1,$" tells the editor you want to edit all lines 1 to $ ($ stands for the last line).
* The "s" stands for substitute.
* After the first / you put the old string
* After the second / you put the new string
* The g stands for global (you want to substitute ALL the foo's on a given line to bar.

## Three other common commands are:

| What you type | Resulting action |
| --- | --- |
| `:q` | quit (exit the file) |
| `:w` | write (save any changes) |
| `:wq` | write (save) and then quit |
| `:q!` | quit without save (if you've made changes but don't want them saved) |
| `:e filename` | to start editing another file |

The above is just a brief introduction. The more you learn about vim the faster you will be able to edit files.

[Top of the Page](#vim-guide)
