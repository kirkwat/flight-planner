#include "Planner.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "DSString.h"
#include "DSStack.h"
#include "Destination.h"

using namespace std;
//default constructor
Planner::Planner(){}
//get and store flights
//arguments - possible flights file path
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

    char origin[20];
    char destination[20];
    char cost[5];
    char time[5];
    char airline[20];

    file.getline(origin,20);
    //iterate through file
    for(int x=0;x<rows;x++){
        //read line
        file.getline(origin,20,'|');
        file.getline(destination,20,'|');
        file.getline(cost,5,'|');
        file.getline(time,5,'|');
        file.getline(airline,20,'\n');
        //store as string
        DSString originstr=origin;
        DSString destinationstr=destination;
        DSString coststr=cost;
        DSString timestr=time;
        DSString airlinestr=airline;
        //remove carriage return character
        for(int y=0;y<20;y++){
            //find location
            if(airline[y]=='\r'){
                airline[y]='\0';
                airlinestr=airline;
                break;
            }
        }
        //get num from string
        int flightTime=getNum(timestr);
        int flightCost=getNum(coststr);
        //add flight
        flights.addFlight(originstr,destinationstr,flightTime,flightCost,airlinestr);
    }
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}
//get and store requested flights
//arguments - requested flights file path
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

    char origin[20];
    char destination[20];
    char effType;

    //iterate through file
    for(int x=0;x<rows;x++){
        //read line
        file.getline(origin,20);
        file.getline(origin,20,'|');
        file.getline(destination,20,'|');
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
//arguments - requested flights file path
void Planner::findPaths(char* inputFile){
    //read input file and store data
    getRequested(inputFile);
    //calculate each flight
    cout<<endl<<"Calculating flight plans..."<<endl;
    for(int x=0;x<requestedPaths.getSize();x++) {
        //iterative backtracking to find flight path
        DSStack<Destination> stack;
        //get source and destination
        DSString source = requestedPaths.at(x).getSource();
        DSString destination = requestedPaths.at(x).getDest();
        //search for source and destination to make sure it exists
        bool sourceExists=false,destExists = false;
        for (int y = 0; y < flights.getSize(); y++) {
            if (flights.originAt(y).getCityName() == destination) {
                //true if destination is found in origin list
                destExists = true;
            }
            if (flights.originAt(y).getCityName() == source) {
                //true if source is found in origin list
                sourceExists = true;
            }
        }
        //search for paths if source and destination exist in the list
        if (destExists&&sourceExists){
            //push source destination on top of stack
            for (int y = 0; y < flights.getSize(); y++) {
                if (source == flights.originAt(y).getCityName()) {
                    stack.push(flights.originAt(y).getDest());
                    break;
                }
            }
            int orgnListLoc = -1;
            //find paths through iterative backtracking
            while (!stack.isEmpty()) {
                //if destination is reached
                if (stack.peek() == destination) {
                    //store path
                    requestedPaths.at(x).storePath(stack);
                    //pop top of stack
                    stack.pop();
                }
                else {
                    //go to list of city that is on top of stack
                    for (int y = 0; y < flights.getSize(); y++) {
                        if (stack.peek() == flights.originAt(y).getCityName()) {
                            //return origin index if it is found
                            orgnListLoc = y;
                            break;
                        }
                    }
                    Destination temp;
                    //loop through connections in top
                    for (int y = 0; y <= flights.originAt(orgnListLoc).getDestinationsSize(); y++) {
                        //check if iterator is null
                        if (flights.originAt(orgnListLoc).getPointerITR() == nullptr) {
                            //pop top of stack
                            stack.pop();
                            //reset iterator
                            flights.originAt(orgnListLoc).resetITR();
                            break;
                        }
                        temp = flights.originAt(orgnListLoc).getITR();
                        //check if connection is in stack already
                        if (isInStack(stack, temp)) {
                            //move iterator
                            flights.originAt(orgnListLoc).nextITR();
                        }
                        else {
                            //push connection to stack
                            stack.push(temp);
                            //move iterator
                            flights.originAt(orgnListLoc).nextITR();
                            break;
                        }
                    }
               }
            }
        }
        //set flight as not possible if destination or source do not exist
        else{
            requestedPaths.at(x).setFlightNotPossible();
        }
    }
    cout<<"...Complete"<<endl;
}
//output most efficient flight paths to output file
//arguments - output file path
void Planner::printTopPaths(char* outputFile){
    cout<<endl<<"Saving efficient paths to "<<outputFile<<"..."<<endl;
    //open file
    ofstream file(outputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<outputFile<<"." << endl;
        return;
    }
    //print all flights and paths
    for(int x=0;x<requestedPaths.getSize();x++){
        file<<"Flight "<<x+1<<": ";
        requestedPaths.at(x).printPaths(file);
        file<<endl;
    }
    cout<<"...Complete"<<endl;
}

//get number from string
//arguments - string representing an integer
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
//find destination in a stack
//arguments - stack holding destinations, destination location
bool Planner::isInStack(DSStack<Destination> stack,Destination city){
    //search stack
    while(!stack.isEmpty()){
        //return true if destination is found
        if(stack.peek()==city){
            return true;
        }
        //pop if not found
        stack.pop();
    }
    //return false if destination is not in stack
    return false;
}