#include "structures/Player.h"
#include "util.cpp"

#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>
#include <vector>
#include <stack>

using namespace std;


vector<Player> getTeam(vector<Player> players){
    vector<Player> currentSolution, bestSolution;
    stack<int> currentRefs;
    int bestDiff = getTeamScore(players);
    int goalScore = bestDiff / 2, bestScore = 0, currentScore = 0;
    int lastId = players.back().id;

    for (auto player: players) {
        currentRefs.push(player.id);
        currentSolution.push_back(player);
        currentScore = player.score;
        while(!currentRefs.empty()){

            if (currentScore == goalScore){
                return currentSolution;
            } else if (abs(goalScore - currentScore) < abs(goalScore - bestScore)){
                bestSolution = currentSolution;
                bestScore = currentScore;
            }

            int currentPlayerId = currentSolution.back().id;

            if (currentPlayerId != lastId && currentScore < goalScore) {
                Player playerToAdd = players[currentPlayerId + 1];
                currentSolution.push_back(playerToAdd);
                currentRefs.push(playerToAdd.id);
                currentScore += playerToAdd.score;
            } else {
                int lastIdTried = lastId;
                do {
                    lastIdTried = currentRefs.top();
                    currentScore -= currentSolution.back().score;
                    currentSolution.pop_back();
                    currentRefs.pop();
                } while(lastIdTried == lastId && !currentRefs.empty());
                
                if (currentRefs.empty()) break;

                Player playerToAdd = players[lastIdTried + 1];
                currentSolution.push_back(playerToAdd);
                currentRefs.push(playerToAdd.id);
                currentScore += playerToAdd.score;
            }


        }


    }


    return bestSolution;
}