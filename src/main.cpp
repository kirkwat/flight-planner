#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Planner.h"

using namespace std;

int main(int argc, char** argv) {
    //run catch test if there are no arguments
    if (argc == 1) {
        return Catch::Session().run();
    }
    //create planner
    Planner planner1=Planner();
    //read and store flights
    planner1.getFlights(argv[1]);
    //read and find requested paths
    planner1.findPaths(argv[2]);
    //save best routes for each path
    planner1.printTopPaths(argv[3]);

    return 0;
}
