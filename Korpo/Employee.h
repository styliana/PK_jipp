#pragma once
#include "KorpoWorkers.h"

class Manager; // forward declaration

class Employee : public KorpoWorkers {
public:
    Employee(std::string name, std::string lastname, int salary);

};
