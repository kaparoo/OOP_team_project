#include "console.h"

#include <iostream>

namespace menu_recomendation_service {
    
    std::map<unsigned int, User> userMap = updateUser();
    std::map<std::string, Cafeteria> cafeteriaMap = updateCafeteria();
    User currentUser; //use in memberConsole

    // 첫시작 콘솔
    void startConsole() {
        // displayClear();
        std::cout << "This is the first page" << std::endl;
        FunctionMap startFunctionMap;
        startFunctionMap.insert(std::make_pair(1, signIn));
        startFunctionMap.insert(std::make_pair(2, nonmemberConsole));
        startFunctionMap.insert(std::make_pair(3, signUp));
        startFunctionMap.insert(std::make_pair(4, finishConsole));
        std::vector<std::string> prompt = { "[1] Sign in", "[2] Search Menu", "[3] Sign up","[4] Exit" };
        askOption(prompt, startFunctionMap);
    }

    //회원용 콘솔
    void memberConsole() {
        // displayClear();
        std::cout << "This is for the member" << std::endl;
        std::cout << "User: " << currentUser.getId() << std::endl;
        FunctionMap memberFunctionMap;
        std::vector<std::string> prompt = { "[0] Back", "[1] Recommend Menu", "[2] Search Menu", "[3] Exit" };
        memberFunctionMap.insert(std::make_pair(1, recommendMenu));
        memberFunctionMap.insert(std::make_pair(2, searchMenu));
        memberFunctionMap.insert(std::make_pair(3, finishConsole));
        memberFunctionMap.insert(std::make_pair(0, startConsole)); //back
        askOption(prompt, memberFunctionMap);
    }

    //비회원용 콘솔
    void nonmemberConsole() {
        // displayClear();
        std::cout << "This is for the non-member" << std::endl;
        std::cout << "If you are a DGIST member, back to the page and log in." << std::endl;
        FunctionMap nonmemberFunctionMap;
        std::vector<std::string> prompt = { "[0] Back", "[1] Search Menu", "[2] Exit" };
        nonmemberFunctionMap.insert(std::make_pair(1, searchMenu));
        nonmemberFunctionMap.insert(std::make_pair(2, finishConsole));
        nonmemberFunctionMap.insert(std::make_pair(0, startConsole)); //back
        askOption(prompt, nonmemberFunctionMap);
    }

    void signIn() { //로그인
        try {
            std::string ID;
            std::string password;
            std::cout << "ID:";
            std::cin >> ID;
            if (isNumeric(ID)) {
                std::cout << '\n' << "Password:";
                std::cin >> password;
                if (userMap[std::stoi(ID)].checkId(password)) {
                    currentUser = userMap[std::stoi(ID)];
                    memberConsole();
                }
                else {
                    throw invalidInput("Password");
                }
            }
            else {
                throw invalidInput("ID");
            }
        }
        catch (invalidInput e) {
            std::cout << e.what() << std::endl;
            startConsole();
        }
    }

    void signUp() { //회원가입
        try {
            std::string newID;
            std::string password;
            std::cout << "ID:";
            std::cin >> newID;
            if (isNumeric(newID)) {
                std::cout << '\n' << "Password:";
                std::cin >> password;
                if (password != "") userMap.insert(std::make_pair(std::stoi(newID), User(std::stoi(newID), password)));
                else {
                    throw invalidInput("Password");
                }
            }
            else {
                throw invalidInput("ID");
            }
        }
        catch (invalidInput e) {
            std::cout << e.what() << std::endl;
            startConsole();
        }
    }

    void recommendMenu() { //메뉴추천
        //날짜 입력
        std::string date;
        std::cout << "Input the date." << "ex) 20201108" << std::endl;
        std::cin >> date;
        while (check(date) == false) {
            std::cout << "No information for the date" << std::endl;
            std::cout << "Input the date again." << std::endl;
            std::cin >> date;
        }
        //시간대 입력
        int selection;
        std::cout << "[1] Lunch [2] Dinner" << std::endl;
        std::cin >> selection;
        while (selection != 1 && selection != 2) {
            std::cout << "It's the wrong input. Input again: " << std::endl;
            std::cin >> selection;
        }
        //유저 칼로리 정보 확인
        if (currentUser.getCalorie() == 0) {
            //이전 칼로리 입력
            int lastCal;
            std::cout << "How many calories did you eat before?" << std::endl;
            std::cin >> lastCal;
            while (lastCal < 0) {
                std::cout << "It's the wrong input. Input again: " << std::endl;
                std::cin >> lastCal;
            }
        }
        else {
            //칼로리 정보 입력유무
            int update;
            std::cout << "Do you want to revise last eaten menu's calories?" << std::endl;
            std::cout << "[1] Yes [2] No" << std::endl;
            std::cin >> update;
            if (update == 1) {
                //이전 칼로리 입력
                int lastCal;
                std::cout << "How many calories did you eat before?";
                std::cin >> lastCal;
                while (lastCal < 0) {
                    std::cout << "It's the wrong input. Input again: ";
                    std::cin >> lastCal;
                }
                currentUser.setCalorie(lastCal);
            }
        }
        int excessCal = currentUser.getCalorie() - 1000;
        std::cout << "This is a recommended menu based on the recommended calories per meal." << std::endl;
        if (excessCal > 600) {
            std::cout << "It is recommended not to eat at least one meal." << std::endl;
        }
        else {
            //메뉴가져오기
            if (selection == 1) {
                for (auto cafeteria : cafeteriaMap) {
                    std::cout << std::endl;
                    std::cout << cafeteria.first << std::endl;
                    if (cafeteria.second.getMenuTable(std::stoi(date), validTime::Lunch, 1000 - excessCal).size() == 0)
                        std::cout << "There is no menu that can be recommended" << std::endl;
                    else {
                        for (auto menulist : cafeteria.second.getMenuTable(std::stoi(date), validTime::Lunch, 1000 - excessCal)) {
                            std::cout << '<' << menulist.first << '>' << std::endl;
                            std::cout << menulist.second.getCalorie() << "kcal" << std::endl;
                            for (auto food : menulist.second.getFoodList()) {
                                std::cout << food << std::endl;
                            }
                        }
                    }
                }
                std::cout << std::endl;
            }
            else {
                for (auto cafeteria : cafeteriaMap) {
                    std::cout << std::endl;
                    std::cout << cafeteria.first << std::endl;
                    for (auto menulist : cafeteria.second.getMenuTable(std::stoi(date), validTime::Dinner, 1000 - excessCal)) {
                        std::cout << '<' << menulist.first << '>' << std::endl;
                        std::cout << menulist.second.getCalorie() << "kcal" << std::endl;
                        if (menulist.second.getFoodList().size() == 0) std::cout << "No food can be provided." << std::endl;
                        else {
                            for (auto food : menulist.second.getFoodList()) {
                                std::cout << food << std::endl;
                            }
                        }
                    }
                }
                std::cout << std::endl;
            }



        }

    }

    void searchMenu() { //메뉴검색
        //날짜 입력
        std::string date;
        std::cout << "Input the date." << "ex) 20201108" << std::endl;
        std::cin >> date;
        while (check(date) == false) {
            std::cout << "No information for the date" << std::endl;
            std::cout << "Input the date again." << std::endl;
            std::cin >> date;
        }
        //시간대 입력
        int selection;
        std::cout << "[1] Lunch [2] Dinner" << std::endl;
        std::cin >> selection;
        while (selection != 1 && selection != 2) {
            std::cout << "It's the wrong input. Input again: " << std::endl;
            std::cin >> selection;
        }
        std::cout << "search menu" << std::endl;
        //메뉴가져오기
        validTime _time = validTime::Lunch; // selection == 1
        if (selection == 2) {
            _time = validTime::Dinner;
        }
        for (auto cafeteria : cafeteriaMap) {
            std::cout << std::endl;
            std::cout << cafeteria.first << std::endl;
            for (auto menulist : cafeteria.second.getMenuTable(std::stoi(date), _time)) {
                std::cout << '<' << menulist.first << '>' << std::endl;
                std::cout << "Price: " << menulist.second.getCost() << "won" <<std::endl;
                for (auto food : menulist.second.getFoodList()) {
                    std::cout << food << std::endl;
                }
            }
        }
        std::cout << std::endl;
    }

    //종료
    void finishConsole() {
        storeUser(userMap); // user 정보 저장
        exit(0); //콘솔 종료
    }

    //날짜 확인
    bool check(std::string s) {
        std::string s1 = s.substr(0, 6);
        int s2 = std::stoi(s.substr(6, 2));
        if (s.length() != 8)
            return false;
        else if (s1 != "202011")
            return false;
        else if ((9 <= s2 && s2 <= 13) || (16 <= s2 && s2 <= 20))
            return true;
        else
            return false;
    }

    void askOption(std::vector<std::string> prompt, FunctionMap actions) {
        // displayClear();
        void (*action)();
        while (1) { // 종료시까지 실행
            std::cout << project_title << std::endl;
            displayPromptInBox(prompt, 1);

            /*
            for(const auto& line : prompt) {
                std::cout << line << std::endl;
            }
            */

            std::string user_input;
            std::cout << std::endl << "Enter the number: ";
            std::cin >> user_input;

            int option;

            try {
                option = std::stoi(user_input);
                if (actions.find(option) == actions.end()) { // 유효하지 않은 선택
                    std::cout << "This is an invalid choice!" << std::endl;
                    std::cout << "Please choose between the numbers on the screen!" << std::endl;
                    continue;
                }
                else {
                    action = actions[option]; // 선택에 맞는 함수를 찾음   
                    action();
                    std::cout << "If you enter any character, return to the previous one." << std::endl;
                    std::string any;
                    std::cin >> any;
                }
            }
            catch (std::exception e) {
                // displayClear();
                std::cout << "This is an invalid choice!" << std::endl;
                std::cout << "Please choose between the numbers on the screen!" << std::endl;
            }
        }
    }
}