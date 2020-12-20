#include "menu.h"

namespace menu_recomendation_service {

	dayOfWeek changeTypeOfDay(const std::string& target_day) {
        dayOfWeek day;
        if (target_day == "월") {
            day = dayOfWeek::Mon;
        }
        else if (target_day == "화") {
            day = dayOfWeek::Tue;
        }
        else if (target_day == "수") {
            day = dayOfWeek::Wed;
        }
        else if (target_day == "목") {
            day = dayOfWeek::Thu;
        }
        else if (target_day == "금") {
            day = dayOfWeek::Fri;
        }
        else if (target_day == "토") {
            day = dayOfWeek::Sat;
        }
        else if (target_day == "일") {
            day = dayOfWeek::Sun;
        }
        else { // Error
            day = dayOfWeek::None;
            // throw day;
        }
        return day;
	}

	Menu::Menu(const unsigned int& date, const unsigned int& cost, const unsigned int& calorie, const dayOfWeek& day) noexcept {
        // this->date = new unsigned int(date);
        // this->cost = new unsigned int(cost);
        // this->calorie = new unsigned int(calorie);
        // this->day = new dayOfWeek(day);
        this->date = date;
        this->cost = cost;
        this->calorie = calorie;
        this->day = day;
	}

    Menu::Menu(const unsigned int& date, const unsigned int& cost, const unsigned int& calorie, const dayOfWeek& day, std::vector<std::string>& new_list) noexcept : Menu::Menu(date, cost, calorie, day) {
        this->foodList = new_list;
    }

    Menu::~Menu() {
        // delete date;
        // delete cost;
        // delete calorie;
        // delete day;
        this->foodList.clear();
    }

    unsigned int Menu::getDate() const { return this->date; }
    unsigned int Menu::getCost() const { return this->cost; }
    unsigned int Menu::getCalorie() const { return this->calorie; }
    dayOfWeek Menu::getDay() const { return this->day; }
    std::vector<std::string> Menu::getFoodList() const { return this->foodList; }

}