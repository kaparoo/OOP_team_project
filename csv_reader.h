#ifndef __OOP_CSV_READER__
#define __OOP_CSV_READER__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;

class CSVReader {
private:
    string file_name;
public:
    CSVReader(const string);
    ~CSVReader() {};

    vector<vector<string>> getData();
};

#endif