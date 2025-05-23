// House.h | Header | Chris Crisostomo | 04/07/2025
#pragma once
#include "GenericPlayer.h"

class House : public GenericPlayer {
public:
	House(const string& name = "Dealer");
	virtual ~House();
	virtual bool isHitting() const;
	void flipFirstCard();
};