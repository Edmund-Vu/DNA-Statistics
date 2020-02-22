#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

dnaStats::dnaStats(){
  string dnaString;
  int lineCount;
  int sum = 0;
  int nucleoTotal = 0;
  int squaredDiff = 0;
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
    if(c == '\n'){ //checks whether the read character is a newline
      lineCount++; //tracks total new lines in the file
    } else{
    inStream.get(c);
    dnaString += c;
  }
}

void dnaStats::calcStats(){
  int countLine; // tracks the number of lines read

  for(int i = 0; i < dnaString.size(); ++i){
    if(dnaString[i] != '\n'){
      nucleoTotal++;
    } else{
      countLine++;
      squaredDiff += (nucleoTotal - mean)^2;
      if(countLine == lineCount){
        sum = nucleoTotal;
        mean = sum / lineCount;
        variance = squaredDiff - nucleoTotal;
        stDev = Sqrt(variance);
      }
    }
  }
  cout << "The sum of the length of the DNA strings is: " << sum << endl;
  cout << "The mean of the length of the DNA strings is: " << mean << endl;
  cout << "The variance of the length of the DNA strings is; " < variance << endl;
  cout << "The standard deviation of the length of the DNA strings is: " << stDev << endl;
