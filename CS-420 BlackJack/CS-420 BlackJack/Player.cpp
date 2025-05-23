// Player.h | c++ | Chris Crisostomo | 04/07/2025
#include "Player.h"

// constructor
Player::Player(const string& name) : GenericPlayer() {
	setName(name);
}

// deconstructor
Player::~Player() {}

// indicates whether the player wants to hit or stay
bool Player::isHitting() const {
	cout << getName() << ", hit or stay? (H/S): ";
	char response;
	cin >> response;
	return (response == 'h' || response == 'H');
}

// win message display
bool Player::win() const {
	cout << getName() << " wins." << endl;
	return true;
}

// lose message display
bool Player::lose() const {
	cout << getName() << " loses." << endl;
	return true;
}

// push message display
bool Player::push() const {
	cout << getName() << " pushes." << endl;
	return true;
}