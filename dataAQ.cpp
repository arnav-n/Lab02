/*
  See lab description - fill in with data aggregator and query for testing
*/
//TO DO: implement constructor
//implement createStateDemogData
//then implement functions to return extremes
#include "dataAQ.h"
#include <iterator>
#include <map>
#include <iostream>
using namespace std;
dataAQ::dataAQ(){
  map<string, stateDemog> states; 
}
void dataAQ::createStateData(vector<shared_ptr<demogData> > theData){
  //takes in a vector of counties:
  //for each county, check if the state exists in dataAQ's hashmap using map.find()
  //if the state exists, add the county the state's hashmap: <county name, County object>
  //if the state does not exist, create a new key, value pair in the dataAQ hashmap: <state name, State object>
  for(int i= 0;i<theData.size();i++){
    demogData curCounty = *theData[i];
    string statename = curCounty.getState();
    if (states.find(statename) == states.end() ) {
      // not found, create a new State object, push it to the map with key=statename, push the current county to its map
      stateDemog newstate(statename);
      newstate.pushCounty(curCounty);
      states.insert({statename, newstate});
    }else {
      //found, get value at key=statename, and push the county to its map
      states[statename].pushCounty(curCounty);
    }
  }
}

//for all: iterate through the map, storing the current extreme and its corresponding state. at the end,
// return the state that is currently stored. 
string dataAQ::youngestPop(){
  map<string, stateDemog>:: iterator it;
  double curMax = 0;
  string curName = "";

  for (it = states.begin(); it!=states.end(); it++){
      stateDemog d = it->second;
      double totalYoung = d.getpopUnder5();
      double proportion = totalYoung/d.getTotalPop();
      if(proportion>curMax){
          curMax=proportion;
          curName=it->first;
      }
  }
  return curName;
}
string dataAQ::teenPop(){
  map<string, stateDemog>:: iterator it;
  double curMax = 0;
  string curName = "";

  for (it = states.begin(); it!=states.end(); it++){
      stateDemog d = it->second;
      double totalTeen = d.getpopUnder18();
      double proportion = totalTeen/d.getTotalPop();
      if(proportion>curMax){
          curMax=proportion;
          curName=it->first;
      }
  }
  return curName;
}
string dataAQ::wisePop(){
  map<string, stateDemog>:: iterator it;
  double curMax = 0;
  string curName = "";

  for (it = states.begin(); it!=states.end(); it++){
      stateDemog d = it->second;
      double totalOld = d.getpopOver65();
      double proportion = totalOld/d.getTotalPop();
      if(proportion>curMax){
          curMax=proportion;
          curName=it->first;
      }
  }
  return curName;
}
string dataAQ::underServeHS(){
  map<string, stateDemog>:: iterator it;
  double curMin = 100;
  string curName = "";

  for (it = states.begin(); it!=states.end(); it++){
      stateDemog d = it->second;
      double totalDiplomas = d.getHSup();
      double proportion = totalDiplomas/d.getTotalPop();
      if(proportion<curMin){
          curMin=proportion;
          curName=it->first;
      }
  }
  return curName;
}
string dataAQ::collegeGrads(){
  map<string, stateDemog>:: iterator it;
  double curMax = 0;
  string curName = "";

  for (it = states.begin(); it!=states.end(); it++){
      stateDemog d = it->second;
      double totalGrads = d.getBAup();
      double proportion = totalGrads/d.getTotalPop();
      if(proportion>curMax){
          curMax=proportion;
          curName=it->first;
      }
  }
  return curName;
}