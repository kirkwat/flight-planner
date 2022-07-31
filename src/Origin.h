#ifndef INC_20F_FLT_PLN_ORIGIN_H
#define INC_20F_FLT_PLN_ORIGIN_H

#include "DSString.h"
#include "DSList.h"
#include "Destination.h"

//This class contains characteristics of an origin of a flight plan.
class Origin {
private:
    DSString cityName;                  //city origin
    DSList<Destination> destinations;   //flights connected to origin
    Destination dest;                   //destination connected flight plan origin

public:
    Origin();
    Origin(DSString);

    void addDestination(DSString);
    void addDestination(DSString,int,int,DSString);

    Destination getITR();
    Node<Destination>* getPointerITR();
    void nextITR();
    void resetITR();

    Destination getDest();
    DSString getCityName();
    Destination getDestination(int);
    int getDestinationsSize();

};


#endif //INC_20F_FLT_PLN_ORIGIN_H
