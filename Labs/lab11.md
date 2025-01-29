# Lab 11

Practice using the C++ Standard Template Library (STL)

Lab 11 Exercises
* [Exercise 1: Read and Print GPS Locations Using a Vector](#exercise-1-read-and-print-gps-locations-using-a-vector) (lab11_path)
* [Exercise 2: Read and Print Titles and Locations Using a Map](#exercise-2-read-and-print-titles-and-locations-using-a-map) (lab11_lookup)

## Exercise 1: Read and Print GPS Locations Using a Vector

Working in your CSCI211 starter-repo `211/lab11_path/` directory, write a program (called `path`) that reads a collection of GPS locations until end of input is reached. Each GPS location is expressed as two numeric coordinates: the first number is always latitude and the second number is always longitude. As each set of coordinates is read from standard input, create a new `Location` object and add the `Location` to a vector. AFTER all the input has been read, traverse the vector and print the GPS locations to standard output (`cout`). You can use the Location class `print` function to put each location on its own line with a comma between the latitude and longitude:<br>

The first four lines are the input. The second four lines are the output.
```
$ ./path
39.727565 -121.847693
39.729188 -121.846447
39.729807 -121.842767
39.729089 -121.842585
39.727565,-121.847693
39.729188,-121.846447
39.729807,-121.842767
39.729089,-121.842585
$
```

* Use the provided class `Location` to store each of the locations.
* Look at the provided location.h file to see how class `Location` works, but do not change anything in class `Location`.
* You must use a single STL vector to store all the `Location` object pointers.
* At the end of the program, you can traverse the vector and delete all location objects (similar to how you would traverse an array of pointers to objects to delete all objects); however, you are not required to call delete on the `Location` objects for this lab exercise.<br>

How to declare a vector of pointers to Foo objects and add one Foo object to the vector:
```cpp
#include <vector>
using namespace std;

int main()
{
    // declares a vector of pointers to class Foo
    vector<Foo *> my_foos;

    // create a new Foo object and insert it at end of the vector
    my_foos.push_back(new Foo());

    ...
}
```

Read about the [vector's operator[]](https://www.cplusplus.com/reference/vector/vector/operator[]/) to learn how to access elements in the vector similar to how you access elements in an array. You may use any of the [STL vector member functions](https://www.cplusplus.com/reference/vector/vector/).<br>

Submit `path.cpp` to INGInious.

## Exercise 2: Read and Print Titles and Locations Using a Map

Working in your CSCI211 starter-repo `211/lab11_lookup/` directory, write a program (called `lookup`) that reads a collection of GPS locations and titles. Each title is a string without any spaces. You should use the provided `Location` class to hold the GPS locations (this class is the same as the Location class in Exercise 1). Continue reading locations and titles from standard input until the user enters 0 (while using 0 to signal the end of input is limiting, it makes writing the program much easier). You should **not** use EOF here, because your program will need to handle input after it receives all pairs of GPS locations and titles.<br>

After 0 is entered, read titles from standard input until the end of input. As each title is read, look up the title in the map. If the location is found, print the location associated with the title (see below for how the output should be formatted). If the title is not in the map, print the message (shown below) indicating that the title is not in the database.<br>

The following input:
```
39.727565   -121.847693   211_Lab
39.729188   -121.846447   211_Lecture
39.729807   -121.842767   Celestinos_Pizza
39.729089   -121.842585   The_Bear
0
The_Bear
311_Lecture
Celestinos_Pizza
```

Should produce this output (all messages, including the error message, should be printed to standard output):
```
The_Bear is at 39.729089,-121.842585
311_Lecture not in database
Celestinos_Pizza is at 39.729807,-121.842767
```

* You must use a C++ STL map to store the title/location pairs.
* You can read the [STL map documentation](https://www.cplusplus.com/reference/map/map/) for more information. Explore the map member functions to find examples of how to use the STL map.
  * Hint: The [insert function](https://cplusplus.com/reference/map/map/insert/) and the [find function](https://cplusplus.com/reference/map/map/find/) may be useful.
  * Hint: you can use the [operator[]](https://cplusplus.com/reference/map/map/operator[]/) to insert elements into a map in a way that is similar to how you set values in an array (just be aware that you are actually adding an element to the map when you use the [] brackets with a key that did not previously exist)
* You do not have to call delete on the Location objects for this exercise.<br>

> HINT: The map's `find` function returns an iterator. You may find it helpful to review the slides from Lecture 10: Templates, STL.<br>

Submit `lookup.cpp` to INGInious.

## Exercise 3 (no points, just for fun)

Working in your CSCI211 starter-repo `211/lab11_google/` directory, modify the program in Exercise 2 so that instead of printing the lat/long when you find a location in the map, print a complete Google Maps URL:

```
The_Bear is at __________
```
where the `__________` is replace with the URL.<br>

You can test your URL by pasting it into a browser. If the target is shown, then your URL is correct. Everything else about this program should be the same as the lookup program in Exercise 2.<br>

The Google Maps URL has changed since this exercise was originally assigned, so actually getting an accurate location marker requires more information than just the coordinates mentioned above. However, your URL should return a map that centers on Chico, CA.

## Lab 11 Submissions

All labs are due at 11:59pm the Friday following lab. For this lab you must submit `path.cpp` (Exercise 1) and `lookup.cpp` (Exercise 2) to [INGInious](https://inginious.csuchico.edu/). If you are not able to complete all the exercises, turn in your partial work for partial credit, or submit later for late credit.<br>

Optional but recommended submission step: confirm the changes that have been made to the repo using `git status` and then add, commit, and push your code to GitHub (the `add` command with the `-A` option updates all files in the working tree):
```
$ git status
$ git add -A
$ git commit -m "completes lab11 exercises"
$ git push origin main
```

[Top of the Page](#lab-11)
