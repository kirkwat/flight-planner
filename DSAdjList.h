//
// Created by watso on 11/2/2020.
//

#ifndef INC_20F_FLT_PLN_DSADJLIST_H
#define INC_20F_FLT_PLN_DSADJLIST_H

#include "DSList.h"
#include "City.h"

using namespace std;

class DSAdjList{
private:
    DSList<City> flightPaths;

public:
    DSAdjList();
    void addFlight(DSString,DSString);
    int findOrigin(DSString);
    City getOriginAt(int);
    City getDestinationAt(int,int);

};

#endif //INC_20F_FLT_PLN_DSADJLIST_H
