#include "menu.h"

// [Constructor]
Menu::Menu() {
	Menu(201911066, 201911066, dayOfWeek::Sun, validTime::Both); // Dummy data
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, dayOfWeek new_day, validTime new_time) {
	this->date = new_date;
	this->cost = new_cost;
	this->day  = new_day;
	this->time = new_time;
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, dayOfWeek new_day, validTime new_time, string new_food) {
	Menu(new_date, new_cost, new_day, new_time);
	this->foodList.push_back(new_food);
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, dayOfWeek new_day, validTime new_time, vector<string> new_list) {
	Menu(new_date, new_cost, new_day, new_time);
	this->foodList = new_list;
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, dayOfWeek new_day, validTime new_time, string* new_list, const unsigned int& size) {
	Menu(new_date, new_cost, new_day, new_time);
	this->addFood(new_list, size);
}

// [Destructor]
Menu::~Menu() { foodList.clear(); }

// [Member functions]

void Menu::setCost(const unsigned int new_cost) { this->cost = new_cost; }

inline void Menu::addFood(const string food_name) {
	// Avoid duplication in the foodList
	if(!isFoodInMenu(food_name)) (this->foodList).push_back(food_name);
}
void Menu::addFood(const string* food_array, const unsigned int& size) {
	for (int i = 0; i < size; ++i) addFood(food_array[i]);
}

unsigned int Menu::getDate() const { return this->date; }
unsigned int Menu::getCost() const { return this->cost; }
dayOfWeek Menu::getDay() const { return this->day; }
validTime Menu::getValidTime() const { return this->time; }
vector<string> Menu::getFoodList() const { return this->foodList; }

inline bool Menu::isValidFor(validTime target_time) const {
	auto menuTime = this->time;
	if (menuTime == validTime::Lunch && target_time == validTime::Lunch) {
		return true;
	} else if (menuTime == validTime::Dinner && target_time == validTime::Dinner) {
		return true;
	} else if (menuTime == validTime::Both) { // Value of targetTime is not matter
		return true;
	}
	return false;
}
inline bool Menu::isFoodInMenu(const string food_name) const {
	const auto& foods = this->foodList; // make alias
	return (find(foods.begin(),foods.end(), food_name) != foods.end());
}