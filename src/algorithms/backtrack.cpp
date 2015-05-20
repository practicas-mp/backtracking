#include "structures/Player.h"
#include "util.cpp"
#include <utility>
#include <vector>
#include <stack>

using namespace std;

pair< vector<Player>, vector<Player> >getTeams(vector<Player> players){
    vector<Player> currentSolution;
    int goalScore = getTeamScore(players) / 2;
    int currentScore = 0;
    int lastId = players.back().id;

    for(auto player : players) {

        currentSolution.push_back(player);

        while (currentSolution.empty() == false) {

            int currentPlayerId = currentSolution.back().id;

            if (currentPlayerId != lastId){
                Player playerToAdd = players[currentPlayerId + 1];
                currentSolution.push_back(playerToAdd);
                currentScore += playerToAdd.weight;

            } else {
                int lastTriedId = lastId;

                while (lastTriedId == lastId && currentSolution.size() > 1) {
                    currentSolution.pop_back();
                    lastTriedId = currentSolution.back().id;
                }
                currentSolution.pop_back();
                
                if (currentSolution.empty()) break;

                currentSolution.push_back(players[lastTriedId + 1]);
                currentScore += players[lastTriedId + 1].weight;
            }

            if (currentScore == goalScore){
                return make_pair(currentSolution, currentSolution);
            }

        }
    }

}


/*pair <vector <Player>, vector <Player> > getTeams(vector <Player> players){
    vector<vector <Player> > teams = powerset(players);
    int size = teams.size() / 2, total_score = getTeamScore(players),
        curr_diff, curr_best_index = 0,
        curr_best_diff = total_score - 2 * getTeamScore(teams[0]);

    for(int i = 1; i < size; ++i){
        curr_diff = total_score - 2 * getTeamScore(teams[i]);

        if(curr_diff == 0){
            return make_pair(teams[i], teams[teams.size() - i - 2]) ;
        } else if(curr_diff < curr_best_diff){
            curr_diff = curr_best_diff;
            curr_best_index = i;
        }
    }

    return make_pair(teams[curr_best_index], teams[teams.size() - curr_best_index - 1]);
}*/
