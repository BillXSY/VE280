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
    this->team = tm;
    this->ID = id;
    if (tm == SOSBrigade) {
        this->name = SOS_Name[id - 1];
    } else {
        this->name = SC_Name[id - 1];
    }
}

class SimplePlayer : public Player {
public:
    SimplePlayer() {};

    int bet(unsigned int bankroll, unsigned int minimum) override;

    bool draw(Card dealer, const Hand &player) override; // Player's current hand

    virtual void expose(Card c);

    virtual void shuffled();
};

int SimplePlayer::bet(unsigned int bankroll, unsigned int minimum) {
    if (this->ID == 1 && this->team == 0) {// special case for Suzumiya Haruhi (SOS ID: 1)
        return int(2 * minimum);
    }
    return int(minimum);
}

bool SimplePlayer::draw(Card dealer, const Hand &player) {
    int hand_count = player.handValue().count;
    bool isSoft = player.handValue().soft;

    if (!isSoft && hand_count < 12) {
        return true;
    } else if (!isSoft && hand_count == 12) {
        if (dealer.spot >= 2 && dealer.spot <= 4) {
            return false;
        }
        return true;
    } else if (!isSoft && hand_count >= 13 && hand_count <= 16) {
        if (dealer.spot >= 0 && dealer.spot <= 4) {
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


// -----------------------------------------------------------------------------------------------//


class CountingPlayer : public SimplePlayer {
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
    if (this->ID == 3 && this->team == 0 && count <= -2 &&
        bankroll >= 2 * minimum) { // special case of Asahina Mikuru (SOS ID: 3)
        return int(2 * minimum);
    }
    if (this->ID == 4 && this->team == 1 && count >= 4 &&
        bankroll >= 2 * minimum) { // special case of Kakyoin Noriaki (SC ID: 4)
        return int(2 * minimum);
    }
    if (count >= 2 && bankroll >= 2 * minimum) {
        return int(2 * minimum);
    }
    return int(minimum);
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

/* EFFECTS: get a pointer to a player.

// "dealerSide" describes whether the dealer is from SOS Brigade or Stardust Crusade.
// This depends on the last program argument: [sos|sc].
// sc means the dealer team is Stardust Crusaders,
// sos means the dealer team is SOS Brigade.

// "playerType" describes whether Koizumi Itzuki and Mohammed Avdol are simple player or count player.
// This depends on the penultimate program argument: [simple|counting].

// If this argument is "simple", then Itzuki and Avdol are simple players.
// If this argument is "counting", then Itzuki and Avdol are countingplayers.

// "ID" is the player's ID.*/
extern Player *get_Player(string &dealerSide, string &playerType, int &ID) {
    if (dealerSide == "sc") { //initial players in SOS team
        switch (ID) {
            case 1: {// brave simple player
                SimplePlayer *Player = new SimplePlayer;
                Player->setPlayer(Team(0), 1);
                return Player;
            }
            case 2: { // normal counting player
                CountingPlayer *Player = new CountingPlayer;
                Player->setPlayer(Team(0), 2);
                return Player;
            }
            case 3: { // contrary counting player
                CountingPlayer *Player = new CountingPlayer;
                Player->setPlayer(Team(0), 3);
                return Player;
            }
            case 4: { // simple player
                SimplePlayer *Player = new SimplePlayer;
                Player->setPlayer(Team(0), 4);
                return Player;
            }
            case 5: {
                if (playerType == "simple") {
                    SimplePlayer *Player = new SimplePlayer;
                    Player->setPlayer(Team(0), 5);
                    return Player;
                } else if (playerType == "count") {
                    CountingPlayer *Player = new CountingPlayer;
                    Player->setPlayer(Team(0), 5);
                    return Player;
                }

            }
        }
    } else if (dealerSide == "sos") { // initial players in SC team
        switch (ID) {
            case 1: {// rich counting player
                CountingPlayer *Player = new CountingPlayer;
                Player->setPlayer(Team(1), 1);
                return Player;
            }
            case 2: { // counting player with special power
                CountingPlayer *Player = new CountingPlayer;
                Player->setPlayer(Team(1), 2);
                return Player;
            }
            case 3: { // normal somple player
                SimplePlayer *Player = new SimplePlayer;
                Player->setPlayer(Team(1), 3);
                return Player;
            }
            case 4: { // cautious count player
                CountingPlayer *Player = new CountingPlayer;
                Player->setPlayer(Team(1), 4);
                return Player;
            }
            case 5: {
                if (playerType == "simple") {
                    SimplePlayer *Player = new SimplePlayer;
                    Player->setPlayer(Team(1), 5);
                    return Player;
                } else if (playerType == "count") {
                    CountingPlayer *Player = new CountingPlayer;
                    Player->setPlayer(Team(1), 5);
                    return Player;
                }

            }
        }
    }
    return nullptr;
}
