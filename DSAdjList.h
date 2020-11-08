//
// Created by watso on 11/2/2020.
//

#ifndef INC_20F_FLT_PLN_DSADJLIST_H
#define INC_20F_FLT_PLN_DSADJLIST_H

#include "DSList.h"
#include "Origin.h"

using namespace std;

class DSAdjList{
private:
    DSList<Origin> flightPaths;

public:
    DSAdjList();
    void addFlight(DSString,DSString);
    int findOrigin(DSString);
    Origin getOriginAt(int);
    Origin& originAt(int);
    Destination getDestinationAt(int,int);
    int getSize();

};

#endif //INC_20F_FLT_PLN_DSADJLIST_H
