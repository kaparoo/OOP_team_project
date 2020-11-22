#ifndef __OOP_MENU__
#define __OOP_MENU__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::find;

enum class dayOfWeek {Mon, Tue, Wed, Thu, Fri, Sat, Sun, None};
enum class validTime {Lunch, Dinner, Both, None};

class Menu {
private:
    // Member variables
    unsigned int date = 201911066; // <- key variable
    unsigned int cost = 201911066;
    dayOfWeek day = dayOfWeek::None;
    validTime time = validTime::None;
    vector<string> foodList;

public:
    // Constructure
    Menu();
    Menu(unsigned int, unsigned int, dayOfWeek, validTime);
    Menu(unsigned int, unsigned int, dayOfWeek, validTime, const string);
    Menu(unsigned int, unsigned int, dayOfWeek, validTime, const string*, const int);
    Menu(unsigned int, unsigned int, dayOfWeek, validTime, vector<string>);

    // Destructure
    ~Menu();

    // Member functions
    inline void defaultSetter(unsigned int, unsigned int, dayOfWeek, validTime);

    inline void setDate(const unsigned int);
    inline void setCost(const unsigned int);
    inline void setDay(const dayOfWeek);
    inline void setTime(const validTime);
    
    inline void addFood(const string);
    void addFood(const string*, const int);
    // bool removeFood(const string);

    unsigned int getDate() const;
    unsigned int getCost() const;
    dayOfWeek getDay() const;
    validTime getValidTime() const;
    vector<string> getFoodList() const;

    // Check whether we can select the menu at targetTime
    inline bool isValidFor(validTime) const;
    // Search food in the menu (using STL::find())
    inline bool isFoodInMenu(const string) const;
};

#endif