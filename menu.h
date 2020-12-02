#ifndef __OOP_MENU__
#define __OOP_MENU__

#include <algorithm>
<<<<<<< HEAD
=======
#include <iostream>
>>>>>>> c0f6a2f9210069d74a26aca3933a88543afb400d
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::find;

enum class dayOfWeek {Mon, Tue, Wed, Thu, Fri, Sat, Sun, None};

dayOfWeek changeTypeOfDay(const string& target_day);

class Menu {
private:
    // Member variables (20201109 is placeholder, i.e., dummy data)
    unsigned int date = 20201109; // <- key variable
    unsigned int cost = 20201109;
    unsigned int calorie = 20201109; // total calorie
    dayOfWeek day = dayOfWeek::None;
    vector<string> foodList;
    
    // Private member functions   
    inline void defaultSetter(unsigned int, unsigned int, unsigned int, dayOfWeek);
    inline bool isFoodInMenu(const string) const; // Search food in the menu (using std::find() function of STL)

public:
    // Constructor & Destructor
    Menu();
    Menu(unsigned int, unsigned int, unsigned int, dayOfWeek);
    Menu(unsigned int, unsigned int, unsigned int, dayOfWeek, const string);
    Menu(unsigned int, unsigned int, unsigned int, dayOfWeek, const string*, const int);
    Menu(unsigned int, unsigned int, unsigned int, dayOfWeek, vector<string>);
    ~Menu();

    // Public member functions
    inline void setDate(const unsigned int);
    inline void setCost(const unsigned int);
    inline void setCalorie(const unsigned int);
    inline void setDay(const dayOfWeek);

    inline void addFood(const string);
    void addFood(const string*, const int);

    unsigned int getDate() const;
    unsigned int getCost() const;
    unsigned int getCalorie() const;
    dayOfWeek getDay() const;
    validTime getValidTime() const;
    vector<string> getFoodList() const;
};

#endif