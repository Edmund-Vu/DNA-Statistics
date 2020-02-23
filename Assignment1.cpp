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
}

dnaStats::~dnaStats(){

}

void readFromFile(string input){
  int lineCount = 0;
  string dnaString = "";
  ifstream inFile;
  inFile.open(input);
  char c;

  while(!inFile.eof()){
    if(c == '\n'){ //checks whether the read character is a newline
      lineCount++; //tracks total new lines in the file
    }
    inFile.get(c);
    dnaString += c;
  }
}

void dnaStats::calcStats(){
  int countLine = 0;; // tracks the number of lines read

  for(int i = 0; i < dnaString.size(); ++i){
    if(dnaString[i] != '\n'){
      nucleoTotal++;
    } else{
      countLine++;
      squaredDiff += pow((nucleoTotal - mean), 2);
      if(countLine == lineCount){
        sum = nucleoTotal;
        mean = sum / lineCount;
        variance = squaredDiff - nucleoTotal;
        stDev = sqrt(variance);
      }
    }
  }
  cout << "The sum of the length of the DNA strings is: " << sum << endl;
  cout << "The mean of the length of the DNA strings is: " << mean << endl;
  cout << "The variance of the length of the DNA strings is; " << variance << endl;
  cout << "The standard deviation of the length of the DNA strings is: " << stDev << endl;
}

void calcProb(){
  double relProbAA = 0.0;
  double relProbAC = 0.0;
  double relProbAT = 0.0;
  double relProbAG = 0.0;

  double relProbCA = 0.0;
  double relProbCC = 0.0;
  double relProbCT = 0.0;
  double relProbCG = 0.0;

  double relProbTA = 0.0;
  double relProbTC = 0.0;
  double relProbTT = 0.0;
  double relProbTG = 0.0;

  double relProbGA = 0.0;
  double relProbGC = 0.0;
  double relProbGT = 0.0;
  double relProbGG = 0.0;

  for(int i = 0; i < dnaString.size(); ++i){
    // First nucleotide A
    if(dnaString[i] == 'a' || dnaString[i] == 'A'){
      if(dnaString[i+1] == 'a' || dnaString[i] == 'A'){
        relProbAA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        relProbAC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        relProbAT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        relProbAG += 1;
      }
    }
    // First nucleotide C
    else if(dnaString[i] == 'c' || dnaString[i] == 'C'){
      if(dnaString[i+1] == 'a' || dnaString[i+1] == 'A'){
        relProbCA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        relProbCC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        relProbCT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        relProbCG += 1;
      }
    }
    // First nucleotide T
    else if(dnaString[i] == 't' || dnaString[i] == 'T'){
      if(dnaString[i+1] == 'a' || dnaString[i+1] == 'A'){
        relProbTA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        relProbTC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        relProbTT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        relProbTG += 1;
      }
    }
    //First nucleotide G
    else if(dnaString[i] == 'g' || dnaString[i] == 'G'){
      if(dnaString[i+1] == 'a' || dnaString[i+1] == 'A'){
        relProbGA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        relProbGC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        relProbGT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        relProbGG += 1;
      }
    }
  }
  cout << "The relative probability of each bigram is as follows: " << endl;

  cout << "AA: " << relProbAA/nucleoTotal << endl;
  cout << "AC: " << relProbAC/nucleoTotal << endl;
  cout << "AT: " << relProbAT/nucleoTotal << endl;
  cout << "AG: " << relProbAG/nucleoTotal << endl;

  cout << "CA: " << relProbCA/nucleoTotal << endl;
  cout << "CC: " << relProbCC/nucleoTotal << endl;
  cout << "CT: " << relProbCT/nucleoTotal << endl;
  cout << "CG: " << relProbCG/nucleoTotal << endl;

  cout << "TA: " << relProbTA/nucleoTotal << endl;
  cout << "TC: " << relProbTA/nucleoTotal << endl;
  cout << "TT: " << relProbTT/nucleoTotal << endl;
  cout << "TG: " << relProbTG/nucleoTotal << endl;

  cout << "GA: " << relProbGA/nucleoTotal << endl;
  cout << "GC: " << relProbGC/nucleoTotal << endl;
  cout << "GT: " << relProbGT/nucleoTotal << endl;
  cout << "GG: " << relProbGG/nucleoTotal << endl;
}
