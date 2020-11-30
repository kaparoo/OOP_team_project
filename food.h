#ifndef __OOP_FOOD__
#define __OOP_FOOD__

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Food {
private:
	string name;
	unsigned int calorie;
public:
	Food(string);
	Food(string, unsigned int);

	void setCal(unsigned int);
	string getName();
	unsigned int getCal();
};

map<string,Food> updateFood();

#endif