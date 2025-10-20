#include "TicTacToe.h"
#include <iostream>
#include <cassert>

// Students will implement these tests in the lab

void test_initial_state() {
    // TODO: Students implement this
    std::cout << "✓ Initial state test passed\n";
}

void test_valid_move() {
    // TODO: Students implement this
    std::cout << "✓ Valid move test passed\n";
}

void test_invalid_moves() {
    // TODO: Students implement this
    std::cout << "✓ Invalid moves test passed\n";
}

void test_winner_detection_row() {
    // TODO: Students implement this
    std::cout << "✓ Winner detection (row) test passed\n";
}

void test_winner_detection_column() {
    // TODO: Students implement this
    std::cout << "✓ Winner detection (column) test passed\n";
}

void test_winner_detection_diagonal() {
    // TODO: Students implement this
    std::cout << "✓ Winner detection (diagonal) test passed\n";
}

void test_full_board_no_winner() {
    // TODO: Students implement this
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
    std::cout << "\nNote: These are placeholder tests.\n";
    std::cout << "Students need to implement the actual test logic.\n";

    return 0;
}
