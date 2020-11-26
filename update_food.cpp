#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "food.h"

using namespace std;
int main(){
	ifstream menu("food.txt",std::ios::in);
    string name;
    string calorie;
    vector<Food> Food_list;

    while (menu.peek() != EOF) { //파일 끝인지 체크  
        getline(menu, name, ',');
        getline(menu, calorie);
        Food_list.push_back(Food(name, stoi(calorie)));
        cout << name << " " << calorie << endl;
    }
    menu.close();

    return 0;
}