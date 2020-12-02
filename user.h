#ifndef __OOP_USER__
#define __OOP_USER__

#include <fstream>
#include <string>
#include <map>

#include "csv_reader.h"
#include "menu.h"

using std::map;
using std::make_pair;
using std::pair;
using std::string;
using std::ifstream;
using std::ofstream;

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
	~User() {};

	void setCal(Menu);
	void setCal(int);
	void changePassword(string);

	int getId();
	bool checkId(string);
	int getCal();
	string getPassword();

    // Non-member functions
	friend void storeUser(User);
	friend void storeUser(map<int, User>);
	friend map<int, User> updateUser(); 
};

void storeUser(User);
void storeUser(map<int, User>);
map<int, User> updateUser();

#endif