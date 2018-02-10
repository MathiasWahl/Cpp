
//Oppg 1c) Lage denne filen
#include <iostream>
#include "utilities.cpp"
using namespace std;


void testCallByValue(int a, int b, int c) {
  int v0 = a;
  int increment = b;
  int iterations = c;
  int result = incrementByValueNumTimes(v0, increment, iterations); std::cout << "v0: " << v0
                  << " \tincrement: " << increment
                  << " \titerations: " << iterations
                  << " \tresult: " << result << std::endl;

}


void testCallByPointer(int a, int b, int c) {
  int v0 = a;
  int increment = b;
  int iterations = c;
  incrementByValueNumTimes2(v0, increment, iterations);
  std::cout << "v0 is now: " << v0
                  << " \tincrement: " << increment
                  << " \titerations: " << iterations << endl;
}


void testTableSorting(){
  int percentages[20];
  randomizeArray(percentages, 20);
  cout << "Nå er den random:" << endl;
  printArray(percentages, 20);
  cout << "Nå er den sorted:" << endl;
  sortArray(percentages, 20);
  printArray(percentages, 20);
  cout << endl;

}


void testCStrings(){
  int numberOfGrades = 17;
  char lowestGrade = 'E';
  char highestGrade = 'A';
  //int differentGrades = int(highestGrade - lowestGrade);
  int differentGrades = 5;
  cout << differentGrades << endl;

  char grades[numberOfGrades];
  grades[numberOfGrades] = '\0';
  randomizeCString(grades,numberOfGrades - 1,lowestGrade);
  cout << "Generated grades:\n" << grades << endl;


  int gradeCount[differentGrades];
  for (int i = 0; i < differentGrades; i++){
    gradeCount[i] = countOccurencesOfCharacter(grades, numberOfGrades, (highestGrade + i));
  }
  cout << "Gradecount (A-B-C-D-E):\n";
  printArray(gradeCount, differentGrades);

  double total = 0;
  for (int i = 0; i < differentGrades; i++){
    total += gradeCount[i] * (differentGrades-i);
  }
  double snitt = total / 16;
  cout << "Average score: " << snitt << endl << endl;




}
