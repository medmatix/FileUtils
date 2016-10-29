#ifndef READDATA_H
#define READDATA_H


class ReadData
{
    public:
        /** Default constructor */
        ReadData();
        /** Default destructor */
        virtual ~ReadData();

        /** Access fIlePath
         * \return The current value of fIlePath
         */
        string GetfIlePath() { return fIlePath; }
        /** Set fIlePath
         * \param val New value to set
         */
        void SetfIlePath(string val) { fIlePath = val; }
        /** Access rawDataFile
         * \return The current value of rawDataFile
         */
        vector<string> GetrawDataFile() { return rawDataFile; }
        /** Set rawDataFile
         * \param val New value to set
         */
        void SetrawDataFile(vector<string> val) { rawDataFile = val; }
        /** Access sepChars
         * \return The current value of sepChars
         */
        string GetsepChars() { return sepChars; }
        /** Set sepChars
         * \param val New value to set
         */
        void SetsepChars(string val) { sepChars = val; }
        /** Access nCols
         * \return The current value of nCols
         */
        int GetnCols() { return nCols; }
        /** Set nCols
         * \param val New value to set
         */
        void SetnCols(int val) { nCols = val; }
        /** Access nRows
         * \return The current value of nRows
         */
        int GetnRows() { return nRows; }
        /** Set nRows
         * \param val New value to set
         */
        void SetnRows(int val) { nRows = val; }
        /** Access hasHeader
         * \return The current value of hasHeader
         */
        bool GethasHeader() { return hasHeader; }
        /** Set hasHeader
         * \param val New value to set
         */
        void SethasHeader(bool val) { hasHeader = val; }
        /** Access toParse
         * \return The current value of toParse
         */
        string GettoParse() { return toParse; }
        /** Set toParse
         * \param val New value to set
         */
        void SettoParse(string val) { toParse = val; }
        /** Access parsedLine
         * \return The current value of parsedLine
         */
        vector<string> GetparsedLine() { return parsedLine; }
        /** Set parsedLine
         * \param val New value to set
         */
        void SetparsedLine(vector<string> val) { parsedLine = val; }
        /** Access colNames
         * \return The current value of colNames
         */
        vector<string> GetcolNames() { return colNames; }
        /** Set colNames
         * \param val New value to set
         */
        void SetcolNames(vector<string> val) { colNames = val; }
        /** Access varTypes
         * \return The current value of varTypes
         */
        vector<string> GetvarTypes() { return varTypes; }
        /** Set varTypes
         * \param val New value to set
         */
        void SetvarTypes(vector<string> val) { varTypes = val; }
        /** Access parsedStruct
         * \return The current value of parsedStruct
         */
        vector<vector<string> > GetparsedStruct() { return parsedStruct; }
        /** Set parsedStruct
         * \param val New value to set
         */
        void SetparsedStruct(vector<vector<string> > val) { parsedStruct = val; }

    protected:

    private:
        string fIlePath; //!< Member variable "fIlePath"
        vector<string> rawDataFile; //!< Member variable "rawDataFile"
        string sepChars; //!< Member variable "sepChars"
        int nCols; //!< Member variable "nCols"
        int nRows; //!< Member variable "nRows"
        bool hasHeader; //!< Member variable "hasHeader"
        string toParse; //!< Member variable "toParse"
        vector<string> parsedLine; //!< Member variable "parsedLine"
        vector<string> colNames; //!< Member variable "colNames"
        vector<string> varTypes; //!< Member variable "varTypes"
        vector<vector<string> > parsedStruct; //!< Member variable "parsedStruct"
};

#endif // READDATA_H
