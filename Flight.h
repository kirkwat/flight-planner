//
// Created by watso on 11/7/2020.
//

#ifndef INC_20F_FLT_PLN_FLIGHT_H
#define INC_20F_FLT_PLN_FLIGHT_H

#include "DSString.h"
#include "DSList.h"
#include "DSStack.h"
#include "Path.h"

class Flight {
private:
    DSString source;
    DSString dest;
    char effType;
    DSList<Path> paths;

public:
    Flight();
    Flight(DSString,DSString,char);
    void storePath(DSStack<DSString>);
    DSString getSource();
    DSString getDest();
    char getEffType();
    int getPathsSize();
    void printPathAt(int);
};


#endif //INC_20F_FLT_PLN_FLIGHT_H
