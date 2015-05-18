#ifndef __PLAYER_H__
#define __PLAYER_H__

struct Player {
	int id; 	// we need some kind of identifier
	int weight;

	Player();

	Player(int id, int weight);

	inline bool operator<(const Player &other) const { return id < other.id; }

	inline bool operator==(const Player &other) const { return id == other.id; }
};



#include "player.cpp"

#endif