#include<iostream>
using namespace std;
class User {
protected:
	string name;
	int member_id;
	string password;
	string last_eaten_food;
	string personal_allergics;
public:
	User() {}
	User(string, int, string, string, string);
	bool login(int, string);
	bool search(string, string,string);
	void saveData();
};
User::User(string name, int member_id, string password, string last_eaten_food="", string personal_allergics="") {
	name = name;
	member_id = member_id;
	password = password;
	last_eaten_food = last_eaten_food;
	personal_allergics = personal_allergics;
}
bool User::login(int member_id, string check_password) {
	if (this->password == check_password) { return true; }
	else { return false; }
}
bool User::search(string Restaurant_name, string date, string type) {
}
void User::saveData() {}
class Student :public User {

};
class Professor :public User {

};
class Employees :public User {

};
