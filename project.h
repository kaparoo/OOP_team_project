// name of the header guard, SE271_TEAM_PROJECT is temporary
// add any methods or member variables as much as you want 

#ifndef SE271_TEAM_PROJECT
#define SE271_TEAM_PROJECT

#include <string>

class Food {

public:
    Food();
    Food(std::string = "Dummy", unsigned int = 0);
    ~Food();

    inline std::string getName() const;
    inline unsigned int getCalorie() const;

private:
    std::string name;
    unsigned int* calorie;

};

class Cafetria {
public:
    int current_date;
    inline std::string getName() const;
    Food* getFood(const int& date) const;
private:
    std::string name;
    //daily_menu 
};

class User {
public:
    virtual inline bool login(std::string id, std::string password);
    virtual inline std::string getName() const;
    // TODO: ADD MORE METHODS
protected:
    std::string name;
    std::password;
    int member_id;
    Food* last_eaten_food;
};

class Student : public User {
};

class Professor : public User {
};

class Employees : public User {
};

#endif
