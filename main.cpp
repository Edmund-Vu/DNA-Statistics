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

    dnaStats a;

    a.readFromFile(in);
    a.calcStats(out);
    a.calcProb(out);

    in.close();
  }
  return 0;
}
