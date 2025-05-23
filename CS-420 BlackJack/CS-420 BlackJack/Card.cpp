// Card.cpp | C++ | Chris Crisostomo | 04/07/2025
#include "Card.h"

// constructor
Card::Card(RANK r, SUIT s, bool isUp) 
	: rank(r), suit(s), isFaceUp(isUp) {}

// return value of card if face up
int Card::getValue() const {
	if (!isFaceUp) {
		return 0;
	}

	if (rank == JACK || rank == QUEEN || rank == KING) {
		return 10;
	}

	return rank;
}

// flips a card
void Card::flip() {
	isFaceUp = !isFaceUp;
}

// overloaded << operator 
ostream& operator<<(ostream& os, const Card& aCard) {
	// constant string array for ranks
	static const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "J", "Q", "K" };

	// const string array for suits
	static const string SUITS[] = { "C", "D", "H", "S" };

	// store rank and suit if card is facing up
	if (aCard.isFaceUp) {
		os << RANKS[aCard.rank] << SUITS[aCard.suit];
	}
	// if not facing up, card displays XX
	else {
		os << "XX";
	}
	return os;
}