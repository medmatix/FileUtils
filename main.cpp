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
 * @version 0.025
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

/**
1. "anno" Apr 13, 2010, http://stackoverflow.com/questions/
2625411/how-to-build-a-sentence-parser-using-only-the-c-standared-library

*/

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <tuple>
#include <algorithm>
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
    int nrows;
    int ncols;
    vector<string> csvToParse;
    vector<string> parsedCSV;
    list<vector<string> > dataStruct;
    vector<string> rowElements;
    string lineToParse;
    vector<string> parsedLine;
    vector<string> colNames;


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
        if(hasHeader) {
            lineToParse = csvToParse[0];
            parsedLine = parseLine(lineToParse);
            colNames= parsedLine;
        }
        else {
            lineToParse = csvToParse[0];
            parsedLine = parseLine(lineToParse);
        }
        setNcols();
        setNrows();
        convertCSVToDataStruct();
    }


    /** Methods */
    //Accessors
    /** Accessor-get number of columns/variables in table*/
    int getNcols() {
        return ncols;
    }
    /** Accessor-get number of rows/onservations in table*/
    int getNrows() {
        return nrows;
    }
    /** Accessor-set number of columns/variables in table*/
    void setNcols() {
        ncols = parsedLine.size();
    }
    /** Accessor-set number of rows/observations in table*/
    void setNrows() {
        nrows = csvToParse.size();
    }

    /** Accessor-return the uploaded CSV file to caller */
    list<vector<string> > convertCSVToDataStruct() {return dataStruct;}

    /** Accessor-return the data structure (table) to caller */
    list<vector<string> > getDataStruct() {
        return dataStruct;
    }

    /**parse a line of the csv file, return it to caller */
    vector<string> parseLine(string lineToParse) {
        string line = lineToParse;
        // break the input in to tokens using a space as the delimiter
        istringstream stream(line);
        string obsItem;
        while (getline(stream, obsItem, ',')) {
            // store each obsItem in a vector
            rowElements.push_back(obsItem);
        }
    return rowElements;
}
    /** read a stated CSV file from disk */
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

    /** write some data structure to disk as a csv */
    void putCSV() {}

    /**display the csv data read from disk */
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
    /** convert a data structure to a single string object and return the object */
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
