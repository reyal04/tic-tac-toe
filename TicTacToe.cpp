#include "TicTacToe.h"
#include <iostream>
#include <cassert>

// Test 1: Initial state
void test_initial_state() {
    TicTacToe game;
    assert(game.getCurrentPlayer() == 'X');
    assert(game.getMoveCount() == 0);
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            assert(game.getCell(r, c) == ' ');
    assert(!game.isGameOver());
    std::cout << "✓ Initial state test passed\n";
}

// Test 2: Valid move
void test_valid_move() {
    TicTacToe game;
    assert(game.makeMove(0, 0));
    assert(game.getCell(0, 0) == 'X');
    assert(game.getCurrentPlayer() == 'O');
    assert(game.getMoveCount() == 1);
    std::cout << "✓ Valid move test passed\n";
}

// Test 3: Invalid moves
void test_invalid_moves() {
    TicTacToe game;

    // Out of bounds
    assert(!game.makeMove(-1, 0));
    assert(!game.makeMove(3, 3));

    // Valid move first
    assert(game.makeMove(0, 0));
    assert(game.getMoveCount() == 1);

    // Occupied cell
    assert(!game.makeMove(0, 0));

    // Fill up to end the game
    game.makeMove(1, 0); // O
    game.makeMove(0, 1); // X
    game.makeMove(1, 1); // O
    game.makeMove(0, 2); // X
    game.makeMove(1, 2); // O
    game.makeMove(2, 0); // X
    game.makeMove(2, 1); // O
    game.makeMove(2, 2); // X

    // Game is over now
    assert(game.isGameOver());

    // Move after game over should fail
    assert(!game.makeMove(1, 1));
    std::cout << "✓ Invalid moves test passed\n";
}

// Test 4: Winner detection (row)
void test_winner_detection_row() {
    TicTacToe game;
    game.makeMove(0, 0); // X
    game.makeMove(1, 0); // O
    game.makeMove(0, 1); // X
    game.makeMove(1, 1); // O
    game.makeMove(0, 2); // X wins row 0
    assert(game.isGameOver());
    assert(game.getWinner() == 'X');
    std::cout << "✓ Winner detection (row) test passed\n";
}

// Test 5: Winner detection (column)
void test_winner_detection_column() {
    TicTacToe game;
    game.makeMove(0, 1); // X
    game.makeMove(0, 0); // O
    game.makeMove(1, 1); // X
    game.makeMove(1, 0); // O
    game.makeMove(2, 2); // X
    game.makeMove(2, 0); // O wins column 0
    assert(game.isGameOver());
    assert(game.getWinner() == 'O');
    std::cout << "✓ Winner detection (column) test passed\n";
}

// Test 6: Winner detection (diagonal)
void test_winner_detection_diagonal() {
    TicTacToe game;
    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(1, 1); // X
    game.makeMove(0, 2); // O
    game.makeMove(2, 2); // X wins diagonal
    assert(game.isGameOver());
    assert(game.getWinner() == 'X');
    std::cout << "✓ Winner detection (diagonal) test passed\n";
}

// Test 7: Full board, no winner (tie)
void test_full_board_no_winner() {
    TicTacToe game;
    // Fill board:
    // X O X
    // O O X
    // O X O
    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(0, 2); // X
    game.makeMove(1, 0); // O
    game.makeMove(1, 1); // X
    game.makeMove(1, 2); // O
    game.makeMove(2, 0); // X
    game.makeMove(2, 1); // O
    game.makeMove(2, 2); // X

    assert(game.isFull());
    assert(game.isGameOver());
    assert(game.getWinner() == ' ');
    std::cout << "✓ Full board no winner test passed\n";
}

int main() {
    std::cout << "Running Tic-Tac-Toe tests...\n\n";

    test_initial_state();
    test_valid_move();
    test_invalid_moves();
    test_winner_detection_row();
    test_winner_detection_column();
    test_winner_detection_diagonal();
    test_full_board_no_winner();

    std::cout << "\nAll tests passed! ✓\n";
    return 0;
}
