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

void deck_init(Deck *deck) {
    cout << "Shuffling the deck" << endl;
    for (int i = 0; i < SHUFFLE_TIME; ++i) {
        int cut = get_cut();
        cout << "cut at " << cut << endl;
        deck->shuffle(cut);
    }
}

void CheckDeck(Deck *deck, Player *player) {
    if (deck->cardsLeft() < 20) {
        deck_init(deck);
        player->shuffled();
    }
}

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

//TODO: I think this function is mostly designed for the time-stopping guy. Recheck this and modify the main function after finished time stopping
bool CheckCards(Deck *deck, int &thisHand) {
    if (deck->cardsLeft() == 0) {
        cout << "Hand " << thisHand-- << " card used up, this hand will start again" << endl;
        return true;
    }
    return false;
}

void
deal_dealer(Deck *deck, Player *player, Card *card_dealer, Hand *hand_dealer, bool ifFaceUp, const string &dealerName) {
    *card_dealer = deck->deal();
    hand_dealer->addCard(*card_dealer);
    if (ifFaceUp) {
        player->expose(*card_dealer);
        cout << "Dealer: " << dealerName << " dealt " << SpotNames[card_dealer->spot] << " of "
             << SuitNames[card_dealer->suit] << endl;
    }
}

void deal_player(Deck *deck, Player *player, Card *card_player, Hand *hand_player, const string &playerName) {
    *card_player = deck->deal();
    hand_player->addCard(*card_player);
    player->expose(*card_player);
    cout << "Player: " << playerName << " dealt " << SpotNames[card_player->spot] << " of "
         << SuitNames[card_player->suit] << endl;
}


// MODIFIES: bankroll
// EFFECTS: compare the total counts of player and dealer, and revise the bankroll accordingly
void compare(Hand *hand_dealer, Hand *hand_player, int *bankroll, int const *wager, const string &playerName,
             const string &dealerName) {
    using namespace std;
    if (hand_player->handValue().count > hand_dealer->handValue().count) {
        cout << "Player: " << playerName << " wins this hand" << endl;
        *bankroll += *wager;
    } else if (hand_player->handValue().count < hand_dealer->handValue().count) {
        cout << "Dealer: " << dealerName << " wins this hand" << endl;
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
    /*cout << Players[0]->getTeam() << " " << Players[0]->getName() << " " << Players[0]->getID() << endl;
    cout << Players[1]->getTeam() << " " << Players[1]->getName() << " " << Players[1]->getID() << endl;
    cout << Players[2]->getTeam() << " " << Players[2]->getName() << " " << Players[2]->getID() << endl;
    cout << Players[3]->getTeam() << " " << Players[3]->getName() << " " << Players[3]->getID() << endl;
    cout << Players[4]->getTeam() << " " << Players[4]->getName() << " " << Players[4]->getID() << endl;*/
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

    // round
    while (currPlayer < 5 && currDealer < 5) {
        deck_init(deck);

        bool isJJEscaped = false;

        string playerName = Players[currPlayer]->getName();
        thisHand = 0;
        if (bankroll < minBet) {
            cout << "Player: " << playerName << " has " << bankroll << " after " << thisHand << " hands " << endl;
            // TODO: need to check
            if (playerName == "Joseph Joestar") {
                cout << "Dealer: Joseph Joestar: \"Ni Ge Run Da Yo\"" << endl;
            }
        }

        // hand
        while (thisHand < max_hands && bankroll >= minBet && !isJJEscaped) {
            thisHand++;
            hand_dealer->discardAll();
            hand_player->discardAll();
            cout << "Hand " << thisHand << " bankroll " << bankroll << endl;

            CheckDeck(deck, Players[currPlayer]);//check deck, re-ini and inform the player if needed

            int wager = Players[currPlayer]->bet(bankroll, minBet);

            cout << "Player: " << playerName << " bets " << wager << endl;

            deal_player(deck, Players[currPlayer], card_player, hand_player, playerName);//one face-up to player
            if (CheckCards(deck, thisHand)) continue;
            deal_dealer(deck, Players[currPlayer], card_dealer, hand_dealer, true,
                        Dealers[currDealer]);//one face-up to dealer
            if (CheckCards(deck, thisHand)) continue;

            deal_player(deck, Players[currPlayer], card_player, hand_player, playerName);//one face-up to player
            if (CheckCards(deck, thisHand)) continue;

            deal_dealer(deck, Players[currPlayer], card_dealer2, hand_dealer, false,
                        Dealers[currDealer]);//one face-down to dealer
            if (CheckCards(deck, thisHand)) continue;


            // check if player gets a natural 21, and revise the bankroll accordingly
            if (CheckN21(hand_player, &bankroll, &wager, playerName)) {
                cout << "Player: " << playerName << " has " << bankroll << " after " << thisHand << " hands " << endl;
                continue;
            }

            //draw one card face-up to player
            while (Players[currPlayer]->draw(*card_dealer, *hand_player) && hand_player->handValue().count <= 21) {
                deal_player(deck, Players[currPlayer], card_player, hand_player, playerName);
            }
            if (CheckCards(deck, thisHand)) continue;


            cout << "Player: " << playerName << "'s total is " << hand_player->handValue().count << endl;

            //check if player bust, and revise the bankroll accordingly
            if (CheckPlayerBust(hand_player, &bankroll, &wager, playerName)) {
                cout << "Player: " << playerName << " has " << bankroll << " after " << thisHand << " hands " << endl;
                continue;
            }

            // if the Player hasn't busted, announce and expose the dealer's hole card
            Players[currPlayer]->expose(*card_dealer2);
            cout << "Dealer: " << Dealers[currDealer] << "'s hole card is " << SpotNames[card_dealer2->spot] << " of "
                 << SuitNames[card_dealer2->suit] << endl;

            //draw one card face-up to dealer
            while (hand_dealer->handValue().count < 17) {
                deal_dealer(deck, Players[currPlayer], card_dealer, hand_dealer, true, Dealers[currDealer]);
            }
            if (CheckCards(deck, thisHand)) continue;

            cout << "Dealer: " << Dealers[currDealer] << "'s total is " << hand_dealer->handValue().count << endl;

            //check if dealer bust, and revise the bankroll accordingly
            if (CheckDealerBust(hand_dealer, &bankroll, &wager, Dealers[currDealer])) {
                cout << "Player: " << playerName << " has " << bankroll << " after " << thisHand << " hands " << endl;
                continue;
            }

            //compare the total counts of player and dealer, and revise the bankroll accordingly
            compare(hand_dealer, hand_player, &bankroll, &wager, playerName, Dealers[currDealer]);

            // bankroll after one hand
            // TODO: position of the command may need change
            cout << "Player: " << playerName << " has " << bankroll << " after " << thisHand << " hands " << endl;
        }

        // after several hands, determine if player wins
        if (bankroll < minBet) {
            // kick out the player, and start a new round.
            cout << "Player: " << playerName << " has been kicked out. The winner of this round is "
                 << Dealers[currDealer]
                 << "." << endl;
            currPlayer++;
            bankroll = stoi(argv[1]);
            if (Dealers[currDealer] == "Joseph Joestar") {
                cout << "Dealer: Joseph Joestar: \"Nice!\"" << endl;
            }
        } else if (thisHand >= max_hands && bankroll >= minBet) {
            // kick out the dealer, and start a new round.
            cout << "Dealer: " << Dealers[currDealer] << " has been kicked out. The winner of this round is "
                 << playerName
                 << "." << endl;
            currDealer++;
        }
    }

    if ((currPlayer == 5 && currDealer < 5 && dealerSide == "sc") ||
        (currPlayer < 5 && currDealer == 5 && dealerSide == "sos")) {
        cout
                << "Game over. The winner is Stardust Crusaders. SOS Brigade will return the computer to Joseph Joestar and Suzumiya Haruhi will become a member of Stardust Crusaders"
                << endl;
    } else if ((currPlayer < 5 && currDealer == 5 && dealerSide == "sc") ||
               (currPlayer == 5 && currDealer < 5 && dealerSide == "sos")) {
        cout
                << "Game over. The winner is SOS Brigade. SOS Brigade got four computers and Stardust Crusaders become an affiliate group of SOS Brigade"
                << endl;
    }


    return 0;
}