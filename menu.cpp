#include "menu.h"

#include <algorithm>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::find;

// Constructor & Destructor
Menu::Menu() { /* Make dummy first (!!MUST USE SETTERS!!)*/ }
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day) {
	defaultSetter(new_date, new_cost, new_calorie, new_day); // NOTE! foodList is not setted yet!
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, const string food_name) {
	defaultSetter(new_date, new_cost, new_calorie, new_day);
	this->addFood(food_name);
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, const string* food_array, const int size) {
	defaultSetter(new_date, new_cost, new_calorie, new_day);
	this->addFood(food_array, size);
}
Menu::Menu(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day, vector<string> food_list) {
	defaultSetter(new_date, new_cost, new_calorie, new_day);
	this->foodList = food_list;
}
Menu::~Menu() { foodList.clear(); }

// Member functions
inline void Menu::defaultSetter(unsigned int new_date, unsigned int new_cost, unsigned int new_calorie, dayOfWeek new_day) {
	this->date = new_date;
	this->cost = new_cost;
	this->calorie = new_calorie;
	this->day = new_day;
}

inline void Menu::setDate(const unsigned int new_date) { this->date = new_date; }
inline void Menu::setCost(const unsigned int new_cost) { this->cost = new_cost; }
inline void Menu::setDay(const dayOfWeek new_day) { this->day = new_day; }
inline void Menu::setCalorie(const unsigned int new_calorie) { this->calorie = new_calorie;}

inline void Menu::addFood(const string food_name) {
	// avoid duplication in foodList
	if(!isFoodInMenu(food_name)) this->foodList.push_back(food_name);
}
void Menu::addFood(const string* food_array, const int size) {
	for (int i = 0; i < size; ++i) this->addFood(food_array[i]);
}

unsigned int Menu::getDate() const { return this->date; }
unsigned int Menu::getCost() const { return this->cost; }
unsigned int Menu::getCalorie() const { return this->calorie; }
dayOfWeek Menu::getDay() const { return this->day; }
vector<string> Menu::getFoodList() const { return this->foodList; }

inline bool Menu::isFoodInMenu(const string food_name) const {
 	const auto& foods = this->foodList; // make alias
 	return (find(foods.begin(), foods.end(), food_name) != foods.end());
}

// data_files 폴더의 csv 파일에는 요일이 한글로 되어있으므로
// 이를 Menu 인스턴스에서 사용할 수 있도록 validTime으로 변환
dayOfWeek changeTypeOfDay(const string& target_day) {
    dayOfWeek day;
    if(target_day == "월" || target_day == "Mon") {
        day = dayOfWeek::Mon;
    } else if(target_day == "화" || target_day == "Tue") {
        day = dayOfWeek::Tue;
    } else if(target_day == "수" || target_day == "Wed") {
        day = dayOfWeek::Wed;
    } else if(target_day == "목" || target_day == "Thu") {
        day = dayOfWeek::Thu;
    } else if(target_day == "금" || target_day == "Fri") {
        day = dayOfWeek::Fri;
    } else {
        day = dayOfWeek::None; // Error
    }
    return day;
}