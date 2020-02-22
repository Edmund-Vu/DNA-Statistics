#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dnaStats{
  private:
    string dnaString;
    int lineCount;
    int sum;
    int nucleoTotal;
    int squaredDiff;
    double mean;
    double variance;
    double stDev;
    double relProbA;
    double relProbC;
    double relProbT;
    double relProbG;
  public:
    dnaStats();
    ~dnaStats();

    void readFromFile(string input);
    void calcStats();
    void calcProb();
    void gaussDist();
};
