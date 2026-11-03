#include "game.h"
#include <iostream>

Game::Game(std::string title) : m_title (std::move(title)), m_last_score(0) {}

const std::string& Game::title() const {
    return m_title;
}

int Game::last_score() const {
    return m_last_score;
}

void Game::play() {
 std::cout << "Game::play called";
}

void Game::ask_play_again() const {
    char choice = 'n';
    std::cout << "Want to play again? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y'){
    return true;
 } else {
    std::cout << "Good bye!\n";
    return false;
  }
}
