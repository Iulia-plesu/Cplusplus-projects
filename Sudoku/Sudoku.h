#pragma once
#include <array>

class Sudoku {
private:
    static const int N = 9;
    int grid[N][N];
    bool original[N][N];
    int level;

    void printGrid();
    bool isSolved();
    void generateSudoku();
    bool solveSudoku();
    bool isSafe(int row, int col, int num);

public:
    Sudoku(int difficultyLevel);
    void play();
};