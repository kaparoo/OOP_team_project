#ifndef __OOP_USER__
#define __OOP_USER__

#include <map>
#include <string>

#include "menu.h"

namespace menu_recomendation_service {
	class User final {
	private:
		static unsigned int usernum; // total number of the registered users
		unsigned int id;
		std::string password;
		unsigned int calorie;

		// Private member function
		std::string getPassword() const;

	public:
    User(){};
		User(const unsigned int&, const std::string&) noexcept;
		User(const unsigned int&, const std::string&, const unsigned int&) noexcept;
		~User();

		// Public member functions
		void setCalorie(const Menu&);
		void setCalorie(const unsigned int&);

		unsigned int getId() const;
		unsigned int getCalorie() const;

		bool checkId(const std::string&);
		void changePassword(const std::string&);

		// Friend functions
		friend void storeUser(const User&);
		friend void storeUser(std::map<unsigned int, User>&);
		friend std::map<unsigned int, User> updateUser();

	};
  std::map<unsigned int, User> updateUser();
}

#endif // !__OOP_USER__