#include<iostream>
#include<vector>
#include"raylib.h"

using namespace std;

void DrawBarsInsertion(const std::vector<int>& bars, int currentIndex, int nextIndex, bool swapping) {
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

void DrawTextInfoInsertion(int currentIndex, int nextIndex, bool swapping, bool sorted) {
	DrawText("Insertion Sort Visualization", 10, 10, 20, DARKGRAY);

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

int mainInsertion()
{
	const int screenWidth = 1024;
	const int screenHeight = 900;
	const int barWidth = 10;
	const int numBars = screenWidth / barWidth;

	InitWindow(screenWidth, screenHeight, "insertion sort");
	SetTargetFPS(60);

	std::vector<int> bars(numBars);
	for (int i = 0; i < numBars; ++i) {
		bars[i] = GetRandomValue(10, screenHeight - 10);
	}

	int i = 0, j = 0, key = 0;
	bool sorted = false;
	bool swapping = false;


	while (!WindowShouldClose()) {
		//UpdateMusicStream(*backgroundMusic);

		if (!sorted) {
			if (i < numBars) {
				key = bars[i];
				j = i - 1;

				while (j >= 0 && bars[j] > key) {
					bars[j + 1] = bars[j];
					j--;
					swapping = true;
				}
				bars[j + 1] = key;

				if (j != i - 1) {
					swapping = true;
				}
				else {
					swapping = false;
				}

				i++;
			}
			else {
				sorted = true;
			}
		}


		BeginDrawing();
		ClearBackground(YELLOW);
		DrawBarsInsertion(bars, j, j + 1, swapping);
		DrawTextInfoInsertion(j, j + 1, swapping, sorted);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}