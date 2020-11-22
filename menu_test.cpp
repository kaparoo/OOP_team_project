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

int main() {
	Menu menu = Menu(20201116, 4500, dayOfWeek::Mon, validTime::Lunch);
    string foods[] = {"쟁반짜장", "계란볶음밥", "지코바치밥"};
    menu.addFood(foods, 3);
    cout << menu.getDate() << "(" << dayOfWeekToStr(menu.getDay()) << ")" << endl;
	cout << "메뉴 가격: " << menu.getCost() << endl;
    cout << "제공 시간: ";
    validTime time = menu.getValidTime();
    if (time == validTime::Lunch) cout << "점심(중식)";
    else if (time == validTime::Dinner) cout << "저녁(석식)";
    else if (time == validTime::Both) cout << "점심, 저녁 모두";
    cout << endl;
    cout << "메뉴: ";
    auto foodList = menu.getFoodList();
    for (const string& food : foodList) {
        cout << food << " ";
    }
    cout << endl;
	return 0;
}