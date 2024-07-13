#include<iostream>
#include<vector>
#include"raylib.h"

using namespace std;

void DrawBarsMerge(const std::vector<int>& bars, int left, int mid, int right, int currentIndex, int nextIndex, bool merging) {
    for (size_t i = 0; i < bars.size(); ++i) {
        Color color = BLUE;
        if (i >= left && i <= right) {
            color = GREEN;
        }
        if (i == currentIndex || i == nextIndex) {
            color = RED;
        }
        DrawRectangle(i * 10, 900 - bars[i], 10 - 1, bars[i], color);
    }
}

void DrawTextInfoMerge(int left, int mid, int right, int currentIndex, int nextIndex, bool merging, bool sorted) {
    DrawText("Merge Sort Visualization", 10, 10, 20, DARKGRAY);

    if (sorted) {
        DrawText("Array is sorted!", 10, 40, 20, GREEN);
    }
    else {
        DrawText(TextFormat("Merging: bars[%d] to bars[%d]", left, right), 10, 40, 20, DARKGRAY);
        DrawText(TextFormat("Comparing: bars[%d] and bars[%d]", currentIndex, nextIndex), 10, 70, 20, DARKGRAY);
    }
}

void merge(std::vector<int>& bars, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = bars[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = bars[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            bars[k] = L[i];
            i++;
        }
        else {
            bars[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        bars[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        bars[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& bars, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(bars, left, mid);
        mergeSort(bars, mid + 1, right);

        merge(bars, left, mid, right);
    }
}

int mainMerge() {
    const int screenWidth = 1024;
    const int screenHeight = 900;
    const int barWidth = 10;
    const int numBars = screenWidth / barWidth;

    InitWindow(screenWidth, screenHeight, "Merge Sort");
    SetTargetFPS(60);

    std::vector<int> bars(numBars);
    for (int i = 0; i < numBars; ++i) {
        bars[i] = GetRandomValue(10, screenHeight - 10);
    }

    bool sorted = false;
    int left = 0;
    int right = numBars - 1;
    int currentStep = 0;

    while (!WindowShouldClose()) {
        if (!sorted) {
            if (currentStep < numBars) {
                mergeSort(bars, left, right);
                sorted = true;
            }
        }

        BeginDrawing();
        ClearBackground(YELLOW);
        DrawBarsMerge(bars, left, left + (right - left) / 2, right, 0, 0, false);
        DrawTextInfoMerge(left, left + (right - left) / 2, right, 0, 0, false, sorted);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
