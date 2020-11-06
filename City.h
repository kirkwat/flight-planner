//
// Created by watso on 11/2/2020.
//

#ifndef INC_20F_FLT_PLN_CITY_H
#define INC_20F_FLT_PLN_CITY_H

#include "DSString.h"
#include "DSList.h"

class City {
private:
    DSString cityName;
    DSList<City> destinations;

public:
    City();
    City(DSString);
    void addDestination(DSString);
    DSString getCityName();

};

#endif //INC_20F_FLT_PLN_CITY_H
