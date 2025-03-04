#include <iostream>
#include "raylib.h"

int mainBubble();
int mainSelection();
int mainInsertion();
int mainMerge();

using namespace std;
int main()
{
    Color Dark_Green = Color{ 20,160,133,255 };

    const int screenWidth = 1024;
    const int screenHeight = 900;
    

    cout << "Hello World!\n";

    InitWindow(screenWidth, screenHeight, "Sorting Visualizer");
    InitAudioDevice(); 
    SetTargetFPS(60);
    
    Image icon = LoadImage("C:/Users/IDEAPAD/Downloads/pngasset.png");
    if (icon.data != NULL) {
        SetWindowIcon(icon);
    }
    else {
        cout << "Failed to load image!" << endl;
    }



    while (WindowShouldClose() == false) {
        Vector2 mousePoint = GetMousePosition();


        Rectangle bubbleButtonBounds = { screenWidth / 2 - 100 , screenHeight / 2,200,50 };
        bool bubbleButtonHover = CheckCollisionPointRec(mousePoint, bubbleButtonBounds);
        bool bubbleButtonPressed = bubbleButtonHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

        Rectangle selectionButtonBounds = { screenWidth / 2 - 100 , screenHeight / 2 + 70,200,50 };
        bool selectionButtonHover = CheckCollisionPointRec(mousePoint, selectionButtonBounds);
        bool selectionButtonPressed = selectionButtonHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

        Rectangle insertionButtonBounds = { screenWidth / 2 - 100 , screenHeight / 2 + 140,200,50 };
        bool insertionButtonHover = CheckCollisionPointRec(mousePoint, insertionButtonBounds);
        bool insertionButtonPressed = insertionButtonHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

        Rectangle mergeButtonBounds = { screenWidth / 2 - 100 , screenHeight / 2 + 210,200,50 };
        bool mergeButtonHover = CheckCollisionPointRec(mousePoint, mergeButtonBounds);
        bool mergeButtonPressed = mergeButtonHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);




        

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Sorting Visualizer", screenWidth / 2 - MeasureText("Sorting Visualizer", 40) / 2, screenHeight / 2 - 100, 40, BLACK);

        DrawRectangleRec(bubbleButtonBounds, bubbleButtonHover ? LIGHTGRAY : GRAY);
        DrawText("Bubble Sort", screenWidth / 2 - MeasureText("Bubble Sort", 20) / 2, screenHeight / 2 + 15, 20, BLACK);

        DrawRectangleRec(selectionButtonBounds, selectionButtonHover ? LIGHTGRAY : GRAY);
        DrawText("Selection Sort", screenWidth / 2 - MeasureText("Selection Sort", 20) / 2, screenHeight / 2 + 85, 20, BLACK);

        DrawRectangleRec(insertionButtonBounds, insertionButtonHover ? LIGHTGRAY : GRAY);
        DrawText("Insertion Sort", screenWidth / 2 - MeasureText("Insertion Sort", 20) / 2, screenHeight / 2 + 155, 20, BLACK);

        DrawRectangleRec(mergeButtonBounds, mergeButtonHover ? LIGHTGRAY : GRAY);
        DrawText("Merge Sort", screenWidth / 2 - MeasureText("Merge Sort", 20) / 2, screenHeight / 2 + 225, 20, BLACK);


        if (bubbleButtonPressed) {
            mainBubble();
        }
        if (selectionButtonPressed)
        {
            mainSelection();
        }
        if (insertionButtonPressed)
        {
            mainInsertion();
        }
        if (mergeButtonPressed)
        {
            mainMerge();
        }

        EndDrawing();
    }
    CloseAudioDevice();

    CloseWindow();
    return 0;
}

