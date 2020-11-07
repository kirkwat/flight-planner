#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Planner.h"
#include <iostream>
#include "DSAdjList.h"

using namespace std;

int main(int argc, char** argv) {
    //run catch test if there are no arguments
    if (argc == 1) {
        return Catch::Session().run();
    }

    //Planner planner1=Planner();

    //planner1.getFlights(argv[1]);

    //.findPlans(argv[2]);

    //planner1.printTopPaths(argv[3]);
    cout<<"HELLO"<<endl;
    DSAdjList list1;
    list1.addFlight("Dallas","Austin");
    list1.addFlight("Austin","Houston");
    list1.addFlight("Dallas","Houston");
    list1.addFlight("Austin","Chicago");
    //what list should look like:
    // D | A- > H
    // A | D -> H -> C
    // H | A -> D
    // C | A
    //check origin list
    //cout<<"TEST:"<<list1.getOriginAt(0).getCityName()<<endl;
    //cout<<"NICE"<<endl;


    return 0;
}
//flightData.txt pathsToCalculate.txt output.txt

//in the destination objects, have a linked list of airlines