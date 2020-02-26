#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

dnaStats::dnaStats(){

}

dnaStats::~dnaStats(){
  cout << "The analysis of this file has finished." << endl;
}

void dnaStats::readFromFile(ifstream& inputStream){
  char c;
  while(!inputStream.eof()){
    if(c == '\n'){ //checks whether the read character is a newline
      lineCount++; //tracks total new lines in the file
    }
    inputStream.get(c);
    dnaString += c;
  }
}

void dnaStats::calcSumAndMean(ofstream& outputStream){
  for(int i = 0; i < dnaString.size(); ++i){
    if(dnaString[i] != '\n'){
      nucleoTotal += 1;
    } else{
      countLine += 1;
    }
  }
  sum = nucleoTotal;
  mean = nucleoTotal / countLine;
  outputStream << "The sum of the length of the DNA strings is: " << sum << endl;
  outputStream << "The mean of the length of the DNA strings is: " << mean << endl;
}

void dnaStats::calcVarAndDev(ofstream& outputStream){
  double countLine = -1;
  for(int i = 0; i < dnaString.size(); ++i){
    if(dnaString[i] != '\n'){
      nucleoCount += 1;
    } else{
      countLine += 1;
      squaredDiff += pow((nucleoCount - mean), 2);
      nucleoCount = 0;
    }
  }
  squaredDiff = squaredDiff - pow((mean), 2);
  variance = squaredDiff / countLine;
  stDev = sqrt(variance);

  outputStream << "The variance of the length of the DNA strings is: " << variance << endl;
  outputStream << "The standard deviation of the length of the DNA strings is: " << stDev << endl;
}

void dnaStats::calcProb(ofstream& outputStream){
  double nucleoTotal = 0.0;
  string nucleoString = "";
  for(int j = 0; j < dnaString.size(); ++j){
    if(dnaString[j] != '\n'){
      nucleoTotal += 1;
      nucleoString += dnaString[j];
    }
  }

  for(int i = 0; i < nucleoString.size(); ++i){
    // First nucleotide A
    if(nucleoString[i] == 'a' || nucleoString[i] == 'A'){
      probA += 1;
      if(i % 2 == 0){
        if(nucleoString[i+1] == 'a' || nucleoString[i+1] == 'A'){
          relProbAA += 1;
          if(relProbAA == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i+1] == 'c' || nucleoString[i+1] == 'C'){
          relProbAC += 1;
          if(relProbAC == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i+1] == 't' || nucleoString[i+1] == 'T'){
          relProbAT += 1;
          if(relProbAT == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i+1] == 'g' || nucleoString[i+1] == 'G'){
          relProbAG += 1;
          if(relProbAG == 1){
            bigramCount += 1;
          }
        }
      }

      // First nucleotide C
    } else if(nucleoString[i] == 'c' || nucleoString[i] == 'C'){
      probC += 1;
      if(i % 2 == 0){
        if(nucleoString[i+1] == 'a' || nucleoString[i+1] == 'A'){
          relProbCA += 1;
          if(relProbCA == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i+1] == 'c' || nucleoString[i+1] == 'C'){
          relProbCC += 1;
          if(relProbCC == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i+1] == 't' || nucleoString[i+1] == 'T'){
          relProbCT += 1;
          if(relProbCT == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i+1] == 'g' || nucleoString[i+1] == 'G'){
          relProbCG += 1;
          if(relProbCG == 1){
            bigramCount += 1;
          }
        }
      }

      // First nucleotide T
    } else if(nucleoString[i] == 't' || nucleoString[i] == 'T'){
      probT += 1;
      if(i % 2 == 0){
        if(nucleoString[i+1] == 'a' || nucleoString[i+1] == 'A'){
          relProbTA += 1;
          if(relProbTA == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i] == 'c' || nucleoString[i+1] == 'C'){
          relProbTC += 1;
          if(relProbTC == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i] == 't' || nucleoString[i+1] == 'T'){
          relProbTT += 1;
          if(relProbTT == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i] == 'g' || nucleoString[i+1] == 'G'){
          relProbTG += 1;
          if(relProbTG == 1){
            bigramCount += 1;
          }
        }
      }

      // First nucleotide G
    } else if(nucleoString[i] == 'g' || nucleoString[i] == 'G'){
      probG += 1;
      if(i % 2 == 0){
        if(nucleoString[i] == 'a' || nucleoString[i+1] == 'A'){
          relProbGA += 1;
          if(relProbGA == 1){
            bigramCount += 1;
          }
        }else if(nucleoString[i] == 'c' || nucleoString[i+1] == 'C'){
          relProbGC += 1;
          if(relProbGC == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i] == 't' || nucleoString[i+1] == 'T'){
          relProbGT += 1;
          if(relProbGT == 1){
            bigramCount += 1;
          }
        } else if(nucleoString[i] == 'g' || nucleoString[i+1] == 'G'){
          relProbGG += 1;
          if(relProbGG == 1){
            bigramCount += 1;
          }
        }
      }
    }
  }

  probA = probA/nucleoTotal;
  probC = probC/nucleoTotal;
  probT = probT/nucleoTotal;
  probG = probG/nucleoTotal;

  outputStream << "The probability of each nucleotide is as follows: " << endl;

  outputStream << "A: " << probA << endl;
  outputStream << "C: " << probC << endl;
  outputStream << "T: " << probT << endl;
  outputStream << "G: " << probG << endl;

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
  outputStream << "TC: " << relProbTC/bigramCount << endl;
  outputStream << "TT: " << relProbTT/bigramCount << endl;
  outputStream << "TG: " << relProbTG/bigramCount << endl;

  outputStream << "GA: " << relProbGA/bigramCount << endl;
  outputStream << "GC: " << relProbGC/bigramCount << endl;
  outputStream << "GT: " << relProbGT/bigramCount << endl;
  outputStream << "GG: " << relProbGG/bigramCount << endl;

}

void dnaStats::gaussDist(ofstream& outputStream){
  for(int i = 0; i < 1000; ++i){
    float a = ((float) rand() / (RAND_MAX));
    float b = ((float) rand() / (RAND_MAX));
    float C = (sqrt(-2*log(a))) * (cos(2*M_PI*b));
    float D = (stDev*C) + mean;

    for(int j = 0; j < D; ++j){
      float rangeOfProb = ((float) rand() / (RAND_MAX));
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
