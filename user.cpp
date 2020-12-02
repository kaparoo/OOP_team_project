#include "user.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "csv_reader.h"
#include "menu.h"

using namespace std;
int User::usernum = 0;

User::User(int fir_id, string fir_password) {
	id = fir_id;
	password = fir_password;
	calorie = 0;
	usernum++;
}
User::User(int fir_id, string fir_password, int fir_calorie) {
	id = fir_id;
	password = fir_password;
	calorie = fir_calorie;
	usernum++;
}
int User::getId() {
	return id;
}
bool User::checkId(string check_password) {
	if (this->password == check_password)
		return true;
	else
		return false;
}
string User::getPassword() {
	return password;
}
void User::changePassword(string new_password) {
	password = new_password;
}
int User::getCal() {
	return calorie;
}
void User::setCal(Menu m) {
	calorie = static_cast<int>(m.getCalorie());
}
void User::setCal(int m) {
	calorie = m;
}
User::~User() {}
map<int, User> updateUser() {
	map<int, User> m;
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getDataTable();
	for (int i = 0; i < data.size(); i++) {
		m.insert(pair<int, User>(stoi(data[i][0]), User(stoi(data[i][0]), data[i][1], stoi(data[i][2]))));
	}
	return m;
}

void storeUser(User u1) { // 새로운 유저가 만들어지면 무조건 storeUser해주세요.
	
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getDataTable();
	ofstream newfile;
	newfile.open("data.csv");
	for (int i = 0; i < User::usernum; i++) {
		for (int j = 0; j < 3; j++) {
			newfile << data[i][j] << ",";
		}
		newfile << "\n";
	}
	newfile << u1.id << "," << u1.password << "," << u1.calorie << "," << "\n";
}

void storeUser(map<int, User> userMap) {
	ofstream newfile;
	newfile.open("data.csv");
	for (auto p : userMap) {
		newfile << p.first << "," << userMap[p.first].password << "," << userMap[p.first].calorie << "," << "\n";
	}
}

/* 컴파일 오류때문에 주석처 (11/30)
 * main함수는 프로그램 내에서 오직 하나만 존재해야 해
 * 테스트 때문에 집어넣은거야? -박재우
 * 맞습니다.
 */
 // int main() {
 // 	int a;
 //	User u(201911066, "dddd", 333);
 //	storeUser(u);
 //	map<int, User> m = updateUser();
 //	for (auto p : m) {
 //		cout << p.first << m[p.first].getPassword() << endl;
 //	}
 //	m[201911195].changePassword("Kee");
 //	storeUser(m);
 //}