#include "menu.h"

// Constructor
Menu::Menu() { /* Make dummy first (!!MUST USE SETTERS!!)*/ }
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, validTime new_time) {
	defaultSetter(new_date, new_cost, new_calorie, new_day, new_time);
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, validTime new_time, const string food_name) {
	defaultSetter(new_date, new_cost, new_calorie, new_day, new_time);
	this->addFood(food_name);
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, validTime new_time, const string* food_array, const int size) {
	defaultSetter(new_date, new_cost, new_calorie, new_day, new_time);
	this->addFood(food_array, size);
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, validTime new_time, vector<string> food_list) {
	defaultSetter(new_date, new_cost, new_calorie, new_day, new_time);
	this->foodList = food_list;
}

// Destructor
Menu::~Menu() { foodList.clear(); }

// Member functions
inline void Menu::defaultSetter(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, validTime new_time) {
	this->date = new_date;
	this->cost = new_cost;
	this->calorie = new_calorie;
	this->day = new_day;
	this->time = new_time;
}

inline void Menu::setDate(const unsigned int new_date) { this->date = new_date; }
inline void Menu::setCost(const unsigned int new_cost) { this->cost = new_cost; }
inline void Menu::setDay(const dayOfWeek new_day) { this->day = new_day; }
inline void Menu::setTime(const validTime new_time) { this->time = new_time; }
inline void Menu::setCalorie(const unsigned int new_calorie) { this->calorie = new_calorie;}

inline void Menu::addFood(const string food_name) {
	// Avoid duplication in foodList
	if(!isFoodInMenu(food_name)) this->foodList.push_back(food_name);
}
void Menu::addFood(const string* food_array, const int size) {
	for (int i = 0; i < size; ++i) this->addFood(food_array[i]);
}

unsigned int Menu::getDate() const { return this->date; }
unsigned int Menu::getCost() const { return this->cost; }
unsigned int Menu::getCalorie() const { return this->calorie; }
dayOfWeek Menu::getDay() const { return this->day; }
validTime Menu::getValidTime() const { return this->time; }
vector<string> Menu::getFoodList() const { return this->foodList; }

inline bool Menu::isValidFor(validTime target_time) const {
	auto menuTime = this->time;
	if (menuTime == validTime::Lunch && target_time == validTime::Lunch) {
		return true;
	} else if (menuTime == validTime::Dinner && target_time == validTime::Dinner) {
		return true;
	} else if (menuTime == validTime::Both) { // Value of targetTime does not matter
		return true;
	}
	return false;
}

inline bool Menu::isFoodInMenu(const string food_name) const {
	const auto& foods = this->foodList; // make alias
	return (find(foods.begin(),foods.end(), food_name) != foods.end());
}