#ifndef __OOP_USER__
#define __OOP_USER__

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "csv_reader.h"
#include "menu.h"

using namespace std;

class User {
protected:
	static int usernum;
	int id;
	string password;
	int calorie;
public:
	User() { usernum++; id = 0; calorie = 0; }
	User(int, string);
	User(int, string, int);
	~User();
	int getId();
	bool checkId(string);
	int getCal();
	void setCal(Menu);
	void setCal(int);
	void changePassword(string);
	string getPassword();
	friend void storeUser(User);
	friend void storeUser(map<int, User>);
	friend map<int, User> updateUser();
	//void setCal(Menu);
	//maybe set id 
};

map<int, User> updateUser();

#endif
