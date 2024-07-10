#include <iostream>
#include "raylib.h"

int mainBubble();

using namespace std;
int main()
{
    Color Dark_Green = Color{ 20,160,133,255 };

    const int screenWidth = 1024;
    const int screenHeight = 900;
    

    cout << "Hello World!\n";

    InitWindow(screenWidth, screenHeight, "Sorting Visualizer");
    SetTargetFPS(60);
    
   /* Image icon = LoadImage("istockphoto - 928418862 - 612x612.jpg");
    SetWindowIcon(icon);*/

    /*Music backgroundMusic = LoadMusicStream("background.mp3");
    PlayMusicStream(backgroundMusic);*/


    while (WindowShouldClose() == false) {
        Vector2 mousePoint = GetMousePosition();
        Rectangle buttonBounds = { screenWidth / 2 - 100 , screenHeight / 2,200,50 };
        bool buttonHover = CheckCollisionPointRec(mousePoint, buttonBounds);
        bool buttonPressed = buttonHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Sorting Visualizer", screenWidth / 2 - MeasureText("Sorting Visualizer", 40) / 2, screenHeight / 2 - 100, 40, BLACK);

        if (buttonHover) {
            DrawRectangleRec(buttonBounds, LIGHTGRAY);
        }
        else {
            DrawRectangleRec(buttonBounds, GRAY);
        }

        DrawText("Bubble Sort", screenWidth / 2 - MeasureText("Bubble Sort", 20) / 2, screenHeight / 2 + 15, 20, BLACK);

        if (buttonPressed) {
            //DrawText("Button Pressed!", screenWidth / 2 - MeasureText("Button Pressed!", 20) / 2, screenHeight / 2 + 100, 20, RED);
            mainBubble();
        }

        EndDrawing();
    }
   /* UnloadMusicStream(backgroundMusic);
    CloseAudioDevice();*/

    CloseWindow();
    return 0;
}

