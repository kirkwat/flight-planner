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
    currentITR=destinations.ITRgetPointer();
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
    cout<<"GET ITR CITY1:"<<currentITR->payload.getCityName()<<endl;
    destinations.ITRsetPointer(currentITR);
    cout<<"GET ITR CITY2:"<<currentITR->payload.getCityName()<<endl;
    return destinations.ITRgetPayload();
}
//return iterator pointer
Node<Destination>*  Origin::getPointerITR(){
    return currentITR;
    //return destinations.ITRgetPointer();
}
//set iterator pointer
void  Origin::setPointerITR(){
    currentITR=destinations.ITRgetPointer();
}
//move iterator
void Origin::nextITR(){
    cout<<"IN THE NEXT ITR FOR ORIGIN"<<endl;
    cout<<"\tDESTINATION BEFORE:"<<destinations.ITRgetPayload().getCityName()<<endl;
    destinations.ITRnext();
    currentITR=destinations.ITRgetPointer();
    cout<<"\tDESTINATION AFTER:"<<destinations.ITRgetPayload().getCityName()<<endl;
    cout<<"GET ITR CITY AFTER NEXT:"<<currentITR->payload.getCityName()<<endl;
}
//reset iterator
void Origin::resetITR(){
    destinations.ITRreset();
}
//get destinations size
int Origin::getDestinationsSize() {
    return destinations.getSize();
}