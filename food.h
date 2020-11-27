#include <iostream>
#include <vector>
using namespace std;
class Food {
private:
	string name;
	unsigned int calorie;
public:
	Food(string);
	Food(string, unsigned int);

	void setCal(unsigned int);
	string getName();
	unsigned int getCal();
};