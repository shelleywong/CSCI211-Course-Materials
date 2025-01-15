/*
 weather.cpp
 Shelley Wong (swong26)
 Last updated: January 14, 2025

 This program can be used to convert a CSV file with NOAA climate data to an
 input file that uses a format similar to the input (.in) files we have used in
 CSCI 211 programming assignments (e.g. Video descriptions where the title, url,
 comment, length, and rating are all on different lines).

 For example, if the first line of data looks like this:
 "USC00042402","DE SABLA, CA US","2005-01-01","1.18","0.0",,"42","30"

 This program will put it into the converted.in file looking like this:
 USC00042402
 DE SABLA CA US
 2005-01-01
 1.18
 0.0
 none
 42
 30

 In the commands below, I am starting with the `chico-weather-2005-2024.csv`
 file, and the converted output is put into a file called `converted.in`
 (using .in to indicate that this file can be used as input for your Final
 Project program).

 You can compile and run this program with the following commands:
 $ g++ -std=c++11 -o weather weather.cpp
 $ ./weather chico-weather-2005-2024.csv converted.in
*/
#include <iostream>  // cin, cout, cerr, getline, endl
#include <fstream>  // ifstream, ofstream
#include <limits>   // numeric_limits
using namespace std;

// If string is not empty, remove quotation marks at start and end of string
// Otherwise, set this string to be a value that indicates it is empty (I am
// using "none" in this case, but you may want to use a different value)
void formatString(string& str){
    if(str != ""){
        str = str.substr(1, str.size()-2);
    }
    else{
        str = "none";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3){
        cerr << "Must specify input and output file." << endl;
        return 1;
    }
    if (argc > 3){
        cerr << "Too many command line arguments specified." << endl;
        return 1;
    }

    // 1st command line argument should be the CSV file
    ifstream ifile(argv[1]);
    // 2nd arg is the name of the file that will hold the converted data
    ofstream ofile(argv[2]);

    // Make sure you can open the CSV file
    if (!ifile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // First line contains table headers. In this case, we want to ignore this
    // line (we just need the data that comes after this line)
    ifile.ignore(numeric_limits<streamsize>::max(), '\n');

    // Take each entry from the CSV file, grab the values (separated by commas),
    // remove the quotes from around each value, then output the data to an
    // output file, with each piece of data on a separate line
    string station;   // Station ID
    string name;      // Station Name/Location
    string name2;     // Station Name part 2 (State and Country)
    string date;      // date in YYYY-MM-DD format
    string prcp;      // precipitation
    string snow;      // snowfall
    string tavg;      // average temperature
    string tmax;      // maximum temperature
    string tmin;      // minimum temperature
    // For each loop, we will get the historical daily weather data for one
    // station on one day
    while(getline(ifile, station, ',')) {
        getline(ifile, name, ',');
        getline(ifile, name2, ',');
        name = name + name2;  // creates name without comma
        getline(ifile, date, ',');
        getline(ifile, prcp, ',');
        getline(ifile, snow, ',');
        getline(ifile, tavg, ',');
        getline(ifile, tmax, ',');
        getline(ifile, tmin, '\n');

        // remove quotation marks and give empty entries a placeholder value
        formatString(station);
        formatString(name);
        formatString(date);
        formatString(prcp);
        formatString(snow);
        formatString(tavg);
        formatString(tmax);
        formatString(tmin);

        // Add all data for one entry to the converted.in file
        // (each value will be on 1 line, so each entry will be 8 lines)
        ofile << station << endl;
        ofile << name << endl;
        ofile << date << endl;
        ofile << prcp << endl;
        ofile << snow << endl;
        ofile << tavg << endl;
        ofile << tmax << endl;
        ofile << tmin << endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}
