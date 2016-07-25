/**
 * @file: main.cpp (current working version of code here)
 *
 * @title: C++ classes for Manipulating CSV Files
 *
 * Copyright 2016 David York <david@debian2x8david>
 *
 * @author David York
 * @contributors  no others
 * @date Friday July 20, 2016
 * @version 0.02
 *
 * @description Classes to provide C++ tools to manipulate CSV files,
 *       including reading and writing such files from and to disk
 *       into a string data structure then parsing the individual fields
 *       from the string structure.
 *
 * @license:
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_vector.h>
// #include <atlas/cblas.h>   // uses atlas version of blas, is faster?

using namespace std;


/** Declarations */
map<string, pair<string, int> > headerKey;
tuple<> dataRow;

/** Classes */
class UtilCSV
{
protected:
    string fromCSVFile;
    int readToLine;
    bool hasHeader;
    vector<string> csvToParse;
    vector<string> parsedCSV;
    list<tuple<> > dataStruct;


public:
    /** Constructors */
    // Default constructor
    UtilCSV() {}

    // Full constructor
    UtilCSV(string frCSV, bool header, int rtoline = 0) {
        fromCSVFile = frCSV;
        hasHeader = header;
        readToLine = 0;
        csvToParse = getCSV();
        parsedCSV = parseCSVLine(csvToParse);

    }


    /** Methods */
    //Accessors
    list<tuple<> > getDataStruct() {
        return dataStruct;
    }

    vector<string> parseCSVLine(vector<string> internCSVToParse) {
        vector<string> internParsedCSV = internCSVToParse;
        return internParsedCSV;
    }

    vector<string> getCSV() {
        vector<string> theCSV;
        string inFileLine;
        ifstream infile(fromCSVFile.c_str(), ios::in);
        if(hasHeader) {
            infile >> inFileLine;
            theCSV.push_back(inFileLine+"\n");

        }
        do {
            infile >> inFileLine;
            theCSV.push_back(inFileLine+"\n");
        } while(!infile.eof() );
        infile.close();
        return theCSV;
    }
    void putCSV() {}


    void displayInternCSV() {
        cout << "unparsed:" << endl;
        for(unsigned int i = 0; i < csvToParse.size(); ++i){
            cout << csvToParse[i];
        }
        cout << endl << "parsed:"<< endl;

        for(unsigned int i = 0; i < parsedCSV.size(); ++i){
            cout << parsedCSV[i];
        }
        cout << endl;

    }

    string toString() {
        string internalContent;
        return internalContent;
    }

};



/**
 * Main is Unit test code for the classes here
 */
int main()
{
    string frmCSV ="./data/AirPassengers.csv";
    bool hHeader = true;
    cout << endl <<"UtilCSV Unit Testing" << endl << endl;
    UtilCSV Airpass(frmCSV, hHeader);
    Airpass.displayInternCSV();
    /*vector<string> csvFile = Airpass.getCSV();
    for(unsigned int i = 0; i < csvFile.size(); ++i){
        cout << csvFile[i];
    }
    cout << endl;
    */

    return 0;
}
