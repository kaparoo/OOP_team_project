#include "user.h"

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

// Member functions
void User::changePassword(string new_password) { 
    password = new_password;
}

void User::setCal(Menu m) {
    calorie = static_cast<int>(m.getCalorie());
}
void User::setCal(int m) {
    calorie = m;
}

inline bool User::checkId(string check_password) {
    if(this->password == check_password)
        return true;
    else
        return false;
}

int User::getId() {
    return id;
}
string User::getPassword() {
    return password;
}
int User::getCal() {
    return calorie;
}

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
	
	CSVReader reader("./data_files/data.csv");
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
    newfile.close();
}

void storeUser(map<int, User> userMap) {
	ofstream newfile;
	newfile.open("./data_files/data.csv");
	for (auto p : userMap) {
		newfile << p.first << "," << userMap[p.first].password << "," << userMap[p.first].calorie << "," << "\n";
	}
    newfile.close();
}