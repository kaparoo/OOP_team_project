#include "csv_reader.h"

#include <iostream>
#include <fstream>

CSVReader::CSVReader(const string new_file_name): file_name(new_file_name) {}

vector<string> splitLine(const string& line, const char& delimeter) {
    vector<string> result;
    string word = "";
    char cursor;
    for(int i = 0; i < line.length(); ++i) {
        cursor = line[i];
        if(cursor == delimeter) {
            if(word.length()>0) result.push_back(word);
            word.clear();
        } else {
            if(cursor == ' ') continue;
            word += cursor;
        }
    }
    return result;
}

vector<vector<string>> CSVReader::getDataTable() {
    ifstream csvFile(file_name);
    vector<vector<string>> dataTable;
    string line = "";
    while(getline(csvFile, line)) {
        vector<string> dataRow = splitLine(line, ',');
        dataTable.push_back(dataRow);
    }
    csvFile.close();

    return dataTable;
}