#include "algorithms/bb.cpp"
#include "structures/Player.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char **argv){
    if(argc < 2){
        cerr << "Error\nUsage: bin/teams <input file>";
        exit(1);
    }

    ifstream input_file(argv[1]);

    if(input_file.is_open()){
        vector <Player> players;
        input_file >> players;

        auto teams = getTeams(players);

        for(auto player: teams.second){
            cout << player.id << ' ';
        }

    } else {
        cerr << "Error opening file" << endl;
        return 1;
    }

}