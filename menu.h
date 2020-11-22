#ifndef __OOP_MENU__
#define __OOP_MENU__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::find;

enum class dayOfWeek {Mon, Tue, Wed, Thu, Fri, Sat, Sun};
enum class validTime {Lunch, Dinner, Both};

class Menu {
    private:
      
      // Member variables
      unsigned int date; // <- key variable
      unsigned int cost;
      dayOfWeek day;
      validTime time;
      vector<string> foodList;

    public:
      
      // Constructure
      Menu();
      Menu(unsigned int, unsigned int, dayOfWeek, validTime);
      Menu(unsigned int, unsigned int, dayOfWeek, validTime, string);
      Menu(unsigned int, unsigned int, dayOfWeek, validTime, vector<string>);
      Menu(unsigned int, unsigned int, dayOfWeek, validTime, string*, const unsigned int&);

      // Destructure
      ~Menu();

      // Member functions
      void setCost(const unsigned int);
      
      inline void addFood(const string);
      void addFood(const string*, const unsigned int&);
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