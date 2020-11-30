#ifndef __OOP_CAFETERIA__
#define __OOP_CAFETERIA__

#include <map>
#include <string>
#include <vector>

#include "csv_reader.h"
#include "menu.h"
#include "food.h"

using namespace std;

class Cafeteria {
protected:
    static map<string, Food> foodMap = updateFood();
    string directory_prefix = "./data_files/";
	string csv_list_file_name;
    vector<string> csvFileList;
    typedef vector<Menu> MenuList;
    //menulist이름, menulist로 map(식당마다 메뉴리스트 이름과 개수가 달라서)
    map<string, MenuList> MenuMap;
public:
	Cafeteria();
    Cafeteria(const string&);
    virtual ~Cafeteria();
    dayOfWeek changeTypeOfDay(const string&) const;// change type of day from std::string to dayOfWeek(enum defined in menu.h)
    int getTotalCalorie(vector<string>) const;
    map<string,vector<string>> getMenutable(string);
    map<string,vector<string>> getMenutable(string, int, int=1000);
};

class StaffCafeteria : public Cafeteria {
public:
    StaffCafeteria();
    ~StaffCafeteria();
};

class StudentCafeteria : public Cafeteria {
public:
    StudentCafeteria();
    ~StudentCafeteria();
};

class ResearchCafeteria : public Cafeteria {
public:
    ResearchCafeteria();
    ~ResearchCafeteria();
};

map<string,Cafeteria> updateCafeteria();
#endif