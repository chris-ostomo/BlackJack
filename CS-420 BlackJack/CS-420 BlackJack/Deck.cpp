// Deck.h | c++ | Chris Crisostomo | 04/07/2025
#include "Deck.h"
#include <algorithm>
#include <random>

// constructor
Deck::Deck() {
	cardVector.reserve(52);
	populate();
}

// deconstructor
Deck::~Deck() {};

// populate a standard deck of cards
void Deck::populate() {
	clearHand();
	// outer for loop creates cards of 4 suits
	for (int s = Card::CLUBS; s <= Card::SPADES; s++) {
		// inner loop creates cards ACE - KING for each suit 
		for (int r = Card::ACE; r <= Card::KING; r++) {
			// adds new cards to deck
			add(new Card(static_cast<Card::RANK>(r), static_cast<Card::SUIT> (s)));
		}
	}
}

// shuffles deck of cards
// UPDATE: used random_device and mt19937 for new seed in first iteration
void Deck::shuffle() {
	random_device rd;
	mt19937 g(rd());
	std::shuffle(cardVector.begin(), cardVector.end(), g);
}

// deals one card to hand
void Deck::deal(Hand& aHand) {
	if (!cardVector.empty()) {
		aHand.add(cardVector.back());
		cardVector.pop_back();
	}
	else {
		cout << "The deck is out of cards. Unable to deal." << endl;
	}
}

// gives additional cards to any player
void Deck::additionalCards(GenericPlayer& aGenericPlayer) {
	while (!aGenericPlayer.isBusted() && aGenericPlayer.isHitting()) {
		deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		
		// if generic player busts, call bust()
		if (aGenericPlayer.isBusted()) {
			aGenericPlayer.bust();
		}
	}
}