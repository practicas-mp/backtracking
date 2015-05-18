#include "structures/player.h"
#include <vector>
#include <cassert>
#include <set>
#include <stack>



int sumWeights(const set<Player> &players){
	int result = 0;
	for(auto player : players){
		result += player.weight;
	}

	return result;
}

int sumWeights(const vector<Player> &players){
	int result = 0;
	for(auto player : players){
		result += player.weight;
	}

	return result;
}

set<Player> divideTeams(const vector<Player> &players) {
	set<Player> optimal_result;
	int optimal_difference = sumWeights(players) - 0;



}