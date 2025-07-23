#include "Block.h"
#include "Position.h"

Block_L::Block_L() { // Block L
    ID = 1;
    cells = {
        {Position(0,2), Position(1,0), Position(1,1), Position(1,2)},
        {Position(0,1), Position(1,1), Position(2,1), Position(2,2)},
        {Position(1,0), Position(1,1), Position(1,2), Position(2,0)},
        {Position(0,0), Position(0,1), Position(1,1), Position(2,1)}
    };
    Move(0, 3);
}

Block_J::Block_J() { // Block J
    ID = 2;
    cells = {
        {Position(0,0), Position(1,0), Position(1,1), Position(1,2)},
        {Position(0,1), Position(0,2), Position(1,1), Position(2,1)},
        {Position(1,0), Position(1,1), Position(1,2), Position(2,2)},
        {Position(0,1), Position(1,1), Position(2,0), Position(2,1)}
    };
    Move(0, 3);
}

Block_I::Block_I() { // Block I
    ID = 3;
    cells = {
        {Position(1,0), Position(1,1), Position(1,2), Position(1,3)},
        {Position(0,2), Position(1,2), Position(2,2), Position(3,2)},
        {Position(2,0), Position(2,1), Position(2,2), Position(2,3)},
        {Position(0,1), Position(1,1), Position(2,1), Position(3,1)}
    };
    Move(-1, 3);
}

Block_O::Block_O() { // Block O 
    ID = 4;
    cells = {
        {Position(0,0), Position(0,1), Position(1,0), Position(1,1)}
    };
    Move(0, 4);
}

Block_S::Block_S() { // Block S
    ID = 5;
    cells = {
        {Position(0,1), Position(0,2), Position(1,0), Position(1,1)},
        {Position(0,1), Position(1,1), Position(1,2), Position(2,2)},
        {Position(1,1), Position(1,2), Position(2,0), Position(2,1)},
        {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}
    };
    Move(0, 3);
}

Block_T::Block_T() { // Block T
    ID = 6;
    cells = {
        {Position(0,1), Position(1,0), Position(1,1), Position(1,2)},
        {Position(0,1), Position(1,1), Position(1,2), Position(2,1)},
        {Position(1,0), Position(1,1), Position(1,2), Position(2,1)},
        {Position(0,1), Position(1,0), Position(1,1), Position(2,1)}
    };
    Move(0, 3);
}

Block_Z::Block_Z() { // Block Z
    ID = 7;
    cells = {
        {Position(0,0), Position(0,1), Position(1,1), Position(1,2)},
        {Position(0,2), Position(1,1), Position(1,2), Position(2,1)},
        {Position(1,0), Position(1,1), Position(2,1), Position(2,2)},
        {Position(0,1), Position(1,0), Position(1,1), Position(2,0)}
    };
    Move(0, 3);
}
