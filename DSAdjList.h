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
    DSList<DSList<City>> flights;

public:
    DSAdjList();
    //addEdge();

};

#endif //INC_20F_FLT_PLN_DSADJLIST_H
