#ifndef __OOP_CAFETERIA__
#define __OOP_CAFETERIA__

#include <iostream> 
#include <string> 
#include <vector> 
#include <fstream> 
#include <map>

using namespace std;

class cafeteria {
public:

    string getPrice(string cafeteria, string date, string type);
    string* getMenu(string cafeteria, string date, string type);
    cafeteria();
    cafeteria(string a);
    ~cafeteria();
private:
    map<string, vector<string>>student;
    map<string, vector<string>>research;
    map<string, vector<string>>professor;

};
cafeteria::cafeteria() {}
cafeteria::cafeteria(string a) {
    if (a == "student") {
        vector<string>mon;
        vector<string>tue;
        vector<string>wed;
        vector<string>thu;
        vector<string>fri;
        vector<string> info;

        ifstream myfile;
        myfile.open("C:\\Users\\�ҿ�\\Desktop\\2-2\\student.csv");
        //myfile.open("csv_files/student_cafeteria_weekly_menu(11.09~11.13).csv"); 
        while (myfile.good()) {

            string line;
            getline(myfile, line, ',');
            info.push_back(line);


        }
        for (int i = 0; i < 15; i++) {
            if (i == 2) {
                mon.push_back(info[12]);
                tue.push_back(info[12]);
                wed.push_back(info[12]);
                thu.push_back(info[12]);
                fri.push_back(info[12]);
            }
            else if (i == 4) {
                mon.push_back(info[24]);
                tue.push_back(info[24]);
                wed.push_back(info[24]);
                thu.push_back(info[24]);
                fri.push_back(info[24]);
            }
            else if (i == 10) {
                mon.push_back(info[60]);
                tue.push_back(info[60]);
                wed.push_back(info[60]);
                thu.push_back(info[60]);
                fri.push_back(info[60]);
            }


            mon.push_back(info[6 * i + 1]);
            tue.push_back(info[6 * i + 2]);
            wed.push_back(info[6 * i + 3]);
            thu.push_back(info[6 * i + 4]);
            fri.push_back(info[6 * i + 5]);

        }
        student.insert(pair<string, vector<string>>(info[7], mon));
        student.insert(pair<string, vector<string>>(info[8], tue));
        student.insert(pair<string, vector<string>>(info[9], wed));
        student.insert(pair<string, vector<string>>(info[10], thu));
        student.insert(pair<string, vector<string>>(info[11], fri));

        //string date = "2020.11.16";
        //vector<string>print(student.at(date));
        //cout << print[2] << endl;
        /*for (int i = 0; i < mon.size(); i++) {
            cout << tue[i]<<endl;
        }*/
    }

}
cafeteria::~cafeteria() {}
string cafeteria::getPrice(string cafeteria, string date, string type) {
    if (cafeteria == "student") {
        vector<string>print(student.at(date));
        if (type == "�ǰ") { return print[2]; }
        else if (type == "�߽�") { return print[5]; }
        else if (type == "�") { return print[12]; }
    }

}
string* cafeteria::getMenu(string cafeteria, string date, string type) {
    if (cafeteria == "student") {
        vector<string>print(student.at(date));
        if (type == "�ǰ") {
            string* returnlist = new string[2];
            returnlist[0] = print[3];
            returnlist[1] = print[4];
            return returnlist;
            delete[] returnlist;
        }
        else if (type == "�߽�") {
            string* returnlist = new string[6];
            for (int i = 0; i < 6; i++) {
                returnlist[i] = print[6 + i];
            }
            return returnlist;
            delete[] returnlist;
        }
        else if (type == "�") {
            string* returnlist = new string[5];
            for (int i = 0; i < 5; i++) {
                returnlist[i] = print[13 + i];
            }
            return returnlist;
            delete[] returnlist;
        }
    }
}

#endif