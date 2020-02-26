#include "Assignment1.cpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv){
  ofstream out;
  ifstream in;

  out.open("EdmundVu.out");
  if(out.is_open()){
    out << "Edmund Vu" << endl;
    out << "ID: 2325913" << endl;
    out << "Email: evu@chapman.edu" << endl;
  } else{
    cout << "Failed to open file" << endl;
  }

  while(true){
    string filepath;
    cout << "What is the text file name?" << endl;
    cin >> filepath;

    in.open(filepath.c_str());

    dnaStats *dna = new dnaStats;

    dna -> readFromFile(in);
    dna -> calcSumAndMean(out);
    dna -> calcVarAndDev(out);
    dna -> calcProb(out);
    dna -> gaussDist(out);
    delete dna;
    in.close();

    string userInput;
    cout << "Would you like to input another file? (Y/N)" << endl;
    cin >> userInput;

    if(userInput == "n" || userInput == "N"){
      out.close();
      return 0;
    } else if(userInput == "y" || userInput == "Y"){
      break;
    } else{
      cout << "That is not a valid input." << endl;
      cout << "Please enter only the letter Y for yes, or N for no." << endl;
    }
  }
  return 0;
}
