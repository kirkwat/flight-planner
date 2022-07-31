#ifndef INC_20F_FLT_PLN_FLIGHT_H
#define INC_20F_FLT_PLN_FLIGHT_H

#include "DSString.h"
#include "DSList.h"
#include "DSStack.h"
#include "Path.h"
#include "Destination.h"

//This class contains characteristics of possible flight plans for a given origin and destination.
class Flight {
private:
    DSString source;        //origin city
    DSString dest;          //destination city
    DSString effType;       //efficiency type (time or cost)
    DSList<Path> paths;     //possible flight plans
    bool flightPossible;    //if flight is possible or not

public:
    Flight();
    Flight(DSString,DSString,char);

    void storePath(DSStack<Destination>);
    void printPaths(ofstream &fout);
    void sortPaths(int,int);
    void calculatePathsTC();

    void setFlightNotPossible();
    DSString getSource();
    DSString getDest();
};


#endif //INC_20F_FLT_PLN_FLIGHT_H
