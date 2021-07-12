//
// Created by 71401 on 2021/7/4.
//

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

#include "rand.h"
#include "deck.h"
#include "hand.h"
#include "card.h"
#include "player.h"

using namespace std;

const int SHUFFLE_TIME = 7;

// MODIFIES: deck
// EFFECTS: shuffle the deck for 7 times
void deck_init(Deck *deck) {
    cout << "Shuffling the deck" << endl;
    for (int i = 0; i < SHUFFLE_TIME; ++i) {
        int cut = get_cut();
        cout << "cut at " << cut << endl;
        deck->shuffle(cut);
    }
}

// MODIFIES: deck
// EFFECTS: check if there are less than 20 cards in the deck
// shuffle if needed
void CheckDeck(Deck *deck, Player *player) {
    if (deck->cardsLeft() < 20) {
        deck_init(deck);
        player->shuffled();
    }
}

// MODIFIES: bankroll
// EFFECTS: check if N21
// calculate the bankroll if N21
bool CheckN21(Hand *hand_player, int *bankroll, int const *wager, const string &playerName) {
    if (hand_player->handValue().count == 21 && hand_player->handValue().soft) {
        *bankroll += *wager * 3 / 2;
        cout << "Player: " << playerName << " dealt natural 21" << endl;
        return true;
    }
    return false;
}

// MODIFIES: bankroll
// EFFECTS: check if player bust, and revise the bankroll accordingly
bool CheckPlayerBust(Hand *hand_player, int *bankroll, int const *wager, const string &playerName) {
    if (hand_player->handValue().count > 21) {
        *bankroll -= *wager;
        cout << "Player: " << playerName << " busts" << endl;
        return true;
    }
    return false;
}

// MODIFIES: bankroll
// EFFECTS: check if dealer bust, and revise the bankroll accordingly
bool CheckDealerBust(Hand *hand_dealer, int *bankroll, int const *wager, const string &dealerName) {
    if (hand_dealer->handValue().count > 21) {
        *bankroll += *wager;
        cout << "Dealer: " << dealerName << " busts" << endl;
        return true;
    }
    return false;
}

// MODIFIES: bankroll
// EFFECTS: check if JJ escapes due to bankroll decreasing
bool CheckJJ(const string &playerName, int currBR, int iniBR, int thisHand) {
    if (playerName == "Joseph Joestar" && currBR < iniBR / 2) {
        cout << "Player: " << playerName << " has " << currBR << " after " << thisHand << " hands " << endl;
        cout << "Player: Joseph Joestar: \"Ni Ge Run Da Yo\"" << endl;
        return true;
    }
    return false;
}

// MODIFIES: deck, hand_dealer
// EFFECTS: draw a new card for dealer, let player know if it's face-up
void deal_d(Deck *deck, Player *player, Card *card_d, Hand *hand_d, bool ifFaceUp, const string &NameD, int &CdCount) {

    if (deck->cardsLeft() == 0) {
        string s;
        throw s;
    }

    *card_d = deck->deal();
    hand_d->addCard(*card_d);
    CdCount++;

    while (NameD == "Kujo Jotaro" && hand_d->handValue().count > 21) {
        cout << "Dealer: Kujo Jotaro: \"Star Platinum, Za Warudo\"" << endl;
        hand_d->discardAll();
        for (int i = 0; i < CdCount; ++i) {
            if (deck->cardsLeft() == 0) {
                string s;
                throw s;
            }
            *card_d = deck->deal();
            hand_d->addCard(*card_d);
        }
    }

    if (ifFaceUp) {
        player->expose(*card_d);
        cout << "Dealer: " << NameD << " dealt " << SpotNames[card_d->spot] << " of "
             << SuitNames[card_d->suit] << endl;
    }
}

// MODIFIES: hand_player
// EFFECTS: draw a new face-up card for player
void deal_p(Deck *deck, Player *player, Card *card_player, Hand *hand_player, int &PlayerCardCount) {
    string playerName = player->getName();
    if (deck->cardsLeft() == 0) {
        string s;
        throw s;
    }

    *card_player = deck->deal();
    hand_player->addCard(*card_player);
    PlayerCardCount++;
    player->expose(*card_player);


    while (player->getName() == "Kujo Jotaro" && hand_player->handValue().count > 21) {
        cout << "Player: Kujo Jotaro: \"Star Platinum, Za Warudo\"" << endl;
        hand_player->discardAll();
        for (int i = 0; i < PlayerCardCount; ++i) {
            if (deck->cardsLeft() == 0) {
                string s;
                throw s;
            }
            *card_player = deck->deal();
            hand_player->addCard(*card_player);
            player->expose(*card_player);
        }

    }

    cout << "Player: " << playerName << " dealt " << SpotNames[card_player->spot] << " of "
         << SuitNames[card_player->suit] << endl;
}

// MODIFIES: bankroll
// EFFECTS: compare the total counts of player and dealer, and revise the bankroll accordingly
void compare(Hand *hand_d, Hand *hand_p, int *bankroll, int const *wager, const string &NameP, const string &NameD) {
    if (hand_p->handValue().count > hand_d->handValue().count) {
        cout << "Player: " << NameP << " wins this hand" << endl;
        *bankroll += *wager;
    } else if (hand_p->handValue().count < hand_d->handValue().count) {
        cout << "Dealer: " << NameD << " wins this hand" << endl;
        *bankroll -= *wager;
    } else {
        cout << "Push\n";
    }
}

int main(int argc, char const *argv[]) {
//    Players initialization
    string player_type = argv[3];
    string dealerSide = argv[4];
    int ID[] = {1, 2, 3, 4, 5};
    Player *Players[5] = {get_Player(dealerSide, player_type, ID[0]), get_Player(dealerSide, player_type, ID[1]),
                          get_Player(dealerSide, player_type, ID[2]), get_Player(dealerSide, player_type, ID[3]),
                          get_Player(dealerSide, player_type, ID[4])};

//    Dealers initialization
    string Dealers[5];
    if (dealerSide == "sos") {
        for (int i = 0; i < 5; ++i) {
            Dealers[i] = SOS_Name[i];
        }
    } else {
        for (int i = 0; i < 5; ++i) {
            Dealers[i] = SC_Name[i];
        }
    }

    Hand *hand_player = new Hand;
    Hand *hand_dealer = new Hand;
    Card *card_player = new Card;
    Card *card_dealer = new Card;
    Card *card_dealer2 = new Card;
    Deck *deck = new Deck;

    int thisHand = 0;
    int minBet = 5;

    int currPlayer = 0;
    int currDealer = 0;

    int bankroll = stoi(argv[1]);
    int max_hands = stoi(argv[2]);
    bool doubledJJBK = false;

    // round
    while (currPlayer < 5 && currDealer < 5) {
        deck_init(deck);
        Players[currPlayer]->shuffled();

        string playerName = Players[currPlayer]->getName();
        thisHand = 0;

        // double JJ's bankroll
        if (!doubledJJBK && playerName == "Joseph Joestar") {
            bankroll *= 2;
            doubledJJBK = true;
        }

        bool isJJEscaped = false;

        // check initial state
        if (bankroll < minBet) {
            if (playerName == "Joseph Joestar") { // special case of JJ's double bankroll is still smaller than minBet
                cout << "Player: Joseph Joestar: \"Ni Ge Run Da Yo\"" << endl;
                isJJEscaped = true;
                currPlayer++;
                bankroll = stoi(argv[1]);
//                continue;
            }
        }

        // hand
        while (thisHand < max_hands && bankroll >= minBet && !isJJEscaped) {
            thisHand++;
            hand_dealer->discardAll();
            hand_player->discardAll();
            cout << "Hand " << thisHand << " bankroll " << bankroll << endl;

            //check deck, re-ini and inform the player if needed
            CheckDeck(deck, Players[currPlayer]);

            int wager = Players[currPlayer]->bet(bankroll, minBet);
            cout << "Player: " << playerName << " bets " << wager << endl;

            int PlayerCardCount = 0;
            int DealerCardCount = 0;

            deal_p(deck, Players[currPlayer], card_player, hand_player, PlayerCardCount);//one face-up to player
            deal_d(deck, Players[currPlayer], card_dealer, hand_dealer, true,
                   Dealers[currDealer], DealerCardCount);//one face-up to dealer
            deal_p(deck, Players[currPlayer], card_player, hand_player, PlayerCardCount);//one face-up to player
            deal_d(deck, Players[currPlayer], card_dealer2, hand_dealer, false,
                   Dealers[currDealer], DealerCardCount);//one face-down to dealer


            // check if player gets a natural 21,
            // and revise the bankroll accordingly
            if (CheckN21(hand_player, &bankroll, &wager, playerName)) {
                continue;
            }

            //draw one card face-up to player
            try {
                while (Players[currPlayer]->draw(*card_dealer, *hand_player) && hand_player->handValue().count <= 21) {
//                    cout << hand_player->handValue().count << ' ';
                    deal_p(deck, Players[currPlayer], card_player, hand_player, PlayerCardCount);
                }
            }
            catch (string s) {
                cout << "Hand " << thisHand-- << " card used up, this hand will start again" << endl;
                CheckDeck(deck, Players[currPlayer]);
                continue;
            }
            cout << "Player: " << playerName << "'s total is " << hand_player->handValue().count << endl;

            //check if player bust, and revise the bankroll accordingly
            if (CheckPlayerBust(hand_player, &bankroll, &wager, playerName)) {
                if (CheckJJ(playerName, bankroll, stoi(argv[1]), thisHand)) {
                    isJJEscaped = true;
                    currPlayer++;
//                    bankroll = stoi(argv[1]);
                }
                continue;
            }

            // if the Player hasn't busted, announce and expose the dealer's hole card
            Players[currPlayer]->expose(*card_dealer2);
            cout << "Dealer: " << Dealers[currDealer] << "'s hole card is " << SpotNames[card_dealer2->spot] << " of "
                 << SuitNames[card_dealer2->suit] << endl;

            //draw one card face-up to dealer
            try {
                while (hand_dealer->handValue().count < 17) {
                    deal_d(deck, Players[currPlayer], card_dealer, hand_dealer, true, Dealers[currDealer],
                           DealerCardCount);
                }
            }
            catch (string s) {
                cout << "Hand " << thisHand-- << " card used up, this hand will start again" << endl;
                CheckDeck(deck, Players[currPlayer]);
                continue;
            }
            cout << "Dealer: " << Dealers[currDealer] << "'s total is " << hand_dealer->handValue().count << endl;

            //check if dealer bust, and revise the bankroll accordingly
            if (CheckDealerBust(hand_dealer, &bankroll, &wager, Dealers[currDealer])) {
                continue;
            }

            //compare the total counts of player and dealer, and revise the bankroll accordingly
            compare(hand_dealer, hand_player, &bankroll, &wager, playerName, Dealers[currDealer]);
            if (CheckJJ(playerName, bankroll, stoi(argv[1]), thisHand)) {
                isJJEscaped = true;
                currPlayer++;
                continue;
            }

        }

        // kick out the player, and start a new round.

        // special case of JJ's double bankroll is still smaller than minBet
        if (playerName == "Joseph Joestar" && isJJEscaped) {
            bankroll = stoi(argv[1]);
            cout << "Player: " << playerName << " has been kicked out. The winner of this round is "
                 << Dealers[currDealer] << "." << endl;
            continue;
        }

        // player lose
        if (bankroll < minBet) {
            cout << "Player: " << playerName << " has " << bankroll << " after " << thisHand << " hands " << endl;
            cout << "Player: " << playerName << " has been kicked out. The winner of this round is "
                 << Dealers[currDealer] << "." << endl;
            currPlayer++;
            bankroll = stoi(argv[1]);

            if (Dealers[currDealer] == "Joseph Joestar") {
                cout << "Dealer: Joseph Joestar: \"Nice!\"" << endl;
            }
            if (Dealers[currDealer] == "Kakyoin Noriaki") {
                cout << "Dealer: Kakyoin Noriaki: \"rerorerorero rerorerorero\"" << endl;
            }

        }

            // kick out the dealer, and start a new round.
            // dealer lose
        else if (thisHand >= max_hands && bankroll >= minBet) {
            cout << "Player: " << playerName << " has " << bankroll << " after " << thisHand << " hands " << endl;
            cout << "Dealer: " << Dealers[currDealer] << " has been kicked out. The winner of this round is "
                 << playerName << "." << endl;
            currDealer++;

            if (playerName == "Joseph Joestar") {
                cout << "Player: Joseph Joestar: \"Nice!\"" << endl;
            }
            if (playerName == "Kakyoin Noriaki") {
                cout << "Player: Kakyoin Noriaki: \"rerorerorero rerorerorero\"" << endl;
            }
        }
    }

    // terminal state
    if ((currPlayer == 5 && currDealer < 5 && dealerSide == "sc") ||
        (currPlayer < 5 && currDealer == 5 && dealerSide == "sos")) {
        cout << "Game over. The winner is Stardust Crusaders. "
             << "SOS Brigade will return the computer to Joseph Joestar "
             << "and Suzumiya Haruhi will become a member of Stardust Crusaders" << endl;
    } else if ((currPlayer < 5 && currDealer == 5 && dealerSide == "sc") ||
               (currPlayer == 5 && currDealer < 5 && dealerSide == "sos")) {
        cout << "Game over. The winner is SOS Brigade. SOS Brigade got"
             << " four computers and Stardust Crusaders become an affiliate group of SOS Brigade" << endl;
    }

    return 0;
}
