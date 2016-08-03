/**
 * @file: main.cpp (current working version of code here)
 *
 * @title: C++ classes for Manipulating CSV Files
 *
 * @Copyright 2016 David York <david@debian2x8david>
 *
 * @author David York
 * @contributors  no others
 * @date Tuesday August 2, 2016
 * @version 0.034
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
2. Shammas, Namir; C/C++ Mathematical Algorithms for Scientists and Engineers,
McGraw-Hill, 1995.

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

/** Classes */
class UtilCSV
{
protected:
    string fromCSVFile;
    int readToLine;
    bool hasHeader;
    int nrows;
    int ncols;
    vector<string> rowElements;
    string lineToParse;
    vector<string> parsedLine;
    vector<string> colNames;
    vector<string> csvToParse;
    list<vector<string> > dataStruct;

public:
    /** Constructors */
    // Default constructor
    UtilCSV() {}

    // Full constructor
    UtilCSV(string frCSV, bool header, int rtoline = 0) {
        fromCSVFile = frCSV;
        hasHeader = header;
        readToLine = 0;         // has no effect yet (ie. 0 = 'all')
        csvToParse = readCSV(" ");

        if(hasHeader) {         // if there is header save as column names
            lineToParse = csvToParse[0];
            parsedLine = parseLine(lineToParse);

            colNames = parsedLine;
            csvToParse.erase(csvToParse.begin());
            lineToParse = "";
        }
        else {                  // no header, Vn as column names
            lineToParse = csvToParse[0];
            parsedLine = parseLine(lineToParse);
            stringstream ss;
            string numVar;
            for(unsigned int i=0; i < parsedLine.size(); ++i) {
                ss << "V"<< i;
                numVar = ss.str();
                colNames.push_back(numVar);
                ss.str("");
                ss.clear();
            }
        }
        setNcols();
        cout << "no. cols: " << getNcols() << endl;
        setNrows();
        cout << "no. rows: " << getNrows() << endl;
        parsedLine.clear();
        dataStruct = buildDataStruct(csvToParse);
    }


    /** Methods */
    //Accessors
    /** Accessor-get number of columns/variables in table*/
    int getNcols() {
        return ncols;
    }
    /** Accessor-get number of rows/observations in table*/
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

    /** Accessor-reset column names*/
    void setColNames(vector<string> cnames) {
            stringstream ss;
            string numVar;
            if(cnames.size() == colNames.size()) {
                    for(unsigned int i=0; i < cnames.size(); ++i) {
                    ss << "V"<< i;
                    numVar = ss.str();
                    colNames.push_back(numVar);
                    ss.str("");
                    ss.clear();
                }
            } else {
                cout<<"names vectors do not have same length,must match"<<endl;
            }

    }

    /** Accessor-get current column names*/
    vector<string> getColNames() {
        return colNames;
    }

    /** Accessor-return the uploaded CSV file to caller */
    vector<string> getCVS() {return csvToParse;}

    /** Accessor-return the data structure (table) to caller */
    list<vector<string> > getDataStruct() {
        return dataStruct;
    }

    /** read a stated CSV file from disk */
    vector<string> readCSV(string iFileN) {
        vector<string> theCSV;
        string inFileLine;
        string inFileName = fromCSVFile;
        ifstream infile(fromCSVFile.c_str(), ios::in);
        if (!infile) {
            cout << "Could not open file." << endl;
            exit(1);
        }
        while(true) {
            infile >> inFileLine;
            if(infile.eof()) break;
            theCSV.push_back(inFileLine+"\n");
        }
        infile.close();
        return theCSV;
    }

    /**parse a line of the csv file, return it to caller */
    vector<string> parseLine(string lineToParse) {
        string line = lineToParse;
        // break the input in to tokens using a space as the delimiter
        istringstream sstream(line);
        string obsItem;
        while (!sstream.eof() ) {
            // store each obsItem in a vector
            getline(sstream, obsItem, ',');
            rowElements.push_back(obsItem);
        }
    return rowElements;
    }

    /** build a data Structure / Class of records of types string as vectors
     * of parsed strings of observations data (fields). */
    list<vector<string> > buildDataStruct (vector<string> csvToParse) {
        list<vector<string> > internDataStruct;
        for(unsigned int i = 0; i < csvToParse.size(); ++i) {
        parsedLine.clear();
        lineToParse = csvToParse[i];
        internDataStruct.push_back(parseLine(lineToParse));
        }
        return internDataStruct;
    }

    /** write some data structure of strings to disk as a csv */
    void writeCSV(list<vector<string> > dataStruct, string oFName = "datafile.csv") {
        vector<string> dataRow;
        string csvLineOut;
        char cont = 'y';
        oFName = "./data/datafile.csv";
        ofstream outFile(oFName.c_str(), ios::app);
        if (!outFile) {
            cout << "Could not open file." << endl;
            exit(1);
        }
        outFile.close();
    }

    /**display the csv data read from disk */
    void displayInternCSV() {
        cout << "unparsed:" << endl;
        for(unsigned i = 0; i < colNames.size(); ++i) {
            if(i == ncols - 1) {
                cout << colNames[i] << "\n";
            } else {
                cout << colNames[i] << ",";
            }
        }
        for(int i = 0; i < csvToParse.size(); ++i){
            cout << csvToParse[i];
        }
        cout << endl;
    }

    void displayDataStruct() {
        cout << "parsed data structure:" << endl;
        vector<string> dataRow;
        string dSLineOut;

        for(list<vector<string> >::iterator it=dataStruct.begin(); it != dataStruct.end(); it++) {
            dataRow.clear();
            dataRow = *it;
            dSLineOut = "";
            for(unsigned int j = 0; j < dataRow.size(); j++){
                dSLineOut = dSLineOut + dataRow[j] + " " ;
            }
            cout <<  dSLineOut << endl;
        }

    }

    void displayColNames() {
        cout << endl << "Column Names" << endl;
        for(unsigned i = 0; i < colNames.size(); ++i) {
            if(i == ncols -1) {
                cout << colNames[i] << "\n";
            } else {
                cout << colNames[i]<<",  ";
            }
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
    Airpass.displayColNames();
    Airpass.displayDataStruct();
    //Airpass.writeCSV(Airpass.getDataStruct());


    return 0;
}
