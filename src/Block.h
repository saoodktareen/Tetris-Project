#pragma once
#include <vector>
#include "Position.h"
#include "colours.h"
using namespace std;

// Single Tetris Block 
class Block{ 
private: // Data Members
    int cellSize; // Size of each cell
    int rotationState; // Current Rotation State of Block
    vector<Color> colours; // List of Block Colours
    int rowOffset; // Vertical Translation
    int colOffset; // Horizontal Translation

public:
    Block(); // Default Constructor
    void Draw(int offset_x, int offset_y); // Drawing Blocks
    void Move(int rows, int columns); // Moving Block
    void Rotate(); // Rotating Blocks
    void undoRotation(); // Undo last rotation (Collision Handling)
    int ID; // Unique ID for each Block
    vector<vector<Position>> cells;;
    vector<Position> getCellPositions(); // Getting Block Position tiles
};