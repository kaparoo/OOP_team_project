#ifndef __OOP_MENU__
#define __OOP_MENU__

#include <iostream>
#include <string>
#include <vector>

using std::vector
using std::string

typedef enum dayOfWeek {Mon, Tue, Wed, Thu, Fri, Sat, Sun};
typedef enum validTime {Lunch, Dinner, Allday};

class Menu {
    private:
      
      // Member variables
      unsigned int date; // <- key variable
      unsigned int cost;
      dayOfWeek day;
      validTime valid;
      vector<string> foodList;
      vector<string> remarkList;

    public:
      
      // Constructure
      Menu();
      
      // Destructure
      ~Menu();

      // Member functions
      inline void setCost(const int);
      
      void addFood(const string);
      void addFood(const string*, const int);
      void addRemark(const string);
      void addRemark(const string*, const int);
      void removeFood(string);
      void removeRemark(string);

      inline unsigned int getDate() const;
      inline unsigned int getCost() const;
      inline dayOfWeek getDay() const;
      inline validTime getValidTime() const;

      inline bool isValidFor(validTime) const;

};

#endif