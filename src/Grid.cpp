#include "Grid.h"
#include <iostream>
#include "colours.h"
using namespace std;

Grid::Grid() { // Default Constructor
    rows = 20;
    cols = 10;
    cellSize = 30; 
    Initialize(); // Fills grid with 0's
    colours = getCellColours(); 
}

void Grid::Initialize() { // Initializing with 0's
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            grid[i][j] = 0; // Represent empty cell with 0
        }
    }
}

void Grid::Print() { // Prints the grid to the console
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << grid[i][j] << " "; 
        }
        cout << endl;
    }
}

void Grid::Draw() { // Renders Grid
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            int cellValue = grid[i][j];
            DrawRectangle((j * cellSize) + 11, (i * cellSize) + 11, cellSize - 1, cellSize - 1, colours[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int columns) { // Checks if cell is out of boundaries
    if(row >= 0 && row < rows && columns >= 0 && columns < cols){
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int columns) { // Checks if cell contains a 0
    if(grid[row][columns] == 0){
        return true;
    }
    return false;
}

bool Grid::IsRowFull(int row) { // Checks if row is full
    for (int column = 0; column < cols; column++) {
        if (grid[row][column] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) { // Clears row if it is full
    for (int i = 0; i < cols; i ++) {
        grid[row][i] = 0; // Empties complete row
    }
}

int Grid::ClearFullRows() { // Clears full rows and returns number of cleared rows
    int completed = 0;
    for (int i = rows - 1; i >= 0; i--) {
        if (IsRowFull(i)) {
            ClearRow(i);
            completed++;
        } else if (completed > 0) {
            MoveRowDown(i, completed); // Push row down by 'completed' number of rows
        }
    }
    return completed;
}

void Grid::MoveRowDown(int row, int numRows) { // Moves down n number of rows
    for (int column = 0; column < cols; column++) {
        grid[row + numRows][column] = grid[row][column]; // Copy cell down
        grid[row][column] = 0; // Clear original cell
    }
}
