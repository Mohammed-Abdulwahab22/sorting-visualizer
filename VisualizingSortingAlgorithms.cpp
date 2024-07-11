#include <iostream>
#include "raylib.h"

int mainBubble();
int mainSelection();

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


        Rectangle bubbleButtonBounds = { screenWidth / 2 - 100 , screenHeight / 2,200,50 };
        bool bubbleButtonHover = CheckCollisionPointRec(mousePoint, bubbleButtonBounds);
        bool bubbleButtonPressed = bubbleButtonHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

        Rectangle selectionButtonBounds = { screenWidth / 2 - 100 , screenHeight / 2 + 70,200,50 };
        bool selectionButtonHover = CheckCollisionPointRec(mousePoint, selectionButtonBounds);
        bool selectionButtonPressed = selectionButtonHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);


        

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Sorting Visualizer", screenWidth / 2 - MeasureText("Sorting Visualizer", 40) / 2, screenHeight / 2 - 100, 40, BLACK);

        DrawRectangleRec(bubbleButtonBounds, bubbleButtonHover ? LIGHTGRAY : GRAY);
        DrawText("Bubble Sort", screenWidth / 2 - MeasureText("Bubble Sort", 20) / 2, screenHeight / 2 + 15, 20, BLACK);

        DrawRectangleRec(selectionButtonBounds, selectionButtonHover ? LIGHTGRAY : GRAY);
        DrawText("Selection Sort", screenWidth / 2 - MeasureText("Selection Sort", 20) / 2, screenHeight / 2 + 85, 20, BLACK);


        if (bubbleButtonPressed) {
            //DrawText("Button Pressed!", screenWidth / 2 - MeasureText("Button Pressed!", 20) / 2, screenHeight / 2 + 100, 20, RED);
            mainBubble();
        }
        if (selectionButtonPressed)
        {
            mainSelection();
        }

        EndDrawing();
    }
   /* UnloadMusicStream(backgroundMusic);
    CloseAudioDevice();*/

    CloseWindow();
    return 0;
}

