#include "player.h"
#include <iostream>

string Player::getName() {
    return name;
}

int Player::getID() {
    return ID;
}
// EFFECTS: get the ID of the player.

Team Player::getTeam() {
    return team;
}
// EFFECTS: get the team of the player.

void Player::setPlayer(Team tm, int id) {
    team = tm;
    ID = id;
}
// EFFECTS: set a member's name, ID and team
// MODIFIES: name, ID, team

class SimplePlayer : public Player {
public:
    int bet(unsigned int bankroll, unsigned int minimum);

    bool draw(Card dealer, const Hand &player);

    void expose(Card c);

    void shuffled();

    string getName();

    int getID();

    Team getTeam();

    void setPlayer(Team tm, int id);

    ~SimplePlayer() {}
};

int SimplePlayer::bet(unsigned int bankroll, unsigned int minimum) {
    if (team == 0 && ID == 1) {
        return (int) (2 * minimum);
    } else {
        return (int) minimum;
    }
}

bool SimplePlayer::draw(Card dealer, const Hand &player) {
    bool hit = false;
    if (!player.handValue().soft) {
        if (player.handValue().count <= 11) {
            hit = true;
        } else if (player.handValue().count == 12) {
            if (dealer.spot == 4 || dealer.spot == 5 || dealer.spot == 6) {
                hit = false;
            } else {
                hit = true;
            }
        } else if (player.handValue().count >= 13 && player.handValue().count <= 16) {
            if (dealer.spot >= 2 && dealer.spot <= 6) {
                hit = false;
            } else {
                hit = true;
            }
        } else {
            hit = false;
        }
    }

    if (player.handValue().soft) {
        if (player.handValue().count <= 17) {
            hit = true;
        } else if (player.handValue().count == 18) {
            if (dealer.spot == 2 || dealer.spot == 7 || dealer.spot == 8) {
                hit = false;
            } else {
                hit = true;
            }
        } else {
            hit = false;
        }
    }
    return hit;
}

void SimplePlayer::expose(Card c) {}

void SimplePlayer::shuffled() {}

void SimplePlayer::setPlayer(Team tm, int id) {
    this->team = tm;
    this->ID = id;
    if (this->team == 0) {
        if (id == 1) {
            name = "Suzumiya Haruhi";
        } else if (id == 4) {
            name = "Kyon";
        } else if (id == 5) {
            name = "Koizumi Itzuki";
        }
    } else if (this->team == 1) {
        if (id == 3) {
            name = "Jean Pierre Polnareff";
        } else if (id == 5) {
            name = "Mohammed Avdol";
        }
    }
}

string SimplePlayer::getName() {
    return name;
}

int SimplePlayer::getID() {
    return ID;
}

Team SimplePlayer::getTeam() {
    return team;
}

// -----------------------------------------------------------------------------------------------//

class CountingPlayer : public Player {
    int count;
public:
    int bet(unsigned int bankroll, unsigned int minimum);

    bool draw(Card dealer, const Hand &player);

    void expose(Card c);

    void shuffled();

    string getName();

    int getID();

    Team getTeam();

    void setPlayer(Team tm, int id);

    ~CountingPlayer() {}
};

bool CountingPlayer::draw(Card dealer, const Hand &player) {
    return false;
}

int CountingPlayer::bet(unsigned int bankroll, unsigned int minimum) {
    if (this->team == 0 && ID == 3) {
        if (count < (-2) && bankroll > (int) minimum) {
            return (int) (2 * minimum);
        } else {
            return (int) minimum;
        }
    } else if (this->team == 1 && ID == 4) {
        if (count >= 4 && bankroll > (int) minimum) {
            return (int) (2 * minimum);
        } else {
            return (int) minimum;
        }
    } else {
        if ((count >= 2) && (bankroll >= (int) (2 * minimum))) {
            return (int) (2 * minimum);
        } else {
            return (int) minimum;
        }
    }
}

void CountingPlayer::shuffled() {
    count = 0;
}

void CountingPlayer::expose(Card c) {
    if (c.spot >= 8 && c.spot <= 12) {
        count--;
    } else if (c.spot <= 4) {
        count++;
    }
}

void CountingPlayer::setPlayer(Team tm, int id) {
    this->team = tm;
    this->ID = id;
    if (this->team == 0) {
        if (id == 2) {
            name = "Nagato Yuki";
        } else if (id == 3) {
            name = "Asahina Mikuru";
        } else if (id == 5) {
            name = "Koizumi Itzuki";
        }
    } else if (this->team == 1) {
        if (id == 1) {
            name = "Joseph Joestar";
        } else if (id == 2) {
            name = "Kujo Jotaro";
        } else if (id == 4) {
            name = "Kakyoin Noriaki";
        } else if (id == 5) {
            name = "Mohammed Avdol";
        }
    }
}

string CountingPlayer::getName() {
    return this->name;
}

int CountingPlayer::getID() {
    return this->ID;
}

Team CountingPlayer::getTeam() {
    return team;
}


Player *get_Player(string &dealerSide, string &playerType, int &ID) {
    if (dealerSide == "sos") {
        if (ID == 1) {
            CountingPlayer *countplayer = new CountingPlayer;
            countplayer->setPlayer(Team(1), 1);
            return countplayer;
        } else if (ID == 2) {
            CountingPlayer *countplayer = new CountingPlayer;
            countplayer->setPlayer(Team(1), 2);
            return countplayer;
        } else if (ID == 3) {
            SimplePlayer *simplayer = new SimplePlayer;
            simplayer->setPlayer(Team(1), 3);
            return simplayer;
        } else if (ID == 4) {
            CountingPlayer *countplayer = new CountingPlayer;
            countplayer->setPlayer(Team(1), 4);
            return countplayer;
        } else {//if (ID==5)
            if (playerType == "simple") {
                SimplePlayer *simplayer = new SimplePlayer;
                simplayer->setPlayer(Team(1), 5);
                return simplayer;
            } else {//if (playerType=="counting")
                CountingPlayer *countplayer = new CountingPlayer;
                countplayer->setPlayer(Team(1), 5);
                return countplayer;
            }
        }
    } else if (dealerSide == "sc") {
        if (ID == 1) {
            SimplePlayer *simplayer = new SimplePlayer;
            simplayer->setPlayer(Team(0), 1);
            return simplayer;
        } else if (ID == 2) {
            CountingPlayer *countplayer = new CountingPlayer;
            countplayer->setPlayer(Team(0), 2);
            return countplayer;
        } else if (ID == 3) {
            CountingPlayer *countplayer = new CountingPlayer;
            countplayer->setPlayer(Team(0), 3);
            return countplayer;
        } else if (ID == 4) {
            SimplePlayer *simplayer = new SimplePlayer;
            simplayer->setPlayer(Team(0), 4);
            return simplayer;
        } else {
            if (playerType == "simple") {
                SimplePlayer *simplayer = new SimplePlayer;
                simplayer->setPlayer(Team(0), 5);
                return simplayer;
            } else {
                CountingPlayer *countplayer = new CountingPlayer;
                countplayer->setPlayer(Team(0), 5);
                return countplayer;
            }
        }
    } else {
        return nullptr;
    }
}

