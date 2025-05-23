// GenericPlayer.h | Header | Chris Crisostomo | 04/07/2025
#pragma once
#include "Hand.h"
#include "Card.h"

class GenericPlayer : public Hand {
public:
	GenericPlayer();
	virtual ~GenericPlayer();
	virtual bool isHitting() const = 0;
	bool isBusted() const;
	bool bust() const;
	string getName() const;
	void setName(const string& name);

	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

private:
	string name;
};