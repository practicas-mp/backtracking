#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <vector>

using namespace std;


struct Player {
    int id;     // we need some kind of identifier
    int score;

    Player();

    Player(int score);

    void autoID();

    bool operator==(const Player &other){ return this->id == other.id; }

    friend istream& operator>>(istream &is, Player &player);

    friend istream& operator>>(istream &is, vector <Player> &players);

    private:
        static int uid;

};

#endif