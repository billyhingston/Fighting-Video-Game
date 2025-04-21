#include "Merchant.h"
// constructor
Merchant::Merchant(string in_name) : Human(in_name){
	power = 20;
	money = 200;
}

// method
string Merchant::show_name() {
	return "Merchant " + name;
}