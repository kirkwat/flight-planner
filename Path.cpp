//
// Created by watso on 11/8/2020.
//

#include "Path.h"

//default constructor
Path::Path(){}
//add connection to path
void Path::addConnection(DSString city){
    connections.push_back(city);
}
