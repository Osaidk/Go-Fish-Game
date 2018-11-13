//
// Created by Osaid K on 11/7/18.
//

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "player.h"

Card::Card() {
    myRank=1;
    mySuit=spades;
}

Card::Card(int rank, Suit s) {
    myRank=rank;
    mySuit=s;

}


string Card::toString() const {
    return rankString(myRank)+suitString(mySuit);
}



string Card::rankString(int r) const {
    switch (r){
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        default:
            return "K";
    }
}


int Card::getRank() const {
    return myRank;
}



string Card::suitString(Suit s) const {
    string suit;
    if (s==spades){
        return suit = "s";
    }
    else if (s==hearts){
        return suit = "h";
    }
    else if (s==clubs){
        return suit="c";
    }
    else return suit="d";

}

bool Card::operator==(const Card &rhs) const {
    if (myRank==rhs.myRank) return true;
    return false;

}


bool Card::operator!=(const Card &rhs) const {
    if (myRank!=rhs.myRank) return true;
    return false;
}

bool Card::sameSuitAs(const Card &c) const {
    if (mySuit==c.mySuit) return true;
    return false;
}


ostream & operator<<(ostream &out, const Card &c) {
    out << c.toString();
    return out;
}