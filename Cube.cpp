//
// Created by adam on 8/12/21.
//

#include "Cube.h"
#include <iostream>
#include <random>
#include <algorithm>

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

bool Cube::whiteIsSolved() {
    for (int x = 1; x < 5; x++) {
        char check = this->cube[x].getColor(4);
        if (not(this->cube[x].getColor(6) == check && this->cube[x].getColor(7) == check &&
                this->cube[x].getColor(8) == check)) {
            return false;
        }
    }
    for (int x = 0; x < 9; x++)
        if (this->cube[5].getColor(x) != 'w') {
            return false;
        }
    return true;
}

bool Cube::midRowComplete() {
    char colors[] = {'b', 'r', 'g', 'o'};
    for (int x = 0; x < 4; x++) {
        if (not(this->cube[x + 1].getColor(3) == colors[x] and this->cube[x + 1].getColor(5) == colors[x])) {
            return false;
        }
    }
    return true;
}

bool Cube::yellowCrossIsSolved() {
    if (this->cube[0].getColor(1) != 'y') {
        return false;
    }
    if (this->cube[0].getColor(3) != 'y') {
        return false;
    }
    if (this->cube[0].getColor(5) != 'y') {
        return false;
    }
    if (this->cube[0].getColor(7) != 'y') {
        return false;
    }
    return true;
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
        while (not(this->cube[x].getColor(1) == (this->cube[x].getColor(4)) and
                   this->cube[0].getColor(slots5[x - 1]) == 'w')) {
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
    // white corners
    int cornerSlots[] = {6, 8, 2, 0};
    int cornerSlots2[] = {0, 2, 8, 6};
    int facePlusOne[] = {2, 3, 4, 1};
    int whiteCornersCount = 0;
    std::string testStrings[] = {"brw", "grw", "gow", "bow"};
    while (not whiteIsSolved()) {
        for (int x = 0; x < 4; x++) {

            std::string test = testStrings[x];
            std::sort(test.begin(), test.end());

            for (int y = 0; y < 4; y++) {
                std::string colorString;
                colorString.append(1, this->cube[0].getColor(cornerSlots[x]));
                colorString.append(1, this->cube[x + 1].getColor(2));
                colorString.append(1, this->cube[facePlusOne[x]].getColor(0));
                std::sort(colorString.begin(), colorString.end());

                if (std::equal(colorString.begin(), colorString.end(), test.begin(), test.end())) {
                    while (this->cube[5].getColor(cornerSlots2[x]) != 'w') {
                        rightHandRule(x + 1, false);
                    }
                    whiteCornersCount++;
                }
                turnU();
            }
        }
        for (int x = 0; x < 4; x++) {
            std::string test = testStrings[x];
            std::sort(test.begin(), test.end());


            std::string colorString;
            colorString.append(1, this->cube[5].getColor(cornerSlots2[x]));
            colorString.append(1, this->cube[x + 1].getColor(8));
            colorString.append(1, this->cube[facePlusOne[x]].getColor(6));
            std::sort(colorString.begin(), colorString.end());

            if (std::equal(colorString.begin(), colorString.end(), test.begin(), test.end())) {
                while (this->cube[5].getColor(cornerSlots2[x]) != 'w') {
                    rightHandRule(x + 1, false);
                }
                whiteCornersCount++;
            } else {
                for (char c: colorString) {
                    if (c == 'w') {
                        rightHandRule(x + 1, false);
                        turnU();
                        break;
                    }
                }
            }
        }
    }
    //
    // middle row
    while (not midRowComplete()) {
        char faceColors[] = {'o', 'b', 'r', 'g', 'o', 'b'};
        int face[] = {4, 1, 2, 3, 4, 1};
        int topSlots[] = {0, 3, 7, 5, 1};
        for (int x = 1; x < 5; x++) {
            if (this->cube[face[x]].getColor(1) == faceColors[x]) {
                if (this->cube[0].getColor(topSlots[x]) == faceColors[x - 1]) {
                    turnUp();
                    leftHandRule(face[x]);
                    rightHandRule(face[x - 1], false);
                } else {
                    if (this->cube[0].getColor(topSlots[x]) == faceColors[x + 1]) {
                        turnU();
                        rightHandRule(face[x], false);
                        leftHandRule(face[x + 1]);
                    }
                }
            }
            if (not(this->cube[face[x]].getColor(5) == faceColors[x] and
                    this->cube[face[x + 1]].getColor(3) == faceColors[x + 1]) and
                (this->cube[face[x]].getColor(5) != 'y' and
                 this->cube[face[x + 1]].getColor(3) != 'y')) {
                rightHandRule(face[x], false);
                leftHandRule(face[x + 1]);
            }
        }

        turnU();
    }
    //
    // yellow line
    int count = 0;
    for (int x = 0; x < 4; x++) {
        if (this->cube[0].getColor(1) != 'y') {
            count++;
        }
        turnU();
    }
    if (count > 2) {
        turnF();
        rightHandRule(2, false);
        turnFp();
    }
    for (int x = 0; x < 4; x++) {
        if (this->cube[0].getColor(5) == 'y' && this->cube[0].getColor(7) == 'y' &&
            this->cube[0].getColor(1) != 'y' && this->cube[0].getColor(3) != 'y') {
            turnF();
            rightHandRule(2, false);
            turnFp();
            break;
        }
        turnU();
    }
    for (int x = 0; x < 4; x++) {
        if (this->cube[0].getColor(5) == 'y' && this->cube[0].getColor(3) == 'y' &&
            this->cube[0].getColor(1) != 'y' && this->cube[0].getColor(7) != 'y') {
            turnF();
            rightHandRule(2, false);
            turnFp();
            break;
        }
        turnU();
    }
//
// yellow corners
//    std::string testStrings2[] = {"bo", "br", "gr", "go", "bo", "br"};
//    int face[] = {4, 1, 2, 3, 4, 1, 2};
//    int topSlots[] = {0, 6, 8, 2, 0, 6};
//    bool doIt = false;
//    for (int x = 1; x < 5; x++) {
//
//        std::string test = testStrings2[x];
//        std::sort(test.begin(), test.end());
//
//        std::string test2 = testStrings2[x + 1];
//        std::sort(test2.begin(), test2.end());
//
//        for (int y = 0; y < 4; y++) {
//            doIt = false;
//
//            std::string colorString;
//            colorString.append(1, this->cube[face[x]].getColor(2));
//            colorString.append(1, this->cube[face[x + 1]].getColor(0));
//            std::sort(colorString.begin(), colorString.end());
//
//            std::string colorString2;
//            colorString2.append(1, this->cube[face[x + 1]].getColor(2));
//            colorString2.append(1, this->cube[face[x + 2]].getColor(0));
//            std::sort(colorString2.begin(), colorString2.end());
//
//            if ((not std::equal(colorString.begin(), colorString.end(), test.begin(), test.end())) &&
//                (not std::equal(colorString2.begin(), colorString2.end(), test2.begin(), test2.end()))){
//                for (char c: colorString){
//                    for (char k: colorString2){
//                        if (c == k){
//                            doIt = true;
//                        }
//                    }
//                }
//                if (doIt) {
//                    rightHandRule(face[x], false);
//                    rightHandRule(face[x], false);
//                    rightHandRule(face[x], false);
//                    leftHandRule(face[x + 1]);
//                    leftHandRule(face[x + 1]);
//                    leftHandRule(face[x + 1]);
//                }
//            }
//        }
//        turnU();
//    }

//
// flip yellow corners
//    for (int x = 0; x < 4; x++) {
//        while (this->cube[0].getColor(6) != 'y') {
//            rightHandRule(2, true);
//        }
//        turnU();
//    }
//

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

void Cube::leftHandRule(int face) {
    if (face == 1) {
        turnBp();
        turnUp();
        turnB();
        turnU();
        return;
    }
    if (face == 2) {
        turnLp();
        turnUp();
        turnL();
        turnU();
        return;
    }
    if (face == 3) {
        turnFp();
        turnUp();
        turnF();
        turnU();
        return;
    }
    if (face == 4) {
        turnRp();
        turnUp();
        turnR();
        turnU();
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