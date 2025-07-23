#pragma once
#include <vector>
#include "Position.h"
#include "colours.h"
using namespace std;

class Block {
protected: // Data Members
    int cellSize; // Size of each cell
    int rotationState; // Current Rotation State of Block
    vector<Color> colours; // List of Block Colours
    int rowOffset; // Vertical Translation
    int colOffset; // Horizontal Translation

public:
    Block(); // Default Constructor
    virtual void Draw(int offset_x, int offset_y); // Drawing Blocks
    virtual void Move(int rows, int columns); // Moving Block
    virtual void Rotate(); // Rotating Blocks
    void undoRotation(); // Undo last rotation (Collision Handling)
    int ID; // Unique ID for each Block
    vector<vector<Position>> cells; 
    vector<Position> getCellPositions(); // Getting Block Position tiles
};

class Block_L : public Block { // Block L
public:
    Block_L();
};

class Block_J : public Block { // Block J
public:
    Block_J();
};

class Block_I : public Block { // Block I
public:
    Block_I();
};

class Block_O : public Block { // Block O
public:
    Block_O();
};

class Block_S : public Block { // Block S
public:
    Block_S();
};

class Block_T : public Block { // Block T
public:
    Block_T();
};

class Block_Z : public Block { // Block Z
public:
    Block_Z();
};
