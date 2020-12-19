#ifndef __OOP_CAFETERIA__
#define __OOP_CAFETERIA__

#include <map>
#include <string>
#include <vector>

#include "csv_reader.h"
#include "menu.h"
#include "food.h"

using namespace std;

enum class validTime { Lunch, Dinner, None };

class Cafeteria {
protected:
    // Member variables
    static map<string, Food> foodMap;
    static const string dir_prefix;
    string csv_list_file_name;
    vector<string> csvFileList;
    vector<int> dateList;
    typedef vector<Menu> MenuList;
    map<string, MenuList> menuTable;
    map<string, validTime> categoryValidTime;

    // Protected member functions
    inline void setCSVFileList(void);
    inline int getTotalCalorie(const vector<string>& foodList) const;

    void addCSVtoMenuTable(const string& csv_file_name);

public:
    // Constructor & Destructor
    Cafeteria() {}; // DO NOT USE this default Constructure
    Cafeteria(const string new_list_file_name, const map<string, validTime> newCategoryValidTime);
    virtual ~Cafeteria() {};

    // Public member functions
    inline bool isValidDate(const int& date) const;
    map<string, Menu> getMenuTable(const int& date, const validTime& time); // for non-member user
    map<string, Menu> getMenuTable(const int& date, const validTime& time, const int& calorie); // for member user
};


map<string, Cafeteria> updateCafeteria();
#endif