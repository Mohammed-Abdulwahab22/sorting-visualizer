#include <iostream>
#include <vector>
#include "raylib.h"

using namespace std;

//basic implementation for bubble sort
//void bubbleSort(int arr[], int n)
//{
//	int i, j;
//	bool swapped;
//	for ( i = 0; i < n-1; i++)
//	{
//		swapped = false;
//		for ( j = 0; j < n-i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1]) {
//				swap(arr[j], arr[j + 1]);
//				swapped = true;
//			}
//		}
//
//		if (swapped == false) {
//			break;
//		}
//	}
//}
//basic implementation for bubble sort
//void printArray(int arr[], int size)
//{
//	int i;
//	for ( i = 0; i < size; i++)
//	{
//		cout << " " << arr[i];
//	}
//	cout << endl;
//}


void DrawBars(const std::vector<int>& bars, int currentIndex, int nextIndex, bool swapping) {
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

void DrawTextInfo(int currentIndex, int nextIndex, bool swapping, bool sorted) {
	DrawText("Bubble Sort Visualization", 10, 10, 20, DARKGRAY);

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


int mainBubble()
{
	//basic implementation for bubble sort
	//int arr[] = { 64,34,25,12,22,11,90 };
	//int N = sizeof(arr) / sizeof(arr[0]);
	//bubbleSort(arr, N);
	//cout << "Sorted Array: \n";
	//printArray(arr, N);

	const int screenWidth = 1024;
	const int screenHeight = 900;
	const int barWidth = 10;
	const int numBars = screenWidth / barWidth;



	
	InitWindow(screenWidth, screenHeight, "bubble sort");
	SetTargetFPS(60);

	std::vector<int> bars(numBars);
	for (int i = 0; i < numBars; ++i) {
		bars[i] = GetRandomValue(10, screenHeight - 10);
	}

	int i = 0, j = 0;
	bool sorted = false;
	bool swapping = false;

	while (!WindowShouldClose()) {
		//UpdateMusicStream(*backgroundMusic);

		if (!sorted) {
			if (i < numBars - 1) {
				if (j < numBars - i - 1) {
					if (bars[j] > bars[j + 1]) {
						std::swap(bars[j], bars[j + 1]);
						swapping = true;
					}
					else {
						swapping = false;
					}
					j++;
				}
				else {
					j = 0;
					i++;
				}
			}
			else {
				sorted = true;
			}
		}

		BeginDrawing();
		ClearBackground(YELLOW);
		DrawBars(bars, j, j + 1, swapping);
		DrawTextInfo(j, j + 1, swapping, sorted);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}