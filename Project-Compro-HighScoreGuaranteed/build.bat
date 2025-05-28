@echo off
echo [INFO] Compiling 2048 Game with High Score tracking...
g++ -std=c++20 main.cpp GameBase.cpp Game2048.cpp GameManager.cpp ScoreTrackingGame.cpp -o game2048.exe
IF %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compilation failed.
    pause
    exit /b %ERRORLEVEL%
)
echo [SUCCESS] Compilation complete! Run game2048.exe to play.
pause