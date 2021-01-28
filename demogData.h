#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>

using namespace std;

/*
  class to represent county demographic data
  from CORGIS
*/
class demogData {
  public:
    demogData(string inN, string inS, double in65, double in18,
        double in5) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), BAup(-1), HSup(-1) {
    }
    //step 2
    demogData(string inN, string inS, double in65, double in18,
        double in5, double inBA, double inHS) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), BAup(inBA), HSup(inHS) {
    }

    string getName() { return name; }
    string getState() { return state; }
    double getpopOver65() { return popOver65; }
    double getpopUnder18() { return popUnder18; }
    double getpopUnder5() { return popUnder5; }
    //step 3
    double getBAup() { return BAup; }
    double getHSup() { return HSup
    ; }

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

private:
    const string name;
    const string state;
    const double popOver65;
    const double popUnder18;
    const double popUnder5;
    //step 1
    const double BAup;
    const double HSup;
};
#endif
