//
// Created by watso on 11/2/2020.
//

#include "DSAdjList.h"

using namespace std;
//default constructor
DSAdjList::DSAdjList() {}
//add flight to adjacency list
void DSAdjList::addFlight(DSString origin, DSString destination){
    //create cities
    City orgn=City(origin);
    City dstntn=City(destination);
    //add both cities to origin list
    flightPaths.push_back(orgn);
    flightPaths.at(flightPaths.getSize()-1).addDestination2(dstntn);
    flightPaths.push_back(dstntn);
    flightPaths.at(flightPaths.getSize()-1).addDestination2(orgn);











    //add origin city
    int orgnLoc=findOrigin(origin);
    //if origin is not already in list
    if(orgnLoc==-1){
        City orgn=City(origin);
        orgn.addDestination(destination);
        flightPaths.push_back(orgn);
    }
    //if origin is already in list
    else{
        flightPaths.at(orgnLoc).addDestination(destination);
    }

    //add destination city
    orgnLoc=findOrigin(destination);
    //if destination is not already in list
    if(orgnLoc==-1){
        City orgn=City(destination);
        orgn.addDestination(origin);
        flightPaths.push_back(orgn);
    }
    //if destination is already in list
    else{
        flightPaths.at(orgnLoc).addDestination(origin);
    }
}
//find origin city in list
int DSAdjList::findOrigin(DSString city){
    if(flightPaths.getSize()!=0){
        cout<<"GG"<<endl;
        for(int x=0;x<flightPaths.getSize();x++){
            if(city==flightPaths.at(x).getCityName()){
                return x;
            }
        }
    }
    return -1;
}
//return origin city
City DSAdjList::getOriginAt(int index) {
    return flightPaths.at(index);
}
//return destination city
City DSAdjList::getDestinationAt(int x, int y) {
    return flightPaths.at(x).getDestination(y);
}