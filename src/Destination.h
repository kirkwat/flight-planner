#ifndef INC_20F_FLT_PLN_DESTINATION_H
#define INC_20F_FLT_PLN_DESTINATION_H

#include "DSString.h"
#include "DSList.h"

//This class contains characteristics of a flight destination.
class Destination {
private:
    DSString cityName;          //city of destination
    DSList<int> flightTimes;    //time of each flight to destination
    DSList<double> flightCosts; //cost of each flight to destination
    DSList<DSString> airlines;  //airlines used to get to destinaton

public:
    Destination();
    Destination(DSString);
    Destination(DSString,int,int,DSString);
    bool operator== (const Destination&)const;

    void addAirline(int,int,DSString);

    int getAirlinesSize();
    int getTime(int);
    double getCost(int);
    DSString getAirline(int);
    DSString getCityName();
};


#endif //INC_20F_FLT_PLN_DESTINATION_H
