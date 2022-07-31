#include "Origin.h"

//default constructor
Origin::Origin(){
    cityName="NULL";
    dest=Destination("NULL");
}
//overloaded constructor
//arguments - origin city
Origin::Origin(DSString location){
    cityName=location;
    dest=Destination(location);
}
//add destination to flight/only city name for testing
//arguments - destination city
void Origin::addDestination(DSString dstntn){
    //check if destination already exists
    for(int x=0;x<destinations.getSize();x++){
        if(destinations.at(x).getCityName()==dstntn){
            //just return because there is not any info to add to destination
            return;
        }
    }
    //add new destination
    destinations.push_back(Destination(dstntn));
}
//add destination to flight
//arguments - destination city, time of flight, cost of flight, airline of flight
void Origin::addDestination(DSString dstntn, int flightTime,int flightCost,DSString airline){
    //check if destination already exists
    for(int x=0;x<destinations.getSize();x++){
        if(destinations.at(x).getCityName()==dstntn){
            //if found, add new airline info to existing destination
            destinations.at(x).addAirline(flightTime,flightCost,airline);
            return;
        }
    }
    //add new destination
    destinations.push_back(Destination(dstntn,flightTime,flightCost,airline));
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
//return destinaton object for origin
Destination Origin::getDest(){
    return dest;
}
//return city string
DSString Origin::getCityName() {
    return cityName;
}
//return destination at given index
//arguments - index for destination list
Destination Origin::getDestination(int index) {
    return destinations.at(index);
}
//get destinations size
int Origin::getDestinationsSize() {
    return destinations.getSize();
}