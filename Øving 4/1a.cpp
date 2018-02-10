#include <iostream>
using namespace std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
  for (int i = 0; i < numTimes; i++) {
    startValue += increment;
  }
  return startValue;
}

void testCallByValue() {
  int v0 = 5;
  int increment = 2;
  int iterations = 10;
  int result = incrementByValueNumTimes(v0, increment, iterations); std::cout << "v0: " << v0
                  << " increment: " << increment
                  << " iterations: " << iterations
                  << " result: " << result << std::endl;
}

int main() {
  testCallByValue();
  return 0;
}
