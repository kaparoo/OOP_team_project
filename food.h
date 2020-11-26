#include <iostream>
#include <vector>
using namespace std;
class Food {
private:
	string name;
	vector<string> ingredients;
	unsigned int calorie;
	vector<string> allergic;
public:
	Food(string Name) {
		name = Name;
	}
	Food(string Name, int Calorie) {
		name = Name;
		calorie = Calorie;
	}

	//set information of Food
	void addIngredient(string ingredient) { ingredients.push_back(ingredient); }
	void addIngredient(vector<string> ingredient_list) {
		for (string& ingredient: ingredient_list) {
			ingredients.push_back(ingredient);
		}
	}
	void setCalorie(unsigned int Calorie) {
		calorie = Calorie;
	}
	void addAllergic(string Allergic) { allergic.push_back(Allergic); }
	void addAllergic(vector<string> Allergic_list) {
		for (string& Allergic : Allergic_list) {
			allergic.push_back(Allergic);
		}
	}

	// get informaiton of Food
	string getName() { return name; }
	vector<string> getIngredient() { return ingredients; }
	unsigned int getCalorie() { return calorie; }
	vector<string> getAllergic() { return allergic; }
};