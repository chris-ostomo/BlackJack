// Hand.cpp | C++ | Chris Crisostomo | 04/07/2025
#include "Hand.h"

// call reverse() on cardVector and pass value of 7
Hand::Hand() {
	cardVector.reserve(7);
}

// deconstructor calls clearHand()
Hand::~Hand() {
	clearHand();
}

// call push_back() on cardVector and pass cardPtr
void Hand::add(Card* cardPtr) {
	cardVector.push_back(cardPtr);
}

void Hand::clearHand() {
// declare iterator of vector<Card*>
	vector<Card*>::iterator iter;

// delete each *iter
	for (iter = cardVector.begin(); iter != cardVector.end(); iter++) {
		delete* iter;
		*iter = NULL; // Good practice
	}
	cardVector.clear(); // call clear() on cardVector
}

int Hand::getTotal() const {
	// if cardVector is empty or the value of the first card is 0
	if (cardVector.empty() || cardVector[0]->getValue() == 0) {
		return 0;
	}
	
	// base values
	int total = 0;
	bool containsAce = false;

	// create const_iterator to add up card values
	vector<Card*>::const_iterator iter;

	// loop thru vector
	for (iter = cardVector.begin(); iter != cardVector.end(); iter++) {
		total = total + (*iter)->getValue(); // calc total of all cards

		// if card is ace, set bool to true
		if ((*iter)->getValue() == Card::ACE) {
			containsAce = true;
		}
	}

	// add 10 to 1 since ace value = 1
	if (containsAce && total <= 11) {
		total = total + 10;
	}

	return total;
}