#include "food.h"

#include <iostream>

#include "config.h"
#include "csv_reader.h"

namespace menu_recomendation_service {

	Food::Food(const std::string& name) noexcept {
		this->name = name;
		this->calorie = 0;
	}

	Food::Food(const std::string& name, const unsigned int& calorie) noexcept {
		this->name = name;
		this->calorie = calorie;
	}

	Food::~Food() {
		// delete name;
		// delete calorie;
	}

	inline void Food::setCalorie(const unsigned int& calorie) {
		// if (this->calorie != nullptr) delete this->calorie;
		// this->calorie = new unsigned int(calorie);
        this->calorie = calorie;
    }

	inline std::string Food::getName() const {
		return this->name;
	}

	unsigned int Food::getCalorie() const {
		return this->calorie;
	}

	std::map<std::string, Food> updateFood() {

		CSVReader foodFile(file_path+food_file);

		std::map<std::string, Food> foodMap;

		const std::vector<std::vector<std::string>>& foodCalorieTable = foodFile.getDataTable();

		for (const std::vector<std::string>& line : foodCalorieTable) {
			// line[0]: name of food, line[1]: calorie(type: string) of food
            const std::string _name = line[0];
            unsigned int _calorie = std::stoi(line[1]);
            
            // std::cout << _name << " : " << line[1] << std::endl;

            
            /*
            if(isNumeric(line[1]) == true) {
                int temp = std::stoi(line[1]);
                if(temp > 0) _calorie = temp;
            }*/
            
			foodMap.insert(std::make_pair(_name, Food(_name, _calorie)));
		}

		return foodMap;
	}

} // namespace menu_recomendation_service