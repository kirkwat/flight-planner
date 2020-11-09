//
// Created by watso on 11/7/2020.
//

#include "Origin.h"

//default constructor
Origin::Origin(){
    cityName="NULL";
}
//overloaded constructor
Origin::Origin(DSString location){
    cityName=location;
}
//add destination to flight/only city name for testing
void Origin::addDestination(DSString dstntn){
    for(int x=0;x<destinations.getSize();x++){
        if(destinations.at(x).getCityName()==dstntn){
            //just return because there is not any info to add to destination
            return;
        }
    }
    destinations.push_back(Destination(dstntn));
}
//add destination to flight
void Origin::addDestination(DSString dstntn, int flightTime,int flightCost,DSString airline){
    for(int x=0;x<destinations.getSize();x++){
        if(destinations.at(x).getCityName()==dstntn){
            destinations.at(x).addAirline(flightTime,flightCost,airline);
            return;
        }
    }
    destinations.push_back(Destination(dstntn,flightTime,flightCost,airline));
}
//return city string
DSString Origin::getCityName() {
    return cityName;
}
//return destination city
Destination Origin::getDestination(int index) {
    return destinations.at(index);
}
//return destination at iterator node
Destination Origin::getITR(){
    return destinations.ITRgetPayload();
}
//return iterator pointer
Node<Destination>*  Origin::getPointerITR(){
    return destinations.ITRgetPointer();
}
//move iterator
void Origin::nextITR(){
    destinations.ITRnext();
}
//reset iterator
void Origin::resetITR(){
    destinations.ITRreset();
}
//get destinations size
int Origin::getDestinationsSize() {
    return destinations.getSize();
}