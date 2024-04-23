#pragma once
#include "KorpoWorkers.h"

class Intern : public KorpoWorkers {
public:
    Intern(std::string name, std::string lastname); //Has no salary - default: 0
};
