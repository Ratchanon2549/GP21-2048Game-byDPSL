@echo off
:: ปิดการแสดงคำสั่งขณะรัน เพื่อให้หน้าจอดูสะอาด

echo [INFO] Compiling 2048 Game with High Score tracking...
:: แสดงข้อความแจ้งว่ากำลังคอมไพล์โปรแกรม

g++ -std=c++20 main.cpp GameBase.cpp Game2048.cpp GameManager.cpp ScoreTrackingGame.cpp -o game2048.exe
:: คอมไพล์ไฟล์ทั้งหมดให้เป็นโปรแกรมชื่อ game2048.exe โดยใช้มาตรฐาน C++20

IF %ERRORLEVEL% NEQ 0 (
    :: ถ้าเกิดข้อผิดพลาดจากการคอมไพล์ (ERRORLEVEL ไม่เท่ากับ 0)
    
    echo [ERROR] Compilation failed.
    :: แสดงข้อความแจ้งว่าคอมไพล์ล้มเหลว

    pause
    :: หยุดรอผู้ใช้กดปุ่มใด ๆ เพื่ออ่านข้อความ

    exit /b %ERRORLEVEL%
    :: ออกจาก batch script พร้อมคืนค่า error ไปยังระบบ
)

echo [SUCCESS] Compilation complete! Run game2048.exe to play.
:: แสดงข้อความว่าคอมไพล์เสร็จสมบูรณ์

pause
:: หยุดรอผู้ใช้กดปุ่ม เพื่อให้เห็นข้อความสุดท้ายก่อนหน้าต่างปิด
