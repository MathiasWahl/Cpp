// Øving 1, av Mathias Wahl.
// Slik jeg forstod det trengte jeg kun å levere en .cpp-fil med oppg 2, osm blir denne filen :)

#include<iostream>
#include<cmath>
using namespace std;

//OPPG. 2

// a)
int max(int a,int b){
	if (a > b){
		cout << "A is greater than B" << endl;
		return a;
	} else if (a < b){
		cout << "B is greater than A" << endl;
		return b;
	} else {
		cout << "A and B are equal" << endl;
		return (-1);
	}
}


int fibonacci(int n){
	int a = 0;
	int b = 1;
	int temp = 0;
	cout << "Fibonacci numbers:" << endl;
	for (int x = 1; x <= n; x++){
		cout <<  x << ": " << b << endl;
		temp = b;
		b += a;
		a = temp;
	}
	cout << "---" << endl;
	return b;
}		


int squareNumberSum(int n){
	int totalSum = 0;
	for (int i = 0; i < n; i++){
		totalSum += (i*i);
		cout << (i*i) << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

void triangleNumbersBelow(int n){
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	while (acc < n){
		cout << acc << endl;
		acc += num;
		num += 1;
	}
}

bool isTriangleNumber(int number){
	int acc = 1;
	while (number > 0){
		number -= acc;
		acc += 1;
	}
	return (number == 0);
}

bool isPrime(int n){
	bool primeness = true;
	for (int j = 2; j < n; j++){
		if ((n%j) == 0){
			primeness = false;
			break;
		}
	}
	return primeness;
}

void naivePrimeNumberSearch(int n){
	for (int number = 2; number < n; number ++){
		if (isPrime(number)){
			cout << number << " is a prime." << endl;
		}
	}
}

int findGreatestDivisor(int n){
	for (int divisor = (n-1); n > 0; n --){
		if ((n%divisor) == 0){
			return divisor;
		}
	}	
	return -1; //Letteste formen for exception handling	
}


int main(){
/*	
 	NB! lagde denne kodesnutten før jeg leste main() oppgaven. Lar det stå, den kan ignoreres:
 
	int a = 0.0;
	int b = 0.0;
	cout << "Write A (int): ";
	cin >> a;
	cout << "Write B (int): ";
	cin >> b;

	int largest = max(a,b);
 */

       	cout << "Oppgave a)\n" << max(5,6) <<  endl;
      	 cout << "---" << endl;
      	 
       	cout << "Oppg c): Fibonacci." << endl;
       	fibonacci(10);
		
       	cout << "Oppg d: Sum av kvadrerte tall. Bruker n = 5 og får:" << endl;
       	squareNumberSum(5);
       	cout << "---" << endl; 
      	 
       	cout << "Oppg e: Trekanttall. Bruker n = 20: " << endl;
       	triangleNumbersBelow(20);
       	cout << "Sjekker nå om number = 15 er et trekanttall:" << endl;
       	if  (isTriangleNumber(15)){
		       cout << "True." << endl;
       	} else {
		       cout << "False." << endl;
       	cout << "---" << endl;
      	 }


       	cout << "Oppg f & g: Primtall. Bruker n = 17;" << endl;
       	cout << "Is 17 a prime?" << endl;
       	if (isPrime(17)){
       	         cout << "True." << endl;
       	} else {
       	         cout << "False." << endl;
       	cout << "---" << endl;
       	}       
       	cout << "Prime numbers below 17:" << endl;
       	naivePrimeNumberSearch(17);
       	cout << "---" << endl;
	       
	
	cout << "Oppg h: Største fellesnevner. Bruker n = 50:" << endl;
	cout << findGreatestDivisor(50) << endl;
	cout << "---" << endl;

       	return 0;
}


