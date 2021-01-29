/*
  See lab description - fill in with data aggregator and query for testing
*/
#include "demogData.h"
#include "stateDemog.h"
#include <vector>
#include <iostream>
#include <memory>
class dataAQ {
  public:
    dataAQ();
    //function to aggregate the data - this CAN and SHOULD vary per student - depends on how they map
    void createStateData(std::vector<shared_ptr<demogData> > theData);

    //return the name of the state with the largest population under age 5
    string youngestPop();

    //return the name of the state with the largest population under age 18
    string teenPop();

    //return the name of the state with the largest population over age 65
    string wisePop();

    //return the name of the state with the largest population who did not finish high school
    string underServeHS();

    //return the name of the state with the largest population who completed college
    string collegeGrads();


    //additional methods AND data to support above methods.  You are allowed for data to be public
    std::map<string, stateDemog> states; 

 };