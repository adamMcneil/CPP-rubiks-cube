#include <iostream>
#include "Cube.h"
#include "Face.h"


int main() {
    char colors[6] = {'y', 'b', 'r', 'g', 'o', 'w'};
    Cube rubiks(colors);

    rubiks.turnR();
    rubiks.turnU();
    rubiks.turnU();
    rubiks.turnB();
    rubiks.turnDp();
    rubiks.turnL();
    rubiks.turnD();
    rubiks.turnBp();
    rubiks.turnF();
    rubiks.turnLp();
    rubiks.turnRp();
    rubiks.turnUp();
    rubiks.turnFp();
    rubiks.turnR();
    rubiks.turnU();
    rubiks.turnB();
    rubiks.turnDp();
    rubiks.turnL();
    rubiks.turnD();

    rubiks.printCube();
}
