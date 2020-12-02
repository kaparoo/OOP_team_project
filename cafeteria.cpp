// #include "cafeteria.h"
// 
// // initialize static variables
// const string Cafeteria::dir_prefix = "./data_files/";
// map<string, Food> Cafeteria::foodMap = updateFood();
// 
// Cafeteria::Cafeteria(const string& new_list_file_name) {
//     this->csv_list_file_name = new_list_file_name;
//     setCSVFileList(); // load csv files
//     for(const string& csv_file_name : this->csvFileList)
//         addCSVtoMenuTable(csv_file_name);
// }
// 
// inline void Cafeteria::setCSVFileList(void) {
//     const string list_file_dir = (this->dir_prefix) + (this->csv_list_file_name);
//     ifstream csvListFile(list_file_dir); // plain text file(.txt)
//     string csv_file_name = "";
//     while(getline(csvListFile, csv_file_name))
//         this->csvFileList.push_back(csv_file_name);
//     csvListFile.close();
// }
// 
// inline int Cafeteria::getTotalCalorie(const vector<string>& foodList) const {
//     int total_calorie = 0;
//     for(const string& food_name: foodList) {
//         if(this->foodMap.find(food_name) != this->foodMap.end()) {
//             Food food = foodMap[food_name];
//             total_calorie += food.getCal();
//         }
//     }
//     return total_calorie;
// }
// 
// void Cafeteria::addCSVtoMenuTable(const string& csv_file_name) {
//     CSVReader csvFile(csv_file_name);
//     vector<vector<string>> csvDataTable = csvFile.getDataTable();
//     const int& num_row = csvDataTable.size();
//     const int& num_col = csvDataTable[0].size();
//     const vector<string>& dayList = csvDataTable[0];
//     const vector<string>& dateList = csvDataTable[1];
//     for(int row = 2; row < num_row; ++row) {
//         MenuList categoryMenuList;
//         const vector<string>& category = csvDataTable[row];
//         const vector<string>& category_title = splitLine(category[0], '-');
//         const string& category_name = category_title[0];
//         const int& category_cost = stoi(category_title[1]);
//         for(int i = 1; i < num_col; ++i) {
//             const dayOfWeek& current_day = changeTypeOfDay(dayList[i]);
//             const int& current_date = stoi(dateList[i]);
//             const vector<string>& foodList = splitLine(category[i], '&');
//             const int& current_calorie = getTotalCalorie(foodList);
//             Menu currentMenu(current_date, category_cost, current_calorie, current_day, foodList);
//             categoryMenuList.push_back(currentMenu);
//         }
//         if(menuTable.find(category_name) == menuTable.end()) {
//             this->menuTable.insert(make_pair(category_name, categoryMenuList));
//         } else {
//             MenuList menuList = this->menuTable[category_name];
//             menuList.insert(menuList.end(), categoryMenuList.begin(), categoryMenuList.end());
//             this->menuTable[category_name] = menuList;
//         }
//     }
// }
// 
// map<string,Cafeteria> updateCafeteria(){
//   map<string,Cafeteria> CafeteriaMap;
//   Cafeteria studentCafeteria("student_cafeteria_csv_list.txt");
//   Cafeteria staffCafeteria("staff_cafeteria_csv_list.txt");
//   Cafeteria researchCafeteria("research_cafeteria_csv_list.txt");
//   CafeteriaMap.insert(make_pair("StudentCafeteria",studentCafeteria));
//   CafeteriaMap.insert(make_pair("StaffCafeteria",staffCafeteria));
//   CafeteriaMap.insert(make_pair("ResearchCafeteria",researchCafeteria));
// }
// 