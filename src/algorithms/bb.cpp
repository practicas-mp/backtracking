#include "structures/Player.h"
#include "util.cpp"

#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

using namespace std;


template <class T> vector <T> difference(vector <T> total, vector <T> partial){
    vector <T> diff;
    diff.reserve(total.size() - partial.size());
    vector <T>::iterator first = partial.begin(), last = partial.end();

    for(auto candidate: total){
        if(find(first, last, candidate) == last){
            diff.push_back(candidate);
        }
    }

    return diff;
}


pair <vector <Player>, vector <Player> > getTeams(vector <Player> players){
    int size = players.size(), level = 0,
        total_score = getTeamScore(players),
        curr_best_diff = total_score;
        curr_score = 0, curr_diff;

    vector <Player> curr_solution, curr_best_solution;
    curr_solution.reserve(players.size());
    stack <int> ref;
    ref.push(-1);

    while(level > -1){  // TODO: revise diffs stuff
        if(level <= size or curr_score > total_score / 2){
            curr_diff = abs(curr_best_diff - 2 * players[level].score);
            curr_score += players[level].score

            if(curr_diff < curr_best_diff){
                curr_solution.push_back(players[level]);

                if(curr_diff == 0){
                    return curr_solution;
                } else {
                    curr_best_solution = curr_solution;
                }
            }

            ref.push(level + 1);
            ++level;
        } else {
            level = ref.pop();
            curr_score -= curr_solution.pop_back().score;
        }
    }

    return make_pair(curr_best_solution, difference(players, curr_best_solution));
}
