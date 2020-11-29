#include "user.h"

#include <iostream>
#include <fstream>
#include <string>
#include "check_user_num.h"
#include "csv_reader.h"
#include <map>

using namespace std;

User::User(int fir_id,string fir_password) {
	id = fir_id;
	password = fir_password;
}
bool User::checkId(int check_id, string check_password) {
	Usernum u;
	int num = u.Getnum();
	int help;
	string help_s;
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getData();
	for (int i = 0; i < num; i++) {
		help = stoi(data[i][0]);
		help_s = data[i][1];
		if (check_id == help) {
			if (check_password == help_s) {
				cout << "login 성공!";
				return "True";
			}
			else {
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
map<int, string> User::Getusermap(){
	Usernum u;
	int num = u.Getnum();
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getData();
	for (int i = 0; i < num; i++) {
		m.insert(pair<int, string>(stoi(data[i][0]), data[i][1]));
	}
	if (id!=0)
		m.insert(pair<int, string>(id, password));
	return m;
}
User::~User() {
	Usernum u;
	int num = u.Getnum();
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
	while (id != 0)
	{
		newfile << id << "," << password << "," << calorie << "," << endl;
		id = 0;
	}
}