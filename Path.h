//
// Created by watso on 11/8/2020.
//

#ifndef INC_20F_FLT_PLN_PATH_H
#define INC_20F_FLT_PLN_PATH_H

#include "DSString.h"
#include "DSList.h"
#include "Destination.h"

class Path {
private:
    DSList<Destination> connections;
    int time;
    double cost;

public:
    Path();

    void addConnection(Destination);
    void printPath(ofstream &fout);
    void calculateTC();

    int getTime();
    double getCost();

};

#endif //INC_20F_FLT_PLN_PATH_H
