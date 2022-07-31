# Flight Planner - CS 2341 Project 4

Developed and maintained by Kirk Watson.

Email: klwatson@smu.edu

Class: Data Structures CS 2341 - Fall 2020

Southern Methodist University

## Functionality

This program determines all possible flight plans for a person wishing to travel between two different cities while accounting for time and costs.
To perform an exhaustive search of all possible flights originating from a particular city, this program implements an iterative backtracking algorithm.
This program utilizes the following self-implemented data structures: String, Stack, Linked List, and Adjacency List.

## How to Use

To use this program, compile and build with CMAKE. There are 3 command-line arguments.
To run CATCH tests on the self-implemented Linked List, Stack, and Adjacency List class, simply run the program with no command-line arguments.

### Possible Flights File Path

* Contains a sequence of city pairs representing  0-stop flights that can be used in preparing a flight plan.
* Formatting
    * First line is a number indicating how many rows of data will be in the file.
    * Subsequent rows will contain two city names, the cost of the flight, and the number of minutes of the flight separated with a pipe `|`.
    * A correctly formatted input file is located in the `input` directory.

### Requested Flights File Path

* Contains a sequence of origin/destination city pairs which are used to determine if the flight is or is not possible.
* Formatting
  * First line is a number indicating how many rows of data will be in the file.
  * Subsequent lines will contain a pipe-delimited list of city pairs with a trailing character to indicate sorting the output of flights by time (T) or cost (C).
  * A correctly formatted input file is located in the `input` directory.

### Output File Path

* Empty .txt file that will hold the generated index.

Here is an example of the command-line arguments:

`../input/possibleFlights.txt ../input/requestedFlights.txt ../output/output.txt`