#include "structures/Player.h"
#include "util.cpp"

#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>
#include <vector>

using namespace std;


vector <Player> getTeam(vector <Player> players){
    int size = players.size(), level = 0,
        total_score = getTeamScore(players),
        curr_best_diff = total_score,
        curr_score = 0, curr_diff = total_score, new_diff;

    vector <Player> curr_solution, curr_best_solution;
    curr_solution.reserve(players.size());
    stack <int> ref;
    ref.push(-1);

    while(level > -1){  // TODO: revise diffs stuff
        assert(level == size or level == players[level].id or level == -1);

        if(level < size and curr_score <= total_score / 2){
            new_diff = curr_diff - 2 * players[level].score;

            if(abs(new_diff) < abs(curr_diff)){
                curr_solution.push_back(players[level]);
                curr_diff = new_diff;
                curr_score += players[level].score;
                
                if(abs(curr_diff) < curr_best_diff){
                    curr_best_diff = abs(curr_diff);
                    curr_best_solution = curr_solution;
                }

                if(curr_diff == 0){
                    break;
                }

                ref.push(level + 1);
            }
            
            ++level;
        } else {
            curr_diff += 2 * players[level - 1].score;
            curr_score -= players[level - 1].score;
            
            if(not curr_solution.empty()){
                curr_solution.pop_back();
            }

            level = ref.top();
            ref.pop();
        }
    }

    return curr_best_solution;
}
