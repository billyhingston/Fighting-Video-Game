#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Human.h"
#include "Soldier.h"
#include "Merchant.h"
#include "Goblin.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void gain_money(Human& user) {
	int number = (rand() % 4) + 1;		// (rand() % 4) + 1 makes range 1 - 5
	int guess;
	cout << "----- GET MONEY ----" << endl << "Guess a number 1 - 5: ";
	cout << "(For testing), the number is: " << number << endl;
	cin >> guess;
	if (guess == number) {
		user.money = user.money + 50;
		cout << "You guessed: " << guess << ". That is the correct number!" << endl << "You gained $50!" << endl;
	}
	else if (((guess + 1) == number)||((guess - 1) == number)) {		// one off
		user.money = user.money + 40;
		cout << "You guessed: " << guess << ". That is one off" << endl << "You gained $40!" << endl;
	}
	else if (((guess + 2) == number) || ((guess - 2) == number)) {
		user.money = user.money + 30;
		cout << "You guessed: " << guess << ". That is two off" << endl << "You gained $30!" << endl;
	}
	else if (((guess + 3) == number) || ((guess - 3) == number)) {
		user.money = user.money + 20;
		cout << "You guessed: " << guess << ". That is three off" << endl << "You gained $20!" << endl;
	}
	else if (((guess + 4) == number) || ((guess - 4) == number)) {
		user.money = user.money + 10;
		cout << "You guessed: " << guess << ". That is four off" << endl << "You gained $10!" << endl;
	}
	else{
		cout << "Guess too far off. You were not healed!" << endl;
	}
	cout << "---------------" << endl;
}
void heal(Human& user, Human& gob) {
	cout << "You were healed by 50 (Max health is 100), but the Goblin increases its attack power by 5!" << endl;
	user.health = user.health + 50;
	if (user.health > 150) {			// max health is 150 (from soldier class)
		user.health = 150;
	}
	gob.power = gob.power + 5;
	cout << user.show_name() << " (health): " << user.show_health() << " (power): " << user.show_power();
	cout << " (money): " << user.show_money() << endl;
	cout << "---------" << endl;

}

int main() {
	int player_choice = 3;
	string name;
	cout << "###################### Welcome to the game! ######################" << endl;
	cout << "You fight 5 goblins and when all their health drops to 0, you win. You can hit or shoot them. Note that shooting cost" << endl;
	cout << "money. However, you can give goblins money to spare them. A goblin needs $100 to be satisfied. If you" << endl;
	cout << "spare a goblin, the next goblin you fight will be weaker. Good luck!" << endl;
	cout << "##################################################################" << endl;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Choose your character! (1) - Soldier, (2) - Merchant: ";
	while ((player_choice != 1)&& (player_choice != 2)) {
		cin >> player_choice;
		if ((player_choice != 1) && (player_choice != 2)) {
			cout << "Invlaid selection. Reselect: ";
		}
	}
	Human* user;
	if (player_choice == 1) {
		user = new Soldier(name);
	}
	else {
		user = new Merchant(name);
	}
	int select;
	int amount_given;
	string gob_arr[5] = { "1", "2", "3", "4", "5"};
	int power = 0;
	srand(time(0));
	int goblin_likabilty = 0;
	for (int i = 0; i < 5; i++) {			// fight 5 goblins
		if (user->show_health() > 0) {		// so the messages aren't displayed after you die
			cout << "--------------------------------------" << endl;
			if (goblin_likabilty == 0) {
				power = (rand() % 20) + 15;		// (rand() % 20) + 15 makes range 15 - 35
				cout << "      The goblins DESPISE you! (15 - 35 power)" << endl;
			}
			else if (goblin_likabilty == 1) {
				power = (rand() % 20) + 10;		// (rand() % 20) + 10 makes range 10 - 30
				cout << "      The goblins hate you! (10 - 30 power)" << endl;
			}
			else if (goblin_likabilty == 2) {
				power = (rand() % 20) + 5;		// (rand() % 20) + 5 makes range 5 - 25
				cout << "      The goblins don't like you. (5 - 25 power)" << endl;
			}
			else if (goblin_likabilty == 3) {
				power = (rand() % 20) + 1;		// (rand() % 20) + 1 makes range 1 - 21
				cout << "      The goblins tolerate you. (1 - 21 power)" << endl;
			}
			else {
				power = (rand() % 10) + 1;		// (rand() % 10) + 1 makes range 1 - 11
				cout << "      The goblins kinda like you! (1 - 11 power)" << endl;
			}
		}
		Goblin* gob = new Goblin(gob_arr[i], power);
		while ((user->show_health() > 0)&&(gob->show_health() > 0)) {
			cout << "--------------------------------------" << endl;
			cout << user->show_name() << " (health): " << user->show_health() << " (power): " << user->show_power();
			cout << " (money): " << user->show_money() << endl << "VS." << endl;
			cout << "xx- " << gob->show_name() << " (health): " << gob->show_health() << " (power): " << gob->show_power();
			cout << " (money): " << gob->show_money() << " -xx" << endl;
			if (user->show_health() > 0) {	// user turn
				cout << "----------------" << endl;
				cout << "Your Turn!" << endl << "(1) - hit, (2) - shoot, (3) - give money, (4) - get money, (5) - heal" << endl;
				cin >> select;
				if (select == 1) {
					user->hit(*gob);
				}
				else if (select == 2) {
					user->shoot(*gob);
				}
				else if (select == 3) {
					cout << "(>= 50) - power decrease by 10" << endl << "(>= 25) - power decrease by 7" << endl;
					cout << "(>= 13) - power decrease by 5" << endl << "(Goblin power cannot go below 5 unless)" << endl;
					cout << "choose the amount of money to give: ";
					cin >> amount_given;
					if (user->show_money() >= amount_given) {
						user->give_money(*gob, amount_given);
					}
					else {
						cout << "You don't have enough money!" << endl;
					}
				}
				else if (select == 4) {
					gain_money(*user);
				}
				else if (select == 5) {
					heal(*user, *gob);
				}
				else {
					cout << "Invlaid selection. Turn skipped" << endl;
				}
				cout << "xx- " << gob->show_name() << " (health): " << gob->show_health() << " (power): " << gob->show_power();
				cout << " (money): " << gob->show_money() << " -xx" << endl;
			}
			else {
				break;
			}
			if ((gob->show_health() > 0)&&(gob->check_money() == 0)) {         // Goblin attacks
				cout << "----------------" << endl;
				cout << gob->show_name() << "'s Turn!" << endl;
				gob->hit(*user);
				cout << user->show_name() << " (health): " << user->show_health() << " (power): " << user->show_power();
				cout << " (money): " << user->show_money() << endl;
			}
			else {
				if (gob->check_money() == 1) {
					cout << "xxxxxxxxxxxxxxx" << endl << "You SPARED " << gob->show_name() << "!" << endl;
					delete gob;
					goblin_likabilty++;
				}
				else {
					cout << "xxxxxxxxxxxxxxx" << endl << "You KILLED " << gob->show_name()  << "!" << endl;
					delete gob;
				}
			}
		}
	}
	if (user->show_health() > 0) {
		cout << "xxxxxxxxxxxx" << endl << "x You Win! x" << endl << "xxxxxxxxxxxx" << endl;
	}
	else {
		cout << "xxxxxxxxxxxx" << endl << "x You Lose x" << endl << "xxxxxxxxxxxx" << endl;
	}

	return 0;
}