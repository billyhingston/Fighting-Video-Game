#pragma once
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Human
{
	// attribute
protected:
	string name;
	int health;
	int power;
	int money;

	friend void gain_money(Human& user);
	friend void heal(Human& user, Human& gob);

public:
	// constructor
	Human(string in_name);

	// method
	virtual string show_name();
	int show_health();
	int show_power();
	int show_money();
	void hit(Human& opp);
	void shoot(Human& opp);
	void give_money(Human& opp, int amount);

};

