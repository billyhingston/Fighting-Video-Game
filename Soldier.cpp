#include "Soldier.h"
// constructor
Soldier::Soldier(string in_name) : Human(in_name){
	health = 150;
	power = 30;
}

// method
string Soldier::show_name() {
	return "Soldier " + name;
}