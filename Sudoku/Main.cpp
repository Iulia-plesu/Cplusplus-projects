#include <iostream>
#include "Sudoku.h"

int main() {
    int level;
    std::cout << "Choose the difficulty level:\n1: Easy\n2: Medium\n3: Hard\n-> ";
    std::cin >> level;

    Sudoku game(level);

    game.play();

    return 0;
}
