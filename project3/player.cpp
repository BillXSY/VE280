//
// Created by 71401 on 2021/7/3.
//
#include <iostream>
#include "player.h"

string Player::getName() {
    return name;
}

int Player::getID() {
    return ID;
}


Team Player::getTeam() {
    return team;
}

void Player::setPlayer(Team tm, int id) {
    team = tm;
    ID = id;
}

class SimplePlayer : Player {
public:
    SimplePlayer() {};

    int bet(unsigned int bankroll, unsigned int minimum) override;

    bool draw(Card dealer, const Hand &player) override; // Player's current hand

    virtual void expose(Card c);

    virtual void shuffled();
};

int SimplePlayer::bet(unsigned int bankroll, unsigned int minimum) {
    return int(minimum);
}

bool SimplePlayer::draw(Card dealer, const Hand &player) {
    int hand_count = player.handValue().count;
    bool isSoft = player.handValue().soft;

    if (!isSoft && hand_count < 12) {
        return true;
    } else if (!isSoft && hand_count == 12) {
        if (dealer.spot >= 2 & dealer.spot <= 4) {
            return false;
        }
        return true;
    } else if (!isSoft && hand_count >= 13 && hand_count <= 16) {
        if (dealer.spot >= 0 & dealer.spot <= 4) {
            return false;
        }
        return true;
    } else if (!isSoft && hand_count >= 17) {
        return false;
    } else if (isSoft && hand_count <= 17) {
        return true;
    } else if (isSoft && hand_count == 18) {
        if (dealer.spot == 0 || dealer.spot == 5 || dealer.spot == 6) {
            return false;
        }
        return true;
    } else if (isSoft && hand_count >= 19) {
        return false;
    }
    return false;
}

void SimplePlayer::expose(Card c) {}

void SimplePlayer::shuffled() {}

class CountingPlayer : SimplePlayer {
private:
    int count;
public:
    CountingPlayer();

    int bet(unsigned int bankroll, unsigned int minimum);

    void expose(Card c);

    void shuffled();
};

CountingPlayer::CountingPlayer() {
    count = 0;
}

int CountingPlayer::bet(unsigned int bankroll, unsigned int minimum) {
    if (count >= 2 && bankroll >= 2 * minimum) {
        return int(2 * minimum);
    }
    return minimum;
}


void CountingPlayer::expose(Card c) {
    if (c.spot <= 4) {
        count++;
    } else if (c.spot >= 8) {
        count--;
    }
}

void CountingPlayer::shuffled() {
    count = 0;
}



