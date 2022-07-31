#ifndef INC_20F_FLT_PLN_PATH_H
#define INC_20F_FLT_PLN_PATH_H

#include "DSString.h"
#include "DSList.h"
#include "Destination.h"

//This class contains characteristics of a path of a flight plan.
class Path {
private:
    DSList<Destination> connections;    //list of connected flight destinations
    int time;                           //total time used in flight path
    double cost;                        //total cost used in flight path

public:
    Path();

    void addConnection(Destination);
    void printPath(ofstream &fout);
    void calculateTC();

    int getTime();
    double getCost();

};

#endif //INC_20F_FLT_PLN_PATH_H
