#include <iostream>
#include "raylib.h"

using namespace std;


void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for ( i = 0; i < n-1; i++)
	{
		swapped = false;
		for ( j = 0; j < n-i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
}

void printArray(int arr[], int size)
{
	int i;
	for ( i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}

int main()
{
	int arr[] = { 64,34,25,12,22,11,90 };
	int N = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, N);
	cout << "Sorted Array: \n";
	printArray(arr, N);



	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "bubble sort");
	SetTargetFPS(60);

	while (WindowShouldClose() == false)
	{

	}
	
	CloseWindow();
	return 0;
}