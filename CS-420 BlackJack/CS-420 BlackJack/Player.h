// Player.h | Header | Chris Crisostomo | 04/07/2025
#pragma once
#include "GenericPlayer.h"

class Player : public GenericPlayer {
public:
	Player(const string& name = " ");
	virtual ~Player();
	virtual bool isHitting() const;
	bool win() const;
	bool lose() const;
	bool push() const;
};