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
  public:
    dnaStats();
    ~dnaStats();

    void readFromFile(ifstream& inputStream);
    void calcStats(ofstream& outputStream);
    void calcProb(ofstream& outputStream);
    void gaussDist(ofstream& outStream);
};
