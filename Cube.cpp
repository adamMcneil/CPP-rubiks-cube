//
// Created by adam on 8/12/21.
//

#include "Cube.h"
#include <iostream>
#include <random>

Cube::Cube(char colors[6]) {
    for (int i = 0; i < 6; i++) {
        cube[i] = Face(colors[i]);
    }
}

void Cube::mixCube() {
    for (int x = 0; x < 15; x++) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist12(0, 11);
        int randomNum = dist12(rng);
        if (randomNum == 0) {
            turnU();
        }
        if (randomNum == 1) {
            turnUp();
        }
        if (randomNum == 2) {
            turnD();
        }
        if (randomNum == 3) {
            turnDp();
        }
        if (randomNum == 4) {
            turnR();
        }
        if (randomNum == 5) {
            turnRp();
        }
        if (randomNum == 6) {
            turnL();
        }
        if (randomNum == 7) {
            turnLp();
        }
        if (randomNum == 8) {
            turnF();
        }
        if (randomNum == 9) {
            turnFp();
        }
        if (randomNum == 10) {
            turnB();
        }
        if (randomNum == 11) {
            turnBp();
        }
    }
}

void Cube::solveCube() {
    //solve daisy
    int daisyCount = 0;
    int faces[] = {1, 2, 3, 4};
    int slots[] = {1, 3, 5, 7};
    int slots2[] = {1, 3, 7, 5};
    int slots3[] = {7, 5, 1, 3};
    int slots4[] = {7, 3, 5, 1};
    int slots5[] = {3, 7, 5, 1};

    while (daisyCount < 4) {
        int count = 0;
        for (int x: slots) {
            if (this->cube[5].getColor(x) == 'w') {
                daisyCount++;
                while (this->cube[0].getColor(slots4[count]) == 'w') {
                    turnU();
                }
                if (x == 1) {
                    turnF();
                    turnF();
                }
                if (x == 3) {
                    turnL();
                    turnL();
                }
                if (x == 5) {
                    turnR();
                    turnR();
                }
                if (x == 7) {
                    turnB();
                    turnB();
                }
            }
            count++;
        }


        for (int x: faces) {
            if (this->cube[x].getColor(3) == 'w') {
                daisyCount++;
                while (this->cube[0].getColor(slots2[x - 1]) == 'w') {
                    turnU();
                }
                if (x == 1) {
                    turnBp();
                }
                if (x == 2) {
                    turnLp();
                }
                if (x == 3) {
                    turnFp();
                }
                if (x == 4) {
                    turnRp();
                }
            }
            if (this->cube[x].getColor(5) == 'w') {
                daisyCount++;
                while (this->cube[0].getColor(slots3[x - 1]) == 'w') {
                    turnU();
                }
                if (x == 1) {
                    turnF();
                }
                if (x == 2) {
                    turnR();
                }
                if (x == 3) {
                    turnB();
                }
                if (x == 4) {
                    turnL();
                }
            }
        }
        for (int x: faces) {
            if (this->cube[x].getColor(1) == 'w') {
                daisyCount++;
                if (x == 1) {
                    turnL();
                    turnUp();
                    turnF();
                }
                if (x == 2) {
                    turnF();
                    turnUp();
                    turnR();
                }
                if (x == 3) {
                    turnR();
                    turnUp();
                    turnB();
                }
                if (x == 4) {
                    turnB();
                    turnUp();
                    turnL();
                }
            }
            if (this->cube[x].getColor(7) == 'w') {
                daisyCount++;
                while (this->cube[0].getColor(slots3[x - 1]) == 'w') {
                    turnU();
                }
                if (x == 1) {
                    turnLp();
                    turnF();
                    turnL();

                }
                if (x == 2) {
                    turnFp();
                    turnR();
                    turnF();
                }
                if (x == 3) {
                    turnRp();
                    turnB();
                    turnR();
                }
                if (x == 4) {
                    turnBp();
                    turnL();
                    turnB();
                }
            }
        }
        daisyCount = 0;
        for (int x: slots) {
            if (this->cube[0].getColor(x) == 'w') {
                daisyCount++;
            }
        }
    }
    //
    // resolve daisy
    for (int x: faces) {
        while (this->cube[x].getColor(1) != (this->cube[x].getColor(4)) and
               this->cube[0].getColor(slots5[x - 1]) != 'w') {
            turnU();
        }
        if (x == 1) {
            turnL();
            turnL();
        }
        if (x == 2) {
            turnF();
            turnF();
        }
        if (x == 3) {
            turnR();
            turnR();
        }
        if (x == 4) {
            turnB();
            turnB();
        }
    }
    //
    int cornerSlots[] = {0, 2, 6, 8};
    // white corners
    for (int x: cornerSlots){

    }
}


void Cube::rightHandRule(int face, bool up) {
    if (up) {
        turnL();
        turnD();
        turnLp();
        turnDp();
        return;
    }
    if (face == 1) {
        turnF();
        turnU();
        turnFp();
        turnUp();
        return;
    }
    if (face == 2) {
        turnR();
        turnU();
        turnRp();
        turnUp();
        return;
    }
    if (face == 3) {
        turnB();
        turnU();
        turnBp();
        turnUp();
        return;
    }
    if (face == 4) {
        turnL();
        turnU();
        turnLp();
        turnUp();
        return;
    }
}

bool Cube::isCubeSolved() {
    // finish
    std::cout << "isCubedSolved is not finished";
    return false;
}

void Cube::printCube() {
    for (int i = 0; i < 9; i += 3) {
        std::cout << "\n";
        std::cout << "     ";
        for (int j = 0; j < 3; j++) {
            std::cout << this->cube[0].getColor(j + i);
        }
    }
    for (int i = 0; i < 9; i += 3) {
        std::cout << "\n";
        for (int j = 1; j < 5; j++) {
            std::cout << " ";
            for (int k = 0; k < 3; k++) {
                std::cout << this->cube[j].getColor(k + i);
            }
        }
    }
    for (int i = 0; i < 9; i += 3) {
        std::cout << "\n";
        std::cout << "     ";
        for (int j = 0; j < 3; j++) {
            std::cout << this->cube[5].getColor(j + i);
        }
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
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    int position2[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    int faces[] = {1, 4, 4, 3, 3, 2, 2, 1};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
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
        cube[0].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnUp() {
    //  4-1
    //  3-4
    //  2-3
    //  1-2
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    int position2[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    int faces[] = {4, 1, 3, 4, 2, 3, 1, 2};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
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
        cube[0].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnD() {
    //  4-1
    //  3-4
    //  2-3
    //  1-2
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {6, 7, 8, 6, 7, 8, 6, 7, 8, 6, 7, 8};
    int position2[] = {6, 7, 8, 6, 7, 8, 6, 7, 8, 6, 7, 8};
    int faces[] = {4, 1, 3, 4, 2, 3, 1, 2};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesOld[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesNew[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[5].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[5].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnDp() {
    //  1-4
    //  4-3
    //  3-2
    //  2-1
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {6, 7, 8, 6, 7, 8, 6, 7, 8, 6, 7, 8};
    int position2[] = {6, 7, 8, 6, 7, 8, 6, 7, 8, 6, 7, 8};
    int faces[] = {1, 4, 4, 3, 3, 2, 2, 1};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesNew[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesOld[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[5].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[5].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnR() {
    // 5-2
    // 2-0
    // 0-4
    // 4-5
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {2, 5, 8, 2, 5, 8, 2, 5, 8, 0, 3, 6};
    int position2[] = {2, 5, 8, 2, 5, 8, 6, 3, 0, 8, 5, 2};
    int faces[] = {5, 2, 2, 0, 0, 4, 4, 5};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesOld[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesNew[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[3].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[3].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnRp() {
    // 2-5
    // 0-2
    // 4-0
    // 5-4
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {2, 5, 8, 2, 5, 8, 0, 3, 6, 2, 5, 8};
    int position2[] = {2, 5, 8, 2, 5, 8, 8, 5, 2, 6, 3, 0};
    int faces[] = {2, 5, 0, 2, 4, 0, 5, 4};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesNew[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesOld[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[3].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[3].setSquare(indexesNew[i], oldFace[i]);
    }

}

void Cube::turnL() {
    // 2-5
    // 0-2
    // 4-0
    // 5-4
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {0, 3, 6, 0, 3, 6, 2, 5, 8, 0, 3, 6};
    int position2[] = {0, 3, 6, 0, 3, 6, 6, 3, 0, 8, 5, 2};
    int faces[] = {2, 5, 0, 2, 4, 0, 5, 4};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesOld[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesNew[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[1].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[1].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnLp() {
    // 5-2
    // 2-0
    // 0-4
    // 4-5
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {0, 3, 6, 0, 3, 6, 0, 3, 6, 2, 5, 8};
    int position2[] = {0, 3, 6, 0, 3, 6, 8, 5, 2, 6, 3, 0};
    int faces[] = {5, 2, 2, 0, 0, 4, 4, 5};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesNew[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesOld[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[1].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[1].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnF() {
    // 0-3
    // 3-5
    // 5-1
    // 1-0
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {6, 7, 8, 0, 3, 6, 0, 1, 2, 2, 5, 8};
    int position2[] = {0, 3, 6, 2, 1, 0, 2, 5, 8, 8, 7, 6};
    int faces[] = {0, 3, 3, 5, 5, 1, 1, 0};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesOld[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesNew[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[2].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[2].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnFp() {
    // 3-0
    // 5-3
    // 1-5
    // 0-1
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {0, 3, 6, 0, 1, 2, 2, 5, 8, 6, 7, 8};
    int position2[] = {6, 7, 8, 6, 3, 0, 0, 1, 2, 8, 5, 2};
    int faces[] = {3, 0, 5, 3, 1, 5, 0, 1};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesNew[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesOld[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[2].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[2].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnB() {
    // 3-0
    // 5-3
    // 1-5
    // 0-1
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {2, 5, 8, 6, 7, 8, 0, 3, 6, 0, 1, 2,};
    int position2[] = {0, 1, 2, 8, 5, 2, 6, 7, 8, 6, 3, 0};
    int faces[] = {3, 0, 5, 3, 1, 5, 0, 1};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesOld[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesNew[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[4].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[4].setSquare(indexesNew[i], oldFace[i]);
    }
}

void Cube::turnBp() {
    // 0-3
    // 3-5
    // 5-1
    // 1-0
    char oldCube[12] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int index = 0;
    int position1[] = {0, 1, 2, 2, 5, 8, 6, 7, 8, 0, 3, 6};
    int position2[] = {2, 5, 8, 8, 7, 6, 0, 3, 6, 2, 1, 0};
    int faces[] = {0, 3, 3, 5, 5, 1, 1, 0};
    for (int i = 0; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            oldCube[index] = cube[faces[i]].getColor(position1[index]);
            index++;
        }
    }
    index = 0;
    for (int i = 1; i < 8; i += 2) {
        for (int j = 0; j < 3; j++) {
            cube[faces[i]].setSquare(position2[index], oldCube[index]);
            index++;
        }
    }
    // 0-2 2-8 8-6 6-0
    // 1-5 5-7 7-3 3-1
    int indexesNew[8] = {0, 2, 8, 6, 1, 5, 7, 3};
    int indexesOld[8] = {2, 8, 6, 0, 5, 7, 3, 1};
    char oldFace[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    for (int i = 0; i < 8; i++) {
        oldFace[i] = cube[4].getColor(indexesOld[i]);
    }
    for (int i = 0; i < 8; i++) {
        cube[4].setSquare(indexesNew[i], oldFace[i]);
    }
}