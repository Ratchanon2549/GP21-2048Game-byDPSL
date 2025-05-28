#include "ScoreTrackingGame.h"
#include <fstream>
#include <iostream>

ScoreTrackingGame::ScoreTrackingGame() : highScore(0) {
    loadHighScore();
    std::cout << "[DEBUG] Loaded High Score: " << highScore << std::endl;
}

void ScoreTrackingGame::loadHighScore() {
    std::ifstream file(saveFile);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        std::cout << "[DEBUG] highscore.txt not found. Will create new." << std::endl;
    }
}

void ScoreTrackingGame::saveHighScore() const {
    std::ofstream file(saveFile);
    if (file.is_open()) {
        file << highScore;
        file.close();
        std::cout << "[DEBUG] Saved High Score: " << highScore << std::endl;
    }
}

int ScoreTrackingGame::getHighScore() const {
    return highScore;
}

void ScoreTrackingGame::addScore(int delta) {
    score += delta;
    std::cout << "[DEBUG] Score updated: " << score << std::endl;

    if (score > highScore) {
        highScore = score;
    }

    saveHighScore(); // ✅ Always save high score, even if unchanged
}

ScoreTrackingGame::~ScoreTrackingGame() {
    saveHighScore();
}