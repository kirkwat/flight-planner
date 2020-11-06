//
// Created by watso on 11/2/2020.
//

#include "City.h"

//default constructor
City::City(){
    cityName="NULL";
}
//overloaded constructor
City::City(DSString location){
    cityName=location;
}

void City::addDestination(DSString destination) {
    City dstntn=City(destination);
    destinations.push_back(dstntn);
}

DSString City::getCityName() {
    return cityName;
}