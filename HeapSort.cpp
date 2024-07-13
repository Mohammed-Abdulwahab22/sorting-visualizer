#include<iostream>
#include<vector>
#include"raylib.h"

using namespace std;

void DrawBarsHeap(const std::vector<int>& bars, int currentIndex, int nextIndex, bool swapping) {
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

void DrawTextInfoHeap(int currentIndex, int nextIndex, bool swapping, bool sorted) {
    DrawText("Heap Sort Visualization", 10, 10, 20, DARKGRAY);

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

void heapify(vector<int>& arr, int n, int i, int& currentIndex, int& nextIndex, bool& swapping) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        currentIndex = i;
        nextIndex = largest;
        swapping = true;
        heapify(arr, n, largest, currentIndex, nextIndex, swapping);
    }
}

void heapSort(vector<int>& arr, int n, int& currentIndex, int& nextIndex, bool& swapping, bool& sorted) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, currentIndex, nextIndex, swapping);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        currentIndex = 0;
        nextIndex = i;
        swapping = true;
        heapify(arr, i, 0, currentIndex, nextIndex, swapping);
    }
    sorted = true;
}

int mainHeap() {
    const int screenWidth = 1024;
    const int screenHeight = 900;
    const int barWidth = 10;
    const int numBars = screenWidth / barWidth;

    InitWindow(screenWidth, screenHeight, "Heap Sort Visualization");
    SetTargetFPS(60);

    std::vector<int> bars(numBars);
    for (int i = 0; i < numBars; ++i) {
        bars[i] = GetRandomValue(10, screenHeight - 10);
    }

    int currentIndex = 0, nextIndex = 0;
    bool sorted = false;
    bool swapping = false;

    while (!WindowShouldClose()) {
        if (!sorted) {
            heapSort(bars, numBars, currentIndex, nextIndex, swapping, sorted);
        }

        BeginDrawing();
        ClearBackground(YELLOW);
        DrawBarsHeap(bars, currentIndex, nextIndex, swapping);
        DrawTextInfoHeap(currentIndex, nextIndex, swapping, sorted);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
