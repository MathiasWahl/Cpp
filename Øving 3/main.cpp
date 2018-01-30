#include "canonball.cpp"
#include "utilities.hpp"
#include <iostream>
#include <ctime>

int main(){
/*
  cout << accY() << endl;
  cout << "\nTest X:" << endl;
  cout << posX(0, 50, 0) << endl;
  cout << posX(0, 50, 2.5) << endl;
  cout << posX(0, 50, 5) << endl;
  cout << "\nTest Y:" << endl;
  cout << posY(0, 25, 0) << endl;
  cout << posY(0, 25, 2.5) << endl;
  cout << posY(0, 25, 5) << endl;
  return 0;
  */
  int input;
  while (true){
    cout << "\n--------------------------------------------------------\nWelcome to the shooting ground! Do you want to play? \n0:Exit\n1:Play \n\t>>>";
    cin >> input;
      if (input == 0){
        break;
      } else if (input == 1){
        playTargetPractice();
      } else {
        cout << "Please choose between 1 and 0" << endl;
      }
    }
  return 0;
  }
