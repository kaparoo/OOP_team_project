#include "csv_reader.h"

#include <fstream>
#include <sstream>

CSVReader::CSVReader(const std::string& file_name) noexcept {
    this->file_name = file_name; // file name with path
}

std::vector<std::vector<std::string>> CSVReader::getDataTable() const {
    
    std::ifstream csvFile(file_name);
    
    std::vector<std::vector<std::string>> dataTable;
    
    std::string line = "";
    while (getline(csvFile, line)) {
        std::vector<std::string> dataRow = splitLine(line, ',');
        dataTable.push_back(dataRow);
    }

    csvFile.close();

    return dataTable;
}

std::vector<std::string> splitLine(const std::string& line, const char& delimiter) {
    std::vector<std::string> result;
    std::stringstream stream(line);
    std::string temp;
    while (std::getline(stream, temp, delimiter)) {
        if(temp!="")
            result.push_back(temp);
    }
    return result;
}

