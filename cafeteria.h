#ifndef __OOP_CAFETERIA__
#define __OOP_CAFETERIA__

#include <map>
#include <string>
#include <vector>

#include "food.h"
#include "menu.h"

namespace menu_recomendation_service {
    
    enum class validTime { Lunch, Dinner, None };

    class Cafeteria final {
    private:
        static std::map<std::string, Food> foodMap;
        std::string csv_list_file_name;
        std::vector<std::string> csvFileList;
        std::vector<unsigned int> dateList;
        std::map<std::string, std::vector<Menu>> menuTable;
        std::map<std::string, validTime> categoryValidTime;

        // Private member functions
        inline void setCSVFileList();
        inline unsigned int getTotalCalorie(const std::vector<std::string>&) const;
        void addCSVtoMenuTable(const std::string&);

    public:
        // Constructor & Destructor
        Cafeteria(const std::string&, const std::map<std::string, validTime>&) noexcept;
        ~Cafeteria() { }

        // Public member functions
        inline bool isValidDate(const int&) const;
        std::map<std::string, Menu> getMenuTable(const int&, const validTime&); // for non-member user
        std::map<std::string, Menu> getMenuTable(const int&, const validTime&, const int&); // for member user

    };

    std::map<std::string, Cafeteria> updateCafeteria();
}

#endif // ! __OOP_CAFETERIA__