#ifndef INC_20F_FLT_PLN_DSADJLIST_H
#define INC_20F_FLT_PLN_DSADJLIST_H

#include "DSList.h"
#include "Origin.h"
#include "Destination.h"

using namespace std;

//This class implements an adjacency list used to determine possible flight plans.
class DSAdjList{
private:
    DSList<Origin> flightPaths; //linked list storing flights

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
