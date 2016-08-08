# UtilCVS
__C++ Classes to read, write and manipulate CSV files (with a table like internal string data structure)__
https://medmatix.github.io/UtilCSV/

###Overview
It is a surprise that there are few open source platform independent C++ data file access libraries for special or delimited file types such as comma separated files (CSV), tab delimited etc. Note worthy is the contribution by [Jay Satiro](https://github.com/jay/CSV) which indeed reads and writes CSV in a slightly narrower scope than we envision. It was also written with Visual Studio, we are using the GCC and compatible libraries with C++11 To hopefully keep to a generality of platform as closely as possible.

Ultimately our goal is to allow sundry text file types to be sourced for to populate a C++ coded dataframe (Gnu R styled) or data tables in general. The purpose is to create a fully funtional data structure suited to use in C++ for data analysis with C++ coded programs.

The model is the paradigm for data handling is based on the R language constructs for the purpose and the Pandas library functionality provided in python.

###Classes
The classes are perhaps best summarized in the [doxygen docs](https://medmatix.github.io/UtilCSV/docs/html/). A more typical API reference is in progress.

More visually, the class diagrams follow here.


###Development

Notes:
- Decision to only construct a string list was made to reduce complexity of this call. Also the more appropriate place for this step is in the dataframe module or in similar classes constructing other kinds of data structures from a loaded CSV.
- Code needs to be simplified and optimized. Some rather cludgy logic used. More use of iterators would be approriate especially.
- Search for existing algorithms or library functions to replace some of the logic. Likely more efficient and tested.The idea afterall is to increase speed of manipulations over the interpreted language algorithms
- Also, parallelizing some of the logic is going to be explored.

UML:
![](https://medmatix.github.com/UtilCSV.svg title="UML for Class")

Unit testing:
This also is ongoing and contained in code of the main() function in main.cpp the current development version or the Release candidate UtilCSV.cpp above.

###References & Acknowledgements
 - for a notable project with same general goal, see Jay Satiro, https://github.com/jay/CSV



###Authors and Contributors

David York, statistical programmer and data scientist



###Support or Contact

 - http://www.crunches-data.appspot.com

 - medmatix@gmail.com

copyright 2016,David York
