#include "Human.h"
// constructor
Human::Human(string in_name) {
	name = in_name;
	health = 100;
	power = 20;
	money = 100;
}

// method
string Human::show_name() {
	return name;
}
int Human::show_health() {
	return health;
}
int Human::show_power() {
	return power;
}
int Human::show_money() {
	return money;
}
void Human::hit(Human& opp) {
	opp.health = opp.health - power;
}
void Human::shoot(Human& opp) {
	if (money >= 25) {
		opp.health = opp.health - (power * 2);
		money = money - 25;
	}
	else {
		cout << "------- Don't have enough money to buy bullets! -------" << endl;
	}
}
void Human::give_money(Human& opp, int amount) {
	if (money >= amount) {
		opp.money = opp.money + amount;
		money = money - amount;
		if (amount >= 50) {
			opp.power = opp.power - 10;
		}
		else if (amount >= 25) {
			opp.power = opp.power - 7;
		}
		else if (amount >= 13) {
			opp.power = opp.power - 5;
		}

		if (opp.power < 5) {			// change to 5 if power is less than 5
			opp.power = 5;
		}
	}
	else {
		cout << "------- Don't have enough money! -------" << endl;
	}
}