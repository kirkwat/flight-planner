//
// Created by watso on 11/7/2020.
//

#ifndef INC_20F_FLT_PLN_ORIGIN_H
#define INC_20F_FLT_PLN_ORIGIN_H

#include "DSString.h"
#include "DSList.h"
#include "Destination.h"

class Origin {
private:
    DSString cityName;
    DSList<Destination> destinations;

public:
    Origin();
    Origin(DSString);
    void addDestination(DSString);
    void addDestination(DSString,int,int,DSString);
    DSString getCityName();
    Destination getDestination(int);
    int getDestinationsSize();
    Destination getITR();
    Node<Destination>* getPointerITR();
    void nextITR();
    void resetITR();

};


#endif //INC_20F_FLT_PLN_ORIGIN_H
