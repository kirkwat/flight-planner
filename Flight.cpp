//
// Created by watso on 11/7/2020.
//

#include "Flight.h"

//default constructor
Flight::Flight(){
    source="NULL";
    dest="NULL";
    effType='0';
}
//overloaded constructor
Flight::Flight(DSString strt,DSString fnsh,char type){
    source=strt;
    dest=fnsh;
    effType=type;
}
//get source
DSString Flight::getSource(){
    return source;
}
//get dest
DSString Flight::getDest(){
    return dest;
}
//get efficiency type
char Flight::getEffType(){
    return effType;
}