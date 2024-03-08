#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[]);
void selection(int arr[]);

int main() {
	int array1[9] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
	int array2[9] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
	printf("array 1 bubble:\n");
	bubble(array1);
	printf("\narray 2 bubble:\n");
	bubble(array2);
	int array3[9] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 }; //creates new identical arrays since first function modified them
	int array4[9] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
	printf("\narray 1 selection:\n");
	selection(array3);
	printf("\narray 2 selection:\n");
	selection(array4);
}

void bubble(int arr[]) {
	int i = 0;
	int swapCount[10] = { 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //acts as a counter for the specific index of a value
	int totalSwaps = 0; //both swapCount and totalSwaps serve the same purpose in both functions
	int temp;
	for (i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i] < arr[j]) {
				swapCount[i]++;
				swapCount[j]++;
				temp = swapCount[i];
				swapCount[i] = swapCount[j];
				swapCount[j] = temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				totalSwaps++;
			}
		}
	}
	for (i = 0; i < 9; i++) {
		printf("%d : %d times swapped\n", arr[i], swapCount[i]);
	}
	printf("total swaps: %d\n\n", totalSwaps);
}

void selection(int arr[]) {
	int temp, totalSwaps = 0;
	int lowest;
	int swapCount[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 9; i++) {
		lowest = i;
		for (int j = i; j < 9; j++) {
			if (arr[lowest] > arr[j])
				lowest = j;
			if (j == 8 && lowest != i) {
				swapCount[i]++;
				swapCount[lowest]++;
				temp = swapCount[i];
				swapCount[i] = swapCount[lowest];
				swapCount[lowest] = temp;
				temp = arr[i];
				arr[i] = arr[lowest];
				arr[lowest] = temp;
				totalSwaps++;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		printf("%d : %d times swapped\n", arr[i], swapCount[i]);
	}
	printf("%d total swaps\n", totalSwaps);
}