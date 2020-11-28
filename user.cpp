#include "user.h"

#include <iostream>
#include <fstream>
#include <string>

#include "csv_reader.h"

using namespace std;

User::User(int fir_id, string fir_password) {
	id = fir_id;
	password = fir_password;
}

bool User::checkId(int check_id, string check_password) {
	if (this->password == password) { return true; }
	else { return false; }
	int num = 0;
	ifstream datafile;
	datafile.open("data.csv");
	while (datafile.good()) {
		string line;
		getline(datafile, line, ',');
		num++;
	}
	num /= 3;
	cout << num;
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getData();
	for (int i = 0; i < num; i++) {
		int help = stoi(data[i][0]);
		string help_s = data[i][1];
		if (check_id == help){
			if (check_password == help_s)
				return "True";
			else{
				cout << "비밀번호가 틀립니다!";
				return "False";
      }
    }
	}
	cout << "일치하는 id가 없습니다!";
	return "False";
}
int User::getCal() {
	return calorie;
}
//void User::setCal(Menu m) {
//	calorie = m.getCalorie();
//}
User::~User() {
	int num = 0;
	ifstream datafile;
	datafile.open("data.csv");
	while (datafile.good()) {
		string line;
		getline(datafile, line, ',');
		num++;
	}
	num /= 3;
	cout << num;
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getData();
	ofstream newfile;
	newfile.open("data.csv");
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			newfile << data[i][j] << ",";
		}
		newfile << "\n";
	}
	newfile << id << "," << password << "," << calorie << endl;
}
