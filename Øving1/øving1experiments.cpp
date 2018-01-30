
#include <iostream>
using namespace std;

int main(){
  cout << "This is a test. \n Hello world! 2 + 2 = "<< (2+2) << endl;
  int a = 4;
  int b = 5;
  double g = static_cast<double>(b) /static_cast<double>(a);
  cout << "a = " << a << ", b = " << b << ", a/b = " << g << endl;
  
  cout << "Now lets test input:" << endl;

  float c = 0.0;
  float d = 0.0;
  cout << "Skriv et tall:\n	>>>";
  cin >> c;
  cout << "Skriv inn et nytt tall:\n	>>>";
  cin >> d; 

  cout << c << " + " << d << " = " << (c+d) << endl;
  
  int e = 0;
  cout << "\n\nNå, skriv et heltall (helst 2):\n     >>>";
  cin >> e;
  if (e == 2) {
	  cout << "Takk for at du skrev 2 :)" << endl;
  } else {
	  cout << "Du er en dust som ikke skrev 2 :(" << endl;
  }
  
  bool bol  = true;
  cout << bol << " <---- Dette er TRUE" << endl;
  return 0;
  }


