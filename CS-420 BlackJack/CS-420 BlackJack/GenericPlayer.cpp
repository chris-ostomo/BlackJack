// GenericPlayer.h | c++ | Chris Crisostomo | 04/07/2025
#include "GenericPlayer.h"

// constructor using member initalizer
GenericPlayer::GenericPlayer() : name("") {}

// deconstructor
GenericPlayer::~GenericPlayer() {}

// busts if total is greater than 21
bool GenericPlayer::isBusted() const {
	if (getTotal() > 21) {
		return true;
	}
	else {
		return false;
	}
}

// displays bust for player
bool GenericPlayer::bust() const {
	cout << getName() << " busts." << endl;
	return true;
}

// getter for name
string GenericPlayer::getName() const {
	return name;
}

// setter for name
void GenericPlayer::setName(const string& name) {
	this->name = name;
}

// overloaded << operator
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
	// store name followed by tab space
	os << aGenericPlayer.getName() << "\t";

	// see if cardVector is empty
	if (!aGenericPlayer.cardVector.empty()) {
		// loop thru all cards for player if not empty
		for (int i = 0; i < static_cast<int>(aGenericPlayer.cardVector.size()); ++i) {
			os << *(aGenericPlayer.cardVector[i]) << "\t";
		}

		int total = aGenericPlayer.getTotal();
		// if total is not 0 then append total
		if (total != 0) {
			os << "(" << total << ")";
		}
	}
	// append empty
	else {
		os << "<empty>";
	}
	return os;
}