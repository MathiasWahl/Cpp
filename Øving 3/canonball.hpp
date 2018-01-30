#include<cmath>
#include<iostream>
using namespace std;


double accY();

double velY(float initVelocityY, float time);

double posX(float initPosition, float initVelocityX, float time);

double posY(float initPosition, float initVelocityY, float time);

void printTime(double time);

float flightTime(float initVelY);

void getUserInput(double *theta, double *absVelocity);

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

void playTargetPractice();
