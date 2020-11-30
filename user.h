#ifndef __OOP_USER__
#define __OOP_USER__

#include<iostream>
#include <fstream>
#include <string>
#include <map>
#include "csv_reader.h"
#include "check_user_num.h"
using namespace std;
class User {
protected:
	int id;
	string password;
	int calorie;
public:
	User() { id = 0;}
	User(int, string);
	User(int, string, int);
	~User();
	bool checkId(string);
	int getCal();
	void changePassword(string);
	string getPassword();
	friend void storeUser(User);
	friend void storeUser(map<int, User>);


	//void setCal(Menu);
	//maybe set id 
};
map<int, User> updateUser();
#endif