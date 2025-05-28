#ifndef SCORE_TRACKING_GAME_H
#define SCORE_TRACKING_GAME_H

#include "Game2048.h"
#include <string>

class ScoreTrackingGame : public Game2048 {
private:
    int highScore = 0;
    const std::string saveFile = "highscore.txt";

public:
    ScoreTrackingGame();
    void loadHighScore();
    void saveHighScore() const;
    int getHighScore() const override;
    void addScore(int delta) override;
    ~ScoreTrackingGame();
};

#endif