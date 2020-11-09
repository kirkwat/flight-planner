//
// Created by watso on 11/7/2020.
//

#include "Flight.h"
#include <iostream>
#include <fstream>

//default constructor
Flight::Flight(){
    source="NULL";
    dest="NULL";
    effType="NULL";
    flightPossible=true;
}
//overloaded constructor
Flight::Flight(DSString strt,DSString fnsh,char type){
    source=strt;
    dest=fnsh;
    if(type=='C'){
        effType="Cost";
    }
    else{
        effType="Time";
    }
    flightPossible=true;
}
//store path
void Flight::storePath(DSStack<Destination> stack) {
    paths.push_back(Path());
    while(!stack.isEmpty()){
        paths.at(paths.getSize()-1).addConnection(stack.peek());
        stack.pop();
    }
}
//print all found paths
void Flight::printPaths(ofstream &fout){
    //check if flight is possible
    if(flightPossible){
        //calculate time and costs
        calculatePathsTC();
        //sort paths by given efficiency
        sortPaths(0,paths.getSize()-1);
        //set display loop limit
        int z=0;
        if(paths.getSize()<3){
            z=paths.getSize();
        }
        else{
            z=3;
        }
        //display paths
        fout<<source<<", "<<dest<<" ("<<effType<<")"<<endl;
        for(int y=0;y<z;y++){
            fout<<"Path "<<y+1<<": "<<source<<" -> ";
            paths.at(y).printPath(fout);
            fout<<endl;
        }
    }
    //if path is not possible
    else{
        fout<<source<<", "<<dest<<" ("<<effType<<")"<<endl;
        fout<<"Flight from "<<source<<" to "<<dest<<" is not possible, no paths shown."<<endl;
    }
}
//sort paths for given mode of efficiency
void Flight::sortPaths(int left, int right){
    //end sort if size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort paths list
    Path pivot = paths.at(right);
    int num = left;
    for (int i = left; i <= right; i++){
        //if true swap elements for time efficiency
        if (effType=="Time"&&paths.at(i).getTime() <= pivot.getTime()){
            Path temp=paths.at(num);
            paths.at(num)=paths.at(i);
            paths.at(i)=temp;
            num++;
        }
        //if true swap elements for cost efficiency
        else if (effType=="Cost"&&paths.at(i).getCost() <= pivot.getCost()){
            Path temp=paths.at(num);
            paths.at(num)=paths.at(i);
            paths.at(i)=temp;
            num++;
        }
    }
    //sort left side
    sortPaths(left, num-2);
    //sort right side
    sortPaths(num, right);
}
//calculate times and costs for each path
void Flight::calculatePathsTC() {
    for(int a=0;a<paths.getSize();a++){
        paths.at(a).calculateTC();
    }
}
//if source or destination does not exist, flight is not possible
void Flight::setFlightNotPossible(){
    flightPossible=false;
}
//get source
DSString Flight::getSource(){
    return source;
}
//get dest
DSString Flight::getDest(){
    return dest;
}