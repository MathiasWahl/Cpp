

int checkCharactersAndPosition(char code[], char guess[], int size){
  int correct = 0;
  for (int i = 0; i < size; i++){
    if (code[i] == guess[i]){
      correct += 1;
    }
  }
  return correct;
}

int checkCharacters(char code[], char guess[], int size, int letters){
  //Blir mye av det samme som gradeCount!
  int hits = 0;
  int freqCode, freqGuess;
  for (int i = 0; i < letters; i++){
    freqCode = countOccurencesOfCharacter(code, size, 'A' + i);
    freqGuess = countOccurencesOfCharacter(guess, size, 'A' + i);
    if (freqGuess <= freqCode){
      hits += freqGuess;
    } else {
      hits += freqCode;
    }
  }
  return hits;
}


void playMastermind(){
  const int SIZE = 4;
  const int LETTERS = 6;
  const int TRIES = 10;

  char code[SIZE + 1];
  char guess[SIZE + 1];

  code[SIZE] = 0;
  guess[SIZE] = 0;

  bool playAgain = true;
  char ans = 'S';
  while (playAgain){

    randomizeCString(code, SIZE , 'A' + LETTERS - 1);

    int rightCharAndPos = 0;
    int rightChars = 0;
    int tries = 1;

    while ((rightCharAndPos < SIZE) and (tries <= TRIES)){
      cout << "TRY " << tries << endl;
      readInputToCString(guess, 'A', 'A' + LETTERS - 1, SIZE);
      rightChars = checkCharacters(code, guess, SIZE, LETTERS);
      rightCharAndPos = checkCharactersAndPosition(code, guess, SIZE);
      cout << "You guessed " << rightChars << " right. " << rightCharAndPos << " of them are in the right position." << endl;
      tries += 1;
      //CHEATERS:
      cout << code << endl << guess << endl;
    }
    switch (rightCharAndPos) {
      case SIZE:
        cout << "Congratulations! You guessed right!" << endl;
        break;
      default:
        cout << "You are out of tries. Better luck next time!" << endl;
    }
    cout << "Do you want to play again? (y/n)\nAswering no will take you back to main menu.\n\t>>>";
    cin >> ans;
    while ((toupper(ans) != 'Y') and (toupper(ans) != 'N')){
      cout << "Please answer y/n:\n\t>>>";
      cin >> ans;
    }
    if (toupper(ans) == 'Y'){
      playAgain = true;
    } else if (toupper(ans) == 'N'){
      playAgain = false;
    }
/*
    while ((toupper(ans) != 'Y') or (toupper(ans) != 'N')){
      cin >> ans;
      switch (toupper(ans)){
        case 'Y':
          break;
        case 'N':
          playAgain = false;
          break;
        default:
          cout << "Please answer y/n:\n\t>>>";
          break;
      }
    } */
  }

}
