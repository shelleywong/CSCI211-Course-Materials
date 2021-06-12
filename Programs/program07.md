# Program 7: Binary Search Tree

CSCI 211: Programming and Algorithms II<br>
Points: 300

* [Objectives](#objectives)
* [Overview](#overview)
* [Program Requirements](#program-requirements)
* [Helpful Hints](#helpful-hints)
* [More Help For When You Are Stuck](#more-help-for-when-you-are-stuck)
* [General Requirements](#general-requirements)
* [Testing Your Program](#testing-your-program)
* [Submitting Your Program](#submitting-your-program)

## Objectives

* Implement a Binary Tree
* Practice writing recursive functions
* More practice parsing commands
* Use the STL vector and queue

## Overview

> Note: Sample tests and a `Makefile` have been provided for you in 211-starter-pack/211/p7.

Write a binary search tree class (called `BST`) that is a tree of C++ strings. A binary search tree (BST), is a binary tree (two children) where for **every** node in the tree, all the values in the node's left subtree are less than the node's value and all the values in the node's right subtree are greater than the node's value.<br>

Write a main.cpp that instantiates a BST object and reads and executes commands from standard input. See table below for the list of commands.<br>

Several of these commands are difficult to implement (especially the `balanced` and `rebalance` commands). It may take you a long time to figure out how to implement them. While you are free to use a search engine, you will face problems like these during employment interviews and you won't be allowed to use Google (even if you are interviewing at Google). The better you are at solving difficult problems, the more career potential you will have.<br>

> Note: Start early and make incremental progress. If you think you can finish a programming assignment in one day, finish it the first day it is assigned. Students who put off these assignments tend to have a bad time.

## Program Requirements

All program input/output must be done in main.cpp. This means that the `BST` functions must pass results back to the calling function using return values and/or reference parameters. Use a [Standard Template Library (STL) vector](https://www.cplusplus.com/reference/vector/vector/) when you need to pass multiple strings.<br>

The program must handle the following commands from input. If a command has an argument, the argument is on the same line as the command. All string arguments are allowed to contain spaces.

> Note: This table shows the arguments that follow each command in main(), they are not the arguments to the BST functions. A few things to notice: `echo` is NOT a BST function. You may want to pass a reference parameter (such as a vector of strings) to the BST functions that print elements in the BST (even though the command may have no arguments listed in this table). If there is a potential error message, your BST function should return something that indicates whether or not the error message should be printed.

| Command | Argument | Action (see below for output formatting) | Potential Error (see below for message) |
| --- | --- | --- | --- |
| echo | string | Write the string to standard output. Do not insert into tree. Used for commenting tests. Has nothing to do with the tree. | none |
| insert | string | Insert the given string into the binary search tree. The tree must maintain the BST property after insert. | Print error if string already in tree. |
| size | none | Print the number of elements (also number of nodes) in the tree. | none (0 if tree is empty) |
| find | string | Print if the given string is or is not in the tree (both messages to stdout) | none |
| print | none | Use a depth-first traversal (DFT) to print all elements in the tree. When you use an inorder DFT, the values will be printed in ascending order (for strings, the values will be in alphabetical order) | none (empty brackets if tree is empty) |
| breadth | none | Use a breadth-first traversal (BFT) to print all elements in the tree. This prints one level of the tree at a time (left to right within a given level) | none (empty brackets if tree is empty) |
| distance | none | Print the average distance nodes are from the root. The root's distance is 0. The root's children are distance == 1, the root's grandchildren are distance == 2, and so on. Calculate the distance for ALL nodes and then take the average. | none (0 if zero or one nodes) |
| balanced | none | Print if the tree is balanced or not balanced (this type of balanced is called "height-balanced". | none (balanced if empty) |
| rebalance | none | Modify the tree so it is balanced. | none |


Each line of the input will have the following format (assume there is always a space between the command and the argument). The "<" and ">" are NOT in the input.<br>

If there is no argument:
```
<command><newline>
```

If there is an argument:
```
<command><space><string that may contain spaces><newline>
```
* The space following the command is NOT part of the string.
* Assume that all string arguments are NOT empty (i.e. if the command is supposed to receive an argument, an argument will be included).<br>

### Example Input/Output

input:
```
insert Saturday
insert Friday
insert Tuesday
insert Monday
insert Thursday
insert Wednesday
echo Number of nodes in tree:
size
find Monday
find Sunday
echo The nodes in depth-first order:
print
echo The nodes in breadth-first order:
breadth
balanced
```

output:
```
Number of nodes in tree:
6
<Monday> is in tree.
<Sunday> is not in tree.
The nodes in depth-first order:
{Friday, Monday, Saturday, Thursday, Tuesday, Wednesday}
The nodes in breadth-first order:
{Saturday, Friday, Tuesday, Monday, Thursday, Wednesday}
Tree is balanced.
```

Output formatting:

| Command | Output Formatting |
| --- | --- |
| echo | Print string argument to standard output followed by newline. |
| insert | None unless there is an error (see below for error message). |
| size | Print the integer size of the tree to standard output followed by a newline. |
| find | If the target string is in the tree, print the following to standard output:  `"<str> is in tree.\n"`  where str is the target. If the target string is NOT in the tree print the following to **standard output**: `"<str> is not in tree.\n"` |
| print | Traverse the tree using a depth-first algorithm. Print all the elements in curly brackets {}, separate strings by a comma+space, and terminate with a newline: {string one, string two, string three}  There is NO comma after the last string. Print `"{}\n"` if the tree is empty (no space between the braces). |
| breadth | Same format as print (it is helpful to write a vector printing function and use it for both print and breadth commands). |
| distance | Print `"Average distance of nodes to root = "` followed by the average (as a double) of all the node's distances from root followed by a newline. |
| balanced | If the tree is balanced, print to standard output: `"Tree is balanced.\n"` If the tree is NOT balanced, print to standard output: `"Tree is not balanced.\n"`
| rebalance | none |

### Error messages

If an illegal command is entered, print to **standard error**: `"Illegal command <cmd>.\n"` where `cmd` is the illegal command. After an illegal command is entered, skip all other characters on that line of input and continue the program.<br>

If `insert` is called on a string that is already in the tree, print to **standard error**: `"insert <str> failed.  String already in tree.\n"` where `str` is the string entered.<br>

The program should continue after both types of errors.<br>

> Note: Always return zero from `main()`, even if there was an error.<br>

## Helpful Hints

Implement and test the commands one at a time in the order they are listed in the above tables. The tests are organized so for each command you implement you will pass one or more additional tests.<br>

Several of the commands are best implemented using one public and one private functions. Consider the `insert` function:
```cpp
class BST
{
    public:
        ...
        bool insert(string str) {return insert(str, m_root);}
        ...
    private:
        ....
        bool insert(string str, Node *&cur_root);
        ....
};
```

If the `cur_root` is passed to the private `insert` function as a reference to a pointer (see above), the implementation will be less complicated. For example, consider the first time that the private `insert()` is called. `m_root` is NULL but since a reference to `m_root` is passed to `insert()` when it sets `cur_root` to the new node, it is really updating `m_root`:
```cpp
bool BST::insert(string str, Node *&cur_root)
{   
    if (cur_root == NULL)
    {
        cur_root = new Node(str);  // first time this is called, cur_root is a reference to m_root.
        return true;
    }
    ...
}
```

Subsequent calls to `insert()` will be passed the `m_left` and `m_right` fields of Nodes. If you use a reference parameter, you don't have to check if `m_left` or `m_right` is NULL before you call `insert`; a reference to a NULL m_left/m_right pointer will work just like the reference to a NULL m_root. If you use this method, you will never have `m_left = new Node(...)` or `m_right = new Node(...)`. All calls to `new Node(str)` will always be assigned to `cur_root`. HOWEVER, if you don't understand how the reference parameter works, you do not have to use it.<br>

> Note: Commands do not contains spaces, so you can read them using operator>> (e.g. `while (cin >> command)`). String arguments may contains spaces, so you must read them using `getline()`.<br>

Implement the recursive `print` function (a depth first traversal or DFT) and `breadth` function (a breadth first traversal or BFT) by inserting elements at the end of a vector as they traverse the tree. Pass the vector to the function as a reference: `void BST::breadth(vector<string> &values)`<br>

The breadth first traversal algorithm requires a queue. Use the [standard template library (STL) queue](https://www.cplusplus.com/reference/queue/queue/?kw=queue). To remove an element from this queue, you first get the element with a call to `front()`, and then you remove it will a call to `pop()`. The `pop()` function removes the first element but DOES NOT RETURN IT so you must use `front()` before you call `pop()`.

* Make sure that you are correctly managing dynamic memory.
* Start today.

## More Help For When You Are Stuck

The following are suggestions for simple ways you can implement balanced() and rebalance() for P7. You are not required to follow these algorithms; however, your solutions should not be less efficient than the algorithms described here (ask the instructor if you are unsure about this). If you continue taking computer science courses, you will get the opportunity to program at least one self-balancing tree -- these have a more complex implementation but are more efficient overall.

### balanced command

Write a recursive function that does two things:
1. determines if the tree is balanced
2. returns the height of the tree<br>

If at any point during the tree traversal you discover a subtree (pointed to by `cur_root`) is not balanced, return -1. Otherwise return the height of the largest sub-tree plus one. Here is the basic algorithm:
```
int BST::balanced(Node *cur_root):

    If cur_root is NULL:
        Return 0  // tree is balanced (current subtree height is zero)

    If either of my children's subtrees (those rooted at cur_root->m_left and cur_root->m_right) is NOT balanced:
        Return -1 // The entire tree is not balanced

    Else return the largest of my children's subtree plus one (plus one is because we must count cur_node in the height)
```

### rebalance command

> Note: This rebalance method temporarily holds all of the tree values in a vector (in sorted order), removes all Nodes from the tree, then re-inserts the values from the vector back into the tree in an optimal order (so that the tree will be balanced).<br>

Use the `print` function to fill a vector with all elements of the tree (remember, your `print` should use a depth-first traversal). The elements will *automatically* be sorted from smallest to largest.<br>

Delete all the Nodes in the tree. Set m_root to NULL.<br>

Write a recursive insert function (`insert_from_vector()`) that will insert all the elements in the vector into the tree calling the regular `insert()` function.<br>

The basic insert_from_vector algorithm works like this:
```
Insert the element in the middle of the vector
Recursively insert the elements before that middle element
Recursively insert the elements after that middle element
```

The argument to this function is always the complete vector of elements plus unique start and stop indexes for the range under consideration, so that as you utilize this function, you recursively insert every element from the elements vector (from elements[start_index] to elements[end_index]):
```
// On each recursive call, you send a different start_index and end_index to the recursive calls
void BST::insert_from_vector(vector <string> &elements, int start_index, int end_index):

    Handle the base cases where the range is of size zero or one:
        Think carefully about what should happen in each of these cases

    Figure out the index of the middle element:
        // if there are two possible middle indexes (e.g. middle of an array of 4 is 1 or 2), pick the smallest
        int middle_index = ...   

    Use your existing insert() to insert elements[middle_index]
    Recursively call insert_from_vector (range: middle_index + 1 .. end_index)
    Recursively call insert_from_vector (range: start_index .. middle_index - 1)
```

## General Requirements

Programs should be well formatted and consistent so they are easy to read. The [General Requirements](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/README.md#general-requirements) listed in the Programs directory README apply to all programming assignments.<br>

Remember that the first lines of all your files (.h and .cpp) must contain the following comments:
```
// filename
// your name (first and last)
// your Chico Portal/Turnin username
// Short summary of the file contents
```

## Testing Your Program

* Some sample tests and a Makefile are included in 211-starter-pack/211/p7.
* [Lab 2](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab02.md) includes instructions for testing your program using the provided sample tests.
* I will test your program with additional tests not posted in the test directory. It is a very good idea to design and implement your own set of tests.<br>

## Submitting Your Program

You MUST turn in your assignment several times (at least three) during development. Only the last submission has to compile and run and only the last submission will be graded. The submissions should show your progress (e.g. the first submission has a little bit of the program working, the second a little more, etc). When I suspect cheating I will look at these early submissions for a clear development trend; I want to prevent students from copying finished programs from another student and then turning them in.<br>

Turn in the following files using [Turnin](https://turnin.ecst.csuchico.edu):
```
main.cpp
bst.cpp
bst.h
```

All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

Assignments can be turned in up to 48 hours late with a 15% penalty.<br>

If you are unable to complete everything on time, you should still turn in whatever work you have. If you turn in nothing, you get a zero. If you turn in something, you receive partial credit.

## For an extra challenge (no points, just for fun)

No extra credit will be give to late assignments (both the regular assignment and the extra credit must be turned in on time).<br>

Implement a `remove` function:
```
remove<space><str>
If the string is in the tree and is removed, print nothing.
If the string is not in the tree, print the following to standard error:  "<str> not in tree and cannot be removed.\n"
```

The `remove` function must reorganize the tree so that it remains a binary search tree. However, you cannot simply reorganize the entire tree like in the `rebalance` command. You must make minimal changes to the tree so it remains a binary search tree. This is difficult, you will need to find a description of the algorithm online.

[Top of the Page](#program-7-binary-search-tree)
