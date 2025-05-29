#ifndef GAME2048_H // ป้องกันไม่ให้ include ไฟล์นี้ซ้ำ
#define GAME2048_H // เริ่มต้น header guard

#include "GameBase.h"
#include <vector>
#include <utility>

class Game2048 : public GameBase { // ประกาศคลาส Game2048 ซึ่งสืบทอดจาก GameBase
public: // ส่วนที่เปิดให้ใช้งานจากภายนอก
    virtual int getHighScore() const; // เมธอดสำหรับดึงคะแนนสูงสุด (อาจ override ได้ในคลาสลูก)
    virtual void addScore(int delta); // เมธอดสำหรับเพิ่มคะแนน (อาจ override ได้ในคลาสลูก)
    void initialize() override; // เริ่มต้นเกมใหม่ (โอเวอร์ไรด์จาก GameBase)
    void display() override; // แสดงกระดานเกม (โอเวอร์ไรด์จาก GameBase)
    bool move(char direction) override; // ขยับกระดานตามทิศทาง (โอเวอร์ไรด์จาก GameBase)
    bool isGameOver() override; // ตรวจสอบว่าเกมจบหรือยัง (โอเวอร์ไรด์จาก GameBase)

private: // ส่วนภายในของคลาสที่ใช้เฉพาะภายในเท่านั้น
    void spawnTile(); // ฟังก์ชันสุ่มเพิ่มเลขใหม่ (เช่น 2 หรือ 4) บนกระดาน
};

#endif