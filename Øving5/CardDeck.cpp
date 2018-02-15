#include "CardDeck.h"
#include "Card.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void CardDeck::swap(int index1, int index2) {
  Card temp = this->cards[index1];
  cards[index1] = this->cards[index2];
  cards[index2] = temp;
}

CardDeck::CardDeck() {

  this->currentCardIndex = 0;

  Suit suits[] = {HEARTS, DIAMONDS, SPADES, CLUBS};
  Rank ranks[] = {TWO,  THREE, FOUR, FIVE,  SIX,  SEVEN, EIGHT,
                  NINE, TEN,   JACK, QUEEN, KING, ACE};
  for (int s = 0; s < 4; s++) {
    for (int r = 0; r < 13; r++) {
      Card *temp = new Card(suits[s], ranks[r]);
      (this->cards).push_back(*temp);
    }
  }
}

void CardDeck::print() {
  for (int i = 0; i < this->cards.size(); i++) {
    Card someCard = this->getCard(i);
    cout << someCard.toString() << endl;
  }
}

void CardDeck::printShort() {
  for (int i = 0; i < this->cards.size(); i++) {
    Card someCard = this->getCard(i);
    cout << someCard.toStringShort() << endl;
  }
}

void CardDeck::shuffle() {
  int one, two;
  for (int i = 0; i < 100; i++) {
    one = rand() % this->cards.size();
    two = rand() % this->cards.size();
    this->swap(one, two);
  }
}
Card CardDeck::drawCard() {
  int last = this->currentCardIndex;
  this->currentCardIndex = (this->currentCardIndex + 1) % (this->cards.size());
  return this->cards[last];
}
// EGEN KODE: HENT KORT PÅ INDEX I
Card CardDeck::getCard(int index) { return (this->cards)[index]; }
