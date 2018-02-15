#include "Card.h"
#include "CardDeck.h"
//#include "CardDeck.cpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {

  /*
    cout << "TEST:" << endl;

    CardStruct card;
    card.r = JACK;
    card.s = HEARTS;

    cout << toString(card) << endl;
    cout << toStringShort(card) << endl;

    Card *myCard = new Card;
    myCard->initialize(HEARTS, TEN);
    cout << myCard->toString() << endl;
    cout << myCard->toStringShort() << endl;

    CardDeck *myDeck = new CardDeck();
  */
  Card *myCard = new Card::Card();
  //myCard->initialize(HEARTS, TEN);
  CardDeck *myDeck = new CardDeck::CardDeck();
/*  myDeck->shuffle();
  myDeck->print();*/

  return 0;
}
