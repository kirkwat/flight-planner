#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Planner.h"

using namespace std;

int main(int argc, char** argv) {
    //run catch test if there are no arguments
    if (argc == 1) {
        return Catch::Session().run();
    }

    Planner planner1=Planner();

    planner1.getFlights(argv[1]);

    planner1.findPaths(argv[2]);

    planner1.printTopPaths(argv[3]);


    return 0;
}
//flightData.txt pathsToCalculate.txt output.txt

//in the destination objects, have a linked list of airlines

//TODO
//complete backtracking algorithm
//output results
//add flight cost, time
//make thorough for extra cases