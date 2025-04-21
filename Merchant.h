#pragma once
#include "Human.h"
class Merchant :
    public Human
{
    // attribute

public:
    // constructor
    Merchant(string in_name);

    // method
    string show_name();
};

