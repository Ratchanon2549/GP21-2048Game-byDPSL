#include "GameManager.h" // รวมเฮดเดอร์ไฟล์ GameManager
#include <iostream> // ไลบรารีสำหรับ input/output
#include <conio.h> // ใช้ getch() สำหรับรับคีย์บอร์ดแบบไม่ต้องกด Enter
#include <thread> // ไลบรารีสำหรับ thread
#include <chrono> // ไลบรารีสำหรับเวลา
using namespace std; // ใช้เนมสเปซ std

GameManager::GameManager(GameBase* g) : game(g) {} // คอนสตรัคเตอร์ รับอ็อบเจ็กต์เกม

void GameManager::run() { // ฟังก์ชันหลักสำหรับรันเกม
    game->initialize(); // เริ่มต้นเกม
    while (!game->isGameOver()) { // วนลูปจนกว่าเกมจะจบ
        game->display(); // แสดงกระดานเกม
        char key = getch(); // รับคีย์จากผู้ใช้
        if (key == -32) key = getch(); // ถ้าเป็นปุ่มลูกศร ให้รับค่าอีกครั้ง
        char dir; // ตัวแปรเก็บทิศทาง
        switch (key) {
            case 'w': case 72: dir = 'w'; break; // ขึ้น
            case 's': case 80: dir = 's'; break; // ลง
            case 'a': case 75: dir = 'a'; break; // ซ้าย
            case 'd': case 77: dir = 'd'; break; // ขวา
            default: continue; // ถ้าไม่ใช่ปุ่มที่ต้องการ ให้ข้ามรอบนี้
        }
        game->move(dir); // เลื่อนกระดานตามทิศทาง
    }
    game->display(); // แสดงกระดานรอบสุดท้าย
    cout << "Game Over!\n"; // แสดงข้อความจบเกม
    for (int i = 5; i >= 1; --i) { // นับถอยหลัง 5 วินาที
        cout << i << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1)); // หน่วงเวลา 1 วินาที
    }
}

GameManager::~GameManager() { // ดิสทรัคเตอร์
    delete game; // ลบอ็อบเจ็กต์เกมเพื่อคืนหน่วยความจำ
}