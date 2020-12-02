#ifndef __OOP_CSV_READER__
#define __OOP_CSV_READER__

#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

vector<string> splitLine(const string&, const char&);

class CSVReader {
private:
    string file_name;
public:
    CSVReader(const string);
    ~CSVReader() {};
    vector<vector<string>> getDataTable();
};

#endif