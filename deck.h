//
// Created by Osaid K on 11/7/18.
//

#ifndef GOFISH1_DECK_H
#define GOFISH1_DECK_H
#include <iostream>
#include <string>
#include <vector>
#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:


    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the deck, all 52 cards present
    Card dealCard();   // get a card, after 52 are dealt, fail

    int  size() const; // # cards left in the deck
    void cards() const;
private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif //GOFISH1_DECK_H
