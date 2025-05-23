// House.h | c++ | Chris Crisostomo | 04/07/2025
#include "House.h"

// constructor
House::House(const string& name) : GenericPlayer() {
	setName(name);
}

// deconstructor
House::~House() {}

// returns true if dealer has <=16
bool House::isHitting() const {
	return getTotal() <= 16;
}

// flips over the first card in hand
void House::flipFirstCard() {
	if (!cardVector.empty()) {
		cardVector[0]->flip();
	}
	else {
		cout << "Ther are no cards to flip." << endl;
	}
}