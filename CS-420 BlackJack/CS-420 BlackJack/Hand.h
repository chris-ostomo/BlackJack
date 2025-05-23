// Player.h | Header | Chris Crisostomo | 04/07/2025
#pragma once
#include <vector>
#include "Card.h"

class Hand {
public:
	Hand();
	virtual ~Hand();

	void add(Card* cardPtr);
	void clearHand();
	int getTotal() const;

protected:
	vector<Card*> cardVector;
};