#include "structures/Player.h"
#include <math.h>
#include <vector>

using namespace std;


template <class T> vector <vector <T> > powerset(vector <T> set){
    int size = set.size();
    int total = pow(2, size);
    vector <vector <T> > solution;
    vector <T> curr;

    for(int i = 1; i < total; ++i){  // don't return empty set
        for(int j = 0; j < size; ++j){
            if(i >> j & 1){
                curr.push_back(set[j]);
            }
        }

        solution.push_back(curr);
        curr.clear();
    }

    return solution;
}


int getTeamScore(vector <Player> players){
    int total = 0;

    for(auto p: players){
        total += p.score;
    }

    return total;
}
