#ifndef __OOP_USER__
#define __OOP_USER__

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "check_user_num.h"
#include "csv_reader.h"

using namespace std;
class User {
protected:
	int id;
	string password;
	unsigned int calorie;
	map<int, string> m;
public:
	User() { id = 0;}
	User(int, string);
	~User();
	map<int, string> Getusermap();
	bool checkId(int, string);
	int getCal();

	//void setCal(Menu);
	//maybe set id 
};

#endif