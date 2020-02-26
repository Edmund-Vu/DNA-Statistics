#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dnaStats{
  public:
    dnaStats();
    ~dnaStats();

    void readFromFile(ifstream& inputStream);
    void calcSumAndMean(ofstream& outputStream);
    void calcVarAndDev(ofstream& outputStream);
    void calcProb(ofstream& outputStream);
    void gaussDist(ofstream& outStream);

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
