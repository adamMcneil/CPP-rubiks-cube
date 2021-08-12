//
// Created by adam on 8/12/21.
//

#ifndef UNTITLED_CUBE_H
#define UNTITLED_CUBE_H
#include "Face.h"

class Cube {
public:
    Cube(char[6]);
    Cube copyCube();
    Face getFace(int);
    void turnU();
    void turnUp();
    void turnD();
    void turnDp();
    void turnR();
    void turnRp();
    void turnL();
    void turnLp();
    void turnF();
    void turnFp();
    void turnB();
    void turnBp();
private:
    Face cube[6] = {Face(' '),Face(' '),Face(' '),Face(' '),Face(' '),Face(' ')};
};


#endif //UNTITLED_CUBE_H
