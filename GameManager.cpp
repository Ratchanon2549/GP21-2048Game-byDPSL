#include "GameManager.h"
#include <iostream>
#include <conio.h> // ใช้ getch()
#include <thread>
#include <chrono>
using namespace std;

GameManager::GameManager(GameBase* g) : game(g) {}

void GameManager::run() {
    game->initialize();
    while (!game->isGameOver()) {
        game->display();
        char key = getch();
        if (key == -32) key = getch(); // arrow keys
        char dir;
        switch (key) {
            case 'w': case 72: dir = 'w'; break;
            case 's': case 80: dir = 's'; break;
            case 'a': case 75: dir = 'a'; break;
            case 'd': case 77: dir = 'd'; break;
            default: continue;
        }
        game->move(dir);
    }
    game->display();
    cout << "Game Over!\n";
    for (int i = 5; i >= 1; --i) {
        cout << i << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

GameManager::~GameManager() {
    delete game;
}