// Game.h | c++ | Chris Crisostomo | 04/07/2025
#include "Game.h"

// constructor
Game::Game(const string& name) {
	player.setName(name);
	deck.populate();
	deck.shuffle();
}

// deconstructor
Game::~Game() {}

// play function
void Game::play() {
	// deals 2 cards to each player
	for (int i = 0; i < 2; i++) {
		deck.deal(player);
		deck.deal(house);
	}

	// flip first card of dealer
	house.flipFirstCard();

	// display hands
	cout << player << endl;
	cout << house << endl;

	// player's turn
	deck.additionalCards(player);

	// if player busts, display lose, flip dealer first card, and clear all hands
	if (player.isBusted()) {
		house.flipFirstCard();
		cout << house << endl;
		player.lose();
		player.clearHand();
		house.clearHand();
		return;
	}

	// flip first dealer card, display dealer hand, and deal additional cards to dealer
	house.flipFirstCard();
	cout << house << endl;
	deck.additionalCards(house);

	// if house busts
	if (house.isBusted()) {
		if (!player.isBusted()) {
			player.win(); // player wins if not busted
		}
	}
	else {
		if (!player.isBusted()) {
			if (player.getTotal() > house.getTotal()) {
				player.win(); // player wins if total is more than dealer
			}
			else if (player.getTotal() < house.getTotal()) {
				player.lose(); // player loses if total is less than dealer
			}
			else player.push(); // all other scenarios push
		}
	}

	// clear all hands
	player.clearHand();
	house.clearHand();
}