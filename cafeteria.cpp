#include "cafeteria.h"

#include "csv_reader.h"
#include "menu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace::std;
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <stdio.h>

std::vector<std::string> split(std::string str, char delimiter)
{
	uint64_t start_pos = 0;
	uint64_t search_pos = 0;
	std::vector<std::string> result;

	while (start_pos < str.size())
	{
		search_pos = str.find_first_of(delimiter, start_pos);
	
		std::string tmp_str;

		if (search_pos == std::string::npos)
		{
			// for last token
			search_pos = str.size();
			tmp_str = str.substr(start_pos, search_pos - start_pos);
			result.push_back(tmp_str);
			break;
		}
		tmp_str = str.substr(start_pos, search_pos - start_pos);
		result.push_back(tmp_str);
		start_pos = search_pos + 1;
	}

	return result;
}

class cafeteria {
public:
	cafeteria();
	cafeteria(string type);
	
private:
	vector<Menu>List;
};
cafeteria::cafeteria(string type) {
	if (type == "student") {
		CSVReader reader("C:\\Users\\소연\\Desktop\\주간메뉴표\\student1.txt");
		vector<vector<string>>info = reader.getData();


		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					int firstdate = 20201108;
					vector<string>food;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i ==3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					food = split(info[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						/*class Food(food[k]) a,*//*,a.getCal()*/
						if (j == 2) {List.push_back( Menu(firstdate + i, 4500, a, validTime::Lunch, food[k])); }
						else if (j == 3) {List.push_back(Menu(firstdate + i, 4000, a, validTime::Lunch, food[k])); }
						else if (j == 4) { List.push_back(Menu(firstdate + i, 4000, a, validTime::Dinner, food[k])); }
						//cout << firstdate + i <<'\t' <<4500 << '\t' <<food[k]<<i<<j << endl;
					}
				}
		}


		CSVReader reader1("C:\\Users\\소연\\Desktop\\주간메뉴표\\student2.txt");
		vector<vector<string>>info2 = reader1.getData();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					int firstdate = 20201115;
					vector<string>food;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i ==4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					food = split(info2[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						if (j == 2) { List.push_back(Menu(firstdate + i, 4500, a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						else if (j == 3) { List.push_back(Menu(firstdate + i, 4000, a, validTime::Lunch,food[k])); }
						else if (j == 4) {List.push_back(Menu(firstdate + i, 4000, a, validTime::Dinner,food[k])); }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}
		}
	}

	else if (type == "research") {
		CSVReader reader("C:\\Users\\소연\\Desktop\\주간메뉴표\\research1.txt");
		vector<vector<string>>info = reader.getData();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					int firstdate = 20201108;
					vector<string>food;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					food = split(info[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						if (j == 2) { List.push_back(Menu(firstdate + i, 4500, a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						else if (j == 3) { List.push_back(Menu(firstdate + i, 4500, a, validTime::Lunch, food[k])); }
						else if (j == 4) { List.push_back(Menu(firstdate + i, 4500, a, validTime::Dinner, food[k])); }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}
		}


		CSVReader reader1("C:\\Users\\소연\\Desktop\\주간메뉴표\\research2.txt");
		vector<vector<string>>info2 = reader1.getData();
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++)
				if (i > 0 && j > 1) {
					int firstdate = 20201115;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					vector<string>food;
					food = split(info2[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						if (j == 2) { List.push_back(Menu(firstdate + i, 4500, a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						else if (j == 3) { List.push_back(Menu(firstdate + i, 4500, a, validTime::Lunch, food[k])); }
						else if (j == 4) { List.push_back(Menu(firstdate + i, 4500, a, validTime::Dinner, food[k])); }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}
		}

	}
	else if (type == "professor") {
		CSVReader reader("C:\\Users\\소연\\Desktop\\주간메뉴표\\professor1.txt");
		vector<vector<string>>info = reader.getData();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 3; j++)
				if (i > 0 && j > 1) {
					int firstdate = 20201108;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i == 3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					vector<string>food;
					food = split(info[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						if (j == 2) { List.push_back(Menu(firstdate + i, 5000, a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}


		}
		CSVReader reader1("C:\\Users\\소연\\Desktop\\주간메뉴표\\professor2.txt");
		vector<vector<string>>info2 = reader.getData();
		for (int i = 0; i < 6; i++) {

			for (int j = 0; j < 3; j++) {
				if (i > 0 && j > 1) {
					int firstdate = 20201115;
					dayOfWeek a;
					if (i == 1) { a = dayOfWeek::Mon; }
					else if (i == 2) { a = dayOfWeek::Tue; }
					else if (i ==3) { a = dayOfWeek::Wed; }
					else if (i == 4) { a = dayOfWeek::Thu; }
					else if (i == 5) { a = dayOfWeek::Fri; }
					vector<string>food;
					food = split(info2[j][i], '&');
					for (int k = 0; k < food.size(); k++) {
						if (j == 2) { List.push_back(Menu(firstdate + i, 5000, a, validTime::Lunch, food[k]))/*date cost day time name*/; }
						//cout << firstdate + i << '\t' << 4500 << '\t' << food[k] << endl;
					}

				}


			}

		}
	}
}
int main() {


	cafeteria a("professor");

	
	return 0;
