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
//store path
void Flight::storePath(DSStack<DSString> stack) {
    paths.push_back(Path());
    while(!stack.isEmpty()){
        paths.at(paths.getSize()-1).addConnection(stack.peek());
        stack.pop();
    }
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
//get destinations size
int Flight::getPathsSize() {
    return paths.getSize();
}
//print path at given index
void Flight::printPathAt(int index){
    paths.at(index).printPath();
}