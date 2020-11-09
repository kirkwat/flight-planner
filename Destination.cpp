//
// Created by watso on 11/7/2020.
//

#include "Destination.h"

//default constructor
Destination::Destination(){
    cityName="NULL";
    flightTimes.push_back(0);
    flightCosts.push_back((double)0);
    airlines.push_back("NULL");
}
//overloaded constructor with city name
Destination::Destination(DSString location){
    cityName=location;
    flightTimes.push_back(0);
    flightCosts.push_back((double)0);
    airlines.push_back("NULL");
}
//overloaded constructor with flight attributes
Destination::Destination(DSString location, int time, int cost, DSString line){
    cityName=location;
    flightTimes.push_back(time);
    flightCosts.push_back((double)cost);
    airlines.push_back(line);
}

bool Destination::operator== (const Destination& copy)const{
    return cityName == copy.cityName;
}
//add another airline to list if there are multiple flights to same destination
void Destination::addAirline(int flightTime,int flightCost,DSString airline){
    flightTimes.push_back(flightTime);
    flightCosts.push_back((double)flightCost);
    airlines.push_back(airline);
}
//return flight time
int Destination::getTime(int index){
    return flightTimes.at(index);
}
//return flight cost
double Destination::getCost(int index){
    return flightCosts.at(index);
}
//return size of airline list
int Destination::getAirlinesSize() {
    return airlines.getSize();
}
//return airline
DSString Destination::getAirline(int index) {
    return airlines.at(index);
}
//return city string
DSString Destination::getCityName() {
    return cityName;
}