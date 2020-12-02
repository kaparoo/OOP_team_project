#ifndef __OOP_USER__
#define __OOP_USER__

<<<<<<< HEAD
=======
#include <iostream>
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
#include <fstream>
#include <string>
#include <map>

#include "csv_reader.h"
#include "menu.h"

<<<<<<< HEAD
using std::map;
using std::make_pair;
using std::pair;
using std::string;
using std::ifstream;
using std::ofstream;

class User {
protected:
    static int usernum;
=======
using namespace std;

class User {
protected:
	static int usernum;
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
	int id;
	string password;
	int calorie;

public:
	User() { usernum++; id = 0; calorie = 0; }
	User(int, string);
	User(int, string, int);
<<<<<<< HEAD
	~User() {};

	void setCal(Menu);
	void setCal(int);
	void changePassword(string);

	int getId();
	bool checkId(string);
	int getCal();
=======
	~User();
	int getId();
	bool checkId(string);
	int getCal();
	void setCal(Menu);
	void setCal(int);
	void changePassword(string);
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
	string getPassword();

    // Non-member functions
	friend void storeUser(User);
	friend void storeUser(map<int, User>);
<<<<<<< HEAD
	friend map<int, User> updateUser(); 
=======
	friend map<int, User> updateUser();
	//void setCal(Menu);
	//maybe set id 
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
};

void storeUser(User);
void storeUser(map<int, User>);
map<int, User> updateUser();

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> cf0a1fe0ca4ffd13b2bdf1acb2ddacdb81aa4805
