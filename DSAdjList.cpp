//
// Created by watso on 11/2/2020.
//

#include "DSAdjList.h"

using namespace std;
//default constructor
DSAdjList::DSAdjList() {}
//add flight to adjacency list
void DSAdjList::addFlight(DSString origin, DSString destination){
    //if adjacen
    if(){

    }





    //TODO NOT DONE
    City orgn=City(origin);
    orgn.addDestination(destination);
    flightPaths.push_back(orgn);
}
//find origin city in list
bool DSAdjList::findOrigin(DSString city){
    if(flightPaths.getSize()!=0){
        for(int x=0;x<flightPaths.getSize();x++){
            if(city==flightPaths.at(x).getCityName()){
                return true;
            }
        }
    }
    return false;
}
