//
// Created by watso on 11/8/2020.
//

#include "Path.h"
#include <iostream>
#include <fstream>

//default constructor
Path::Path(){
    time=0;
    cost=0;
}
//add connection to path
void Path::addConnection(Destination city){
    connections.insert_front(city);
    time=0;
    cost=0;
}
//display path
void Path::printPath(ofstream &fout) {
    for(int x=1;x<connections.getSize();x++){
        if(connections.getSize()-1==x){
            fout<<connections.at(x).getCityName()<<"("<<connections.at(x).getAirline(0)<<"). Time: "<<time<<" Cost: "<<cost;
        }
        else{
            fout<<connections.at(x).getCityName()<<"("<<connections.at(x).getAirline(0)<<") -> ";
        }
    }
}
void Path::calculateTC() {
    for (int x = 1; x < connections.getSize(); x++) {
        if (connections.getSize() - 1 == x) {
            time += connections.at(x).getTime(0);
            cost += connections.at(x).getCost(0);
        } else {
            time += connections.at(x).getTime(0) + 43;
            cost += connections.at(x).getCost(0) + 19;
        }
    }
}
int Path::getTime(){
    return time;
}
int Path::getCost(){
    return cost;
}