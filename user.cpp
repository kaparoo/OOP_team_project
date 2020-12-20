#include "user.h"

#include <fstream>
#include <map>
#include <string>

#include "config.h"
#include "csv_reader.h"
#include "menu.h"

namespace menu_recomendation_service {

	unsigned int User::usernum = 0;

	User::User(const unsigned int& id, const std::string& password) noexcept{
		// this->id = new unsigned int(id);
		// this->password = new std::string(password);
		// this->calorie = new unsigned int(0);
		this->id = id;
        this->password = password;
        this->calorie = 0;
        ++usernum;
	}

	User::User(const unsigned int& id, const std::string& password, const unsigned int& calorie) noexcept {
		// this->id = new unsigned int(id);
		// this->password = new std::string(password);
		// this->calorie = new unsigned int(calorie);
		this->id = id;
        this->password = password;
        this->calorie = calorie;
        ++usernum;
	}

	User::~User() {
		// delete id;
		// delete password;
		// delete calorie;
		// --usernum;
	}

	void User::setCalorie(const Menu& menu) {
		// if (this->calorie != nullptr) delete calorie;
		// this->calorie = new unsigned int(menu.getCalorie());
        this->calorie = menu.getCalorie();
    }

	void User::setCalorie(const unsigned int& new_calorie) {
		// if (this->calorie != nullptr) delete calorie;
		// this->calorie = new unsigned int(new_calorie);
        this->calorie = new_calorie;
    }

	unsigned int User::getId() const { return this->id; }
	unsigned int User::getCalorie() const { return this->calorie; }
	std::string User::getPassword() const { return this->password; } // private member function
	
	bool User::checkId(const std::string& target_password) {
		if (this->password == target_password) {
			return true;
		}
		else {
			return false;
		}
	}
	void User::changePassword(const std::string& new_password) {
		// if (this->password != nullptr) delete this->password;
		// this->password = new std::string(new_password);
        this->password = new_password;
    }

	// Friend functions
	std::map<unsigned int, User> updateUser() {
		std::map<unsigned int, User> userMap;

		CSVReader userFile(file_path + user_file);

		std::vector<std::vector<std::string>> userData = userFile.getDataTable();
		
		for (const auto& row : userData) {
			const unsigned int& _id = std::stoi(row[0]);
			const std::string _pw = row[1];
			const unsigned int& _calorie = std::stoi(row[2]);
			userMap.insert(std::pair<unsigned int, User>(_id, User(_id, _pw, _calorie)));
		}

		return userMap;

	}

	void storeUser(const User& user) {
        CSVReader userFile(file_path + user_file);
        std::vector<std::vector<std::string>> userData = userFile.getDataTable();
        std::ofstream newFile(file_path+user_file);
        for (unsigned int i = 0; i < User::usernum; ++i) {
		    for (int j = 0; j < 3; ++j) {
			    newFile << userData[i][j] << ",";
		    }
		    newFile << "\n";
	    }
	    newFile << user.getId() << "," << user.getPassword() << "," << user.getCalorie() << ","<< "\n";
        newFile.close();
	}

    void storeUser(std::map<unsigned int, User>& userMap) {
    	std::ofstream newFile(file_path+user_file);
	    for (auto p : userMap) {
            const unsigned int _id = p.first;
		    newFile << _id << "," << userMap[_id].getPassword() << "," << userMap[_id].getCalorie() << "," <<"\n";
	    }
        newFile.close();
    }
}