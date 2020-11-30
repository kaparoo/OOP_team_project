#include "cafeteria.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "csv_reader.h"
#include "menu.h"
#include "food.h"

using namespace std;

Cafeteria::Cafeteria() {
    const string& file_directory = directory_prefix + csv_list_file_name;
    ifstream csvListFile(file_directory);
    string csv_file_name = "";
    while(getline(csvListFile, csv_file_name))
        csvFileList.push_back(csv_file_name);
    for(const string& csv_file: csvFileList) { // O(n^4)???? WTF?
        CSVReader reader(csv_file);
        auto dataTable = reader.getDataTable();
        const int& row_num = dataTable.size();
        const int& col_num = dataTable[0].size();
        // dataTable[0][1:col_num]: days, dataTable[1][1:col_num]: dates
        // dataTable[2:row_num]: menu choice(i.e., option) in cafeteria
        const vector<string>& days = dataTable[0];
        const vector<string>& dates = dataTable[1];
        for(int i = 2; i < row_num; ++i) { // each menu choice (e.g., 일품, 중식a, 중식b)
            const vector<string>& option = dataTable[i];
            const vector<string>& option_name_cost = splitLine(option[0], '-');
            const string& option_name = option_name_cost[0];
            // option[0]: e.g., "일품-4500" Hence, splitLine(option[0], '-') == {"일품", "4500"}
            const int& cost = stoi(option_name_cost[1]);
            const validTime& time = validTime::Lunch; // cafeteria doesn't offer dinner yet
            const vector<string>& foodList = splitLine(option[j], '&');
            const int& calorie = getTotalCalorie(foodList);
            MenuList menu_list;
            for(int j = 1; j < col_num; ++j) { // each day(date)
                const dayOfWeek& day = changeTypeOfDay(days[j]);
                const int& date = stoi(dates[j]);
                menu_list.push_back(Menu(date, cost, calorie, day, time));
            }
            MenuMap.insert(make_pair(option_name, menu_list));
        }
    }
}

Cafeteria::Cafeteria(const string& new_list_file_name) {
    this->csv_list_file_name = new_list_file_name;
    Cafeteria();
}

Cafeteria::~Cafeteria() { /* None */ }

// csv 파일에는 요일이 한글로 되어있으므로 이를 Menu 인스턴스에서 사용할 수 있도록 validTime으로 변환
dayOfWeek Cafeteria::changeTypeOfDay(const string& str_day) const {
    dayOfWeek day;
    if(str_day == "월" || str_day == "Mon") {
        day = dayOfWeek::Mon;
    } else if(str_day == "화" || str_day == "Tue") {
        day = dayOfWeek::Tue;
    } else if(str_day == "수" || str_day == "Wed") {
        day = dayOfWeek::Wed;
    } else if(str_day == "목" || str_day == "Thu") {
        day = dayOfWeek::Thu;
    } else if(str_day == "금" || str_day == "Fri") {
        day = dayOfWeek::Fri;
    } else {
        day = dayOfWeek::None; // Error
    }
    return day;
}

int Cafeteria::getTotalCalorie(vector<string> foodList) const {
    int total_calorie = 0;
    for(const string& food : foodList) {
        if(this->foodMap.find(food) == foodMap.end()) {
            continue;
        } else {
            Food targetFood = foodMap[food];
            total_calorie += targetFood.getCal();
        }
    }
    return total_calorie;
}

map<string,vector<string>> Cafeteria::getMenutable(string findDay){
 map<string,vector<string>> allMenu;
 dayOfWeek day=changeTypeOfDay(findDay);
 for(auto& menus:MenuMap){
   for(auto& menu:menus.second){
     if(menu.getDay()==day){
       allMenu.insert(make_pair(menus.first,menu.getFoodList())); // <-- getFood()가 아니라 getFoodList(), 이것때문에 오류나서 일단 주석처리함
       break;
     }
   }
 }
 return allMenu;
}

map<string,vector<string>> Cafeteria::getMenutable(string findDay, int minCalorie,int maxCalorie){
 map<string,vector<string>> allMenu;
 dayOfWeek day=changeTypeOfDay(findDay);
 for(auto& menus:MenuMap){
   for(auto& menu:menus.second){
     if(menu.getDay()==day){
     if(menu.getCalorie()>minCalorie && menu.getCalorie()<maxCalorie){
       allMenu.insert(make_pair(menus.first,menu.getFoodList())); // <-- getFood()가 아니라 getFoodList(), 이것때문에 오류나서 일단 주석처리함
       break;
         }
     }
   }
 }
 return allMenu;
}

StudentCafeteria::StudentCafeteria() : Cafeteria("student_cafeteria_csv_list.txt") {}
StudentCafeteria::~StudentCafeteria() {}

StaffCafeteria::StaffCafeteria() : Cafeteria("staff_cafeteria_csv_list.txt") {}
StaffCafeteria::~StaffCafeteria() {}

ResearchCafeteria::ResearchCafeteria() : Cafeteria("research_cafeteria_csv_list.txt") {}
ResearchCafeteria::~ResearchCafeteria() {}

// map<string,Cafeteria> updateCafeteria(){
//   map<string,Cafeteria> CafeteriaMap;
//   StudentCafeteria student;
//   StaffCafeteria staff;
//   ResearchCafeteria research;
//   CafeteriaMap.insert(make_pair("Student",student));
//   CafeteriaMap.insert(make_pair("Staff",staff));
//   CafeteriaMap.insert(make_pair("research",research));
// }