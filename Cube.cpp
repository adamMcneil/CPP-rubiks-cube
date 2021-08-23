//
// Created by adam on 8/12/21.
//

#include "Cube.h"
#include <iostream>

Cube::Cube(char colors[6]) {
    for (int i = 0; i < 6; i++) {
        cube[i] = Face(colors[i]);
    }
}

std::string Cube::getOtherMiddleColorYellow(int position) {
    // 1-4
    // 3-1
    // 5-3
    // 7-2
    int i = position;
    int count = 2;
    i -= count;
    while (!(i < 4 && i > 0) && count < 3) {
        count++;
        i -= count;
    }
    std::string str;
    str = this->getFace(abs(i)).getColor(1);
    str.append((abs(i)), 1);
    return str;

}

//void Cube::solveCube() {
//    //solve white
//    int count = 0;
//    int spots[4] = {1, 3, 5, 7};
//    for (int i : spots) {
//        if (this->getFace(0).getColor(i) == 'w') {
//            while ()
//        }
//    }
//    for (Face face : this->cube) {
//        for (int i : spots) {
//            if (face.getColor(i) == 'w') {
//                count++;
//
//            }
//        }
//    }
//
//
//    //
//}

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