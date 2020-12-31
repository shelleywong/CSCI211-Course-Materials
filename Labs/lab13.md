# Lab 13

Practice using the C++ Standard Template Library (STL)

## Exercise 1

Working in your 211-starter-pack/211/lab13_path directory, write a program (called `path`) that reads a collection of GPS locations (latitude & longitude) until end of input is reached. AFTER all the input has been read, print the GPS locations to standard output. Put each location on its own line with a comma between the latitude and longitude:<br>

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
* You must use a single STL vector to store all the `Location` object pointers.
* You do not have to call delete on the `Location` objects.<br>

How to use a vector:
```cpp
#include <vector>
using namespace std;

int main()
{
    vector<Foo *> my_foos;  // declares a vector of pointers to class Foo

    my_foos.push_back(new Foo()); // create a new Foo object and insert it at end of the vector

    ...

}
```

Read about the [vector's operator[]](https://www.cplusplus.com/reference/vector/vector/operator[]/) to learn how to access elements in the vector.<br>

Turn in path.cpp.

## Exercise 2

Working in your 211-starter-pack/211/lab13_lookup directory, write a program (called `lookup`) that reads a collection of GPS locations and titles (title is a string without any spaces). Continue reading locations until the user enters 0 (using 0 to end the input limits the program, but it makes writing it much easier).<br>

After 0 is entered, read titles until end of input. After each title is read, look it up in the map and print the location associated with the title.  If the title is not in the map, print the message shown below.<br>

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

Should produce this output (print the error message to standard output):
```
The_Bear is at 39.729089,-121.842585
311_Lecture not in database
Celestinos_Pizza is at 39.729807,-121.842767
```

* You must use a C++ STL map to store the title/location pairs.
* You can read the [STL map documentation](https://www.cplusplus.com/reference/map/map/) for more information. Explore the map member functions to find examples of how to use the STL map.
* You do not have to call delete on the Location objects.<br>

HINT: The map's `find` function returns an iterator.<br>

Turn in lookup.cpp

## Exercise 3 (no points, just for fun)

Working in your 211-starter-pack/211/lab13_google directory, modify the program in Exercise 2 so that instead of printing the lat/long when you find a location in the map, print a complete Google Maps URL:

```
The_Bear is at __________
```
where the `__________` is replace with the URL.<br>

You can test your URL by pasting it into a browser. If the target is shown, then your URL is correct. Everything else about this program should be the same as the lookup program in Exercise 2.<br>

The Google Maps URL has changed since this exercise was originally assigned, so actually getting an accurate location marker requires more information than just the coordinates mentioned above. However, your URL should return a map that centers on Chico, CA.
