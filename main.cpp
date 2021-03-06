#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "demogData.h"
#include "parse.h"
#include "dataAQ.h"
using namespace std;
int main() {
    //read in a csv file and create a vector of objects representing each counties data
    std::vector<shared_ptr<demogData>> theData = read_csv(
            "county_demographics.csv", DEMOG);

    //debug print out
    // for (const auto &obj : theData) {
    //     std::cout << *obj << std::endl;
    // }

    dataAQ aggregated;
    aggregated.createStateData(theData);
    string youngest = aggregated.youngestPop();
    string teenest = aggregated.teenPop();
    string wisest = aggregated.wisePop();
    string diplomaest = aggregated.underServeHS();
    string graddest = aggregated.collegeGrads();

    cout<<"* the state that needs the most pre-schools"<<endl;
    cout<<aggregated.states[youngest];

    cout<<"* the state that needs the most high schools"<<endl;
    cout<<aggregated.states[teenest];

    cout<<"* the state that needs the most vaccines"<<endl;
    cout<<aggregated.states[wisest];

    cout<<"* the state that needs the most help with education"<<endl;
    cout<<aggregated.states[diplomaest];

    cout<<"* the state with most college grads"<<endl  ;
    cout<<aggregated.states[graddest];

    // map<string, stateDemog>:: iterator it;
    //debug print out
    // for (it = aggregated.states.begin(); it!=aggregated.states.end(); it++){
    //     cout<<it->second<<endl;
    // }
	// cout << "There are " << aggregated.states.size() << " states/territories in data set." << endl;

    
    return 0;
}

