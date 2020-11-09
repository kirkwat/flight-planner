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
}
//store path
void Flight::storePath(DSStack<Destination> stack) {
    paths.push_back(Path());
    while(!stack.isEmpty()){
        paths.at(paths.getSize()-1).addConnection(stack.peek());
        stack.pop();
    }
}
//get source
DSString Flight::getSource(){
    return source;
}
//get dest
DSString Flight::getDest(){
    return dest;
}
//get destinations size
int Flight::getPathsSize() {
    return paths.getSize();
}
//print all found paths
void Flight::printPaths(ofstream &fout){
    calculatePathsTC();
    sortPaths(0,paths.getSize()-1);
    int z=0;
    if(paths.getSize()<3){
        z=paths.getSize();
    }
    else{
        z=3;
    }
    fout<<source<<", "<<dest<<" ("<<effType<<")"<<endl;
    for(int y=0;y<z;y++){
        fout<<"Path "<<y+1<<": "<<source<<" -> ";
        paths.at(y).printPath(fout);
        fout<<endl;
    }
}
void Flight::sortPaths(int left, int right){
    //end sort if vector size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort page vector
    Path pivot = paths.at(right);
    int num = left;
    for (int i = left; i <= right; i++){
        //if true swap elements
        if (effType=="Time"&&paths.at(i).getTime() <= pivot.getTime()){
            Path temp=paths.at(num);
            paths.at(num)=paths.at(i);
            paths.at(i)=temp;
            num++;
        }
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
void Flight::calculatePathsTC() {
    for(int a=0;a<paths.getSize();a++){
        paths.at(a).calculateTC();
    }
}