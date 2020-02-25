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
  double probA = 0.0;
  double probC = 0.0;
  double probT = 0.0;
  double probG = 0.0;
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
  int countLine = 0; // tracks the number of lines read

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

  int bigramCount = 0;

  for(int i = 0; i < dnaString.size(); ++i){
    // First nucleotide A
    if(dnaString[i] == 'a' || dnaString[i] == 'A'){
      probA += 1;
      if(dnaString[i+1] == 'a' || dnaString[i] == 'A'){
        if(relProbAA == 0){
          bigramCount += 1;
        }
        relProbAA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        if(relProbAC == 0){
          bigramCount += 1;
        }
        relProbAC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        if(relProbAT == 0){
          bigramCount += 1;
        }
        relProbAT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        if(relProbAG == 0){
          bigramCount += 1;
        }
        relProbAG += 1;
      }
    }
    // First nucleotide C
    else if(dnaString[i] == 'c' || dnaString[i] == 'C'){
      probC += 1;
      if(dnaString[i+1] == 'a' || dnaString[i+1] == 'A'){
        if(relProbCA == 0){
          bigramCount += 1;
        }
        relProbCA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        if(relProbCC == 0){
          bigramCount += 1;
        }
        relProbCC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        if(relProbCT == 0){
          bigramCount += 1;
        }
        relProbCT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        if(relProbCG == 0){
          bigramCount += 1;
        }
        relProbCG += 1;
      }
    }
    // First nucleotide T
    else if(dnaString[i] == 't' || dnaString[i] == 'T'){
      probT += 1;
      if(dnaString[i+1] == 'a' || dnaString[i+1] == 'A'){
        if(relProbTA == 0){
          bigramCount += 1;
        }
        relProbTA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        if(relProbTC == 0){
          bigramCount += 1;
        }
        relProbTC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        if(relProbTT == 0){
          bigramCount += 1;
        }
        relProbTT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        if(relProbTG == 0){
          bigramCount += 1;
        }
        relProbTG += 1;
      }
    }
    //First nucleotide G
    else if(dnaString[i] == 'g' || dnaString[i] == 'G'){
      probG += 1;
      if(dnaString[i+1] == 'a' || dnaString[i+1] == 'A'){
        if(relProbGA == 0){
          bigramCount += 1;
        }
        relProbGA += 1;
      }
      else if(dnaString[i+1] == 'c' || dnaString[i+1] == 'C'){
        if(relProbGC == 0){
          bigramCount += 1;
        }
        relProbGC += 1;
      }
      else if(dnaString[i+1] == 't' || dnaString[i+1] == 'T'){
        if(relProbGT == 0){
          bigramCount += 1;
        }
        relProbGT += 1;
      }
      else if(dnaString[i+1] == 'g' || dnaString[i+1] == 'G'){
        if(relProbGG == 0){
          bigramCount += 1;
        }
        relProbGG += 1;
      }
    }
  }

  outputStream << "The relative probability of each nucleotide is as follows: " << endl;

  outputStream << "A: " << probA/nucleoTotal << endl;
  outputStream << "C: " << probC/nucleoTotal << endl;
  outputStream << "T: " << probT/nucleoTotal << endl;
  outputStream << "G: " << probG/nucleoTotal << endl;

  outputStream << "The relative probability of each bigram is as follows: " << endl;

  outputStream << "AA: " << relProbAA/bigramCount << endl;
  outputStream << "AC: " << relProbAC/bigramCount << endl;
  outputStream << "AT: " << relProbAT/bigramCount << endl;
  outputStream << "AG: " << relProbAG/bigramCount << endl;

  outputStream << "CA: " << relProbCA/bigramCount << endl;
  outputStream << "CC: " << relProbCC/bigramCount << endl;
  outputStream << "CT: " << relProbCT/bigramCount << endl;
  outputStream << "CG: " << relProbCG/bigramCount << endl;

  outputStream << "TA: " << relProbTA/bigramCount << endl;
  outputStream << "TC: " << relProbTA/bigramCount << endl;
  outputStream << "TT: " << relProbTT/bigramCount << endl;
  outputStream << "TG: " << relProbTG/bigramCount << endl;

  outputStream << "GA: " << relProbGA/bigramCount << endl;
  outputStream << "GC: " << relProbGC/bigramCount << endl;
  outputStream << "GT: " << relProbGT/bigramCount << endl;
  outputStream << "GG: " << relProbGG/bigramCount << endl;

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
