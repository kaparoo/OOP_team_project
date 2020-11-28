#ifndef __OOP_USER__
#define __OOP_USER__

#include <iostream>
#include <fstream>
#include <string>

#include "csv_reader.h"

using namespace std;

class User {
protected:
	int id;
	string password;
	unsigned int calorie;
public:
	User() {}
	User(int, string);
	~User();
	bool checkId(int, string);
	int getCal();
	//void setCal(Menu);
	//maybe set id 
};

#endif