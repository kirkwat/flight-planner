#ifndef INC_20F_FLT_PLN_PLANNER_H
#define INC_20F_FLT_PLN_PLANNER_H

#include "DSAdjList.h"
#include "DSString.h"
#include "DSList.h"
#include "DSStack.h"
#include "Flight.h"
#include "Path.h"

//This class is the launcher of the program and determines all possible flight plans.
//In order to determine the possible and requested flights, the input files must be parsed.
//After parsing the files, the flight plans can be calculated.
class Planner {
private:
    DSAdjList flights;                  //contains all possible flights
    DSList<Flight> requestedPaths;      //contains all requested origin/destination pairs

public:
    Planner();

    void getFlights(char*);
    void findPaths(char*);
    void getRequested(char*);
    void printTopPaths(char*);

    int getNum(DSString);
    bool isInStack(DSStack<Destination>,Destination);
};

#endif //INC_20F_FLT_PLN_PLANNER_H
