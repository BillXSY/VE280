#ifndef __CARD_H__
#define __CARD_H__

#include <string>

using namespace std;

enum Suit {
    SPADES, HEARTS, CLUBS, DIAMONDS
};

enum Spot {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
};

enum Team {
    SOSBrigade, StardustCrusaders
};

extern const string SuitNames[DIAMONDS + 1]; //size = 4
extern const string SpotNames[ACE + 1]; //size = 13
extern const string SOS_Name[5];
extern const string SC_Name[5];

struct Card {
    Spot spot;//点数
    Suit suit;//花色
};

// void displayCard(Card card);
// MODIFIES: cout
// EFFECTS: display a card.

#endif /* __CARD_H__ */
