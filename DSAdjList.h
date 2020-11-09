//
// Created by watso on 11/2/2020.
//

#ifndef INC_20F_FLT_PLN_DSADJLIST_H
#define INC_20F_FLT_PLN_DSADJLIST_H

#include "DSList.h"
#include "Origin.h"
#include "Destination.h"

using namespace std;

class DSAdjList{
private:
    DSList<Origin> flightPaths;

public:
    DSAdjList();
    void addFlight(DSString,DSString);
    void addFlight(DSString,DSString,int,int,DSString);
    int findOrigin(DSString);

    Origin& originAt(int);
    Destination getDestinationAt(int,int);
    Origin getOriginAt(int);
    int getSize();

};

#endif //INC_20F_FLT_PLN_DSADJLIST_H
