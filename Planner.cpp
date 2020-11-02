//
// Created by watso on 11/2/2020.
//

#include "Planner.h"
#include <iostream>
#include <fstream>
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
    DSString word;
    file>>word;
    cout<<word<<endl;
}

void Planner::findPlans(char* inputFile){
    ifstream file;
    cout<<"Reading "<<inputFile<<"..."<<endl;
    //open file
    file.open(inputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<inputFile<<"." << endl;
        return;
    }
    DSString word;
    file>>word;
    cout<<word<<endl;
}

void Planner::printTopPaths(char* outputFile){
    cout<<endl<<"Creating index and saving it to "<<outputFile<<"..."<<endl;
    //open file
    ofstream file(outputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<outputFile<<"." << endl;
        return;
    }
    DSString word="hello";
    file<<word<<endl;
}