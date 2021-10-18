#include <iostream>
#include "Cube.h"
#include "Face.h"


int main() {
    char colors[6] = {'y', 'b', 'r', 'g', 'o', 'w'};
    Cube rubiks(colors);
    rubiks.mixCube();
    rubiks.solveCube();
    rubiks.printCube();

}
