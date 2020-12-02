#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "food.h"
#include "cafeteria.h"

using namespace std;

map<string, Food> updateFood() {
	
    ifstream foodFile("./data_files/food.txt", std::ios::in);
    
    string name;
    string calorie;

    map<string, Food> foodMap;

    while (foodFile.peek() != EOF) {
        getline(foodFile, name, ',');
        getline(foodFile, calorie);
        foodMap.insert(make_pair(name, Food(name, stoi(calorie))));
    }

    foodFile.close();
    return foodMap;
}