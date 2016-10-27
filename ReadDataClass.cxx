/* generated by dia/codegen.py */
/*a text file will be read line-by-line and parsed by some criteria provided the stored in a vector of vectors of strings. At completiong of reading all data is expressed as text strings. Functions to assign other types will be included.*/
class ReadDataFile 
{
public:
	string getFileName ();
	void setFileName (string fname);
	vector<string> getRawData ();
	string setFldSep (string fsep);
	int getNCols ();
	int getNRows ();
	bool getHasHeader ();
	vector<string> getColNames ();
	void setColNames (vector<string> cNames);
	vector<string> getVarTypes ();
	void setVarTypes (vector<string> vTypes);
	vector<string> readFile (string fname,
	                         bool hasHeader,
	                         int start,
	                         int end);
	vector<string> parseBlock (string blockToParse);
	void appendParsed (vector<string> pBlock);
	void serializeObj ();
	void displayObj ();
	void toJSONFile ();
	void toString ();
private:
	string readFromFile;;
	vector<string> rawDataStruct;;
	string sepChars;
	int nCols;
	int nRows;
	bool hasHeader;
	string toParse;
	vector<string> parsedBlock;
	vector<strings> colNames;
	vector<strings> varTypes;
	vector<vector<string> > parsedStruct;
};

