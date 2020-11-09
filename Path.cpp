//
// Created by watso on 11/8/2020.
//
#include <iomanip>
#include "Path.h"
#include <iostream>
#include <iomanip>
#include <fstream>

//default constructor
Path::Path(){
    time=0;
    cost=0;
}
//add connection to path
void Path::addConnection(Destination city){
    connections.insert_front(city);
}
//display path
void Path::printPath(ofstream &fout) {
    //set precision for cost
    fout <<fixed;
    fout << setprecision(2);
    //display connections
    for(int x=1;x<connections.getSize();x++){
        //last connection
        if(connections.getSize()-1==x){
            //display total time and cost
            fout<<connections.at(x).getCityName()<<"("<<connections.at(x).getAirline(0)<<"). Time: "<<time<<" Cost: "<<cost;
        }
        else{
            fout<<connections.at(x).getCityName()<<"("<<connections.at(x).getAirline(0)<<") -> ";
        }
    }
}
//calculate time and costs for path
void Path::calculateTC() {
    for (int x = 1; x < connections.getSize(); x++) {
        //last connection
        if (connections.getSize() - 1 == x) {
            time += connections.at(x).getTime(0);
            cost += connections.at(x).getCost(0);
        }
        //add extra time and cost for layovers
        else {
            time += connections.at(x).getTime(0) + 43;
            cost += connections.at(x).getCost(0) + 19;
        }
    }
}
//return time
int Path::getTime(){
    return time;
}
//return cost
double Path::getCost(){
    return cost;
}