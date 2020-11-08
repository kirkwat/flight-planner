//
// Created by watso on 11/7/2020.
//

#ifndef INC_20F_FLT_PLN_FLIGHT_H
#define INC_20F_FLT_PLN_FLIGHT_H

#include "DSString.h"

class Flight {
private:
    DSString source;
    DSString dest;
    char effType;

public:
    Flight();
    Flight(DSString,DSString,char);
    DSString getSource();
    DSString getDest();
    char getEffType();
};


#endif //INC_20F_FLT_PLN_FLIGHT_H
