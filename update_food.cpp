#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "food.h"
#include "cafeteria.h"

using namespace std;

map<string,Food> updateFood() {
	
    ifstream menu("food.txt", std::ios::in);
    
    string name;
    string calorie;
    map<string, Food> Food_list;

    while (menu.peek() != EOF) {
        getline(menu, name, ',');
        getline(menu, calorie);
        Food_list.insert(make_pair(name,Food(name, stoi(calorie))));
        //cout << name << " " << calorie << endl;
    }
    menu.close();
    return Food_list;
}