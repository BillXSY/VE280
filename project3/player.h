#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "hand.h"


class Player {
    // A virtual base class, providing the player interface
protected:
    Team team;
    int ID;
    string name;
 public:
    virtual int bet(unsigned int bankroll,
                    unsigned int minimum) = 0; 
    // REQUIRES: bankroll >= minimum
    // EFFECTS: returns the player's bet, between minimum and bankroll 
    // inclusive

    virtual bool draw(Card dealer,             // Dealer's "up card"
                      const Hand &player) = 0; // Player's current hand
    // EFFECTS: returns true if the player wishes to be dealt another
    // card, false otherwise.

    virtual void expose(Card c) = 0;
    // EFFECTS: allows the player to "see" the newly-exposed card c.
    // For example, each card that is dealt "face up" is expose()d.
    // Likewise, if the dealer must show his "hole card", it is also
    // expose()d.  Note: not all cards dealt are expose()d---if the
    // player goes over 21 or is dealt a natural 21, the dealer need
    // not expose his hole card.

    virtual void shuffled() = 0;
    // EFFECTS: tells the player that the deck has been re-shuffled.

    virtual string getName();
    // EFFECTS: get the name of the player.

    virtual int getID();
    // EFFECTS: get the ID of the player.

    virtual Team getTeam();
    // EFFECTS: get the team of the player.

    virtual void setPlayer(Team tm, int id);
    // EFFECTS: set a member's name, ID and team
    // MODIFIES: name, ID, team

    virtual ~Player() { }
    // Note: this is here only to suppress a compiler warning.
    //       Destructors are not needed for this project.
};

extern Player *get_Player();
// EFFECTS: get a pointer to a player

#endif /* __PLAYER_H__ */
