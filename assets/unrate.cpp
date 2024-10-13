/*
 unrate.cpp
 Shelley Wong (swong26)
 Last updated: Oct 13, 2024

 This program can be used to convert a CSV file with FRED economic data to an
 input file that uses a format similar to the input (.in) files we have used in
 CSCI 211 programming assignments (e.g. Video descriptions where the title, url,
 comment, length, and rating are all on different lines). In the commands below,
 I am starting with the `UNRATE-SeasonallyAdjusted-Sep2024.csv` file, and the
 converted output is put into a file called `converted.in` (using .in to
 indicate that this file can be used as input for your Final Project program).

 You can compile and run this program with the following commands:
 $ g++ -std=c++11 -o unrate unrate.cpp
 $ ./unrate UNRATE-SeasonallyAdjusted-Sep2024.csv converted.in
*/
#include <iostream>  // cin, cout, cerr, getline, endl
#include <fstream>  // ifstream, ofstream
using namespace std;

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

    // remove line of table headers
    string table_headers;
    getline(ifile, table_headers);

    // Take each entry from the CSV file, get the input for each column
    // (separated by commas), then add the data for each entry to a file
    // which can be used like the .in input files in CSCI211 programs
    string date;
    string unrate;
    // Get historical monthly input for one measurement
    while (getline(ifile, date, ',')) {
        getline(ifile, unrate, '\n');

        // Add all data for one entry to the converted.in file
        // (each value will be on 1 line, so each entry will be 2 lines)
        ofile << date << endl;
        ofile << unrate << endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}
