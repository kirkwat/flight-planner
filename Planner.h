//
// Created by watso on 11/2/2020.
//

#ifndef INC_20F_FLT_PLN_PLANNER_H
#define INC_20F_FLT_PLN_PLANNER_H

#include "DSAdjList.h"
#include "DSString.h"
#include "DSList.h"
#include "DSStack.h"
#include "Flight.h"
#include "Path.h"

class Planner {
private:
    DSAdjList flights;
    DSList<Flight> requestedPaths;

public:
    Planner();
    void getFlights(char*);
    void findPaths(char*);
    void getRequested(char*);
    void printTopPaths(char*);
    int getNum(DSString);
    bool isInStack(DSStack<DSString>,DSString);
};

#endif //INC_20F_FLT_PLN_PLANNER_H
