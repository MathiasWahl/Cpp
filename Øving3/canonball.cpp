#include "canonball.hpp"
#import "utilities.cpp"
#include <cmath>
#include <iostream>

using namespace std;

double accY(){
  return -9.81;
}

double velY(float initVelocityY, float time){
  return initVelocityY + accY()*time;
}

double posX(float initPosition, float initVelocityX, float time){
  return initPosition+ initVelocityX*time;
}

double posY(float initPosition, float initVelocityY, float time){
  return initPosition + initVelocityY*time + (accY()*pow(time,2))/2;
}

void printTime(double time){
  int hours = ((int)time / 3600);
  int minutes = (((int)time % 3600) / 60);
  int seconds = ((int)time % 60);

  cout << "Tid: " << hours << " timer, " << minutes << " minutter, "<< seconds << " sekunder." << endl;
}

float flightTime(float initVelY){
  return (-2*initVelY)/accY();
}

// Ber brukeren om to tall, en vinkel (i grader), og en fart.
// Disse verdiene skal lagres i minnet som pekerne
// theta og absVelocity peker paa.
void getUserInput(double *theta, double *absVelocity){
  int angle, velocity;
  cout << "\nPlease enter shooter angle(deg): \n\t>>>";
  cin >> angle;
  cout << "\nPlease enter shooting velocity: \n\t>>>";
  cin >> velocity;

  *theta = angle;
  *absVelocity = velocity;
}

//Convert deg to rad
double degToRad(double deg){
  return (deg * 3.14)/180;
}

// Returnerer henholdsvis farten i X-, og Y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity){
  return cos(degToRad(theta))*absVelocity;
}

double getVelocityY(double theta, double absVelocity){
  return sin(degToRad(theta))*absVelocity;
}

// Dekomponerer farten gitt av absVelocity, i X- og Y-komponentene
// gitt vinkelen theta. Disse komponentene lagres i minnet.
void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY){
  *velocityY = getVelocityY(theta, absVelocity);
  *velocityX = getVelocityX(theta, absVelocity);

}

double getDistanceTraveled(double velocityX, double velocityY){
  float time = flightTime(velocityY);
  double distance = posX(0, velocityX, time);
  return distance;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
  double shotLength = getDistanceTraveled(velocityX, velocityY);
  double difference = distanceToTarget - shotLength;
  return difference;
}

void playTargetPractice(){
  double absVelocity, theta, velocityX, velocityY;
  bool hit = false;
  int tries = 1;
  int target = randomWithLimits(25,250);
  while (not (hit) and (tries <= 10)){
    cout << "\n---------------------------------\nThis is try nr " << tries << endl;
    getUserInput(&theta, &absVelocity);
    getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
    double difference = targetPractice(target ,velocityX, velocityY);
    cout << "\nYour ball went " << getDistanceTraveled(velocityX, velocityY) << " meters!" << endl;
      if (difference < -5){
      cout << "\nYou were " << -(difference) << " meters over." << endl;
    } else if (difference > 5){
      cout << "\nYou were " << (difference) << " meters too short." << endl;
    } else {
      cout << "\nYou hit the target! \nYou were only " << abs(difference) << " meters off." << endl;
      hit = true;
    }
    tries += 1;
  }
  if (tries == 10){
    cout << "You have used your ten tries. Better luck next time!";
  }

}
