#include "menu.h"

// Constructor
Menu::Menu() {}

// Destructor
Menu::~Menu() {}

// Member functions

inline unsigned int Menu::getDate() const { return this->date; }
inline unsigned int Menu::getCost() const { return this->cost; }
inline dayOfWeek Menu::getDay() const { return this->day; }
inline validTime Menu::getValidTime() const { return this->valid; }

inline bool Menu::isValidFor(validTime targetTime) const {
    auto valid = this->valid;
    if(targetTime == Allday) {
        return (valid == Allday);
    } else { // targetTime: Lunch or Dinner
        return (valid == Allday) or (valid == targetTime); 
    }
    return false;
}