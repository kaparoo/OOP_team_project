#include "cafeteria.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "csv_reader.h"
#include "menu.h"
#include "food.h" // for updateFood()

using namespace std;


/*
class Cafeteria {
protected:
    // for data I/O
    static map<string, Food> foodMap = NULL;
    const string directory_prefix("./data_files");
    string csv_file_list_name;
    vector<string> csvFileList;
    // for implementation
    vector<string> categoryList;
    typedef vector<Menu> MenuList;
    typedef map<string, MenuList> MenuMap;
public:
    // Constructure & Destructure
    Cafeteria();
    Cafeteria(const string& new_list_file_name);
    virtual ~Cafeteria() {};
    // Member functions
    inline void setCSVFileList(void);
    inline int getTotalCalorie(const MenuList& menuList) const;
    inline bool isFoodMapNotExist(void) const;
    MenuMap addCSVtoMenuMap(const string& new_list_file_name);
    map<string, Menu> getMenuTable(const int& date, const validTime& time) const; // for non-member user
    map<string, Menu> getMenuTable(const int& date, const validTime& time, const int& calorie) const; // for member user
};
*/

Cafeteria::Cafeteria(const string& new_list_file_name) {
    this->csv_list_file_name = new_list_file_name;
    if(isFoodMapNotExist()) foodMap = updateFood(); // foodMap is NULL
    setCSVFileList(); // load csv files
    for(const string& csv_file_name : this->csvFileList)
        addCSVtoMenuTable(csv_file_name);
}

inline void Cafeteria::setCSVFileList(void) {
    const string list_file_dir = (this->dir_prefix) + (this->csv_list_file_name);
    ifstream csvListFile(list_file_dir); // plain text file(.txt)
    string csv_file_name = "";
    while(getline(csvListFile, csv_file_name))
        this->csvFileList.push_back(csv_file_name);
    csvListFile.close();
}

inline int Cafeteria::getTotalCalorie(const vector<string>& foodList) const {
    int total_calorie = 0;
    for(const string& food_name: foodList) {
        if(this->foodMap.find(food_name) != this->foodMap.end()) {
            Food food = foodMap[food_name];
            total_calorie += food.getCal();
        }
    }
    return total_calorie;
}

inline bool Cafeteria::isFoodMapNotExist(void) const {
    return (this->foodMap) == NULL;
}

void Cafeteria::addCSVtoMenuTable(const string& csv_file_name) {
    CSVReader csvFile(csv_file_name);
    vector<vector<string>> csvData = csvFile.getDataTable();
    
}


map<string,vector<string>> Cafeteria::getMenutable(string findDay, int minCalorie,int maxCalorie){
 map<string,vector<string>> allMenu;
 dayOfWeek day=changeTypeOfDay(findDay);
 for(auto& menus:MenuMap){
   for(auto& menu:menus.second){
     if(menu.getDay()==day){
     if(menu.getCalorie()>minCalorie && menu.getCalorie()<maxCalorie){
       allMenu.insert(make_pair(menus.first,menu.getFoodList()));
       break;
         }
     }
   }
 }
 return allMenu;
}

map<string,Cafeteria> updateCafeteria(){
  map<string,Cafeteria> CafeteriaMap;
  Cafeteria studentCafeteria("student_cafeteria_csv_list.txt");
  Cafeteria staffCafeteria("staff_cafeteria_csv_list.txt");
  Cafeteria researchCafeteria("research_cafeteria_csv_list.txt");
  CafeteriaMap.insert(make_pair("StudentCafeteria",studentCafeteria));
  CafeteriaMap.insert(make_pair("StaffCafeteria",staffCafeteria));
  CafeteriaMap.insert(make_pair("ResearchCafeteria",researchCafeteria));
}