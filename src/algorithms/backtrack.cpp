#include "structures/Player.h"
#include "util.cpp"
#include <utility>
#include <vector>

using namespace std;


pair <vector <Player>, vector <Player> > getTeams(vector <Player> players){
    vector<vector <Player> > teams = powerset(players);
    int size = teams.size() / 2, total_score = getTeamScore(players),
        curr_diff, curr_best_index = 0,
        curr_best_diff = total_score - 2 * getTeamScore(teams[0]);

    for(int i = 1; i < size; ++i){
        curr_diff = total_score - 2 * getTeamScore(teams[i]);

        if(curr_diff == 0){
            return make_pair(teams[i], teams[teams.size() - i - 1]) ;
        } else if(curr_diff < curr_best_diff){
            curr_diff = curr_best_diff;
            curr_best_index = i;
        }
    }

    return make_pair(teams[curr_best_index], teams[teams.size() - curr_best_index - 1]);
}
