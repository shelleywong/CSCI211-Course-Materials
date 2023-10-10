/*
 elec.cpp
 Shelley Wong (swong26)
 Last updated: Oct 10, 2023

 This program can be used to convert a CSV file with U.S. Department of energy
 alternative fuel station data to an input file that uses a format similar to
 the input (.in) files we have used in CSCI 211 programming assignments (e.g.
 Video descriptions where the title, url, comment, length, and rating are all on
 different lines). In the commands below, I am starting with the
 `alt_fuel_stations_oct_10_23.csv` file, and the converted
 output is put into a file called `converted.in` (using .in to indicate that
 this file can be used as input for your Final Project program). Note that any
 empty fields will be left blank (appears as an empty line in converted.in)

 Note: the alt_fuel_stations_oct_10_23.csv file contains Electric (ELEC)
 charging fuel stations only; however, the data fields include different types
 of alternative fuel station options: biodiesel (BD), compressed natural gas (CNG),
 ethanol (E85), hydrogen (HY), liquefied natural gas (LNG), propane (LPG), and
 renewable diesel (RD)). If you would like, you can download a dataset that
 includes the other alternative fuel station options

 You can compile and run this program with the following commands:
 $ g++ -std=c++11 -o alt alt.cpp
 $ ./alt alt_fuel_stations_oct_10_23.csv converted.in
*/
#include <iostream>  // cin, cout, cerr, getline, endl
#include <fstream>  // ifstream, ofstream
#include <sstream>  // istringstream
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

    // Take each entry from the CSV file, grab the values (separated by commas),
    // remove the quotes from around each value, then create an instance of a
    // Data struct and add it to our dataList vector
    string line;
    while (getline(ifile, line)) {
        istringstream iss(line);
        string fuelType; // Fuel Type Code (I only downloaded electric, ELEC)
        string station; // name of the station
        string street; // street address of the station's location
        string intersection; // Brief info about how to locate the station.
        string city;  // city of station's location
        string state;  // 2 character code for U.S. state or Canadian province/territory of station's location.
        string zip;  // zip code (postal code) of the station's location
        string plus4; // The plus-4 portion of the station's ZIP code (U.S. ZIP codes only).
        string phone; // phone number of the station
        string status; // current status of the station, given as code values (E = available, P = planned, T = temporarily unavailable)
        string expectedDate; // For planned stations, date the station is expected to open or start carrying alt fuel. For temporarily unavailable stations, the date station is expected to reopen (date is estimated)
        string groups; // groups with access code (public, private, call ahead, etc)
        string accessDaysTime; // hours of operation, other access info
        string cards; // payment methods accepted (e.g. credit, debit, cash, android/apple pay, etc)
        string bdBlends; // For biodiesel stations, the level of biodiesel blends the station provides.
        string ngFill; // For CNG stations, the type of dispensing capability available (fast-fill, time-fill)
        string ngPSI; // For CNG stations, a space separated list of PSI pressures available.
        string evLev1; // For electric stations, the number of Level 1 EVSE ports.
        string evLev2; // For electric stations, the number of Level 2 EVSE ports.
        string evDCFast; // For electric stations, the number of DC Fast EVSE ports.
        string evOther; // For electric stations, number and type of additional EVSE ports, such as: SP Inductive - Small paddle inductive, LP Inductive - Large paddle inductive, Avcon Conductive
        string evNetwork; // For electric stations, the name of the EV charging network, if applicable (e.g. ChargePoint, Tesla)
        string evNetWeb; // For electric stations, the EV charging network Web site, if applicable.
        string geocode; // A rating indicating the approximate accuracy of the latitude and longitude for the station's address, given as code values
        string lat; // The latitude of the station's address
        string lon; // The longitude of the station's address
        string dateLastConfirmed; // The date the station's details were last confirmed.
        string id; // A unique identifier for this specific station.
        string updated; // The time the station's details were last updated (ISO 8601 format).
        string ownerType; // The type of organization that owns the fueling infrastructure. Owner types are given as code values (FG - federal government owned, P - privately owned, T - utility owned, etc)
        string fedID; // Federal Agency ID (unique identifier)
        string fedName; // Federal Agency name
        string openDate; // The date that the station began offering the fuel. Note that most propane (LPG) stations do not have open dates. Some open dates are approximate
        string hydrogenStatusLink; // For hydrogen stations, a link to a website that provides up-to-date information about the current status of this hydrogen station.
        string ngVehicleClass; // maximum vehicle size that can physically access the fueling infrastructure
        string lpgPrimary; // for propane stations (primary (staffed, can fill vehicles at a rate similar to filling a gas vehicle, accepts credit/fleet cards) or secondary)
        string e85blend; // for E85 stations, whether station has a Blender Pump on site
        string evConnect; // For electric stations, an array of strings identifying the connector types available at this station (NEMA520, CHADEMO, TESLA, etc)
        string country; // The two character country code of the station's location (United States (US) or Canada (CA))
        string intersectionFr; // Brief additional information about how to locate the station, in French, if available
        string accessDayTimesFr; // Hours of operation for the station, in French, if available.
        string bdBlendsFr; // For biodiesel stations, the level of biodiesel blends the station provides, in French, if available.
        string groupsWithAcessFr; // A description of who is allowed to access the station and other station access information, in French, if available.
        string hydrogenIsRetail; // For hydrogen stations, whether a station offers the retail sale of hydrogen by accepting payment at the point of sale
        string accessCode; // A description of who is allowed to access the station, given as code values (true or false)
        string accessDetail; // A description of other station access information, given as code values (call ahead, goverment only, card key after hours or at all times, etc)
        string fedAgency; // If the station is owned by a federal agency, a record for the federal agency that owns this station.
        string facilityType; // The type of facility at which the station is located, given as code values (airport, arena, hotel, college campus, etc)
        string cngDispenser; // For CNG stations, the number of CNG dispensers installed.
        string cngOnSite; // For CNG stations, the type of renewable energy used to generate CNG on-site (hydro, solar, wind, etc)
        string cngTotal; // For CNG stations, the total compressor capacity per compressor, measured in standard cubic feet per minute (scfm).
        string cngStorage; // For CNG stations, the total storage capacity, measured in standard cubic feet (scf).
        string lngOnSite; // For LNG stations, the type of renewable energy used to generate LNG on-site, given as code values (hydro, solar, wind, etc)
        string e85other; // For E85 stations, an array of strings identifying the range(s) of blends other than E85 available at the station, given as code value
        string evPricing; // For electric stations, information about whether and how much users must pay to use the EVSE port.
        string evPricingFr; // For electric stations, information about whether and how much users must pay to use the EVSE port, in French, if available.
        string lpgNozzle; // For LPG stations, an array of strings, identifying the type of nozzles available at the station, given as code values
        string hydrogenPress; // For hydrogen stations, any array of strings identifying the pressures of the hydrogen available (in bar), given as code values
        string hydrogenStan; // For hydrogen stations, any array of strings identifying which SAE International fueling protocol standard(s) the infrastructure meets, given as code values
        string cngFill; // For CNG stations, the type of dispensing capability available, given as code values
        string cngPSI; // For CNG stations, a space separated list of PSI pressures available.
        string cngVehicle; // For CNG stations, the maximum vehicle size that can physically access the fueling infrastructure, given as code values (passenger vehicles (LD), medium-duty (MD), heavy-duty (HD))
        string lngVehicle; // For LNG stations, the maximum vehicle size that can physically access the fueling infrastructure, given as code values (passenger vehicles (LD), medium-duty (MD), heavy-duty (HD))
        string evOnSiteRenew; // For electric stations, the type of renewable energy used to generate electricity on-site, given as code values (hydro, solar, wind, etc)
        string restricted; // For public stations, an indication of whether the station has restricted access, given as a boolean
        string rdBlends; // For renewable diesel stations, the level of renewable diesel blends the station provides.
        string rdBlendsFr; // For renewable diesel stations, the level of renewable diesel blends the station provides, in French, if available.
        string rdBlendBio; // For renewable diesel stations, whether the station provides renewable diesel blended with biodiesel, given as code values
        string rdMax; // For renewable diesel stations, the maximum biodiesel level if blended with biodiesel.
        string npsUnit; // NPS Unit name (national parks unit?)
        string cngStation; // For CNG stations, whether the station sells renewable natural gas (RNG), given as code values
        string lngStation; // For LNG stations, whether the station sells renewable natural gas (RNG), given as code values
        string maxVehicle; // The maximum vehicle size that can physically access the fueling infrastructure, given as code values
        string evWork; // For electric stations, an indication of whether the station is available for employees at a workplace, given as a boolean



        // Get input for each station
        getline(iss, fuelType, ',');
        getline(iss, station, ',');
        getline(iss, street, ',');
        getline(iss, intersection, ',');
        getline(iss, city, ',');
        getline(iss, state, ',');
        getline(iss, zip, ',');
        getline(iss, plus4, ',');
        getline(iss, phone, ',');
        getline(iss, status, ',');
        getline(iss, expectedDate, ',');
        getline(iss, groups, ',');
        getline(iss, accessDaysTime, ',');
        getline(iss, cards, ','); //
        getline(iss, bdBlends, ',');
        getline(iss, ngFill, ',');
        getline(iss, ngPSI, ',');
        getline(iss, evLev1, ',');
        getline(iss, evLev2, ',');
        getline(iss, evDCFast, ',');
        getline(iss, evOther, ',');
        getline(iss, evNetwork, ',');
        getline(iss, evNetWeb, ',');
        getline(iss, geocode, ',');
        getline(iss, lat, ',');
        getline(iss, lon, ',');
        getline(iss, dateLastConfirmed, ',');
        getline(iss, id, ',');
        getline(iss, updated, ',');
        getline(iss, ownerType, ',');
        getline(iss, fedID, ',');
        getline(iss, fedName, ',');
        getline(iss, openDate, ',');
        getline(iss, hydrogenStatusLink, ',');
        getline(iss, ngVehicleClass, ',');
        getline(iss, lpgPrimary, ',');
        getline(iss, e85blend, ',');
        getline(iss, evConnect, ',');
        getline(iss, country, ',');
        getline(iss, intersectionFr, ',');
        getline(iss, accessDayTimesFr, ',');
        getline(iss, bdBlendsFr, ',');
        getline(iss, groupsWithAcessFr, ',');
        getline(iss, hydrogenIsRetail, ',');
        getline(iss, accessCode, ',');
        getline(iss, accessDetail, ',');
        getline(iss, fedAgency, ',');
        getline(iss, facilityType, ',');
        getline(iss, cngDispenser, ',');
        getline(iss, cngOnSite, ',');
        getline(iss, cngTotal, ',');
        getline(iss, cngStorage, ',');
        getline(iss, lngOnSite, ',');
        getline(iss, e85other, ',');
        getline(iss, evPricing, ',');
        getline(iss, evPricingFr, ',');
        getline(iss, lpgNozzle, ',');
        getline(iss, hydrogenPress, ',');
        getline(iss, hydrogenStan, ',');
        getline(iss, cngFill, ',');
        getline(iss, cngPSI, ',');
        getline(iss, cngVehicle, ',');
        getline(iss, lngVehicle, ',');
        getline(iss, evOnSiteRenew, ',');
        getline(iss, restricted, ',');
        getline(iss, rdBlends, ',');
        getline(iss, rdBlendsFr, ',');
        getline(iss, rdBlendBio, ',');
        getline(iss, rdMax, ',');
        getline(iss, npsUnit, ',');
        getline(iss, cngStation, ',');
        getline(iss, lngStation, ',');
        getline(iss, maxVehicle, ',');
        getline(iss, evWork, '\n');

        // Add data for one entry to the converted.in file.
        // I recommend NOT using ALL data (76 data fields) -- just add the
        // fields that you want to focus on for your project
        ofile << station << endl;
        ofile << city << endl;
        ofile << state << endl;
        ofile << status << endl;
        ofile << accessDaysTime << endl;
        ofile << cards << endl;
        ofile << evLev1 << endl;
        ofile << evLev2 << endl;
        ofile << evDCFast << endl;
        ofile << evNetwork << endl;
        ofile << evPricing << endl;
        ofile << restricted << endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}
