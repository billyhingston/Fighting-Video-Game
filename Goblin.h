#pragma once
#include "Human.h"
class Goblin :
    public Human
{
    // attribute

public:
    // constuctor
    Goblin(string in_name, int in_power);

    // method
    string show_name();
    int check_money();

    // destructor
    ~Goblin();
};

