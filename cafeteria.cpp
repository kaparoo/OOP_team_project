#include "cafeteria.h"

#include <iostream>
#include <vector>
#include <string>

#include <stdio.h>

#include "csv_reader.h"
#include "menu.h"
#include "food.h"
#include "foodList.cpp"

using namespace::std;

Cafeteria::Cafeteria(string type) {
	if (type == "student") {
		CSVReader reader("C:\\Users\\소연\\Desktop\\주간메뉴표\\student1.txt");
		vector<vector<string>>info = reader.getData();
		map<string, Food>food_cal = updateFood();

		for (int i = 0; i < 6; i++) {
			
			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					info[1][1] = info[1][1] + ".";
					vector<string>date=splitLine((info[1][1]),'.');
					string firstdate_s = date[0] + date[1] + date[2];
					int firstdate = atoi(firstdate_s.c_str());
					vector<string>food;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					food = splitLine(info[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						unsigned int cal = food_cal.at(food[k]).getCal();
						if (j == 2) { List.push_back(Menu(firstdate + i, 4500,cal,a, validTime::Lunch, food[k])); }
						else if (j == 3) { List.push_back(Menu(firstdate + i, 4000,cal,a, validTime::Lunch, food[k])); }
						else if (j == 4) { List.push_back(Menu(firstdate + i, 4000,cal, a, validTime::Dinner, food[k])); }
						//cout << firstdate + i <<'\t' <<4500 << '\t' <<food[k]<<i<<j << endl;
					}
				}
		}


		CSVReader reader1("C:\\Users\\소연\\Desktop\\주간메뉴표\\student2.txt");
		vector<vector<string>>info2 = reader1.getData();
		map<string, Food>food_cal = updateFood();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					info[1][1] = info[1][1] + ".";
					vector<string>date = splitLine((info[1][1]), '.');
					string firstdate_s = date[0] + date[1] + date[2];
					int firstdate = atoi(firstdate_s.c_str());
					vector<string>food;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					food = splitLine(info2[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						unsigned int cal = food_cal.at(food[k]).getCal();
						if (j == 2) { List.push_back(Menu(firstdate + i, 4500,cal, a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						else if (j == 3) { List.push_back(Menu(firstdate + i, 4000,cal, a, validTime::Lunch, food[k])); }
						else if (j == 4) { List.push_back(Menu(firstdate + i, 4000,cal,a, validTime::Dinner, food[k])); }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}
		}
	}

	else if (type == "research") {
		CSVReader reader("C:\\Users\\소연\\Desktop\\주간메뉴표\\research1.txt");
		vector<vector<string>>info = reader.getData();
		map<string, Food>food_cal = updateFood();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					info[1][1] = info[1][1] + ".";
					vector<string>date = splitLine((info[1][1]), '.');
					string firstdate_s = date[0] + date[1] + date[2];
					int firstdate = atoi(firstdate_s.c_str());
					vector<string>food;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					food = splitLine(info[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						unsigned int cal = food_cal.at(food[k]).getCal();
						if (j == 2) { List.push_back(Menu(firstdate + i, 4500, cal,a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						else if (j == 3) { List.push_back(Menu(firstdate + i, 4500,cal, a, validTime::Lunch, food[k])); }
						else if (j == 4) { List.push_back(Menu(firstdate + i, 4500, cal,a, validTime::Dinner, food[k])); }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}
		}


		CSVReader reader1("C:\\Users\\소연\\Desktop\\주간메뉴표\\research2.txt");
		vector<vector<string>>info2 = reader1.getData();
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					info[1][1] = info[1][1] + ".";
					vector<string>date = splitLine((info[1][1]), '.');
					string firstdate_s = date[0] + date[1] + date[2];
					int firstdate = atoi(firstdate_s.c_str());
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					vector<string>food;
					food = splitLine(info2[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						unsigned int cal = food_cal.at(food[k]).getCal();
						if (j == 2) { List.push_back(Menu(firstdate + i, 4500,cal, a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						else if (j == 3) { List.push_back(Menu(firstdate + i, 4500,cal, a, validTime::Lunch, food[k])); }
						else if (j == 4) { List.push_back(Menu(firstdate + i, 4500,cal,a, validTime::Dinner, food[k])); }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}
		}

	}
	else if (type == "professor") {
		CSVReader reader("C:\\Users\\소연\\Desktop\\주간메뉴표\\professor1.txt");
		vector<vector<string>>info = reader.getData();
		map<string, Food>food_cal = updateFood();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 3; j++)
				if (i > 0 && j > 1) {
					info[1][1] = info[1][1] + ".";
					vector<string>date = splitLine((info[1][1]), '.');
					string firstdate_s = date[0] + date[1] + date[2];
					int firstdate = atoi(firstdate_s.c_str());
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					vector<string>food;
					food = splitLine(info[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						unsigned int cal = food_cal.at(food[k]).getCal();
						if (j == 2) { List.push_back(Menu(firstdate + i, 5000, cal,a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}


		}
		CSVReader reader1("C:\\Users\\소연\\Desktop\\주간메뉴표\\professor2.txt");
		vector<vector<string>>info2 = reader.getData();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 3; j++) {
				if (i > 0 && j > 1) {
					info[1][1] = info[1][1] + ".";
					vector<string>date = splitLine((info[1][1]), '.');
					string firstdate_s = date[0] + date[1] + date[2];
					int firstdate = atoi(firstdate_s.c_str());
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					vector<string>food;
					food = splitLine(info2[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						unsigned int cal = food_cal.at(food[k]).getCal();
						if (j == 2) { List.push_back(Menu(firstdate + i, 5000,cal,a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}


			}

		}
	}
}