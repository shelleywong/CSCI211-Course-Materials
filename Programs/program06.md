# Program 6: Shapes Drawing Program

CSCI 211: Programming and Algorithms II<br>
Points: 150

## Objectives

* Practice using Inheritance
* Practice using Polymorphism
* Use a virtual function
* Practice with 2D arrays

## Overview

The goal of this program is to provide practice in implementing inheritance in C++.<br>

You will create 5 shape classes: Shape (the base class), Square, Point, Triangle, Circle, and a Grid class. Each shape class will draw itself onto a Grid object.<br>

`Makefile` and `main()` files have been provided for you in 211-starter-pack/211/p6, so you don't have to worry about the compilation step or parsing the program input.<br>

The `main` program will read shape descriptions (square, point, triangle, circle) and draw them onto a `Grid`. It will then draw the grid. For example, the following input:
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

Class `Grid` contains a private 60x24 (60 wide and 24 high) grid of characters (a 2D array of char). Initially the grid will be initialized so that all characters are spaces (this is done in `Grid`'s only constructor `Grid()`). Class `Grid` must provide a set function so that the shapes can set individual characters in the grid. This function could have the prototype: `void Grid::set(int x, int y, char c)`. If the (x,y) values are inside the grid, set the (x,y) character in the grid to character `c`. If the (x,y) values are outside the grid, do nothing.<br>

Class `Grid` must also provide a print function: `void Grid::print()`. This function must draw the grid to standard output. `Grid::print()` should first draw all the characters in row 0 followed by an `endl`. Then it should draw all the characters in row 1 followed by an `endl`. And so on.<br>

Class `Shape` must be used as the base class for classes `Square`, `Triangle`, `Circle`, and `Point`. It must store the x and y location that the shape is to be drawn (I called the variables `m_x` and `m_y`). It will have a single constructor that takes x and y as arguments. In addition to the constructor, it will have a single member function `draw()` that must have a single argument, a reference to a `Grid` object (`void draw(Grid &grid)`).  This function must be a `pure virtual` function (learn this term, it will be on the next exam).<br>

You can make a virtual function into a pure virtual function by assigning it to zero in the base class declarations:
```
class Shape
{
    public:
        ...
        virtual void draw(Grid &grid) = 0;  // this is a pure virtual function
        ....
};
```
Pure virtual functions MUST be overridden by the sub class before the sub class can be instantiated.<br>

Class `Square` will inherit class `Shape`. It will provide a single constructor that will have three integer arguments: `x`, `y`, and `size`. It must also implement the `draw()` function. The `draw()` function will draw a size x size square into the Grid using the character '*'. For example, if size = 4, it would draw:
```
****
*  *
*  *
****
```
The x,y will determine where in the Grid the rectangle is drawn. For example, if x = 5, y = 6, the `*` in the top left corner of the square would be drawn at grid location 5,6. The square (and all the other shapes) will be drawn into the grid by calling `Grid::set()`. The `*` in upper left corner of this square would be drawn by calling `grid.set(5,6,'*')`. The next `*` would be drawn by `grid.set(6,6,'*')`.<br>

Class `Square` can be used like this:
```cpp
int main()
{
    Grid my_grid;
    Square my_square(5,7,10); // is located at x = 5, y = 7 and is 10x10 characters in size
    my_square.draw(my_grid);
    my_grid.print();
}
```

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

Class `Circle` works just like class `Triangle`, but uses 'o' (the lowercase letter o, not the number 0). All circles are the same size and must be drawn as shown below. Once again, put its top row in row y, and its leftmost column in col x (just like with triangle).
```
 oo
o  o
o  o
 oo
```

Class `Point`'s constructor takes the same (x,y) as the other shapes and a character: `Point(int x, int y, char c)`. It will draw the single character `c` at the location (x,y).

## Tips and Best Practices

This program has many classes and files. However, they are all very simple.  Once you get one shape working, creating the other shapes should be easy. Make sure you get one shape completely working before you start creating the others.<br>

> Note: It is best to start with the square.

The origin (x = 0, y = 0) of the grid is at the upper left. This simplifies the logic for drawing the grid. As an example, a square of size 2 drawn at (x,y) = (0,0) would occupy the following spots in the grid:
```
0,0
0,1
1,0
1,1
```

## General Requirements

Programs should be well formatted and consistent so they are easy to read. The same [General Requirements](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Programs/program01.md#general-requirements) listed in P1 apply here, including the guidelines for Comments, Formatting, and Style.<br>

Remember that the first lines of all your files (.h and .cpp) must contain the following comments:
```
// filename
// last name, first name
// ecst_username
```

## Testing Your Program

* Some sample tests and a Makefile are included in 211-starter-pack/211/p6.
* [Lab 2](https://github.com/shelleywong/CSCI211-Course-Materials/blob/main/Labs/lab02.md) includes instructions for testing your program using the provided sample tests.
* In this case, I will NOT test your program with any additional tests.<br>

## Submitting Your Program

Turn in the following files using [Turnin](https://turnin.ecst.csuchico.edu):
| .h file | .cpp file |
| --- | --- |
| grid.h | grid.cpp |
| shape.h | shape.cpp |
| triangle.h | triangle.cpp |
| square.h | square.cpp |
| circle.h | circle.cpp |
| point.h | point.cpp |

All programming assignments are **individual** assignments -- you are expected to complete and submit your own program.<br>

Assignments can be turned in up to 48 hours late with a 15% penalty.
