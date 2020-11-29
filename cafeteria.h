#ifndef __OOP_CAFETERIA__
#define __OOP_CAFETERIA__

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#include "csv_reader.h"
#include "menu.h"

class Cafeteria {
public:
	Cafeteria();
	Cafeteria(std::string type);
    ~Cafeteria();

protected:
	std::vector<Menu> List;
};

class StudentCafeteria : public Cafeteria {
public:
    StudentCafeteria();
    ~StudentCafeteria();

}

class ResearchCafeteria : public Cafeteria {
public:
    ResearchCafeteria();
    ~ResearchCafeteria();
}

class ProfessorCafeteria : public Cafeteria {
public:
    ProfessorCafeteria();
    ~ProfessorCafeteria();
}

#endif