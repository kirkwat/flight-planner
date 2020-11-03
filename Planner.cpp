//
// Created by watso on 11/2/2020.
//

#include "Planner.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "DSString.h"

using namespace std;

Planner::Planner(){}

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
    cout<<rows<<endl;

    char origin[15];
    char destination[15];
    char cost[5];
    char time[5];
    char airline[15];

    file.getline(origin,15);
    //iterate through file
    for(int x=0;x<rows;x++){
        file.getline(origin,15,'|');
        file.getline(destination,15,'|');
        file.getline(cost,5,'|');
        file.getline(time,5,'|');
        file.getline(airline,15);

        DSString originstr=origin;
        DSString destinationstr=destination;
        DSString coststr=cost;
        DSString timestr=time;
        DSString airlinestr=airline;

        int flightTime=getNum(timestr);
        int flightCost=getNum(coststr);

        cout<<originstr<<","<<destinationstr<<","<<flightCost<<","<<flightTime<<","<<airlinestr<<endl;

        //TODO
        //store data
    }
    //TODO
}

void Planner::findPlans(char* inputFile){
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
    cout<<rows<<endl;

    char origin[15];
    char destination[15];
    char effType;

    //iterate through file
    for(int x=0;x<rows;x++){
        file.getline(origin,15);

        file.getline(origin,15,'|');
        file.getline(destination,15,'|');
        file>>effType;

        DSString originstr=origin;
        DSString destinationstr=destination;

        cout<<originstr<<","<<destinationstr<<","<<effType<<endl;

        //TODO
        //store data
    }
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