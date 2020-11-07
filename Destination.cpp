//
// Created by watso on 11/7/2020.
//

#include "Destination.h"

//default constructor
Destination::Destination(){
    cityName="NULL";
}
//overloaded constructor
Destination::Destination(DSString location){
    cityName=location;
}
//return city string
DSString Destination::getCityName() {
    return cityName;
}