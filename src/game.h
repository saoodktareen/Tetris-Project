#pragma once
#include "Grid.h"
#include "blocks.cpp"
using namespace std;

class Game{
private:
    vector<Block> blocks; // All Block shapes
    vector<Block> getAllBlocks(); // Initializing Blocks Set
    Block currentBlock; // Block currently falling
    Block nextBlock; // Next Block to fall
    Block getRandomBlock(); // Randomly selects a Block
    bool isBlockOutside(); // Checks if current Block is outside grid
    bool BlockFits(); // Checks if current Block fits in current position
    void RotateBlock(); // Rotates current Block
    void LockBlock(); // Locks Block into grid when it lands
    void MoveBlockLeft(); // Moves Block left
    void MoveBlockRight(); // Moves Block right
    void ResetGame(); // Resets Game 
    void UpdateScore(int linesCleared, int moveDownPoints); // Updates Score and Level
    Grid grid; // Game Grid

public:
    Game(); // Default Constructor
    void Draw(); // Renders elements
    void ManageInput(); // Handles user input
    void MoveBlockDown(); // Moves Block down
    int score; // Player Score
    int level; // Player Level
    int totalLinesCleared; // Player Lines Cleared
    bool GameOver; // Checks if Game is over or not
};