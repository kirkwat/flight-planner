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
//add destination to flight
void Origin::addDestination(DSString dstntn){
    //TODO DEAL WITH MULTIPLES
    destinations.push_back(Destination(dstntn));
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
Destination Origin::ITRget(){
    return destinations.ITRgetPayload();
}
//return iterator pointer
Node<Destination>*  Origin::ITRgetPointer(){
    return destinations.ITRgetPointer();
}
//move iterator
void Origin::ITRnext(){
    destinations.ITRnext();
}
//reset iterator
void Origin::ITRreset(){
    destinations.ITRreset();
}
//get destinations size
int Origin::getDestinationsSize() {
    return destinations.getSize();
}