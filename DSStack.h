//
// Created by watso on 11/2/2020.
//

#ifndef INC_20F_FLT_PLN_DSSTACK_H
#define INC_20F_FLT_PLN_DSSTACK_H

#include "DSList.h"

using namespace std;

template <typename PlaceHolderType>
class DSStack {
private:
    DSList<PlaceHolderType> stack;

public:
    //default constructor
    DSStack(){}
    //insert element at top of list
    void push(PlaceHolderType data){
        stack.insert_front(data);
    }
    //remove element at the top of the list
    void pop(){
        if(stack.getSize()!=0){
            stack.removeAt(0);
        }
    }
    //return the top element of the list
    PlaceHolderType peek(){
        if(stack.getSize()!=0){
            return stack.at(0);
        }
    }
    //return true if stack is empty
    bool isEmpty(){
        return stack.getSize() == 0;
    }
};

#endif //INC_20F_FLT_PLN_DSSTACK_H
