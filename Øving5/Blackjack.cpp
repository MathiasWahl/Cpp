#include "Blackjack.h"
#include "Card.h"
#include "CardDeck.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int Blackjack::getCardValue(Card *card) {
  switch (card->getRank()) {
  case TWO:
    return 2;
    break;
  case THREE:
    return 3;
    break;
  case FOUR:
    return 4;
    break;
  case FIVE:
    return 5;
    break;
  case SIX:
    return 6;
    break;
  case SEVEN:
    return 7;
    break;
  case EIGHT:
    return 8;
    break;
  case NINE:
    return 9;
    break;
  case TEN:
    return 10;
    break;
  case ACE:
    return -1;
    break;
  default:
    return 10;
    break;
  }
}

bool Blackjack::isAce(Card *card) { return (card->getRank() == ACE); }

int Blackjack::getPlayerCardValue(Card *card) {
  if (this->isAce(card)) {
    int ans;
    cout << "Would you like for it to be 1 or 11?\n\t>>>";
    cin >> ans;
    while ((ans != 11) and (ans != 1)) {
      cout << "Please choose 1 or 11\n\t>>>";
      cin >> ans;
    }
    switch (ans) {
    case 1:
      return 1;
      break;
    case 11:
      return 11;
      break;
    }
  }
  return this->getCardValue(card);
}

int Blackjack::getDealerCardValue(Card *card, int currentScore) {
  if (this->isAce(card)) {
    if (currentScore > 10) {
      return 1;
    } else {
      return 11;
    }
  }
  return this->getCardValue(card);
}

bool Blackjack::askPlayerDrawCard() {
  string ans;
  cout << "Would you like to draw aanother card? (Yes/No)\n\t>>>";
  cin >> ans;
  while ((ans != "Yes") and (ans != "No")) {
    cout << "Please answer Yes/No:\n\t>>>";
    cin >> ans;
  }
  if (ans == "Yes") {
    return true;
  } else {
    return false;
  }
}

void Blackjack::drawInitialCards() {
  Card draw = this->deck->drawCard();
  cout << "Your first card was: " << draw.toString() << endl;
  this->playerHand = getPlayerCardValue(&draw);
  this->playerCardsDrawn = 1;

  draw = this->deck->drawCard();
  this->dealerHand = getDealerCardValue(&draw, 0);
  this->dealerCardsDrawn = 1;
  cout << "\nDealers first card: " << draw.toString() << endl;

  draw = this->deck->drawCard();
  cout << "\nYour second card was: " << draw.toString() << endl;
  this->playerHand += getPlayerCardValue(&draw);
  this->playerCardsDrawn += 1;

  draw = this->deck->drawCard();
  this->dealerHand += getDealerCardValue(&draw, this->dealerHand);
  this->dealerCardsDrawn += 1;
}

void Blackjack::playGame() {
  cout << "Welcome to BlackJack!\n" << endl;
  this->deck = new CardDeck();
  srand(time(0));
  for (size_t i = 0; i < (rand() % 20); i++) {
    this->deck->shuffle();
  }
  this->drawInitialCards();
  string ans = "START";
  cout << "\nDo you want to draw another card? Current hand: "
       << this->playerHand
       << ", No. of cards drawn: " << this->playerCardsDrawn
       << "\n('N' for no, anything else for "
          "yes)\n\t>>>";
  cin >> ans;
  while ((this->playerHand <= 21) and (ans != "N")) {
    // DRAW CARD AND ASK
    Card draw = this->deck->drawCard();
    cout << "\nYou drew:    " << draw.toString() << endl;

    this->playerHand += getPlayerCardValue(&draw);
    this->playerCardsDrawn += 1;
    if (this->playerHand < 22) {
      cout << "\nDo you want to draw another card? Current hand: "
           << this->playerHand
           << ", No. of cards drawn: " << this->playerCardsDrawn
           << "\n('N' for no, anything else for "
              "yes)\n\t>>>";
      cin >> ans;
    }
  }
  if (this->playerHand > 21) {
    cout << "You lost with a hand of " << this->playerHand << endl;
  } else {
    while (this->dealerHand < 17) {
      Card draw = this->deck->drawCard();
      this->dealerHand += getPlayerCardValue(&draw);
      this->dealerCardsDrawn += 1;
    }
    cout << endl;
    if (this->dealerHand > this->playerHand) {
      cout << "You lost! Stats: \nPlayer:\tHand: " << this->playerHand
           << "\tNumber of cards: " << this->playerCardsDrawn << endl;
      cout << "Dealer:\tHand: " << this->dealerHand
           << "\tNumber of cards: " << this->dealerCardsDrawn << endl;
    } else if (this->dealerHand < this->playerHand) {
      cout << "You won! Stats: \nPlayer:\tHand: " << this->playerHand
           << "\tNumber of cards: " << this->playerCardsDrawn << endl;
      cout << "Dealer:\tHand: " << this->dealerHand
           << "\tNumber of cards: " << this->dealerCardsDrawn << endl;
    } else if (this->dealerHand == this->playerHand) {
      cout << "It was a tie! Stats: \nPlayer:\tHand: " << this->playerHand
           << "\tNumber of cards: " << this->playerCardsDrawn << endl;
      cout << "Dealer:\tHand: " << this->dealerHand
           << "\tNumber of cards: " << this->dealerCardsDrawn << endl;
    }
  }
  cout << "Bye-bye!" << endl;
}
