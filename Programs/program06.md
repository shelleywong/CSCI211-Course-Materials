# Program 6: Shapes Drawing Program

CSCI 211: Programming and Algorithms II<br>
Points: 150

* [Objectives](#objectives)
* [Overview](#overview)
* [Program Requirements](#program-requirements)
* [Helpful Hints](#helpful-hints)
* [General Requirements](#general-requirements)
* [Testing Your Program](#testing-your-program)
* [Submitting Your Program](#submitting-your-program)

## Objectives

* Practice using Inheritance
* Practice using Polymorphism
* Use a virtual function
* Practice with 2D arrays

## Overview

The goal of this program is to provide practice implementing inheritance in C++.<br>

You will create several classes:
* The base class:
  * Shape
* Derived classes that inherit from Shape:
  * Square
  * Point
  * Triangle
  * Circle
* A Grid class (each Shape class will draw itself onto a Grid object)<br>

> Note: A `Makefile` and `main.cpp` file have been provided for you in the CSCI211 starter-repo `211/p6/` directory, so you don't have to worry about the compilation step or parsing the program input.

The `main` program will read shape descriptions (for square, point, triangle, and circle), create corresponding shape objects, and then draw each shape onto a `Grid` object. For example, the following input:
```
square 0 0 24
square 2 5 4
triangle 10 10
circle 5 16
point 15 3 ?
```

Must produce the output:
```
************************
*                      *
*                      *
*              ?       *
*                      *
* ****                 *
* *  *                 *
* *  *                 *
* ****                 *
*                      *
*           +          *
*          + +         *
*         +++++        *
*                      *
*                      *
*                      *
*     oo               *
*    o  o              *
*    o  o              *
*     oo               *
*                      *
*                      *
*                      *
************************
```

> Note: Start early and make incremental progress. If you think you can finish a programming assignment in one day, finish it the first day it is assigned. Students who put off these assignments tend to have a bad time.

## Program Requirements

You must be careful to use the exact structure, function names, and filenames or your program won't compile with the provided `main`.<br>

### The Grid Class
* Class `Grid` contains a private 60x24 (60 wide and 24 high) grid of characters.
  * The grid should be implemented as a 2D char array (member data of class Grid).
* In the `Grid()` constructor, initialize the grid so that all characters in the grid are spaces.
* Class `Grid` must provide a `set()` function so that the shapes can set individual characters in the grid.
  * This function could have the prototype: `void Grid::set(int x, int y, char c)`.
  * If the (x,y) values are inside the grid, set the (x,y) character in the grid to character `c`.
  * Make sure that any (x,y) values that land outside of the grid are not drawn on the grid (i.e. do nothing with this input).<br>
* Class `Grid` must also provide a print function that draws the grid to standard output.
  * This function could have the prototype: `void Grid::print()`.
  * `Grid::print()` should first draw all the characters in row 0 followed by an `endl`. Then it should draw all the characters in row 1 followed by an `endl`. And so on.<br>

Before you start working on the Shapes, you can compile and test the Grid class using grid_test.cpp (included in the P6 starter pack files):
```
$ make grid_test
$ ./grid_test
```
This test code instantiates a Grid object, draws a couple characters onto the grid, and then prints the grid. You can use this example to confirm that your grid is being drawn as expected (the characters drawn onto the grid identify the upper left hand corner and lower right hand corner of your grid).

### The Base Class

* Class `Shape` must be used as the base class for several derived classes: `Square`, `Triangle`, `Circle`, and `Point`.
* It must store the x and y location where the shape will be drawn (I called the variables `m_x` and `m_y`).
* It will have a single constructor that takes x and y as arguments.
* In addition to the constructor, it will have a single member function `draw()` that must have a single argument, a reference to a `Grid` object (`void draw(Grid &grid)`). This function must be a `pure virtual` function (learn this term, it may be on the next exam).<br>

> Note: In most cases, all class member variables are declared with private member access, because we don't want them to be directly accessible by any object or function outside the class. In this case, we can make base class members `protected` and allow derived classes to have access to these member variables. In this case, we would not need to define the same member variables again in the derived class. The derived class could have private, protected, or public base class access.

You can make a virtual function into a pure virtual function by assigning it to zero in the base class declarations:
```cpp
class Shape
{
    public:
        ...
        virtual void draw(Grid &grid) = 0;  // this is a pure virtual function
        ....
};
```
Pure virtual functions MUST be overridden by the sub class before the sub class can be instantiated.<br>

* In general, you should make all member variables `private`. However, when working with inheritance, you can give member variables `protected` access.
  * `protected` member variables are accessible to the base class that defines them and any derived classes that inherit from the base class.
  * `protected` members are not accessible outside of the base class and derived classes so, similar to `private` members, they cannot be accessed outside of the classes that use them.

### The Derived Classes

#### Class Square

* Class `Square` will inherit class `Shape`.
* It will provide a single constructor that will have three integer arguments: `x`, `y`, and `size`.
* It must also implement the `draw()` function. The `draw()` function will draw a `size x size` square into the Grid using the character `*`. For example, if size = 4, it would draw:
```
****
*  *
*  *
****
```
* The (x,y) will determine where in the Grid the rectangle is drawn. For example, if x = 5, y = 6, the `*` in the top left corner of the square would be drawn at grid location (5,6).
* The square (and all the other shapes) will be drawn into the grid by calling `Grid::set()`. The `*` in upper left corner of this square would be drawn by calling `grid.set(5,6,'*')`. The next `*` would be drawn by `grid.set(6,6,'*')`.<br>

Class `Square` can be used like this:
```cpp
int main()
{
    Grid my_grid;
    // This creates a Square object located at x = 5, y = 7 on the grid
    // The Square is 10x10 characters in size
    Square my_square(5,7,10);
    my_square.draw(my_grid);
    my_grid.print();
}
```

#### Class Triangle

Class `Triangle` works just like class `Square`, but all triangles are the same size, and it uses the character '+'. Thus, the constructor only takes x and y: `Triangle::Triangle(int x, int y)`. Triangles must be drawn as shown below:
```
  +
 + +
+++++
```

Position the triangle so its top is in row y and its left most `+` is in column x.  The # in the next diagram shows where the (x,y) point is.
```
# +
 + +
+++++
```

#### Class Circle

Class `Circle` works just like class `Triangle`, but uses 'o' (the lowercase letter o, not the number 0). All circles are the same size and must be drawn as shown below. Once again, put its top row in row y, and its leftmost column in col x (just like with triangle).
```
 oo
o  o
o  o
 oo
```

#### Class Point

Class `Point`'s constructor takes the same (x,y) as the other shapes and a character: `Point(int x, int y, char c)`. It will draw the single character `c` at the location (x,y).

## Helpful Hints

This program has many classes and files. However, they are all very simple. Work step by step:
* First, complete the Grid class
* Second, complete the Shape class
* Third, complete the classes that inherit from Shape. Once you get one shape working, creating the other shapes should be easy. Make sure you get one shape completely working before you start creating the others.<br>

> Note: It is best to start with the square.

The origin (x = 0, y = 0) of the grid is at the upper left. This simplifies the logic for drawing the grid. As an example, a square of size 2 drawn at (x,y) = (0,0) would occupy the following spots in the grid:
```
0,0
0,1
1,0
1,1
```

The primary purpose of this program is to give you practice working with inheritance. Since you are not submitting main.cpp, you do not need to worry about memory management. However, you may notice that main.cpp uses dynamic memory to instantiate each Shape object. To avoid memory leaks, you would need to do a couple things:
* Delete all Shape objects at the end of `main()`:
```cpp
for (unsigned int i = 0; i < shapes.size(); i++) {
  delete shapes[i];
}
```
* Create a virtual Shape destructor in the Shape class:
```cpp
virtual ~Shape() {};
```
  * The Shape destructor does not need to do anything in this case; however, if the base class destructor is not `virtual`, it will cause undefined behavior. Making the function `virtual` ensures that the destructor for each derived class gets called.
  * The derived class destructors do not need to do anything if you are not using `new` to allocate memory in the derived classes.

## General Requirements

Programs should be well formatted and consistent so they are easy to read. The [General Requirements](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/README.md#general-requirements) listed in the Programs directory README apply to all programming assignments.<br>

Remember that the first lines of all your files (.h and .cpp) must contain the following comments:
```
// filename
// your name (first and last)
// your Chico Portal/INGInious username
// Short summary of the file contents
```

## Testing Your Program

* Some sample tests and a Makefile are included in the CSCI211 starter-repo `211/p6/`.
* Test your code before submitting it to INGInious -- you can review the instructions for Testing Assignments using the provided sample tests in the [Labs directory README](https://github.com/shelleywong/CSCI211-Course-Materials/tree/main/Labs).
* In this case, I will NOT test your program with any additional tests.<br>

## Submitting Your Program

You should aim to turn in your assignment several times (at least three) during development. The submissions should show your progress (e.g. the first submission has a little bit of the program working, the second a little more, etc). When I suspect cheating I will look at these early submissions for a clear development trend; I want to prevent students from copying finished programs from another student and then turning them in. Alternatively, you can show your progress by making several commits to your GitHub repo for each program:
```
$ git add -A
$ git commit -m "<descriptive commit message>"
$ git push origin main
```

Your best INGInious submission will be evaluated for grading, so it is fine if some submissions do not pass all the tests. If multiple submissions pass the same number of tests, your last best submission will be used for grading.<br>

Turn in the following files using [INGInious](https://inginious.csuchico.edu/):
| .h files | .cpp files |
| --- | --- |
| grid.h | grid.cpp |
| shape.h | shape.cpp |
| triangle.h | triangle.cpp |
| square.h | square.cpp |
| circle.h | circle.cpp |
| point.h | point.cpp |

All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

If you are not able to complete this programming assignment, turn in your partial work for partial credit, or submit later for late credit. If you turn in nothing, you get a zero. If you turn in something, you receive a grade that is higher than zero.

[Top of the Page](#program-6-shapes-drawing-program)
