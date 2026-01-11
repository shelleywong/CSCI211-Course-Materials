/*
 flight-convert.cpp
 Shelley Wong (swong26)
 Last updated: November 23, 2025

 This program can be used to convert a CSV file with Flight Delay Data for U.S.
 Airports by Carrier (August 2013 - August 2023) to an input file that uses a
 format similar to the input (.in) files we have used in CSCI 211 programming
 assignments (e.g. Video descriptions where the title, url, comment, length, and
 rating are all on different lines).

 Data downloaded from Kaggle:
 - https://www.kaggle.com/datasets/sriharshaeedala/airline-delay
 Original data source:
 - Bureau of Transportation Statistics, Airline Service Quality Performance 234
 More information for understanding flight delay data:
 - https://www.bts.gov/topics/airlines-and-airports/understanding-reporting-causes-flight-delays-and-cancellations

 For example, if the first line of data contains the metrics and the second line
 is the first entry, as shown below:
 year,month,carrier,carrier_name,airport,airport_name,arr_flights,arr_del15,carrier_ct,weather_ct,nas_ct,security_ct,late_aircraft_ct,arr_cancelled,arr_diverted,arr_delay,carrier_delay,weather_delay,nas_delay,security_delay,late_aircraft_delay
 2023,8,9E,Endeavor Air Inc.,ABE,"Allentown/Bethlehem/Easton, PA: Lehigh Valley International",89.00,13.00,2.25,1.60,3.16,0.00,5.99,2.00,1.00,1375.00,71.00,761.00,118.00,0.00,425.00

 Then this program will remove the first line and put all of the entries into
 the converted.in file looking like this:
 2023
 8
 9E
 Endeavor Air Inc.
 ABE
 "Allentown/Bethlehem/Easton, PA: Lehigh Valley International"
 89.00
 13.00
 2.25
 1.60
 3.16
 0.00
 5.99
 2.00
 1.00
 1375.00
 71.00
 761.00
 118.00
 0.00
 425.00

 In the commands below, I am starting with the `Airline_Delay_Cause.csv`
 file, and the converted output is put into a file called `converted.in`
 (using .in to indicate that this file can be used as input for your Final
 Project program).

 You can compile and run this program with the following commands:
 $ g++ -std=c++11 -o flight-convert flight-convert.cpp
 $ ./flight-convert Airline_Delay_Cause.csv converted.in
*/
#include <iostream>  // cin, cout, cerr, getline, endl
#include <fstream>  // ifstream, ofstream
#include <limits>   // numeric_limits
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

    // First line contains table headers. In this case, we want to ignore this
    // line (we just need the data that comes after this line)
    ifile.ignore(numeric_limits<streamsize>::max(), '\n');

    // Take each entry from the CSV file, grab the values (separated by commas),
    // remove the quotes from around each value, then output the data to an
    // output file, with each piece of data on a separate line

    /* Each row is a unique combination of year, month, carrier, and airport */
    string year; // The year of the data.
    string month; // The month of the data.
    string carrier; // Carrier code.
    string carrier_name; // Carrier name.
    string airport; // Airport code.
    string airport_name; // Airport name.

    /* Discrete counts/totals for number of flights */
    string arr_flights; // Number of arriving flights.
    string arr_del15; // Number of flights delayed by 15 minutes or more.

    /* Columns ending in *_ct: proportionally allocated "count" of delays
       (one flight delay might be attributed to multiple causes, so these
        "counts" sum up the fractions of the delay that are attributed to the
        given category -- all *_ct columns should sum up to arr_del15) */
    string carrier_ct; // Carrier count (delay due to the carrier, e.g. no crew).
    string weather_ct; // Weather count (delay due to weather).
    string nas_ct; // NAS (National Airspace System) count (delay due to the NAS, e.g. heavy air traffic).
    string security_ct; // Security count (delay due to security, e.g. security breach).
    string late_aircraft_ct; // Late aircraft count (delay due to late aircraft arrival (another flight on the same aircraft delayed).

    /* discrete counts of all flights scheduled to arrive at the specified
       airport that were cancelled or diverted */
    string arr_cancelled; // Number of flights canceled.
    string arr_diverted; // Number of flights diverted.

    /* columns ending in *_delay: Total arrival delay minutes (arr_delay), then
       the portion of total delay minutes attributed to each cause */
    string arr_delay; // Total arrival delay (total time in minutes of the delay)
    string carrier_delay; // Delay attributed to the carrier.
    string weather_delay; // Delay attributed to weather.
    string nas_delay; // Delay attributed to the NAS.
    string security_delay; // Delay attributed to security.
    string late_aircraft_delay; // Delay attributed to late aircraft arrival.


    // For each loop, we will get the data for a unique combination of year,
    // month, carrier, and airport
    int count = 0;
    while(getline(ifile, year, ',')) {
        getline(ifile, month, ',');
        getline(ifile, carrier, ',');
        getline(ifile, carrier_name, ',');
        getline(ifile, airport, ',');
        ifile.ignore(); // ignore first quotation mark around airport_name
        getline(ifile, airport_name, '"');
        ifile.ignore(); // ignore comma after airport_name
        getline(ifile, arr_flights, ',');
        getline(ifile, arr_del15, ',');
        getline(ifile, carrier_ct, ',');
        getline(ifile, weather_ct, ',');
        getline(ifile, nas_ct, ',');
        getline(ifile, security_ct, ',');
        getline(ifile, late_aircraft_ct, ',');
        getline(ifile, arr_cancelled, ',');
        getline(ifile, arr_diverted, ',');
        getline(ifile, arr_delay, ',');
        getline(ifile, carrier_delay, ',');
        getline(ifile, weather_delay, ',');
        getline(ifile, nas_delay, ',');
        getline(ifile, security_delay, ',');
        getline(ifile, late_aircraft_delay, '\n');

        // Add all data for one entry to the converted.in file. Each value will
        // be on 1 line -- if you use all data, each entry will be 21 lines).
        // You do not need to utilize all metrics -- feel free to comment-out
        // the data you will not be using in your analysis.
        ofile << year << endl;
        ofile << month << endl;
        ofile << carrier << endl;
        ofile << carrier_name << endl;
        ofile << airport << endl;
        ofile << airport_name << endl;
        // ofile << arr_flights << endl;
        // ofile << arr_del15 << endl;
        // ofile << carrier_ct << endl;
        // ofile << weather_ct << endl;
        // ofile << nas_ct << endl;
        // ofile << security_ct << endl;
        // ofile << late_aircraft_ct << endl;
        // ofile << arr_cancelled << endl;
        // ofile << arr_diverted << endl;
        // ofile << arr_delay << endl;
        // ofile << carrier_delay << endl;
        // ofile << weather_delay << endl;
        // ofile << nas_delay << endl;
        // ofile << security_delay << endl;
        // ofile << late_aircraft_delay << endl;
        count++;
    }

    // Count entries for a sanity check; for the Airline_Delay_Cause.csv file,
    // should have 171666 rows of data (not counting first row of table headings)
    cout << "Count: " << count << endl;
    ifile.close();
    ofile.close();

    return 0;
}

/*
  Usage recommendations from the Kaggle Flight Delay Data page:

  Usage:
  Researchers, analysts, and data enthusiasts can utilize this dataset for a
  variety of purposes, including but not limited to:

  * Performance Analysis: Assess the on-time performance of different carriers
    at specific airports and identify potential areas for improvement.

  * Trend Identification: Analyze temporal trends in delays, cancellations, and
    diversions to understand whether certain months or periods exhibit higher
    operational challenges.

  * Root Cause Analysis: Investigate the primary contributors to delays, such as
    carrier-related issues, weather conditions, NAS inefficiencies, security
    concerns, or late aircraft arrivals.

  * Benchmarking: Compare the performance of various carriers across different
    airports to identify industry leaders and areas requiring attention.

  * Predictive Modeling: Use historical data to develop predictive models for
    flight delays, aiding in the development of strategies to mitigate
    disruptions.

  * Industry Insights: Contribute to a broader understanding of the factors
    influencing operational efficiency within the U.S. aviation sector.

  As users explore and analyze the dataset, they can gain valuable insights that
  may inform decision-making processes, improve operational strategies, and
  contribute to a more efficient and reliable air travel experience.
*/
