#pragma once
#include <vector>
#include <raylib.h>
using namespace std;

class Grid { // Game Board Grid
private:
    int rows;
    int cols;
    int cellSize; 
    bool IsRowFull(int row); // Checks if row is full
    void ClearRow(int row); // Clears row if it is full 
    void MoveRowDown(int row, int numOfRows); // Moves down n number of rows
    vector<Color> colours; // Stores Block Colours

public:
    Grid(); // Default Constructor
    void Initialize(); // Initializing with 0's
    void Print(); // Prints the grid to the console
    void Draw(); // Renders Grid
    bool isCellOutside(int rows, int columns); // Checks if cell is out of boundaries
    bool isCellEmpty(int row, int columns); // Checks if cell contains a 0
    int ClearFullRows(); // Clears full rows and returns number of cleared rows
    int grid[20][10]; // 2D Static Array to represent state of each cell

};

