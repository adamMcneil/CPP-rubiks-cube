#include <iostream>
#include "Cube.h"
using namespace std;

int main() {
    char colors[6] = {'y','b','r','g','o','w'};
    Cube cube(colors);
    cube.turnU();
    for (int i = 0; i < 6; i++){
        Face face = cube.getFace(i);
        cout << endl;
        for (int j = 0; j < 9; j++){
            if (j % 3 == 0 ){
                cout << endl;
            }
            cout << face.getColor(j);
        }
    }
}
