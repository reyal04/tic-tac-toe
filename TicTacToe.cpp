#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
    reset();
}

void TicTacToe::reset() {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            board[r][c] = ' ';
    currentPlayer = 'X';
    moveCount = 0;
    winner = ' ';
    gameOver = false;
}

bool TicTacToe::makeMove(int row, int col) {
    if (gameOver) return false;
    if (row < 0 || row >= 3 || col < 0 || col >= 3) return false;
    if (board[row][col] != ' ') return false;

    // Place move
    board[row][col] = currentPlayer;
    moveCount++;

    // Check for win
    if (checkWin(row, col)) {
        winner = currentPlayer;
        gameOver = true;
    }
    // Check for draw
    else if (isFull()) {
        winner = ' '; // No winner in a tie
        gameOver = true;
    }
    else {
        // Switch turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return true;
}

bool TicTacToe::checkWin(int row, int col) const {
    char player = board[row][col];
    if (player == ' ') return false;

    // Check row
    if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
        return true;

    // Check column
    if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
        return true;

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool TicTacToe::isFull() const {
    return moveCount >= 9;
}

bool TicTacToe::isGameOver() const {
    return gameOver;
}

char TicTacToe::getWinner() const {
    // Recalculate winner just in case
    for (int r = 0; r < 3; ++r)
        if (board[r][0] != ' ' &&
            board[r][0] == board[r][1] &&
            board[r][1] == board[r][2])
            return board[r][0];

    for (int c = 0; c < 3; ++c)
        if (board[0][c] != ' ' &&
            board[0][c] == board[1][c] &&
            board[1][c] == board[2][c])
            return board[0][c];

    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    return ' '; // No winner
}

char TicTacToe::getCell(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
        return '?';
    return board[row][col];
}

char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

int TicTacToe::getMoveCount() const {
    return moveCount;
}

void TicTacToe::printBoard() const {
    std::cout << "\n";
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            std::cout << " " << board[r][c];
            if (c < 2) std::cout << " |";
        }
        std::cout << "\n";
        if (r < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}
