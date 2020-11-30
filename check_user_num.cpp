#include "check_user_num.h"

#include <iostream>
#include <fstream>
#include <string>

#include "csv_reader.h"

Usernum::Usernum() {
	num = 0;
	std::ifstream datafile;
	datafile.open("data_files/data.csv");
	while (datafile.good()) {
		std::string line;
		getline(datafile, line, ',');
		num++;
	}
	num /= 3;
}

int Usernum::Getnum() {
	return num;
}