//
// Created by Osaid K on 11/7/18.
//
#include <iostream>
#include <string>
#include <vector>
#include "deck.h"
#include "card.h"
#include "player.h"
#include <cstdlib>
#include <ctime>


Deck::Deck() {
    int index=0;

    for (int j = 1; j < 14; j++) {
        myCards[index]=Card(j, Card::spades);
        index++;
    }

    for (int j = 1; j < 14; j++) {
        myCards[index]=Card(j, Card::hearts);
        index++;
    }

    for (int j = 1; j < 14; j++) {
        myCards[index]=Card(j, Card::diamonds);
        index++;
    }

    for (int j = 1; j < 14; j++) {
        myCards[index]=Card(j, Card::clubs);
        index++;
    }
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    myIndex=0;
}


void Deck::shuffle() {
    Card temp;
    if (size() > 1) {
        for (int i = 0; i < 52; i++) {
            long card1 = (rand() % 52)+myIndex;
            long card2 = (rand() % 52)+myIndex;
            temp = myCards[card1];
            myCards[card1] = myCards[card2];
            myCards[card2] = temp;
        }
    }
}




Card Deck::dealCard() {
    Card card;
    if (size() > 0) {
        card = myCards[myIndex];
        myIndex++;
        return card;
    }
    else return Card();
}


int Deck::size() const {
    return SIZE - myIndex;
}


void Deck::cards() const {
    for (int i=myIndex; i<52; i++){
        cout << myCards[i];
    }
    cout << endl;
}