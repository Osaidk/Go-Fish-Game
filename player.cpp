//
// Created by Osaid K on 11/7/18.
//

#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include <cstdlib>
#include <ctime>




Player::Player() {
    myName=" ";
}



void Player::addCard(Card c) {
    myHand.push_back(c);
}


void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}



Card Player::chooseCardFromHand() const {
    long card = rand() % (myHand.size());
    return myHand[card];
}





bool Player::cardInHand(Card c) const {
    vector<Card>::const_iterator iterator;
    for (iterator=myHand.begin(); iterator!=myHand.end(); iterator++){
        if (*iterator==c){
            return true;
        }
    }
    return false;
}






Card Player::removeCardFromHand(Card c){
    vector<Card>::iterator iterator;
    for (iterator = myHand.begin() ;iterator!=myHand.end();iterator++){
        if (*iterator==c){
            myHand.erase(iterator);
            return c;
        }
    }
    return c;
}




string Player::showHand() const {
    string myhand;
    vector<Card>::const_iterator iterator;
    for (iterator = myHand.begin(); iterator != myHand.end(); iterator++) {
        myhand += iterator->toString();
    }
    myhand += " ";
    return myhand;
}


string Player::showBooks() const {
    string mybook;
    vector<Card>::const_iterator iterator;
    for (iterator = myBook.begin(); iterator != myBook.end(); iterator++) {
        mybook += iterator->toString();
    }
    mybook += " ";
    return mybook;
}



int Player::getHandSize() const {
    return myHand.size();
}



int Player::getBookSize() const {
    return myBook.size();
}



bool Player::sameRankInHand(Card c) const{
    vector<Card>::const_iterator iterator;
    for (iterator=myHand.begin();iterator!=myHand.end();iterator++){
        if (iterator->getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}



bool Player::checkHandForPair(Card &c1, Card &c2){
    vector<Card>::iterator iterator1,iterator2;
    for (iterator1 = myHand.begin(); iterator1!=myHand.end(); iterator1++){
        for (iterator2 = iterator1+1; iterator2!=myHand.end(); iterator2++){
            if (iterator1->getRank()==iterator2->getRank()){
                c1 = *iterator;
                c2 = *iterator2;
                return true;
            }
        }
    }
    return false;
}





