//
// Created by watso on 11/8/2020.
//

#ifndef INC_20F_FLT_PLN_PATH_H
#define INC_20F_FLT_PLN_PATH_H

#include "DSString.h"
#include "DSList.h"

class Path {
private:
    DSList<DSString> connections;

public:
    Path();
    void addConnection(DSString);
    void printPath();

};

#endif //INC_20F_FLT_PLN_PATH_H
