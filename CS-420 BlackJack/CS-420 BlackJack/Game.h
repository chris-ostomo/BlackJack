// Game.h | Header | Chris Crisostomo | 04/07/2025
#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game {
public:
	Game(const string& name);
	~Game();

	void play();
	
private:
	Deck deck;
	House house;
	Player player;
};