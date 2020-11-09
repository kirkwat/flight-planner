//
// Created by watso on 11/7/2020.
//

#include "Destination.h"

//default constructor
Destination::Destination(){
    cityName="NULL";
    flightTime=0;
    flightCost=0;
    airline="NULL";
}
//overloaded constructor
Destination::Destination(DSString location){
    cityName=location;
    flightTime=0;
    flightCost=0;
    airline="NULL";
}
//overloaded constructor
Destination::Destination(DSString location, int time, int cost, DSString line){
    cityName=location;
    flightTime=time;
    flightCost=cost;
    airline=line;
    //flightTimes.push_back(flightTime);
    //flightCosts.push_back(flightCost);
    //airlines.push_back(airline);
}
bool Destination::operator== (const Destination& copy)const{
    return cityName == copy.cityName;
}
//return city string
DSString Destination::getCityName() {
    return cityName;
}
void Destination::addAirline(int flightTime,int flightCost,DSString airline){/*
    flightTimes.push_back(flightTime);
    flightCosts.push_back(flightCost);
    airlines.push_back(airline);*/
}
//return flight time
int Destination::getTime(){
    return flightTime;
}
//return flight cost
int Destination::getCost(){
    return flightCost;
}