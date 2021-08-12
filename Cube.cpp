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
    cube[0];
    int indexes[8] = {1, 4, 4, 3, 3, 2, 2, 1};
    char oldCube[12] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int index = 0;
    int cubeIndex = 0;
    for (int i = 0; i < 8; i+=2){
        for (int j = 0; j < 3; j++){
            oldCube[index] = cube[indexes[i]].getColor(j);
            index++;
        }
    }
    for (int i = 1; i < 8; i+=2) {
        for (int j = 0; j < 3; j++) {
            cube[indexes[i]].setSquare(j, oldCube[j + cubeIndex]);
        }
        cubeIndex += 3;
    }
    // 02 28 86 60
    //15 57 73 31
}

void Cube::turnUp() {
    //  4-1
    //  3-4
    //  2-3
    //  1-2
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