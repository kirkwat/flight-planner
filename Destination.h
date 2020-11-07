//
// Created by watso on 11/7/2020.
//

#ifndef INC_20F_FLT_PLN_DESTINATION_H
#define INC_20F_FLT_PLN_DESTINATION_H

#include "DSString.h"

class Destination {
private:
    DSString cityName;
    //add other flight attributes here
public:
    Destination();
    Destination(DSString);
    DSString getCityName();
};


#endif //INC_20F_FLT_PLN_DESTINATION_H
