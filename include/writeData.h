#ifndef WRITEDATA_H
#define WRITEDATA_H


class writeData
{
    public:
        /** Default constructor */
        writeData();
        /** Default destructor */
        virtual ~writeData();

        /** Access FileName
         * \return The current value of FileName
         */
        string GetFileName() { return FileName; }
        /** Set FileName
         * \param val New value to set
         */
        void SetFileName(string val) { FileName = val; }
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
        /** Access unParsed
         * \return The current value of unParsed
         */
        string GetunParsed() { return unParsed; }
        /** Set unParsed
         * \param val New value to set
         */
        void SetunParsed(string val) { unParsed = val; }
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
        /** Access dataToProcWrite
         * \return The current value of dataToProcWrite
         */
        vector<vector<string> > GetdataToProcWrite() { return dataToProcWrite; }
        /** Set dataToProcWrite
         * \param val New value to set
         */
        void SetdataToProcWrite(vector<vector<string> > val) { dataToProcWrite = val; }

    protected:

    private:
        string FileName; //!< Member variable "FileName"
        vector<string> rawDataFile; //!< Member variable "rawDataFile"
        string sepChars; //!< Member variable "sepChars"
        int nRows; //!< Member variable "nRows"
        bool hasHeader; //!< Member variable "hasHeader"
        string unParsed; //!< Member variable "unParsed"
        vector<string> parsedLine; //!< Member variable "parsedLine"
        vector<string> colNames; //!< Member variable "colNames"
        vector<string> varTypes; //!< Member variable "varTypes"
        vector<vector<string> > dataToProcWrite; //!< Member variable "dataToProcWrite"
};

#endif // WRITEDATA_H
