//
// Created by watso on 11/7/2020.
//

#include "Destination.h"

//default constructor
Destination::Destination(){
    cityName="NULL";
}
//overloaded constructor
Destination::Destination(DSString location){
    cityName=location;
}
//overloaded constructor
Destination::Destination(DSString location, int flightTime, int flightCost, DSString airline){
    cityName=location;
    flightTimes.push_back(flightTime);
    flightCosts.push_back(flightCost);
    airlines.push_back(airline);
}
bool Destination::operator== (const Destination& copy)const{
    return cityName == copy.cityName;
}
//return city string
DSString Destination::getCityName() {
    return cityName;
}
void Destination::addAirline(int flightTime,int flightCost,DSString airline){
    flightTimes.push_back(flightTime);
    flightCosts.push_back(flightCost);
    airlines.push_back(airline);
}