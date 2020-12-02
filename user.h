#ifndef __OOP_USER__
#define __OOP_USER__

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "csv_reader.h"
#include "menu.h"
#include "check_user_num.h"

using namespace std;

class User {
protected:
    static const string data_file_dir = "./data_files/data.csv"; // data.csv 경로는 고정되어 있으므로 static
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