#include "food.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

Food::Food(string name) {
		this->name = name;
	}

Food::Food(string name, unsigned int calorie) {
		this->name = name;
		this->calorie = calorie;
}

void Food::setCal(unsigned int calorie) {
		this->calorie = calorie;
	}

string Food::getName() { return name; }
unsigned int Food::getCal() { return calorie; }