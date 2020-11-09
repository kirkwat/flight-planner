//
// Created by watso on 11/7/2020.
//

#ifndef INC_20F_FLT_PLN_FLIGHT_H
#define INC_20F_FLT_PLN_FLIGHT_H

#include "DSString.h"
#include "DSList.h"
#include "DSStack.h"
#include "Path.h"
#include "Destination.h"

class Flight {
private:
    DSString source;
    DSString dest;
    DSString effType;
    DSList<Path> paths;
    bool flightPossible;

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
