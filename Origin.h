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
    DSString getCityName();
    Destination getDestination(int);

};


#endif //INC_20F_FLT_PLN_ORIGIN_H
