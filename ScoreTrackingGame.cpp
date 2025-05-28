#include "ScoreTrackingGame.h" // รวมเฮดเดอร์ไฟล์ของ ScoreTrackingGame
#include <fstream> // รวมไลบรารีสำหรับจัดการไฟล์
#include <iostream> // รวมไลบรารีสำหรับ input/output

// คอนสตรัคเตอร์ของคลาส ScoreTrackingGame
ScoreTrackingGame::ScoreTrackingGame() : highScore(0) {
    loadHighScore(); // โหลดคะแนนสูงสุดจากไฟล์
    std::cout << "[DEBUG] Loaded High Score: " << highScore << std::endl; // แสดงผลคะแนนสูงสุดที่โหลดมา (สำหรับดีบัก)
}

// โหลดคะแนนสูงสุดจากไฟล์
void ScoreTrackingGame::loadHighScore() {
    std::ifstream file(saveFile); // สร้าง input file stream เพื่ออ่านไฟล์
    if (file.is_open()) { // ตรวจสอบว่าไฟล์เปิดสำเร็จหรือไม่
        file >> highScore; // อ่านคะแนนสูงสุดจากไฟล์
        file.close(); // ปิดไฟล์
    } else {
        std::cout << "[DEBUG] highscore.txt not found. Will create new." << std::endl; // แสดงผลหากไม่พบไฟล์ (สำหรับดีบัก)
    }
}

// บันทึกคะแนนสูงสุดลงไฟล์
void ScoreTrackingGame::saveHighScore() const {
    std::ofstream file(saveFile); // สร้าง output file stream เพื่อเขียนไฟล์
    if (file.is_open()) { // ตรวจสอบว่าไฟล์เปิดสำเร็จหรือไม่
        file << highScore; // เขียนคะแนนสูงสุดลงไฟล์
        file.close(); // ปิดไฟล์
        std::cout << "[DEBUG] Saved High Score: " << highScore << std::endl; // แสดงผลเมื่อบันทึกคะแนนสูงสุดสำเร็จ (สำหรับดีบัก)
    }
}

// ดึงคะแนนสูงสุด
int ScoreTrackingGame::getHighScore() const {
    return highScore; // คืนค่าคะแนนสูงสุด
}

// เพิ่มคะแนน
void ScoreTrackingGame::addScore(int delta) {
    score += delta; // เพิ่มคะแนน
    std::cout << "[DEBUG] Score updated: " << score << std::endl; // แสดงผลคะแนนที่อัปเดต (สำหรับดีบัก)

    if (score > highScore) { // ตรวจสอบว่าคะแนนปัจจุบันมากกว่าคะแนนสูงสุดหรือไม่
        highScore = score; // อัปเดตคะแนนสูงสุด
    }

    saveHighScore(); // บันทึกคะแนนสูงสุด (✅ บันทึกคะแนนสูงสุดเสมอ แม้ว่าจะไม่เปลี่ยนแปลง)
}

// Destructor ของคลาส ScoreTrackingGame
ScoreTrackingGame::~ScoreTrackingGame() {
    saveHighScore(); // บันทึกคะแนนสูงสุดเมื่อออบเจ็กต์ถูกทำลาย
}