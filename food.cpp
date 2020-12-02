#include "food.h"

Food::Food(string name) {
	this->name = name;
}

Food::Food(string name, unsigned int calorie) {
	this->name = name;
	this->calorie = calorie;
}

inline void Food::setCal(unsigned int calorie) { this->calorie = calorie; }

inline string Food::getName() const { return this->name; };
inline unsigned int Food::getCal() const { return this->calorie; };

map<string, Food> updateFood() {
	
    CSVReader foodFile("./data_files/food.csv");

    map<string, Food> foodMap;

    const vector<vector<string>>& foodCalorieTable = foodFile.getDataTable();
    for(const vector<string>& line: foodCalorieTable)
        // line[0]: name of food, line[1]: calorie(type: string) of food
        foodMap.insert(make_pair(line[0], Food(line[0], stoi(line[1]))));

    // ifstream foodFile("./data_files/food.txt", std::ios::in);
    // string name;
    // string calorie;
    // map<string, Food> foodMap;
    // while (foodFile.peek() != EOF) {
    //     getline(foodFile, name, ',');
    //     getline(foodFile, calorie);
    //     foodMap.insert(make_pair(name, Food(name, stoi(calorie))));
    // }
    // foodFile.close();

    return foodMap;
}

// #include <iostream>
// int main() {
//     const auto foodTable = updateFood();
//     for(const auto& entry : foodTable) {
//         const auto& food_name = entry.first; // key
//         const auto& calorie = entry.second.getCal(); // value
//         std::cout << food_name << " : " << calorie << std::endl;
//     }
//     return 0;
// }