#include "user.h"

int User::usernum = 0;

<<<<<<< HEAD
// Constructors
User::User(int fir_id, string fir_password) {
	this->id = fir_id;
	this->password = fir_password;
	this->calorie = 0;
	usernum++;
}
User::User(int fir_id, string fir_password, int fir_calorie) {
	this->id = fir_id;
	this->password = fir_password;
	this->calorie = fir_calorie;
	usernum++;
}

// Member functions
inline void User::changePassword(string new_password) { this->password = new_password; }

inline void User::setCal(Menu m) { this->calorie = static_cast<int>(m.getCalorie()); }
inline void User::setCal(int m) { this->calorie = m; }

inline bool User::checkId(string check_password) {
    return (this->password == check_password) ? true : false;
}

inline int User::getId() { return this->id; }
inline string User::getPassword() { return this->password; }
inline int User::getCal() { return this->calorie; }

// Non-member functions (frien functions)
=======
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
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
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
<<<<<<< HEAD
    newfile.close();
=======
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
}

void storeUser(map<int, User> userMap) {
	ofstream newfile;
	newfile.open("data.csv");
	for (auto p : userMap) {
		newfile << p.first << "," << userMap[p.first].password << "," << userMap[p.first].calorie << "," << "\n";
	}
<<<<<<< HEAD
    newfile.close();
}
=======
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
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
