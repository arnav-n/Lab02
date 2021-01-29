/*
  class to represent state data - fairly redundent at this point will be improved
  See lab descirption for more information on filling in the implementation of the state demographic data
*/
using namespace std;
#include <string>
#include<iostream>
#include <map>
#include "demogData.h"
#include <algorithm>

class stateDemog{
  public:
    //constructor with parameter name
    stateDemog(string statename);

    stateDemog();
    //getters
    string getName() { return name; }
    double getpopOver65() { return popOver65; }
    double getpopUnder18() { return popUnder18; }
    double getpopUnder5() { return popUnder5; }
    double getBAup() { return BAup; }
    double getHSup() { return HSup; }
    double getTotalPop() { return totalPop; }
    int getNumOfCounties() { return numOfCounties; }
    map<string, demogData> getCounties() { return counties; }

    void pushCounty (demogData county);
    friend std::ostream& operator<<(std::ostream &out, const stateDemog &SD);

  private:
    //unlike county objects, state objects store the total population for all variables, not the propotion
     string name;
     int numOfCounties;
     double popOver65;
     double popUnder18;
     double popUnder5;
    
     double BAup;
     double HSup;

     double totalPop; 
    map<string, demogData> counties; 

};
  
