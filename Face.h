//
// Created by adam on 8/12/21.
//

#ifndef UNTITLED_FACE_H
#define UNTITLED_FACE_H


class Face {
public:
    Face(char);
    char getColor(int i);
    void setSquare(int position, char color);

private:
    char color;
    char face[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
};


#endif //UNTITLED_FACE_H
