#include "game.h"
#include <random>

Game::Game() {  // Default Constructor
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    GameOver = false;
    score = 0;
    level = 1;
    totalLinesCleared = 0;
}

Block Game::getRandomBlock() { // Randomly selects a Block
    if(blocks.empty()){
        blocks = getAllBlocks();
    }

    int RandomIndex = rand() % blocks.size();
    Block block = blocks[RandomIndex];
    blocks.erase(blocks.begin() + RandomIndex);

    return block;
}

vector<Block> Game::getAllBlocks() { // Initializing Blocks Set
    return {Block_I(), Block_J(), Block_L(), Block_O(), Block_S(), Block_T(), Block_Z()};
}

void Game::Draw() { // Renders elements
    grid.Draw();
    currentBlock.Draw(11, 11);

    if(!GameOver){
        switch(nextBlock.ID){
            case 3:
            nextBlock.Draw(257, 370);
            break;

            case 4:
            nextBlock.Draw(254, 355);
            break;

            default:
            nextBlock.Draw(273, 350);
        }
    }
}

void Game::ManageInput() { // Handles user input
    int keyPressed = GetKeyPressed();

    if(GameOver && keyPressed != 0){
        GameOver = false;
        ResetGame();
    }

    switch(keyPressed){
        case KEY_LEFT: // Left Shift
            MoveBlockLeft();
            break;

        case KEY_RIGHT: // Right Shift
            MoveBlockRight(); 
            break;

        case KEY_DOWN: // Down Shift
            MoveBlockDown(); 
            UpdateScore(0,1);
            break;

        case KEY_UP: // Rotate Block
            RotateBlock(); 
            break;
    }
}

void Game::MoveBlockLeft() { // Moves Block left
    if(!GameOver){
        currentBlock.Move(0,-1);
        if(isBlockOutside() || BlockFits() == false){
            currentBlock.Move(0,1);
        }
    }
}

void Game::MoveBlockRight() { // Moves Block right
    if(!GameOver){
        currentBlock.Move(0,1);
        if(isBlockOutside() || BlockFits() == false){
            currentBlock.Move(0,-1);
        }
    }
}

void Game::MoveBlockDown() { // Moves Block down
    if(!GameOver){
        currentBlock.Move(1,0);
        if(isBlockOutside() || BlockFits() == false){
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}

bool Game::isBlockOutside() { // Checks if current Block is outside grid
    vector<Position> Tiles = currentBlock.getCellPositions();
    for (Position item : Tiles){
        if(grid.isCellOutside(item.rows, item.cols)){
            return true;
        }
    }
    return false;
}

void Game::RotateBlock() { // Rotates current Block
    if(!GameOver){
        currentBlock.Rotate();
        if(isBlockOutside() || BlockFits() == false){
            currentBlock.undoRotation();
        }
    }
}

void Game::LockBlock() { // Locks Block into grid when it lands
    vector<Position> Tiles = currentBlock.getCellPositions();
    for(Position item : Tiles){
        grid.grid[item.rows][item.cols] = currentBlock.ID;
    }

    currentBlock = nextBlock;
    if(BlockFits() == false){
        GameOver = true;
    }

    nextBlock = getRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}


bool Game::BlockFits() { // Checks if current Block fits in current position
    vector<Position> Tiles = currentBlock.getCellPositions();
    for(Position item : Tiles){
        if(grid.isCellEmpty(item.rows, item.cols) == false){
            return false;
        }
    }
    return true;
}

void Game::ResetGame() { // Resets Game 
    grid.Initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;
    totalLinesCleared = 0;
    level = 1;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints) { // Updates Score and Level
    score += linesCleared * 100;

    totalLinesCleared += linesCleared;
 
    int newLevel = totalLinesCleared / 10 + 1;
    
    if (newLevel > level) {
        level = newLevel;
    }

    score += moveDownPoints;
}