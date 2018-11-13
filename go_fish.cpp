#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( ) {

    ofstream myfile;
    myfile.open("gofish_results.txt");
    cout << "The Game Started!"<<endl;

    int numCards = 7;
    int ElafFlag = 1;
    int OsaidFlag = 1;
    int DeckBottom = 0;
    int draw=1;
    Card AskingCard;
    Card DrawingCard;
    Player Elaf("Elaf");
    Player Osaid("Osaid");

    Deck d;  //create a deck of cards
    d.cards();
    d.shuffle();
    d.cards();
    myfile << "Deck: " << d.size() << endl;
    dealHand(d, Elaf, numCards);
    dealHand(d, Osaid, numCards);
    d.cards();
    myfile << "Deck: " << d.size() << endl;
    myfile << Elaf.getName() << " has : " << Elaf.showHand() << endl;
    myfile << Osaid.getName() << " has : " << Osaid.showHand() << endl;
    Card card1 = Card();
    Card card2 = Card();

    while (Elaf.checkHandForPair(card1,card2) || Osaid.checkHandForPair(card1,card2)) {
        if (Elaf.checkHandForPair(card1, card2)) {
            Elaf.bookCards(Elaf.removeCardFromHand(card1), Elaf.removeCardFromHand(card2));
        }
        if (Osaid.checkHandForPair(card1, card2)) {
            Osaid.bookCards(Osaid.removeCardFromHand(card1), Osaid.removeCardFromHand(card2));
        }
    }

    myfile << "Elaf's Book : " << Elaf.showBooks() << endl;
    myfile << "Osaid's Book : " << Osaid.showBooks() << endl;

    while (Elaf.getBookSize() + Osaid.getBookSize() < 52) {
        if (ElafFlag) {
            if (Elaf.getHandSize() > 0) {
                AskingCard = Elaf.chooseCardFromHand();
                myfile << endl;
                myfile << "Elaf asks - do you have a " << AskingCard.rankString(AskingCard.getRank()) << "?" << endl;
                if (Osaid.cardInHand(AskingCard)) {
                    myfile << "Osaid says - Yes I have a " << AskingCard.rankString(AskingCard.getRank()) << endl;
                    Elaf.bookCards(Elaf.removeCardFromHand(AskingCard), Osaid.removeCardFromHand(AskingCard));
                    myfile << "Elaf books the " << AskingCard.rankString(AskingCard.getRank()) << endl;
                    draw=0;
                    OsaidFlag=0;
                }
            }

            if (d.size() > DeckBottom && draw) {
                DrawingCard = d.dealCard();
                Elaf.addCard(DrawingCard);
                myfile << "Osaid says - Go Fish!" << endl;
                myfile << "Elaf draws " << DrawingCard << endl;
                myfile << Elaf.getName() << " has : " << Elaf.showHand() << endl;

                if (Elaf.checkHandForPair(card1, card2)) {
                    Elaf.checkHandForPair(card1, card2);
                    Elaf.bookCards(Elaf.removeCardFromHand(card1), Elaf.removeCardFromHand(card2));
                    myfile << "Elaf books " << card1 << " & the new drawn card " << card2 << endl;
                }
                OsaidFlag = 1;
            }
        draw=1;

        }

        if (OsaidFlag) {

            if (Osaid.getHandSize()>0) {
                AskingCard = Osaid.chooseCardFromHand();
                myfile << endl;
                myfile << "Osaid asks - do you have a " << AskingCard.rankString(AskingCard.getRank()) << "?" << endl;
                if (Elaf.cardInHand(AskingCard)) {
                    myfile << "Elaf says - Yes I have a " << AskingCard.rankString(AskingCard.getRank())  << endl;
                    Osaid.bookCards(Osaid.removeCardFromHand(AskingCard), Elaf.removeCardFromHand(AskingCard));
                    myfile << "Osaid books the " << AskingCard.rankString(AskingCard.getRank()) << endl;
                    draw=0;
                    ElafFlag=0;
                }
            }

            if (d.size() > DeckBottom && draw) {
                DrawingCard = d.dealCard();
                Osaid.addCard(DrawingCard);
                myfile << "Elaf says - Go Fish!" << endl;
                myfile << "Osaid draws " << DrawingCard << endl;
                myfile << Osaid.getName() << " has : " << Osaid.showHand() << endl;

                if (Osaid.checkHandForPair(card1,card2)){
                    Osaid.checkHandForPair(card1,card2);
                    Osaid.bookCards(Osaid.removeCardFromHand(card1), Osaid.removeCardFromHand(card2));
                    myfile << "Osaid books " << card1 <<" & the new drawn card "<<card2<<endl;
                }
                ElafFlag=1;
            }
        draw=1;
        }
    }


    myfile << "Elaf Books are " << Elaf.getBookSize() <<endl;
    myfile << "Osaid Books are " << Osaid.getBookSize()<<endl;

    if (Elaf.getBookSize() > Osaid.getBookSize()){
        myfile << "Elaf wins the game."<<endl;
        myfile << "Good luck, Osaid. Next time."<<endl;
    }
    else if (Elaf.getBookSize() < Osaid.getBookSize()){
        myfile << "Osaid wins the game."<<endl;
        myfile << "Good luck, Elaf. Next time."<<endl;
    }
    else {
        myfile<< "How cool!! It's a tie."<<endl;
    }


    myfile.close();
    cout << "The Game is Over" << endl;


    return EXIT_SUCCESS;

}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

