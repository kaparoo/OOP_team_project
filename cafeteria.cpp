#include "cafeteria.h"

// initialize static variables
const string Cafeteria::dir_prefix = "./data_files/";
map<string, Food> Cafeteria::foodMap = updateFood();

Cafeteria::Cafeteria(const string new_list_file_name, const map<string, validTime> newCategoryValidTime) {
    this->csv_list_file_name = new_list_file_name;
    this->categoryValidTime = newCategoryValidTime;
    setCSVFileList(); // load csv files
    for(const string& csv_file_name : this->csvFileList)
        addCSVtoMenuTable(csv_file_name);
}

inline void Cafeteria::setCSVFileList(void) {
    const string& list_file_dir = (this->dir_prefix) + (this->csv_list_file_name);
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

inline bool Cafeteria::isValidDate(const int& date) const {
    return (find(this->dateList.begin(), this->dateList.end(), date) != this->dateList.end());
}

void Cafeteria::addCSVtoMenuTable(const string& csv_file_name) {
    CSVReader csvFile(csv_file_name);
    vector<vector<string>> csvDataTable = csvFile.getDataTable();
    const int& num_row = csvDataTable.size();
    const int& num_col = csvDataTable[0].size();
    const vector<string>& currentDayList = csvDataTable[0];
    const vector<string>& currentDateList = csvDataTable[1];
    for(int row = 2; row < num_row; ++row) {
        MenuList categoryMenuList;
        const vector<string>& category = csvDataTable[row];
        const vector<string>& category_title = splitLine(category[0], '-');
        const string category_name = category_title[0];
        const int category_cost = stoi(category_title[1]);
        for(int i = 1; i < num_col; ++i) {
            const dayOfWeek current_day = changeTypeOfDay(currentDayList[i]);
            const int current_date = stoi(currentDateList[i]);
            const vector<string> foodList = splitLine(category[i], '&');
            const int current_calorie = getTotalCalorie(foodList);
            Menu currentMenu(current_date, category_cost, current_calorie, current_day, foodList);
            categoryMenuList.push_back(currentMenu);
            dateList.push_back(current_date);
        }
        if(menuTable.find(category_name) == menuTable.end()) { // new category
            this->menuTable.insert(make_pair(category_name, categoryMenuList));
        } else { // category is already exist in menuTable 
            MenuList menuList = this->menuTable[category_name];
            menuList.insert(menuList.end(), categoryMenuList.begin(), categoryMenuList.end());
            this->menuTable[category_name] = menuList;
        }
    }
}


map<string, Menu> Cafeteria::getMenuTable(const int& date, const validTime& time) {
    // Assume date is valid date (Use isValidDate() before)
    map<string, Menu> resultTable;

    for(const auto& categoryEntry : this->menuTable) {
        const string category_name = categoryEntry.first;
        if(categoryValidTime[category_name] != time) continue;
        const MenuList categoryMenuList = categoryEntry.second;
        for(const Menu menu : categoryMenuList) {
            if(menu.getDate() == date) {
                resultTable.insert(make_pair(category_name, menu));
                break;
            }
        }
    }

    return resultTable;
}

map<string, Menu> Cafeteria::getMenuTable(const int& date, const validTime& time, const int& calorie) {
    const map<string, Menu>& rawResultTable = getMenuTable(date, time);
    map<string, Menu> resultTable;
    for(const auto& categoryEntry: rawResultTable) {
        const string category_name = categoryEntry.first;
        const Menu categoryMenu = categoryEntry.second;
        if(categoryMenu.getCalorie() <= calorie) { // ??? 맞게 한건가? 예스예스 생성자 어떻게 쓰는지 밑에 수정해줘
            resultTable.insert(make_pair(category_name, categoryMenu));
        } 
    }
    return resultTable;
}

map<string,Cafeteria> updateCafeteria(){
  map<string,Cafeteria> CafeteriaMap;
  map<string, validTime> studentMap;
  studentMap.insert(make_pair("일품", validTime::Lunch));
  studentMap.insert(make_pair("중식", validTime::Lunch));
  studentMap.insert(make_pair("석식", validTime::Dinner));
  Cafeteria studentCafeteria("student_cafeteria_csv_list.txt", studentMap);
  map<string, validTime> staffMap;
  staffMap.insert(make_pair("중식", validTime::Lunch));
  Cafeteria staffCafeteria("staff_cafeteria_csv_list.txt", staffMap);
  map<string, validTime> researchMap;
  //researchMap.insert(make_pair("중식", Lunch));
  Cafeteria researchCafeteria("research_cafeteria_csv_list.txt", researchMap);
  CafeteriaMap.insert(make_pair("StudentCafeteria",studentCafeteria));
  CafeteriaMap.insert(make_pair("StaffCafeteria",staffCafeteria));
  CafeteriaMap.insert(make_pair("ResearchCafeteria",researchCafeteria));
}