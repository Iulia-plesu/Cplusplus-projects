#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

Sudoku::Sudoku(int difficultyLevel) : level(difficultyLevel) {
    std::srand(std::time(nullptr));
    generateSudoku();
}


void Sudoku::printGrid() {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) {
            std::cout << "------|-------|------\n";
        }
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) {
                std::cout << "| ";
            }
            std::cout << grid[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

bool Sudoku::isSolved() {
    std::array<std::array<bool, N>, N> rows = { false };
    std::array<std::array<bool, N>, N> cols = { false };
    std::array<std::array<bool, N>, N> boxes = { false };

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {

            int num = grid[row][col] - 1;

            if (num >= 0 && num < N) {

                int box_index = (row / 3) * 3 + (col / 3);
                if (rows[row][num] || cols[col][num] || boxes[box_index][num]) {
                    return false;
                }
                rows[row][num] = cols[col][num] = boxes[box_index][num] = true;
            }
        }
    }
    return true;
}

void Sudoku::generateSudoku() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            grid[row][col] = 0;
            original[row][col] = false;
        }
    }

    int numMiniSudokusCompleted = 0;
    while (numMiniSudokusCompleted < N) {
        solveSudoku();

        int numToRemove;
        switch (level) {
        case 1:
            numToRemove = 35;
            break;
        case 2:
            numToRemove = 50;
            break;
        case 3:
        default:
            numToRemove = 65;
            break;
        }

        while (numToRemove > 0) {
            int row = std::rand() % N;
            int col = std::rand() % N;

            if (!original[row][col] && grid[row][col] != 0) {
                grid[row][col] = 0;
                numToRemove--;
            }
        }

        numMiniSudokusCompleted++;
    }
}

bool Sudoku::isSafe(int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    for (int y = 0; y < N; y++) {
        if (grid[y][col] == num) {
            return false;
        }
    }

    int start_row = 3 * (row / 3);
    int start_col = 3 * (col / 3);
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::solveSudoku() {
    int row, col;
    bool emptyCell = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptyCell = true;
                break;
            }
        }
        if (emptyCell) {
            break;
        }
    }

    if (!emptyCell)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku())
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

void Sudoku::play() {
    std::cout << "Initial Sudoku puzzle:" << std::endl;
    printGrid();

    int row, col, value;
    bool gameFinished = false;

    while (!gameFinished) {
        std::cout << "Enter the row, column, and value: ";
        std::cin >> row >> col >> value;

        if (row < 1 || row > 9 || col < 1 || col > 9 || value < 1 || value > 9) {
            std::cout << "Invalid input.\n";
            continue;
        }

        if (!original[row - 1][col - 1]) {
            grid[row - 1][col - 1] = value;
        }
        else {
            std::cout << "You can't modify the original numbers.\n";
            continue;
        }

        std::cout << "Updated Sudoku puzzle:" << std::endl;
        printGrid();

        if (isSolved()) {
            std::cout << "Congratulations! You solved the Sudoku!\n";
            gameFinished = true;
        }
    }
}