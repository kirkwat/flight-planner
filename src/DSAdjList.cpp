#include "DSAdjList.h"

using namespace std;
//default constructor
DSAdjList::DSAdjList() {}
//add flight to adjacency list for testing with only source and destination
//arguments - origin city, destination city
void DSAdjList::addFlight(DSString origin, DSString destination){
    int orgn1Loc=findOrigin(origin);
    int orgn2Loc=findOrigin(destination);
    //if both cities are new
    if(orgn1Loc==-1&&orgn2Loc==-1){
        //add origins to flight list
        flightPaths.push_back(Origin(origin));
        flightPaths.push_back(Origin(destination));
        //add destinations and flight data to each origin
        flightPaths.at(flightPaths.getSize()-2).addDestination(destination);
        flightPaths.at(flightPaths.getSize()-1).addDestination(origin);
    }
    //if origin is new, but destination is not
    else if(orgn1Loc==-1&&orgn2Loc!=-1){
        //add new origins to list
        flightPaths.push_back(Origin(origin));
        //add destination and flight data to origins
        flightPaths.at(flightPaths.getSize()-1).addDestination(destination);
        flightPaths.at(orgn2Loc).addDestination(origin);
    }
    //if destination is new, but origin is not
    else if(orgn1Loc!=-1&&orgn2Loc==-1){
        //add new origins to list
        flightPaths.push_back(Origin(destination));
        //add destination and flight data to origins
        flightPaths.at(orgn1Loc).addDestination(destination);
        flightPaths.at(flightPaths.getSize()-1).addDestination(origin);
    }
    //if both the origin and destination already exist
    else{
        //add destination and flight data to origins
        flightPaths.at(orgn1Loc).addDestination(destination);
        flightPaths.at(orgn2Loc).addDestination(origin);
    }
}
//add flight to adjacency list for all flight info
//arguments - origin city, destination city, time of flight, cost of flight, flight airline
void DSAdjList::addFlight(DSString origin, DSString destination, int flightTime, int flightCost, DSString airline){
    int orgn1Loc=findOrigin(origin);
    int orgn2Loc=findOrigin(destination);
    //if both cities are new
    if(orgn1Loc==-1&&orgn2Loc==-1){
        //add origins to flight list
        flightPaths.push_back(Origin(origin));
        flightPaths.push_back(Origin(destination));
        //add destinations and flight data to each origin

        flightPaths.at(flightPaths.getSize()-2).addDestination(destination,flightTime,flightCost,airline);
        flightPaths.at(flightPaths.getSize()-1).addDestination(origin,flightTime,flightCost,airline);
    }
    //if origin is new, but destination is not
    else if(orgn1Loc==-1&&orgn2Loc!=-1){
        //add new origins to list
        flightPaths.push_back(Origin(origin));
        //add destination and flight data to origins
        flightPaths.at(flightPaths.getSize()-1).addDestination(destination,flightTime,flightCost,airline);
        flightPaths.at(orgn2Loc).addDestination(origin,flightTime,flightCost,airline);
    }
    //if destination is new, but origin is not
    else if(orgn1Loc!=-1&&orgn2Loc==-1){
        //add new origins to list
        flightPaths.push_back(Origin(destination));
        //add destination and flight data to origins
        flightPaths.at(orgn1Loc).addDestination(destination,flightTime,flightCost,airline);
        flightPaths.at(flightPaths.getSize()-1).addDestination(origin,flightTime,flightCost,airline);
    }
    //if both the origin and destination already exist
    else{
        //add destination and flight data to origins
        flightPaths.at(orgn1Loc).addDestination(destination,flightTime,flightCost,airline);
        flightPaths.at(orgn2Loc).addDestination(origin,flightTime,flightCost,airline);
    }
}
//find origin city in list
//arguments - origin city
int DSAdjList::findOrigin(DSString city){
    //check if list is empty
    if(flightPaths.getSize()!=0){
        for(int x=0;x<flightPaths.getSize();x++){
            if(city==flightPaths.at(x).getCityName()){
                //return origin index if it is found
                return x;
            }
        }
    }
    //return -1 if origin is not found
    return -1;
}
//get access to origin at given index
//arguments - origin index
Origin& DSAdjList::originAt(int index) {
    return flightPaths.at(index);
}
//return destination city
//arguments - origin list index, destination index
Destination DSAdjList::getDestinationAt(int x, int y) {
    return flightPaths.at(x).getDestination(y);
}
//return origin city at given index
//arguments - origin index
Origin DSAdjList::getOriginAt(int index) {
    return flightPaths.at(index);
}
//return size of adjacency list
int DSAdjList::getSize() {
    return flightPaths.getSize();
}