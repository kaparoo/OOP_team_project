#ifndef __OOP_FOOD__
#define __OOP_FOOD__

#include <map>
#include <string>

namespace menu_recomendation_service {
	class Food final {
	private:
		std::string name;
		unsigned int calorie;

	public:
        Food() noexcept {};
		Food(const std::string&) noexcept;
		Food(const std::string&, const unsigned int&) noexcept;
		~Food();

		inline void setCalorie(const unsigned int&);
		inline std::string getName() const;
		unsigned int getCalorie() const;

	};

	std::map<std::string, Food> updateFood();

}

#endif // !__OOP_FOOD__