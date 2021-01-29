/*
  class to represent state data - fairly redundent at this point will be improved
  See lab descirption for more information on filling in the implementation of the state demographic data
*/
#include "stateDemog.h"
#include <iomanip>
//TO DO: implement push county function to add a county the state's hashmap, and also add that county's 
// demographic data to the state's demographic data

stateDemog::stateDemog(string statename){
    this->name = statename;
    this->popOver65=0;
    this->popUnder18=0;
    this->popUnder5=0;
    this->BAup=0;
    this->HSup=0;
    this->totalPop=0; 
}
stateDemog::stateDemog(){
    this->name = "";
    this->popOver65=0;
    this->popUnder18=0;
    this->popUnder5=0;
    this->BAup=0;
    this->HSup=0;
    this->totalPop=0; 
}
void stateDemog::pushCounty(demogData county){
  string countyName = county.getName();
  counties.insert({countyName, county});
  totalPop += county.getTotalPop();
  popOver65 += (county.getpopOver65() * county.getTotalPop());
  popUnder18 += (county.getpopUnder18() * county.getTotalPop());
  popUnder5 += (county.getpopUnder5() * county.getTotalPop());
  
  BAup += (county.getBAup() * county.getTotalPop());
  HSup += (county.getHSup() * county.getTotalPop());
}

std::ostream& operator<<(std::ostream &out, const stateDemog &SD) {
    int intPop = SD.totalPop;
    int oldPop = SD.popOver65/100;
    int teenPop = SD.popUnder18/100;
    int youngPop = SD.popUnder5/100;

    int collegePop = SD.BAup/100;
    int diplomaPop = SD.HSup/100;
    out << "State Info: " << SD.name;
    out << " Number of Counties: " << SD.counties.size();
    out << "\nPopulation info:\n(over 65): " << setprecision (2) << fixed<< SD.popOver65/SD.totalPop<< "% and total: " << fixed << oldPop;
    out << "\n(under 18): " << setprecision (2) << fixed<< SD.popUnder18/SD.totalPop<< "% and total: " << fixed << teenPop;
    out << "\n(under 5): " << setprecision (2) << fixed<< SD.popUnder5/SD.totalPop<< "% and total: " <<fixed << youngPop;
    out << "\nEducation info:";
    out << "\n(Bachelor or more): " <<setprecision (2) << fixed<< SD.BAup/SD.totalPop <<"% and total: "  << fixed << collegePop;
    out << "\n(high school or more): " <<setprecision (2) << fixed<< SD.HSup/SD.totalPop<< "% and total: "  << fixed << diplomaPop;
    out << "\nTotal population: " << fixed << intPop << "\n"; 
    return out;
}