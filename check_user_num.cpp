#include<iostream>
#include <fstream>
#include <string>
#include "check_user_num.h"
#include "csv_reader.h"

Usernum::Usernum() {
	num = 0;
	ifstream datafile;
	datafile.open("data.csv");
	while (datafile.good()) {
		string line;
		getline(datafile, line, ',');
		num++;
	}
	num /= 3;
}
int Usernum::Getnum() {
	return num;
}