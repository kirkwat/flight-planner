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
//add destination to flight
void City::addDestination(DSString destination) {
    City dstntn = City(destination);
    destinations.push_back(dstntn);
}
//add destination to flight
void City::addDestination2(City destination) {
    City dstntn = City(destination);
    destinations.push_back(dstntn);
}
//return city string
DSString City::getCityName() {
    return cityName;
}
//return destination city
City City::getDestination(int index) {
    return destinations.at(index);
}