#ifndef GAMEBASE_H // ป้องกันไม่ให้รวมไฟล์นี้ซ้ำหลายครั้ง
#define GAMEBASE_H // เริ่มการกำหนดเงื่อนไขของ header guard


const int SIZE = 4;

class GameBase { // คลาสฐานแบบ abstract สำหรับเกม (ใช้เป็นพ่อแบบ)
protected: // ส่วนที่คลาสลูกสามารถเข้าถึงได้
    int score = 0; // ตัวแปรเก็บคะแนนของผู้เล่น

protected: // ยังอยู่ในส่วน protected
    int board[SIZE][SIZE]; // กระดานเกมขนาด 4x4 ใช้เก็บตัวเลขบนกระดาน


public: // ส่วนที่สามารถเรียกใช้งานจากภายนอกคลาสได้
    GameBase(); // คอนสตรัคเตอร์เริ่มต้น
    virtual void initialize() = 0; // เมธอดบริสุทธิ์ (pure virtual) สำหรับเริ่มต้นเกม
    virtual void display() = 0; // เมธอดบริสุทธิ์สำหรับแสดงกระดาน
    virtual bool move(char direction) = 0; // เมธอดบริสุทธิ์สำหรับเลื่อนกระดานตามทิศทางที่รับเข้ามา
    virtual bool isGameOver() = 0; // เมธอดบริสุทธิ์สำหรับตรวจสอบว่าเกมจบหรือยัง
    virtual ~GameBase() {} // เดสตรัคเตอร์แบบเสมือน (virtual destructor) เพื่อให้ลบผ่านพอยน์เตอร์คลาสฐานได้ปลอดภัย
};

#endif // สิ้นสุดเงื่อนไขของ header guard
