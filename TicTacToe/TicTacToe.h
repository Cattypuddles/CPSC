//
// Created by victo on 5/10/2023.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H


class TicTacToe {
public:
    TicTacToe();
    ~TicTacToe();

    void play();

private:
    void initializeGrid();
    void displayGrid();
    std::tuple<int, int> findFirstUnoccupiedSquare();
    std::tuple<int, int> promptForGridCoord();
    bool checkForDraw();
    bool checkForWin();

private:
    char** pp_cGrid= nullptr;
};


#endif //TICTACTOE_TICTACTOE_H
