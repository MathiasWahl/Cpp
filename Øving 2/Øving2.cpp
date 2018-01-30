#include <iomanip>
#include<iostream>
#include <cmath>
#include <string>

using namespace std;


void inputAndPrintInteger(){
	int myInteger;
	cout << "Write an integer:\n	>>> ";
	cin >> myInteger;
	cout << myInteger << " was your integer." << endl;
}

int inputInteger(){
        int myInteger;
        cout << "Write an integer:\n    >>> ";
	cin >> myInteger;
	return myInteger;
}

double inputDouble(){
        double myDouble;
        cout << "\nWrite a double:\n    >>> ";
        cin >> myDouble;
        return myDouble;
}


//Bruker inputInteger i metoden under da den rerurnerer et heltall som kan brukes videre (slik jeg gjør for å gi values til first og second
void inputIntegersAndPrintSum(){
	cout << "The next two integers will be added together." <<  endl;
	int first = inputInteger();
	cout << "Now for the second number:" << endl;
	int second = inputInteger();
	cout << "Your numbers were " << first << " and " << second << ". " << first << " + " << second << " = " << (first + second) << endl;
}

bool isOdd(int check){
	if ((check % 2) == 0){
		return false;
	}
	return true;
}

void printHumanReadableTime(){

	cout << "\nNow we will translate a given number of seconds into hours, minutes and seconds. Please enter a number (of seconds) to be translated:\n    >>> ";
	int totalSeconds;
	cin >> totalSeconds;

	int hours = (totalSeconds / 3600);
	int minutes = ( (totalSeconds % 3600) / 60);
	int seconds = (totalSeconds % 60);
	cout << totalSeconds << " seconds equals " << hours << " hour(s) " << minutes << " minute(s) and " << seconds << " seconds.\n" << endl;
}


// Jeg velger her å bestemme på forhånd hvor mange tall som skal summeres, og kan derfor bruke en for-løkke fra 1 til det bestemte tallet.
// Om jeg skkulle ha valgt metoden som stopper dersom input er 0, hadde det vært gunsig med en while-løkke:
// 	while (input != 0){
// 		total += input;
// 		cin >> input;
// 		}


void inputIntegersUsingLoopAndPrintSum(){
	int numberOfInts;
	cout << "Select how many numbers to add:\n    >>> ";
	cin >> numberOfInts;
	int current;
	int total=0;
	for (int i = 1; i <= numberOfInts; i++){
		cout << "Number " << i << ":\n    >>> ";
		cin >> current;
		total += current;
	}
	cout << "\n\nThe total sum of your " << numberOfInts << " numbers is " << total << endl;
}


//I denne metoden kan man ikke bruke integer fordi det ville flooret både når man gir input og når man gir output.
//Valgte å bruke void funskjon da jeg (til nå) ikke ser at verdiene skal brukes videre.
void convertCash(){
	double EUR;
	double NOK = -1.0;
	while ( NOK < 0){
		cout << "Please enter a positive number below:" << endl;
		cout << "How many NOK to convert to EUR?" ;
		NOK = inputDouble();
	}
	EUR = (NOK/9.64);
	cout << fixed;
	cout << setprecision(2);
	cout << "Your amount equivilates to " << EUR << " Euros. "<< endl;
}


void generateTable(){
	int w, h;
	cout << "Select width: -->" ;
	cin >> w;
	cout <<"\nSelect Height: -->" ;
	cin >> h;
	string table = "";
	for (int i = 1; i <=  h; i++){
		string str = "| ";
		for (int j = 1; j <= w; j++){
		str = str + to_string(i*j) + " | ";
		}
		table = table + str + "\n";

	}
	cout << table << endl;

}

/////////FUNKSJONER/////////

double discriminant(double a, double b, double c){
	return (pow(b,2) - 4*a*c);
}

void printRealRoots(double a, double b, double c){
	double disc = discriminant(a,b,c);
	if (disc == 0){
		cout << "There is one solution, x = " << -b/(2*a);
	} else if (disc > 0){
		double s1 = (-b + sqrt(disc))/(2*a);
		double s2 = (-b - sqrt(disc))/(2*a);
		cout << "There are two solutions: x =  " << s1 << " and x = " << s2 << endl;
	}
	else {
		cout << "There are no solutions." << endl;
	}
}

void solveQuadraticEquations(){
	double a,b,c;
	cout << "Expression on the form ax^2 + bx + c. Please enter a, b and c: \na: >>> ";
	cin >> a;
	cout << "\nb: >>> ";
	cin >> b;
	cout << "\nc: >>> ";
	cin >> c;
	printRealRoots(a,b,c);
}


/////////LOANS/////////

void calculateLoanPayments(double loan, double rente){
	double remaining = loan;
	string info = "Year: \tPayment: \tRemaining:";
	for (int y = 1; y <= 10; y++){
		double payment = loan/10 + remaining*rente/100;
		remaining -= loan/10;
		info += "\n" +  to_string(y) + "\t" +to_string((int)payment) + "     \t" + to_string((int)remaining);
	}
	cout << info;
}

void LoanUI(){
	double loan, interest;
	cout << "We need to know te size of the loan (nok) and interest (in %). \nHow much money?\n	>>>";
	cin >> loan;
	cout << "\nAnd how much interest (in %)?\n	>>>";
	cin >> interest;
	cout << "Here is your payment plan over 10 years:" << endl;
	calculateLoanPayments(loan, interest);
}



int main(){

	/*
	inputAndPrintInteger();
	cout << "\nLets try that again. \n Write an integer:\n    >>> ";
	int yourInt;
	cin >> yourInt;

	cout << yourInt << " was your integer.\n" << endl;
	inputIntegersAndPrintSum();

	cout << "\nNow we will translate a given number of seconds into hours, minutes and seconds. Please enter a number (of seconds) to be translated:\n    >>> ";
	int time;
	cin >> time;
	printHumanReadableTime(time);
	inputIntegersUsingLoopAndPrintSum();
	double number = inputDouble();
	cout << number << endl;
	convertCash();
	*/

	int choice;
	while (true){
		cout << "\nChoose function: 	\n0: Exit 	\n1: Add two numbers	\n2: Add n numbers	\n3: Convert NOK' to EUR		\n4: Convert time	\n5: Generate multitable 	\n6: Solve Quadratic Equations  \n7: Calculate Loan Payments \n	>>> " ;
		cin >> choice;
		bool leave = 0;
		switch(choice){
			case 0:
				cout << "Bye-bye!" << endl ;
				leave = 1;
				break;
			case 1:
				inputIntegersAndPrintSum();
				break;
			case 2:
				inputIntegersUsingLoopAndPrintSum();
				break;
			case 3:
				convertCash();
				break;
			case 4:
				printHumanReadableTime();
				break;
			case 5:
				generateTable();
				break;
			case 6:
				solveQuadraticEquations();
				break;
			case 7:
				LoanUI();
				break;
			default:
				cout << "Invalid option. Try again." << endl;
		}
		if (leave){
			break;
		}
	}

	return 0;
}
