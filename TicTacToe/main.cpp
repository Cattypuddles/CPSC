#include <iostream>
#include "TicTacToe.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    TicTacToe* tic = new TicTacToe();

    tic->play();

    return 0;
}
