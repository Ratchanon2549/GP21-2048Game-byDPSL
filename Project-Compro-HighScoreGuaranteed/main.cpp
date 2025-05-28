#include "ScoreTrackingGame.h"
#include "GameManager.h"

int main() {
    GameManager manager(new ScoreTrackingGame());
    manager.run();
    return 0;
}