#ifndef __OOP_MENU__
#define __OOP_MENU__

#include <vector>
#include <string>

namespace menu_recomendation_service {

	enum class dayOfWeek { Mon, Tue, Wed, Thu, Fri, Sat, Sun, None };
	dayOfWeek changeTypeOfDay(const std::string&);

	class Menu final {
	private:
		unsigned int date;
		dayOfWeek day;
		unsigned int cost;
		unsigned int calorie; // total calorie of the foodList
		std::vector<std::string> foodList;

	public:
		// Constructors & Destructor
		Menu(const unsigned int&, const unsigned int&, const unsigned int&, const dayOfWeek&) noexcept;
		Menu(const unsigned int&, const unsigned int&, const unsigned int&, const dayOfWeek&, std::vector<std::string>&) noexcept;
		~Menu();

		// Public member functions
		unsigned int getDate() const;
		unsigned int getCost() const;
		unsigned int getCalorie() const;
		dayOfWeek getDay() const;
		std::vector<std::string> getFoodList() const;

	};

}

#endif // !__OOP_MENU__