//
// Created by adam on 8/12/21.
//

#include "Cube.h"

Cube::Cube(char colors[6]) {
    for (int i = 0; i < 6; i++) {
        cube[i] = Face(colors[i]);
    }
}

Face Cube::getFace(int i) {
    return cube[i];
}

void Cube::turnU() {
    //  1-4
    //  4-3
    //  3-2
    //  2-1
    int whatFace[8] = {1, 4, 4, 3, 3, 2, 2, 1};
    int whatSpot[12] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 12; j++) {
            oldCube[j] = cube[whatFace[whatSpot[j]]].getColor(j);
        }
    }
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 12; j++) {
            cube[whatFace[i]].setSquare(whatSpot[12], oldCube[j]);
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesOld[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesNew[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[0].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[indexesNew[i]] = oldFace[i];
    }
}

void Cube::turnUp() {
    //  4-1
    //  3-4
    //  2-3
    //  1-2
    int whatFace[8] = {1, 4, 4, 3, 3, 2, 2, 1};
    int whatSpot[12] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 12; j++) {
            oldCube[j] = cube[whatFace[whatSpot[j]]].getColor(j);
        }
    }
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 12; j++) {
            cube[whatFace[i]].setSquare(whatSpot[12], oldCube[j]);
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesNew[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesOld[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[0].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[indexesNew[i]] = oldFace[i];
    }
}

void Cube::turnD() {
    //  4-1
    //  3-4
    //  2-3
    //  1-2
}

void Cube::turnDp() {
    //  1-4
    //  4-3
    //  3-2
    //  2-1
}

void Cube::turnR() {
    // 5-2
    // 2-0
    // 0-4
    // 4-5
}

void Cube::turnRp() {
    // 2-5
    // 0-2
    // 4-0
    // 5-4
}

void Cube::turnL() {
    // 2-5
    // 0-2
    // 4-0
    // 5-4
}

void Cube::turnLp() {
    // 5-2
    // 2-0
    // 0-4
    // 4-5
}

void Cube::turnF() {
    // 0-3
    // 3-5
    // 5-1
    // 1-0
}

void Cube::turnFp() {
    // 3-0
    // 5-3
    // 1-5
    // 0-1
}

void Cube::turnB() {
    // 3-0
    // 5-3
    // 1-5
    // 0-1
}

void Cube::turnBp() {
    // 0-3
    // 3-5
    // 5-1
    // 1-0
}