#include<iostream>
#include<vector>
#include"raylib.h"

using namespace std;

void DrawBarsSelection(const std::vector<int>& bars, int currentIndex, int nextIndex, bool swapping) {
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

void DrawTextInfoSelection(int currentIndex, int nextIndex, bool swapping, bool sorted) {
	DrawText("Selection Sort Visualization", 10, 10, 20, DARKGRAY);

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

int mainSelection()
{
	const int screenWidth = 1024;
	const int screenHeight = 900;
	const int barWidth = 10;
	const int numBars = screenWidth / barWidth;

	InitWindow(screenWidth, screenHeight, "selection sort");
	SetTargetFPS(60);

	std::vector<int> bars(numBars);
	for (int i = 0; i < numBars; ++i) {
		bars[i] = GetRandomValue(10, screenHeight - 10);
	}

	int i = 0, j = 0 , min_idx = 0;
	bool sorted = false;
	bool swapping = false;


	while (!WindowShouldClose()) {
		//UpdateMusicStream(*backgroundMusic);

		if (!sorted) {
			if (i < numBars - 1) {
				if (j < numBars) {
					if (bars[j] < bars[min_idx]) {
						min_idx = j;
					}
					j++;
				}
				else {
					if (min_idx != i) {
						std::swap(bars[i], bars[min_idx]);
						swapping = true;
					}
					else {
						swapping = false;
					}
					i++;
					j = i + 1;
					min_idx = i;
				}
			}
			else {
				sorted = true;
			}
		}


		BeginDrawing();
		ClearBackground(YELLOW);
		DrawBarsSelection(bars, j, j + 1, swapping);
		DrawTextInfoSelection(j, j + 1, swapping, sorted);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}