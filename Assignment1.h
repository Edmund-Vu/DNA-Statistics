/* Edmund Vu
   ID: 2325913
   Email: evu@chapman.edu
   CPSC 350
   Assignment 1 - DNA Strings

   The assignment is to create an analysis program which calculates basic statistics
   from a file of DNA strings.
*/
#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dnaStats{
  public:
    dnaStats(); // Constructor
    ~dnaStats(); // Destructor

    void readFromFile(ifstream& inputStream); // Takes input and reads from the file
    void calcSumAndMean(ofstream& outputStream); // Calcualtes the Sum and Mean
    void calcVarAndDev(ofstream& outputStream); // Calculates the Variance and Standard Deviation
    void calcProb(ofstream& outputStream); // Calculates the probabilities of each nucleotide and nucleotide bigram
    void gaussDist(ofstream& outStream); // Creates 1000 random sequences that follow the input statistics

    string dnaString;
    int lineCount;
    int bigramCount = 0;
    int countLine = -1;
    float sum;
    float nucleoTotal;
    float nucleoCount;
    float squaredDiff;
    float mean;
    float variance;
    float stDev;
    float probA = 0.0;
    float probC = 0.0;
    float probT = 0.0;
    float probG = 0.0;
    float relProbAA = 0.0;
    float relProbAC = 0.0;
    float relProbAT = 0.0;
    float relProbAG = 0.0;
    float relProbCA = 0.0;
    float relProbCC = 0.0;
    float relProbCT = 0.0;
    float relProbCG = 0.0;;
    float relProbTA = 0.0;;
    float relProbTC = 0.0;;
    float relProbTT = 0.0;;
    float relProbTG = 0.0;;
    float relProbGA = 0.0;;
    float relProbGC = 0.0;;
    float relProbGT = 0.0;;
    float relProbGG = 0.0;;
  private:

};
#endif /* ASSIGNMENT1 */
