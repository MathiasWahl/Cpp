#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"
#include <iostream>
#include <string>

using namespace std;

string suitToString(Suit s) {
  switch (s) {
  case DIAMONDS:
    return "Diamonds";
    break;
  case HEARTS:
    return "Hearts";
    break;
  case SPADES:
    return "Spades";
    break;
  case CLUBS:
    return "Clubs";
    break;
  }
}

string rankToString(Rank r) {
  switch (r) {
  case TWO:
    return "Two";
    break;
  case THREE:
    return "Three";
    break;
  case FOUR:
    return "Four";
    break;
  case FIVE:
    return "Five";
    break;
  case SIX:
    return "Six";
    break;
  case SEVEN:
    return "Seven";
    break;
  case EIGHT:
    return "Eight";
    break;
  case NINE:
    return "Nine";
    break;
  case TEN:
    return "Ten";
    break;
  case JACK:
    return "Jack";
    break;
  case QUEEN:
    return "Queen";
    break;
  case KING:
    return "King";
    break;
  case ACE:
    return "Ace";
    break;
  }
}

string toString(CardStruct card) {
  return rankToString(card.r) + " of " + suitToString(card.s);
}

string toStringShort(CardStruct card) {
  string out = "";
  switch (card.s) {
  case DIAMONDS:
    out += "D";
    break;
  case HEARTS:
    out += "H";
    break;
  case SPADES:
    out += "S";
    break;
  case CLUBS:
    out += "C";
    break;
  }
  switch (card.r) {
  case TWO:
    out += "2";
    break;
  case THREE:
    out += "3";
    break;
  case FOUR:
    out += "4";
    break;
  case FIVE:
    out += "5";
    break;
  case SIX:
    out += "6";
    break;
  case SEVEN:
    out += "7";
    break;
  case EIGHT:
    out += "8";
    break;
  case NINE:
    out += "9";
    break;
  case TEN:
    out += "10";
    break;
  case JACK:
    out += "11";
    break;
  case QUEEN:
    out += "12";
    break;
  case KING:
    out += "13";
    break;
  case ACE:
    out += "14";
    break;
  }
  return out;
}

//DEFINING CARD:
void Card::initialize(Suit s, Rank r) {
    this->info.s = s;
    this->info.r = r;
    this->valid = true;
  }
  Suit Card::getSuit() { return (this->info.s); }
  Rank Card::getRank() { return (this->info.r); }
  string Card::toString() {
    if (not(this->valid)) {
      return "Invalid Card";
    } else {
      string out = "";
      out += rankToString(this->info.r);
      out += " of ";
      out += suitToString(this->info.s);
      return out;
    }
  }
  string Card::toStringShort() {
    if (not(this->valid)) {
      return "Invalid Card";
    } else {
      string out = ::toStringShort(this->info);
      return out;
    }
  }
  Card::Card() { this->valid = false; }

  Card::Card(Suit suit, Rank rank) {
    this->info.s = suit;
    this->info.r = rank;
    this->valid = true;
  }


  // clang
