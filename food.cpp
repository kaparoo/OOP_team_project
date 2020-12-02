#include "food.h"

#include <string>

using std::string;

Food::Food(string name) {
	this->name = name;
}

Food::Food(string name, unsigned int calorie) {
	this->name = name;
	this->calorie = calorie;
}

inline void Food::setCal(unsigned int calorie) {
	this->calorie = calorie;
}

inline string Food::getName() const { return this->name; };
inline unsigned int Food::getCal() const { return this->calorie; };