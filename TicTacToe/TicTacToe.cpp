//
// Created by victo on 5/10/2023.
//
#include <iostream>
#include <tuple>
#include "TicTacToe.h"

char** pp_cGrid= nullptr;

TicTacToe::TicTacToe(){

    initializeGrid();

}

TicTacToe::~TicTacToe(){

    std::cout << "TicTacToe destructor called." << std::endl;

}

void TicTacToe::play() {

    bool bWin = false;
    bool bDraw = false;
    int iRow = 0;
    int iColumn = 0;

    std::cout << "TicTacToe Game" << std::endl;
    std::cout << std::endl;

    displayGrid();

    while (!bWin && !bDraw){
    //Human Player Turn
    std::tie(iRow, iColumn) = promptForGridCoord();
    this->pp_cGrid[iRow][iColumn] = 'X';

    displayGrid();
    bWin = checkForWin();
    bDraw = checkForDraw();

    //Computer Player Turn
    if (!bWin && !bDraw) {
        std::tie(iRow, iColumn) = findFirstUnoccupiedSquare();
        this->pp_cGrid[iRow][iColumn] = 'O';
        displayGrid();
        bWin = checkForWin();
        bDraw = checkForDraw();
    }

    if (bDraw && !bWin) {
        std::cout << "Draw! " << std::endl;
    }
}

    std::cout << "Game Over. :^)" << std::endl;
    return;
}

void TicTacToe::initializeGrid(){

    TicTacToe::pp_cGrid = new char* [3];
    TicTacToe::pp_cGrid[0] = new char[3];
    TicTacToe::pp_cGrid[1] = new char[3];
    TicTacToe::pp_cGrid[2] = new char[3];

    for (int i = 0; i < 3; i++){
        for (int j=0; j < 3; j++){
            TicTacToe::pp_cGrid[i][j] = '~';
        }
    }

}

void TicTacToe::displayGrid(){
    std::cout << "Game Board:" << std::endl;
    for (int i = 0; i < 3; i++){
        for (int j=0; j < 3; j++){
            std::cout << pp_cGrid[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::tuple<int, int> TicTacToe::findFirstUnoccupiedSquare(){

    int iRowUnoccupied = -1;
    int iColumnUnoccupied = -1;

    bool bFound = false;

    for (int i = 0; i < 3 && !bFound; i++){
        for (int j=0; j < 3 && !bFound; j++){
            if (this->pp_cGrid[i][j] == '~'){
                iRowUnoccupied = i;
                iColumnUnoccupied = j;
                bFound = true;
            }
        }
    }

    std::tuple<int, int> tupleUnoccupiedGridSquare(iRowUnoccupied, iColumnUnoccupied);
    return tupleUnoccupiedGridSquare;

}

std::tuple<int, int> TicTacToe::promptForGridCoord(){

    int iRowUnoccupied = -1;
    bool isRowCorrect = false;
    int iColumnUnoccupied = -1;
    bool isColumnCorrect = false;

    while (!isRowCorrect){
        std::cout << "Please enter next row: " << std::endl;
        std::cin >> iRowUnoccupied;
        if (iRowUnoccupied > 2){
            std::cout << "Row val must be 2 or smaller. Try again." << std::endl;
        }
        if (iRowUnoccupied <= 2){
            isRowCorrect = true;
        }
    }

    while (!isColumnCorrect){
        std::cout << "Please enter next Column: " << std::endl;
        std::cin >> iColumnUnoccupied;
        if (iColumnUnoccupied > 2){
            std::cout << "Row val must be 2 or smaller. Try again." << std::endl;
        }
        if (iColumnUnoccupied <= 2){
            isColumnCorrect = true;
        }
    }

    if (this->pp_cGrid[iRowUnoccupied][iColumnUnoccupied] != '~'){
        std::cout << "Square Occupied. Try again!" << std::endl;
        promptForGridCoord();
    }

    std::tuple<int, int> tuplePromptForGridSquare(iRowUnoccupied, iColumnUnoccupied);
    return tuplePromptForGridSquare;

}

bool TicTacToe::checkForDraw(){

    bool bContinue = false;

    for (int iRow = 0; iRow < 3; iRow++){
        for (int iColumn = 0; iColumn < 3; iColumn++){
            if (this->pp_cGrid[iRow][iColumn] != 'X' && this->pp_cGrid[iRow][iColumn] != 'O'){
                bContinue = true;
            }
        }
    }
    return !bContinue;
}

bool TicTacToe::checkForWin(){

    bool bWin = false;

    //check for three in one row
    for (int iRow = 0; (iRow < 3) && !bWin; iRow++){
        if (this->pp_cGrid[iRow][0] != '~'){
            if ((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1]) &&
                (this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][2])){

                bWin = true;
                std::cout << "WINNER: " << this->pp_cGrid[iRow][0] << "!" << std::endl;
            }
        }
    }

    //Check for three in one Column
    for (int iColumn = 0; (iColumn < 3) && !bWin; iColumn++){
        if (this->pp_cGrid[0][iColumn] != '~'){
            if ((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn]) &&
                (this->pp_cGrid[0][iColumn] == this->pp_cGrid[2][iColumn])){

                bWin = true;
                std::cout << "WINNER: " << this->pp_cGrid[0][iColumn] << "!" << std::endl;
            }
        }
    }

    if (this->pp_cGrid[0][0] != '~'){

        if ((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) &&
            (this->pp_cGrid[0][0] == this->pp_cGrid[2][2])){

            bWin = true;
            std::cout << "WINNER: " << this->pp_cGrid[0][0] << "!" << std::endl;
        }
    }

    if (this->pp_cGrid[0][2] != '~'){

        if ((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) &&
            (this->pp_cGrid[0][2] == this->pp_cGrid[2][0])){

            bWin = true;
            std::cout << "WINNER: " << this->pp_cGrid[0][2] << "!" << std::endl;
        }
    }

    return  bWin;
}