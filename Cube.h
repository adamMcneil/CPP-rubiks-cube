//
// Created by adam on 8/12/21.
//

#ifndef UNTITLED_CUBE_H
#define UNTITLED_CUBE_H

#include <string>
#include "Face.h"

class Cube {
public:
    Cube(char[6]);
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
    Face cube[6] = {Face(' '),Face(' '),Face(' '),Face(' '),Face(' '),Face(' ')};
    void solveCube();
    void rightHandRule(int, bool);
    void leftHandRule(int);
    bool isCubeSolved();
    void mixCube();
    void printCube();
    bool whiteIsSolved();
    bool midRowComplete();
    bool yellowCornersAreInPlace();
    void finalMove(int);

private:
};


#endif //UNTITLED_CUBE_H
