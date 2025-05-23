// Card.h | Header | Chris Crisostomo | 04/07/2025
#pragma once
#include <iostream>
using namespace std;

class Card {
public:
	enum RANK {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum SUIT {CLUBS, DIAMONDS, HEARTS, SPADES};

	Card(RANK r = ACE, SUIT s = SPADES, bool isUp = true);

	int getValue() const;
	void flip();

	friend ostream& operator<<(ostream& os, const Card& aCard);

protected:
	RANK rank;
	SUIT suit;

private:
	bool isFaceUp;
};