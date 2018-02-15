#ifndef CARDDECK_H_
#define CARDDECK_H_

#include <iostream>
#include <vector>
using namespace std;

class Card;

class CardDeck {

private:
  std::vector<Card> cards;
  int currentCardIndex;

  void swap(int index1, int index2);

public:
  CardDeck();

  void print();

  void printShort();

  void shuffle();

  Card drawCard();

  // EGEN: HENTER KORT PÅ INDEX I
  Card getCard(int index);
};

#endif // CARDDECK_H_
