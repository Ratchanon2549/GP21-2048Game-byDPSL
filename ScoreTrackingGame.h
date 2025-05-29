#ifndef SCORE_TRACKING_GAME_H // ป้องกันการ include ไฟล์ซ้ำ
#define SCORE_TRACKING_GAME_H // เริ่มต้นการกำหนดขอบเขตของ Header Guard


#include "Game2048.h" // รวมไฟล์ Game2048 เพื่อใช้สืบทอดคุณสมบัติ
#include <string> // สำหรับใช้ตัวแปรชนิด string ในคลาส


class ScoreTrackingGame : public Game2048 { // ประกาศคลาส ScoreTrackingGame ซึ่งสืบทอดมาจาก Game2048
private: // ส่วนของข้อมูลภายในคลาสที่เข้าถึงได้เฉพาะภายในคลาส
    int highScore = 0; // ตัวแปรเก็บคะแนนสูงสุด เริ่มต้นที่ 0
    const std::string saveFile = "highscore.txt"; // ตัวแปรเก็บชื่อไฟล์สำหรับบันทึกคะแนนสูงสุด เป็นค่าคงที่


public: // ส่วนที่สามารถเข้าถึงได้จากภายนอกคลาส
    ScoreTrackingGame(); // คอนสตรัคเตอร์
    void loadHighScore(); // ฟังก์ชันโหลดคะแนนสูงสุดจากไฟล์
    void saveHighScore() const; // ฟังก์ชันบันทึกคะแนนสูงสุดลงไฟล์
    int getHighScore() const override; // ฟังก์ชันดึงคะแนนสูงสุด (โอเวอร์ไรด์จาก Game2048)
    void addScore(int delta) override; // ฟังก์ชันเพิ่มคะแนน (โอเวอร์ไรด์จาก Game2048)
    ~ScoreTrackingGame(); // เดสตรัคเตอร์
};


#endif