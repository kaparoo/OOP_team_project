#ifndef __OOP_FOOD__
#define __OOP_FOOD__

#include <fstream>
#include <map>
#include <string>

#include "csv_reader.h"

using std::map;
using std::make_pair;
using std::string;

class Food {
private:
	string name;
	unsigned int calorie;
public:
    Food();
	Food(string);
	Food(string, unsigned int);
    ~Food() {};

	inline void setCal(unsigned int);
	inline string getName() const;
	inline unsigned int getCal() const;
};

map<string, Food> updateFood();

#endif