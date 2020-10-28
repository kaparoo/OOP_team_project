#ifndef SE271_TEAM_PROJECT
#define SE271_TEAM_PROJECT

#include <string>

class Food {

public:
    Food();
    Food(std::string = "Dummy", unsigned int = 0);
    ~Food();

    std::string getName() const;
    unsigned int getCalorie() const;

private:
    std::string name;
    unsigned int* calorie;

};

#endif
