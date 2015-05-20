#ifndef __PLAYER_H__
#define __PLAYER_H__


struct Player {
    int id;     // we need some kind of identifier
    int score;

    Player();

    Player(int id, int score);

    void autoID();

    inline bool operator<(const Player &other) const { return id < other.id; }

    inline bool operator==(const Player &other) const { return id == other.id; }

    private:
        static int uid;

};

#endif