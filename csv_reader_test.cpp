#include "csv_reader.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    CSVReader reader("test.csv");
    vector<vector<string>> dataTable = reader.getData();
    for(vector<string> dataRow : dataTable) {
        for(string data: dataRow) {
            cout << data << ", ";
        }
        cout << endl;
    }
}
