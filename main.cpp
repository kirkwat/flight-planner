#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Planner.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    //run catch test if there are no arguments
    if (argc == 1) {
        return Catch::Session().run();
    }

    Planner planner1=Planner();

    planner1.getFlights(argv[1]);

    planner1.findPlans(argv[2]);

    planner1.printTopPaths(argv[3]);

    return 0;
}
//TODO
//make adj list
//make origin objects
//add curnode iterator for linked list
//read files



//QUESTIONS
//better way to use getline?