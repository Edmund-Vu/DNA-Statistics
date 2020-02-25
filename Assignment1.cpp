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

void dnaStats::readFromFile(ifstream& inputStream){
  int lineCount = 0;
  char c;
  while(!inputStream.eof()){
    if(c == '\n'){ //checks whether the read character is a newline
      lineCount++; //tracks total new lines in the file
    }
    inputStream.get(c);
    dnaString += c;
  }
}

void dnaStats::calcStats(ofstream& outputStream){
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
  outputStream << "The sum of the length of the DNA strings is: " << sum << endl;
  outputStream << "The mean of the length of the DNA strings is: " << mean << endl;
  outputStream << "The variance of the length of the DNA strings is; " << variance << endl;
  outputStream << "The standard deviation of the length of the DNA strings is: " << stDev << endl;
}

void dnaStats::calcProb(ofstream& outputStream){
  double probA = 0.0;
  double probC = 0.0;
  double probT = 0.0;
  double probG = 0.0;

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
      probA += 1;
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
      probC += 1;
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
      probT += 1;
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
      probG += 1;
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

  probA = probA/nucleoTotal;
  probC = probC/nucleoTotal;
  probT = probT/nucleoTotal;
  probG = probG/nucleoTotal;

  outputStream << "The relative probability of each bigram is as follows: " << endl;

  outputStream << "AA: " << relProbAA/nucleoTotal << endl;
  outputStream << "AC: " << relProbAC/nucleoTotal << endl;
  outputStream << "AT: " << relProbAT/nucleoTotal << endl;
  outputStream << "AG: " << relProbAG/nucleoTotal << endl;

  outputStream << "CA: " << relProbCA/nucleoTotal << endl;
  outputStream << "CC: " << relProbCC/nucleoTotal << endl;
  outputStream << "CT: " << relProbCT/nucleoTotal << endl;
  outputStream << "CG: " << relProbCG/nucleoTotal << endl;

  outputStream << "TA: " << relProbTA/nucleoTotal << endl;
  outputStream << "TC: " << relProbTA/nucleoTotal << endl;
  outputStream << "TT: " << relProbTT/nucleoTotal << endl;
  outputStream << "TG: " << relProbTG/nucleoTotal << endl;

  outputStream << "GA: " << relProbGA/nucleoTotal << endl;
  outputStream << "GC: " << relProbGC/nucleoTotal << endl;
  outputStream << "GT: " << relProbGT/nucleoTotal << endl;
  outputStream << "GG: " << relProbGG/nucleoTotal << endl;

}

void dnaStats::gaussDist(ofstream& outputStream){
  double a = (double) rand() / (RAND_MAX);
  double b = (double) rand() / (RAND_MAX);
  double C = sqrt((-2*log(a)) * (cos(2*(M_PI)*b)));
  double D = (stDev*C) + mean;

  for(int i = 0; i < 1000; ++i){
    for(int j = 0; j < D; ++j){
      double rangeOfProb = rand() % 100;
      if(rangeOfProb <= probA){
        outputStream << "A";
      } else if(rangeOfProb <= probA + probC){
        outputStream << "C";
      } else if(rangeOfProb <= probA + probC + probT){
        outputStream << "T";
      } else{
        outputStream << "G";
      }
    }
    outputStream << "\n";
  }
}
