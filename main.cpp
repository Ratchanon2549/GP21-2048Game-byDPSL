#include "ScoreTrackingGame.h" // รวมไฟล์เฮดเดอร์ของ ScoreTrackingGame ซึ่งเป็นคลาสลูกของ Game2048 ใช้ระบบเก็บคะแนนสูงสุด
#include "GameManager.h" // รวมไฟล์เฮดเดอร์ของ GameManager สำหรับควบคุมการทำงานของเกม

int main() { // จุดเริ่มต้นของโปรแกรม (ฟังก์ชันหลัก)
    GameManager manager(new ScoreTrackingGame()); // สร้างอ็อบเจกต์ GameManager โดยส่ง ScoreTrackingGame แบบ dynamic allocation เข้าไป
    manager.run(); // เรียกเมธอด run() เพื่อเริ่มการเล่นเกม
    return 0; // ส่งค่า 0 กลับให้ระบบปฏิบัติการ แสดงว่าโปรแกรมจบสมบูรณ์
}
