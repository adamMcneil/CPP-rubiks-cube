#include <iostream>
#include "Cube.h"
#include "Face.h"


int main() {
    char colors[6] = {'y', 'b', 'r', 'g', 'o', 'w'};
    Cube rubiks(colors);

    rubiks.turnR();
    rubiks.turnU();
    rubiks.turnRp();
    rubiks.turnUp();
    rubiks.turnLp();
    rubiks.turnFp();
    rubiks.turnBp();

    rubiks.printCube();
}
