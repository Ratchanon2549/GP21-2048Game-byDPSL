#include "Game2048.h" // รวมเฮดเดอร์ไฟล์ของ Game2048
#include <iostream> // ไลบรารีสำหรับ input/output
#include <iomanip> // ไลบรารีสำหรับจัดรูปแบบการแสดงผล
#include <cstdlib> // ไลบรารีสำหรับฟังก์ชันสุ่ม
#include <ctime> // ไลบรารีสำหรับเวลา

using namespace std; // ใช้เนมสเปซ std

void Game2048::initialize() { // ฟังก์ชันเริ่มต้นกระดานเกม
    srand(time(0)); // กำหนด seed สำหรับสุ่ม
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0; // กำหนดค่าเริ่มต้นของกระดานเป็น 0
    spawnTile(); // สุ่มตัวเลขใหม่
    spawnTile(); // สุ่มตัวเลขใหม่อีกครั้ง
}

void Game2048::display() { // ฟังก์ชันแสดงผลกระดาน
    system("cls"); // ล้างหน้าจอ (ใช้ "clear" บน Linux/Mac)
    cout << "2048 GAME (Use Arrow Keys: W/A/S/D)\n"; // แสดงชื่อเกมและปุ่มควบคุม
    cout << "Score: " << score << "\n"; // แสดงคะแนนปัจจุบัน
    cout << "High Score: " << getHighScore() << "\n"; // แสดงคะแนนสูงสุด
    cout << "+------------------------+\n"; // ขีดเส้นขอบ
    for (int i = 0; i < SIZE; i++) {
        cout << "|";
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                cout << setw(6) << "."; // ถ้าเป็น 0 ให้แสดงจุด
            else
                cout << setw(6) << board[i][j]; // แสดงตัวเลข
        }
        cout << " |\n";
    }
    cout << "+------------------------+\n"; // ขีดเส้นขอบล่าง
}

bool Game2048::move(char direction) { // ฟังก์ชันเลื่อนกระดานตามทิศทาง
    bool moved = false; // ตัวแปรตรวจสอบว่ามีการเคลื่อนที่หรือไม่

    for (int i = 0; i < SIZE; i++) {
        vector<int> line; // สร้างแถวหรือคอลัมน์ชั่วคราว
        for (int j = 0; j < SIZE; j++) {
            int val;
            switch (direction) {
                case 'w': val = board[j][i]; break; // ขึ้น
                case 's': val = board[SIZE - 1 - j][i]; break; // ลง
                case 'a': val = board[i][j]; break; // ซ้าย
                case 'd': val = board[i][SIZE - 1 - j]; break; // ขวา
            }
            if (val != 0) line.push_back(val); // เก็บเฉพาะค่าที่ไม่เป็น 0
        }

        for (size_t j = 0; j + 1 < line.size(); j++) {
            if (line[j] == line[j + 1]) {
                line[j] *= 2; // รวมเลขที่เท่ากัน
            addScore(line[j]); // เพิ่มคะแนนเมื่อรวมเลข
                line.erase(line.begin() + j + 1); // ลบตัวที่รวมแล้ว
                moved = true; // มีการเคลื่อนที่
            }
        }

        while (line.size() < SIZE) line.push_back(0); // เติม 0 ให้ครบขนาด

        for (int j = 0; j < SIZE; j++) {
            int& target = (direction == 'w') ? board[j][i]
                            : (direction == 's') ? board[SIZE - 1 - j][i]
                            : (direction == 'a') ? board[i][j]
                                                 : board[i][SIZE - 1 - j];
            if (target != line[j]) {
                target = line[j]; // อัปเดตค่าบนกระดาน
                moved = true; // มีการเคลื่อนที่
            }
        }
    }

    if (moved) spawnTile(); // ถ้ามีการเคลื่อนที่ให้สุ่มตัวเลขใหม่
    return moved; // คืนค่าผลลัพธ์
}

bool Game2048::isGameOver() { // ฟังก์ชันตรวจสอบว่าเกมจบหรือยัง
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 0)
                return false; // ถ้ายังมีช่องว่าง เกมยังไม่จบ

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE - 1; j++)
            if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i])
                return false; // ถ้ายังมีเลขที่รวมกันได้ เกมยังไม่จบ

    return true; // เกมจบแล้ว
}

void Game2048::spawnTile() { // ฟังก์ชันสุ่มตัวเลขใหม่บนกระดาน
    vector<pair<int, int>> empty; // เก็บตำแหน่งที่ว่าง
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 0)
                empty.emplace_back(i, j); // เพิ่มตำแหน่งที่ว่าง

    if (!empty.empty()) {
        auto [x, y] = empty[rand() % empty.size()]; // เลือกตำแหน่งว่างแบบสุ่ม
        board[x][y] = (rand() % 10 < 9) ? 2 : 4; // สุ่มเลข 2 หรือ 4
    }
}

// Definitions for virtual functions to avoid vtable linker errors

// Definitions for virtual functions to avoid vtable linker errors
int Game2048::getHighScore() const {
    return 0; // คืนค่า high score (ตัวอย่าง)
}

void Game2048::addScore(int delta) {
    this->score += delta; // เพิ่มคะแนน
}
