#import "utilities.hpp"
#import <cmath>
#import <ctime>
#import <cstdlib>
#import <iostream>

using namespace std;

int randomWithLimits(int Low, int High){
  srand(time(nullptr));
  int randomNum = rand();
  return randomNum % (High - Low + 1) + Low;

}
/*
int main(int argc, char const *argv[]) {
  cout << randomWithLimits(1, 2) << endl;
  return 0;
}
*/
