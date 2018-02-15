#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"
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

  Card *myCard = new Card();
  myCard->initialize(HEARTS, QUEEN);
  cout << myCard ->toStringShort() << endl;
  CardDeck *myDeck = new CardDeck();
  myDeck->shuffle();
  Card temp;
  for (size_t i = 0; i < 53; i++) {
    temp = myDeck ->drawCard();
    cout << temp.toString() << endl;
  }
  Blackjack *BJ = new Blackjack();
  cout << BJ ->askPlayerDrawCard() << endl;
  */
  Blackjack *BJ = new Blackjack();
  BJ->playGame();

  return 0;
}
