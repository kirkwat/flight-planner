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
//display path
void Path::printPath() {
    cout<<"PATH: ";
    for(int x=0;x<connections.getSize();x++){
        cout<<connections.at(x)<<"->";
    }
    cout<<endl;
}
