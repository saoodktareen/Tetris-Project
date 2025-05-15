#include "block.h"
#include "Position.h"

class Block_L : public Block{
private:
public:
    Block_L(){  // Block L
        ID = 1;
        cells = {
            {Position(0,2), Position(1,0), Position(1,1), Position(1,2)}, // For Rotation State 0
            {Position(0,1), Position(1,1), Position(2,1), Position(2,2)}, // For Rotation State 1
            {Position(1,0), Position(1,1), Position(1,2), Position(2,0)}, // For Rotation State 2
            {Position(0,0), Position(0,1), Position(1,1), Position(2,1)} // For Rotation State 3
        };
        Move(0,3); // To start from center
    }
};

class Block_J : public Block{
private:
public:
    Block_J(){ // Block J
        ID = 2;
        cells = {
            {Position(0,0), Position(1,0), Position(1,1), Position(1,2)}, // For Rotation State 0
            {Position(0,1), Position(0,2), Position(1,1), Position(2,1)}, // For Rotation State 1
            {Position(1,0), Position(1,1), Position(1,2), Position(2,2)}, // For Rotation State 2
            {Position(0,1), Position(1,1), Position(2,0), Position(2,1)} // For Rotation State 3
        };
        Move(0,3);
    }
};

class Block_I : public Block{
private:
public:
    Block_I(){ // Block I
        ID = 3;
        cells = {
            {Position(1,0), Position(1,1), Position(1,2), Position(1,3)}, // For Rotation State 0
            {Position(0,2), Position(1,2), Position(2,2), Position(3,2)}, // For Rotation State 1
            {Position(2,0), Position(2,1), Position(2,2), Position(2,3)}, // For Rotation State 2
            {Position(0,1), Position(1,1), Position(2,1), Position(3,1)} // For Rotation State 3
        };
        Move(-1,3); // It has different center coordinates
    }
};

class Block_O : public Block{
private:
public:
    Block_O(){ // Block O
        ID = 4;
        cells = {{Position(0,0), Position(0,1), Position(1,0), Position(1,1)}}; // As all Rotation States are same
        Move(0,4); // It has different center coordinates
    }
};

class Block_S : public Block{
private:
public:
    Block_S(){ // Block S
        ID = 5;
        cells = {
            {Position(0,1), Position(0,2), Position(1,0), Position(1,1)}, // For Rotation State 0
            {Position(0,1), Position(1,1), Position(1,2), Position(2,2)}, // For Rotation State 1
            {Position(1,1), Position(1,2), Position(2,0), Position(2,1)}, // For Rotation State 2
            {Position(0,0), Position(1,0), Position(1,1), Position(2,1)} // For Rotation State 3
        };
        Move(0,3);
    }
};

class Block_T : public Block{
private:
public:
    Block_T(){ // Block T
        ID = 6;
        cells = {
            {Position(0,1), Position(1,0), Position(1,1), Position(1,2)}, // For Rotation State 0
            {Position(0,1), Position(1,1), Position(1,2), Position(2,1)}, // For Rotation State 1
            {Position(1,0), Position(1,1), Position(1,2), Position(2,1)}, // For Rotation State 2
            {Position(0,1), Position(1,0), Position(1,1), Position(2,1)} // For Rotation State 3
        };
        Move(0,3);
    }
};


class Block_Z : public Block{
private:
public:
    Block_Z(){ // Block Z
        ID = 7;
        cells = {
            {Position(0,0), Position(0,1), Position(1,1), Position(1,2)}, // For Rotation State 0
            {Position(0,2), Position(1,1), Position(1,2), Position(2,1)}, // For Rotation State 1
            {Position(1,0), Position(1,1), Position(2,1), Position(2,2)}, // For Rotation State 2
            {Position(0,1), Position(1,0), Position(1,1), Position(2,0)} // For Rotation State 3
        };
        Move(0,3);
    }
};



