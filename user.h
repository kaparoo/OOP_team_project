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
  User(int, string);
	User(string, int, string, string, string);
	bool login(int, string);
	bool search(string, string,string);
	void saveData();
};