#include "Block.h"
using namespace std;

Block::Block() { // Default Constructor
    cellSize = 30;
    rotationState = 0;
    colours = getCellColours();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(int offset_x, int offset_y) { // Drawing Blocks
    vector<Position> Tiles = getCellPositions();
    for (Position item : Tiles) {
        DrawRectangle((item.cols * cellSize) + offset_x, (item.rows * cellSize) + offset_y, cellSize - 1, cellSize - 1, colours[ID]);
    }
}

void Block::Move(int rows, int columns) { // Moving Block
    rowOffset += rows;
    colOffset += columns;
}

vector<Position> Block::getCellPositions() { // Getting Block Position tiles
    vector<Position> Tiles = cells.at(rotationState); // Initial Position
    vector<Position> movedTiles;
    for (Position item : Tiles) {
        Position newPosition = Position(item.rows + rowOffset, item.cols + colOffset); // Changing Position
        movedTiles.push_back(newPosition); // Updating Position
    }
    return movedTiles; // Return Updated Position
}

void Block::Rotate() { // Rotating Blocks
    rotationState++;
    if (rotationState == (int)cells.size()) {
        rotationState = 0;
    }
}

void Block::undoRotation() { // Undo last rotation (Collision Handling)
    rotationState--;
    if (rotationState == -1) {
        rotationState = cells.size() - 1;
    }
}
