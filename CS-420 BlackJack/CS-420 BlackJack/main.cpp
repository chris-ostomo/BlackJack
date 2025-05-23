// main.cpp | c++ | Chris Crisostomo | 04/07/2025
// A Program of Blackjack where dealer stays on soft 17!
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	// displays welcome message
	cout << "Welcome to the Crisostomo Casino! We only offer Blackjack."
		<< endl;

	char again = 'y';
	string name;

	// asks for name
	cout << "What is your name? ";
	getline(cin, name);

	// create game object
	Game HighRollers(name);

	// sentinel controlled loop for game repetition
	while (again == 'y' || again == 'Y') {
		HighRollers.play();

		cout << "\nPlay again? (y/n): ";
		cin >> again;
		cin.ignore();
	}

	// goodbye message
	cout << "Come again soon, " << name << "!" << endl;
	return 0;
}