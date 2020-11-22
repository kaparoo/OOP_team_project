#include "menu.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string dayOfWeekToStr(dayOfWeek day) {
    string result = "Not valid";
    switch(day) {
        case dayOfWeek::Mon:
            result = "Mon";
            break;
        case dayOfWeek::Tue:
            result = "Tue";
            break;
        case dayOfWeek::Wed:
            result = "Wed";
            break;
        case dayOfWeek::Thu:
            result = "Thu";
            break;
        case dayOfWeek::Fri:
            result = "Fri";
            break;
        case dayOfWeek::Sat:
            result = "Sat";
            break;
        case dayOfWeek::Sun:
            result = "Sun";
            break;
    }
    return result;
}

void displayMenu(Menu menu) {
    cout << menu.getDate() << "(" << dayOfWeekToStr(menu.getDay()) << ")" << endl;
    cout << "Menu price: " << menu.getCost() << " Won" << endl;
    cout << "Offer time: ";
    validTime time = menu.getValidTime();
    if (time == validTime::Lunch) cout << "Lunch";
    else if (time == validTime::Dinner) cout << "Dinner";
    else if (time == validTime::Both) cout << "Both";
    cout << endl;
    cout << "Food list: ";
    auto foodList = menu.getFoodList();
    for (const string& food : foodList) {
        cout << food << ", ";
    }
    cout << endl;
}

int main() {
    string food1 = "Rise";
    string food2 = "Jjigae";
    string food3 = "Kimchi";
    string sides[] = {"Banchan1", "Banchan2", "Banchan3"};
    vector<string> foods = { food1, food2, food3, sides[0], sides[1], sides[2] };

    // For cunstructor 1
    // cout << "<Cunstructor 1>" << endl;
    // Menu menu(201911066, 201911066, dayOfWeek::Sun, validTime::Both);
    // menu.addFood(food1);
    // menu.addFood(food2);
    // menu.addFood(food3);
    // menu.addFood(sides, 3);

    // For cunstructor 2
    // cout << "<Cunstructor 2>" << endl;
    // Menu menu(201911066, 201911066, dayOfWeek::Sun, validTime::Both, food1);
    // menu.addFood(food2);
    // menu.addFood(food3);
    // menu.addFood(sides, 3);

    // For cunstructor 3
    // cout << "<Cunstructor 3>" << endl;
    // Menu menu(201911066, 201911066, dayOfWeek::Sun, validTime::Both, sides, 3);
    // menu.addFood(food1);
    // menu.addFood(food2);
    // menu.addFood(food3);

    // For cunstructor 4
    cout << "<Cunstructor 4>" << endl;
    Menu menu(201911066, 201911066, dayOfWeek::Sun, validTime::Both, foods);

    displayMenu(menu);

	return 0;
}