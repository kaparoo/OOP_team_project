#ifndef __OOP_FOOD__
#define __OOP_FOOD__

#include <string>
#include <map>

using std::string;
using std::map;

class Food {
private:
	string name;
	unsigned int calorie;
public:
	Food(string);
	Food(string, unsigned int);
    ~Food() {};

	inline void setCal(unsigned int);
	inline string getName() const;
	inline unsigned int getCal() const;
};

map<string, Food> updateFood();

#endif