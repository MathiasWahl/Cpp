#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cctype>
using namespace std;


//Oppgave 1a) v0 vil ha verdien 5 (du gir bare verdien til 0v inn i funksjonen, ikke objektet)


//b)
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
  for (int i = 0; i < numTimes; i++) {
    startValue += increment;
  }
  return startValue;
}

//d)
void incrementByValueNumTimes2(int& startValue, int increment, int numTimes) {
  for (int i = 0; i < numTimes; i++) {
    startValue += increment;
  }
}


//Denne funksjonen tar høyde for (og omorganiserer) pekerne til num1 og num2
void swapNumbers(int& num1, int& num2){
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

void printArray(int myArray[], int size){
  string out = "";
  for (int entry = 0; entry < size; entry++){
    out += to_string(myArray[entry]) + " ";
  }
  cout << out << endl;
}


void randomizeArray(int myArray[], int size){
  srand(time(0));
  for (int i = 0; i < size; i++){
    myArray[i] = rand() % 101;
  }
}

//Bubble-sort:
void sortArray(int myArray[], int size){
  for (int i = 0; i < size; i++){
    for (int j = i; j < size; j ++){
      if (myArray[i] > myArray[j]){
        swapNumbers(myArray[i], myArray[j]);
      }
    }
  }

}

//Antar sortert array som input
double medianOfArray(int myArray[], int size){
  if ((size % 2) == 0){
    int index = (size / 2) - 1;
    return double(myArray[index] + myArray[index + 1])/2;
  } else {
    return myArray[int(size / 2)];
  }
}


void randomizeCString(char cString[],int size, char limit){
  srand(time(0));
  for (int i = 0; i < size; i++){
    cString[i] = (rand() % (limit - 'A' + 1)) + 'A';
  }
}
bool validate(char letter, char low, char high){
  if ((low <= toupper(letter)) and (toupper(letter) <= high)){
    return true;
  }else{
    return false;
  }
}

void readInputToCString(char anArray[], char lowerLimit, char upperLimit, int length){
  char lowLim = toupper(lowerLimit);
  char highLim = toupper(upperLimit);
  char currentsymbol = lowLim -10;
  cout << "You can write a word of length " << length << " with the charcters between " << lowLim << " and " << highLim << endl;
  for (int i = 0; i<length; i++){
    while (not (validate(currentsymbol, lowLim, highLim))){
      cout << "Please (re)enter symbol" << (i + 1) << ". Keep in mind, symbol must be beween " << lowLim << " and " << highLim << endl;
      cin >> currentsymbol;
    }
  anArray[i] = toupper(currentsymbol);
  currentsymbol = lowLim - 10;
  }
}


int countOccurencesOfCharacter(char searchArray[], int size, char find){
  int occurences = 0;
  for (int i = 0; i < size; i++){
    if (searchArray[i] == find){
      occurences += 1;
    }
  }
  return occurences;
}
