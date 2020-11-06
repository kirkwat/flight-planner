//
// Created by watso on 11/2/2020.
//

#ifndef INC_20F_FLT_PLN_PLANNER_H
#define INC_20F_FLT_PLN_PLANNER_H

#include "DSAdjList.h"
#include "DSString.h"

class Planner {
private:
    DSAdjList flights;

public:
    Planner();
    void getFlights(char*);
    void findPlans(char*);
    void printTopPaths(char*);
    int getNum(DSString);
};

#endif //INC_20F_FLT_PLN_PLANNER_H
