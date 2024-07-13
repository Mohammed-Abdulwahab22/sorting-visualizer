#include <iostream>
#include <vector>
#include "raylib.h"

using namespace std;

void DrawBarsQuick(const std::vector<int>& bars, int currentIndex, int nextIndex, bool swapping) {
    for (size_t i = 0; i < bars.size(); ++i) {
        Color color = BLUE;
        if (i == currentIndex) {
            color = RED;
        }
        else if (i == nextIndex) {
            color = GREEN;
        }
        DrawRectangle(i * 10, 900 - bars[i], 10 - 1, bars[i], color);
    }
}

void DrawTextInfoQuick(int currentIndex, int nextIndex, bool swapping, bool sorted) {
    DrawText("Quick Sort Visualization", 10, 10, 20, DARKGRAY);

    if (sorted) {
        DrawText("Array is sorted!", 10, 40, 20, GREEN);
    }
    else {
        DrawText(TextFormat("Comparing: bars[%d] and bars[%d]", currentIndex, nextIndex), 10, 40, 20, DARKGRAY);
        if (swapping) {
            DrawText("Swapping!", 10, 70, 20, RED);
        }
        else {
            DrawText("No Swap", 10, 70, 20, DARKGRAY);
        }
    }
}

void QuickSort(std::vector<int>& bars, int low, int high, int& currentIndex, int& nextIndex, bool& swapping, bool& sorted) {
    if (low < high) {
        int pivot = bars[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (bars[j] < pivot) {
                i++;
                std::swap(bars[i], bars[j]);
                currentIndex = i;
                nextIndex = j;
                swapping = true;
            }
        }
        std::swap(bars[i + 1], bars[high]);
        currentIndex = i + 1;
        nextIndex = high;
        swapping = true;

        int partitionIndex = i + 1;

        QuickSort(bars, low, partitionIndex - 1, currentIndex, nextIndex, swapping, sorted);
        QuickSort(bars, partitionIndex + 1, high, currentIndex, nextIndex, swapping, sorted);
    }
    else {
        sorted = true;
    }
}

int mainQuick()
{
    const int screenWidth = 1024;
    const int screenHeight = 900;
    const int barWidth = 10;
    const int numBars = screenWidth / barWidth;

    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");
    SetTargetFPS(60);

    std::vector<int> bars(numBars);
    for (int i = 0; i < numBars; ++i) {
        bars[i] = GetRandomValue(10, screenHeight - 10);
    }

    int currentIndex = -1, nextIndex = -1;
    bool swapping = false;
    bool sorted = false;

    QuickSort(bars, 0, numBars - 1, currentIndex, nextIndex, swapping, sorted);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(YELLOW);
        DrawBarsQuick(bars, currentIndex, nextIndex, swapping);
        DrawTextInfoQuick(currentIndex, nextIndex, swapping, sorted);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
