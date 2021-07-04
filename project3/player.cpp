//
// Created by 71401 on 2021/7/3.
//
#include <iostream>
#include "player.h"

int Player::getID() {
    return ID;
}

string Player::getName() {
    return name;
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
/*    virtual string getName();
//    // EFFECTS: get the name of the player.
//
//    virtual int getID();
//    // EFFECTS: get the ID of the player.
//
//    virtual Team getTeam();
//    // EFFECTS: get the team of the player.
//
//    virtual void setPlayer(Team tm, int id);*/
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



