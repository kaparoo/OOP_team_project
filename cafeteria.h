#ifndef __OOP_CAFETERIA__
#define __OOP_CAFETERIA__

#include <map>
#include <string>
#include <vector>

#include "csv_reader.h"
#include "menu.h"
#include "food.h"

using namespace std;

enum class validTime {Lunch, Dinner, None};

class Cafeteria {
protected:
    // Member variables
    // for data I/O
    static map<string, Food> foodMap = NULL;
    static const string dir_prefix = "./data_files";
    string csv_list_file_name;
    vector<string> csvFileList;

    // for implementation
    typedef vector<Menu> MenuList;
    map<string, MenuList> MenuTable;
    
    // Protected member functions
    inline void setCSVFileList(void);
    inline int getTotalCalorie(const vector<string>& foodList) const;
    inline bool isFoodMapNotExist(void) const;
    void addCSVtoMenuTable(const string& csv_file_name);

public:
    // Constructor & Destructor
    Cafeteria() {}; // DO NOT USE this default Constructure
    Cafeteria(const string& new_list_file_name);
    virtual ~Cafeteria() {};

    // Public member functions
    map<string, Menu> getMenuTable(const int& date, const validTime& time) const; // for non-member user
    map<string, Menu> getMenuTable(const int& date, const validTime& time, const int& calorie) const; // for member user
};

#endif