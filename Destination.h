//
// Created by watso on 11/7/2020.
//

#ifndef INC_20F_FLT_PLN_DESTINATION_H
#define INC_20F_FLT_PLN_DESTINATION_H

#include "DSString.h"
#include "DSList.h"

class Destination {
private:
    DSString cityName;
    //DSList<int> flightTimes;
   // DSList<int> flightCosts;
    //DSList<DSString> airlines;
    int flightTime;
    int flightCost;
    DSString airline;

public:
    Destination();
    Destination(DSString);
    Destination(DSString,int,int,DSString);
    DSString getCityName();
    bool operator== (const Destination&)const;
    void addAirline(int,int,DSString);
    int getTime();
    int getCost();
};


#endif //INC_20F_FLT_PLN_DESTINATION_H
