#include "Goblin.h"
// constuctor
Goblin::Goblin(string in_name, int in_power) : Human(in_name){
	power = in_power;
	money = 0;
}

// method
string Goblin::show_name() {
	return "Goblin " + name;
}
int Goblin::check_money() {
	if (money >= 100) {
		return 1;
	}
	else {
		return 0;
	}
}

// destructor
Goblin::~Goblin() {

}