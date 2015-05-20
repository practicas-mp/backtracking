#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;


Player::Player(){
	this->id = -1;	// avoid debugging problems
	this->score = -1;
}


Player::Player(int score) : 
	score(score){
    this->autoID();
}

int Player::uid = 0;

void Player::autoID(){
    this->id = Player::uid++;
}


istream& operator>>(istream &is, Player &player){
    int score;

    is >> score;

    player.score = score;
    player.autoID();

    return is;
}


istream& operator>>(istream &is, vector <Player> &players){
    string foo;
    getline(is, foo);

    while(!is.eof()){
        Player player;
        is >> player;
        players.push_back(player);
    }

    return is;
}