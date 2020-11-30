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
	calorie = 0;
}
User::User(int fir_id, string fir_password, int fir_calorie) {
	id = fir_id;
	password = fir_password;
	calorie = fir_calorie;
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
//void User::setCal(Menu m) {
//	calorie = m.getCalorie();
//}
User::~User() {}
map<int, User> updateUser() {
	map<int, User> m;
	Usernum u;
	int num = u.Getnum();
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getData();
	for (int i = 0; i < num; i++) {
		m.insert(pair<int, User>(stoi(data[i][0]), User(stoi(data[i][0]),data[i][1],stoi(data[i][2]))));
	}
	return m;
}
void storeUser(User u1) { // 새로운 유저가 만들어지면 무조건 storeUser해주세요.
	Usernum u;
	int num = u.Getnum();
	CSVReader reader("data.csv");
	vector<vector<string>> data = reader.getDataTable();
	ofstream newfile;
	newfile.open("data.csv");
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			newfile << data[i][j] << ",";
		}
		newfile << "\n";
	}
}
void storeUser(map<int, User> userMap) {
	ofstream newfile;
	newfile.open("data.csv");
	for (auto p:userMap) {
		newfile << p.first << "," << userMap[p.first].password << "," << userMap[p.first].calorie << ","<<"\n";
	}
}

/* 컴파일 오류때문에 주석처ꈰ (11/30)
 * main함수는 프로그램 내에서 오직 하나만 존재해야 해
 * 테스트 때문에 집어넣은거야? -박재우
 */
// int main() {
// 	int a;
//	User u(20191111, "dddd", 333);
//	storeUser(u);
//	map<int, User> m = updateUser();
//	for (auto p : m) {
//		cout << p.first << m[p.first].getPassword() << endl;
//	}
//	m[201911195].changePassword("Kee");
//	storeUser(m);
//}