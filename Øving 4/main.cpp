#include "tests.cpp"
#include <iostream>
#include "mastermind.cpp"
using namespace std;


int main() {
  while (true){
  int choice = -1;
  int num, incr, iter;
  cout << "Make your choice:\n7: Play mastermind \t6: Test c-strenger \t5: Test random and swap first \t4: Test table soring \n3: Swap numbers \t2: Test nr 2 \t1: Test nr 1 \t0:Exit \n\t>>>";
  cin >> choice;
  if (choice == 1){

    cout << "Choose number: \n\t>>>";
    cin >> num;
    cout << "\nChoose increment: \n\t>>>";
    cin >> incr;
    cout << "\nChoose iterations: \n\t>>>";
    cin >> iter;

    testCallByValue(num, incr, iter);

  } else if (choice  == 0){
    cout << "Bye-bye!" << endl;
    break;
  } else if (choice  == 2){

    cout << "Choose number: \n\t>>>";
    cin >> num;
    cout << "\nChoose increment: \n\t>>>";
    cin >> incr;
    cout << "\nChoose iterations: \n\t>>>";
    cin >> iter;

    testCallByPointer(num, incr, iter);
  } else if (choice  == 3){
    int num1 = 0;
    int num2 = 0;

    cout << "Choose number 1:\n\t>>";
    cin >> num1;
    cout << "\nChoose number 2:\n\t>>";
    cin >> num2;
    swapNumbers(num1, num2);

    cout << "\nNumber 1 is now " << num1 << ", and number 2 is " << num2 << endl;

  } else if (choice  == 4){

    testTableSorting();

  } else if (choice  == 5){
    int anErry[10];
    cout << endl;
    randomizeArray(anErry, 10);
    printArray(anErry,10);
    cout << "Swapper de to forreste:" << '\n';
    swapNumbers(anErry[0], anErry[1]);
    printArray(anErry, 10);
    cout << medianOfArray(anErry, 10);
    cout << endl;
  } else if (choice  == 6){

    testCStrings();
  } else if (choice  == 7){
    playMastermind();
  } else {
    cout << "\nPlease choose between 1 and 0" << endl;
  }
}


  return 0;
}
