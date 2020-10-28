#include "project.h"

#include <string>

Food::Food() : Food("Dummy", 0) {}

Food::Food(std::string name = "Dummy", const unsigned int& calorie = 0) {
    this->name = name;
    this->calorie = new int { calorie };
}

Food::~Food() {
    if(calorie != nullptr) {
    	delete calorie;
    }
};

std::string Food::getName() const { return this->name; }

unsigned int Food::getCalorie() const { return this->calorie; }
