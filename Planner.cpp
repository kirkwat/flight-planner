//
// Created by watso on 11/2/2020.
//

#include "Planner.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "DSString.h"
#include "DSStack.h"

using namespace std;
//default constructor
Planner::Planner(){}
//get and store flights
void Planner::getFlights(char* inputFile){
    ifstream file;
    cout<<"Reading "<<inputFile<<"..."<<endl;
    //open file
    file.open(inputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<inputFile<<"." << endl;
        return;
    }
    //get number of rows from the first line of file
    int rows=0;
    file>>rows;

    char origin[15];
    char destination[15];
    char cost[5];
    char time[5];
    char airline[15];

    file.getline(origin,15);
    //iterate through file
    for(int x=0;x<rows;x++){
        //read line
        file.getline(origin,15,'|');
        file.getline(destination,15,'|');
        file.getline(cost,5,'|');
        file.getline(time,5,'|');
        file.getline(airline,15);
        //store as string
        DSString originstr=origin;
        DSString destinationstr=destination;
        DSString coststr=cost;
        DSString timestr=time;
        DSString airlinestr=airline;//TODO STORE
        //get num from string
        int flightTime=getNum(timestr);//TODO STORE
        int flightCost=getNum(coststr);//TODO STORE
        //add flight
        flights.addFlight(origin,destination);
    }
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}
//get and store requested flights
void Planner::getRequested(char *inputFile) {
    ifstream file;
    cout<<endl<<"Reading "<<inputFile<<"..."<<endl;
    //open file
    file.open(inputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<inputFile<<"." << endl;
        return;
    }
    //get number of rows from the first line of file
    int rows=0;
    file>>rows;

    char origin[15];
    char destination[15];
    char effType;

    //iterate through file
    for(int x=0;x<rows;x++){
        //read line
        file.getline(origin,15);
        file.getline(origin,15,'|');
        file.getline(destination,15,'|');
        file>>effType;
        //store as string
        DSString originstr=origin;
        DSString destinationstr=destination;
        //add flight to list
        requestedPaths.push_back(Flight(originstr,destinationstr,effType));
    }
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}
//find routes for requested paths
void Planner::findPaths(char* inputFile){
    //read input file and store data
    getRequested(inputFile);
    //calculate each flight
    //for(int x=0;x<requestedPaths.getSize();x++){
        //iterative backtracking to find flight path
        DSStack<DSString> stack;
        DSString source=requestedPaths.at(1).getSource();
        DSString destination=requestedPaths.at(1).getDest();
        stack.push(source);
        //find paths through iterative backtracking
        while(!stack.isEmpty()) {
            //if destination is reached
            if(stack.peek()==destination){
                //TODO
                //store path and pop
            }
            else{
                //go to list of city that is on top of stack
                int orgnListLoc = -1;
                for (int x = 0; x < flights.getSize(); x++) {
                    if (stack.peek() == flights.getOriginAt(x).getCityName()) {
                        //return origin index if it is found
                        orgnListLoc = x;
                    }
                }
                //loop through connections in top
                for(int y=0;y<=flights.getOriginAt(orgnListLoc).getDestinationsSize();y++){
                    //check if iterator is null
                    if(flights.getOriginAt(orgnListLoc).ITRgetPointer()==nullptr){
                        //pop top and reset iterator
                        stack.pop();
                        flights.getOriginAt(orgnListLoc).ITRreset();
                        break;
                    }
                    DSString temp=flights.getOriginAt(orgnListLoc).ITRget().getCityName();
                    //check if connection is in stack already
                    if(isInStack(stack,temp)){
                        //move iterator
                        flights.getOriginAt(orgnListLoc).ITRnext();
                    }
                    else{
                        //push connection to stack
                        stack.push(temp);
                        //move iterator
                        flights.getOriginAt(orgnListLoc).ITRnext();
                    }
                }
            }
        }
    //}for loop
    //TODO
}

void Planner::printTopPaths(char* outputFile){
    cout<<endl<<"Saving efficient paths to "<<outputFile<<"..."<<endl;
    //open file
    ofstream file(outputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<outputFile<<"." << endl;
        return;
    }

    //TODO
    //DELETE
    DSString word="hello";
    file<<word<<endl;
}

//get number from string
int Planner::getNum(DSString input){
    int number [5];//assuming num is not bigger than 99999
    int digit;
    int ascii=48;//value for 0
    //extract number from input into array
    for(int i=0;i<input.getLength();i++){
        digit=input[i];
        number[i]=digit-ascii;
    }
    //convert number array into int
    int finalNum=0,z=0;
    for(int i=0;i<input.getLength();i++){
        z=pow(10,input.getLength()-i-1);
        finalNum+=z*number[i];
    }
    //return page number
    return finalNum;
}
//find string in a stack
bool Planner::isInStack(DSStack<DSString> stack,DSString word){
    while(!stack.isEmpty()){
        if(stack.peek()==word){
            return true;
        }
        stack.pop();
    }
    return false;
}
//store path
void Planner::storePath(DSStack<DSString> stack) {

}