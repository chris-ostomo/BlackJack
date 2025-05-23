// Deck.h | Header | Chris Crisostomo | 04/07/2025
#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand {
public:
	Deck();
	virtual ~Deck();
	void populate();
	void shuffle();
	void deal(Hand& aHand);
	void additionalCards(GenericPlayer& aGenericPlayer);
};