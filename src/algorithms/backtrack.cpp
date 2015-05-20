#include "structures/Player.h"
#include "util.cpp"
#include <utility>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<Player> getTeams(vector<Player> players){
    vector<Player> currentSolution;
    vector<Player> bestSolution = players;
    int goalScore = getTeamScore(players) / 2;
    int bestScore = goalScore * 4;
    int lastId = players.back().id;


    int currentScore = players[0].score;
    currentSolution.push_back(players[0]);

    while (currentSolution.empty() == false) {

        if (currentScore == goalScore){
            return currentSolution;
        } else if (abs(goalScore - currentScore) < abs(goalScore - bestScore) ){
            bestSolution = currentSolution;
            bestScore = currentScore;
        }

        int currentPlayerId = currentSolution.back().id;

        if (currentPlayerId != lastId){
            Player playerToAdd = players[currentPlayerId + 1];
            currentSolution.push_back(playerToAdd);
        } else {
            int lastTriedId = lastId;

            while (lastTriedId == lastId && currentSolution.size() > 1) {
                currentSolution.pop_back();
                currentScore -= players[lastTriedId].score;
                lastTriedId = currentSolution.back().id;
            }
            currentScore -= players[lastTriedId].score;
            currentSolution.pop_back();
            
            if (currentSolution.empty()) continue;

            currentSolution.push_back(players[lastTriedId + 1]);
        }

        currentScore += currentSolution.back().score;
    }

    return bestSolution;

}

