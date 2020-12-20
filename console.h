#ifndef __OOP_CONSOLE__
#define __OOP_CONSOLE__

#include <exception>
#include <map>
#include <string>
#include <vector>

#include "cafeteria.h"
#include "config.h"
#include "csv_reader.h"
#include "display.h"
#include "food.h"
#include "menu.h"
#include "user.h"

namespace menu_recomendation_service {

    // 예외 선언
    class invalidInput : public std::exception {
    public:
        std::string message;
        invalidInput(std::string s) { message = s; }
        std::string what() {
            return message + " is invalid.";
        }
    };

    typedef std::map<int, void (*)()> FunctionMap;

    void signIn();
    void signUp();
    void searchMenu();
    bool check(std::string);
    void recommendMenu();
    void askOption(std::vector<std::string>, FunctionMap);
    
    void startConsole();
    void memberConsole();
    void nonmemberConsole();
    void finishConsole();

}

#endif // !__OOP_CONSOLE__