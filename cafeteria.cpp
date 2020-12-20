#include "cafeteria.h"

#include <iostream>
#include <fstream>
#include <algorithm>

#include "config.h"
#include "csv_reader.h"

namespace menu_recomendation_service {

	std::map<std::string, Food> Cafeteria::foodMap = updateFood();

    Cafeteria::Cafeteria(const std::string& new_list_file_name, const std::map<std::string, validTime>& newCategoryValidTime) noexcept {
        if(Cafeteria::foodMap.empty()){
            foodMap = updateFood();
        }
        this->csv_list_file_name = new_list_file_name;
        this->categoryValidTime = newCategoryValidTime;
        
        setCSVFileList(); // load csv files
        
        for (const std::string& csv_file_name : this->csvFileList){
            addCSVtoMenuTable(file_path + csv_file_name);
        }
            
    }

    inline void Cafeteria::setCSVFileList() {
        std::ifstream csvListFile(file_path + csv_list_file_name);
        std::string csv_file_name = "";
        while (std::getline(csvListFile, csv_file_name)) {
            this->csvFileList.push_back(csv_file_name);
            csv_file_name = "";
        }
        csvListFile.close();
    }


    inline unsigned int Cafeteria::getTotalCalorie(const std::vector<std::string>& foodList) const {
        unsigned int total_calorie = 0;
        for (const std::string& food_name : foodList) {
            unsigned int _calorie = foodMap[food_name].getCalorie();
            total_calorie += foodMap[food_name].getCalorie();
        }
        return total_calorie;
    }

    inline bool Cafeteria::isValidDate(const int& date) const {
        return (find(this->dateList.begin(), this->dateList.end(), date) != this->dateList.end());
    }

    void Cafeteria::addCSVtoMenuTable(const std::string& csv_file_name) {
        CSVReader csvFile(csv_file_name);
        std::vector<std::vector<std::string>> csvDataTable = csvFile.getDataTable();
        
        int num_row = csvDataTable.size();
        int num_col = csvDataTable[0].size();

        const std::vector<std::string>& currentDayList = csvDataTable[0];

        const std::vector<std::string>& tempDateList = csvDataTable[1];
        std::vector<unsigned int> currentDateList;
        for(const std::string date : csvDataTable[1]) {
            if(isNumeric(date)){
                const unsigned int temp = std::stoi(date);
                currentDateList.push_back(temp);
            }
        }

        for (int row = 2; row < num_row; ++row) {

            std::vector<Menu> categoryMenuList;

            const std::vector<std::string>& category = csvDataTable[row];
            const std::vector<std::string>& category_title = splitLine(category[0], '-');
            
            const std::string category_name = category_title[0];
            const unsigned int category_cost = std::stoi(category_title[1]);

            for (int i = 1; i < csvDataTable[row].size(); ++i) {
                const dayOfWeek current_day = changeTypeOfDay(currentDayList[i]);

                const unsigned int current_date = currentDateList[i-1];

                std::vector<std::string> foodList = splitLine(category[i], '&');
                
                const unsigned int current_calorie = getTotalCalorie(foodList);
                Menu currentMenu(current_date, category_cost, current_calorie, current_day, foodList);

                categoryMenuList.push_back(currentMenu);
                dateList.push_back(current_date);
            }
            if (menuTable.find(category_name) == menuTable.end()) { // new category
                this->menuTable.insert(std::make_pair(category_name, categoryMenuList));
            }
            else { // category is already exist in menuTable 
                std::vector<Menu> menuList = this->menuTable[category_name];
                menuList.insert(menuList.end(), categoryMenuList.begin(), categoryMenuList.end());
                this->menuTable[category_name] = menuList;
            }
        }
    }

    std::map<std::string, Menu> Cafeteria::getMenuTable(const int& date, const validTime& time) {
        std::map<std::string, Menu> resultTable;

        for (const auto& categoryEntry : this->menuTable) {
            const std::string category_name = categoryEntry.first;
            if (categoryValidTime[category_name] != time) continue;
            const std::vector<Menu> categoryMenuList = categoryEntry.second;
            for (const Menu menu : categoryMenuList) {
                if (menu.getDate() == date) {
                    resultTable.insert(make_pair(category_name, menu));
                    break;
                }
            }
        }

        return resultTable;
    }

    std::map<std::string, Menu> Cafeteria::getMenuTable(const int& date, const validTime& time, const int& calorie) {
        const std::map<std::string, Menu>& rawResultTable = getMenuTable(date, time);
        std::map<std::string, Menu> resultTable;
        for (const auto& categoryEntry : rawResultTable) {
            const std::string category_name = categoryEntry.first;
            const Menu categoryMenu = categoryEntry.second;
            if (categoryMenu.getCalorie() <= calorie) {
                resultTable.insert(make_pair(category_name, categoryMenu));
            }
        }
        return resultTable;
    }

    std::map<std::string, Cafeteria> updateCafeteria() {
        std::map<std::string, Cafeteria> CafeteriaMap;

        std::map<std::string, validTime> studentMap;
        studentMap.insert(std::make_pair("일품", validTime::Lunch));
        studentMap.insert(std::make_pair("중식", validTime::Lunch));
        studentMap.insert(std::make_pair("석식", validTime::Dinner));
        Cafeteria studentCafeteria("student_cafeteria_csv_list.txt", studentMap);

        std::map<std::string, validTime> staffMap;
        staffMap.insert(std::make_pair("중식", validTime::Lunch));
        Cafeteria staffCafeteria("staff_cafeteria_csv_list.txt", staffMap);

        std::map<std::string, validTime> researchMap;
        researchMap.insert(std::make_pair("중식A", validTime::Lunch));
        researchMap.insert(std::make_pair("중식B", validTime::Lunch));
        researchMap.insert(std::make_pair("석식B", validTime::Dinner));
        Cafeteria researchCafeteria("research_cafeteria_csv_list.txt", researchMap);

        CafeteriaMap.insert(std::make_pair("StudentCafeteria", studentCafeteria));
        CafeteriaMap.insert(std::make_pair("StaffCafeteria", staffCafeteria));
        CafeteriaMap.insert(std::make_pair("ResearchCafeteria", researchCafeteria));

        return CafeteriaMap;
    }

}