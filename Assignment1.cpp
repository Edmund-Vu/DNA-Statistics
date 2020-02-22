#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

dnaStats::dnaStats(){
  string dnaString;
  int lineCount;
  int nucleoCount = 0;
  int sum = 0;
  int nucleoTotal = 0;
  double mean = 0.0;
  double variance = 0.0;
  double stDev = 0.0;
  double relProbA = 0;
  double relProbC = 0;
  double relProbT = 0;
  double relProbG = 0;
}

dnaStats::~dnaStats(){

}

void readFromFile(string input){
  ifstream inFile;
  inFile.open(input);
  char c;

  while(!inStream.eof()){
    if(c == '\n'){
      countLine++;
    }
    inStream.get(c);
    dnaString += c;
  }
}

void dnaStats::calcStats(){
  int count;
  int nucleoCount = 0;

  for(int i = 0; i < dnaString.size(); ++i){
    if(dnaString[i] != '\n'){
      nucleoCount++;
    } else{
      count++;
      if(count == countLine){
        sum = nucleoCount;
        mean = sum / countLine;
        break;
      }
    }
  }
  cout << "The sum of the length of the DNA strings is: " << sum << endl;
  cout << "The mean of the length of the DNA strings is: " << mean << endl;
}
