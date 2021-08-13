//
// Created by adam on 8/12/21.
//

#include "Face.h"

Face::Face(char givenColor) {
    for (int i = 0; i < 9; i++){
        face [i] = givenColor;
    }
}
    char Face::getColor(int i) {
        return face[i];
    }
    void Face::setSquare(int position, char color) {
    face[position] = color;
}

