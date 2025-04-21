#pragma once
#include "Human.h"
class Soldier :
    public Human
{
    // attribute

public:
    // constructor
    Soldier(string in_name);

    // method
    string show_name();
};

