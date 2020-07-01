/*
 * Quicksort best time is O(nlogn) and worst is O(n) depends on the pivot point
 * [1] Choose a pivot
 * [2] Find the point where left of pivot is greater than the pivot
 * [3] Find the point where right of the pivot is less than the pivot
 * [4] Swap left and right
 * [5] Repeat 2-4 until left = right
 * [6] When all elems to the left of the pivot are less than it and on the right are greater,
 * then replace the pivot with the left
 * [7] Recurse
 */
#include <iostream>
using namespace std;
void quicksort(int arr[], int left, int right, int n);
int partition(int arr[], int left, int right, int n);

void quick(int arr[], int n) {
	quicksort(arr, 0, n-1, n);
	printf("DONE\n");
}

void quicksort(int arr[], int left, int right, int n) {

	// get stable pivot for subarray
	int index = partition(arr, left, right, n);

	// sort left half of the stable pivot
	if (left < index - 1) {
		quicksort(arr, left, index - 1, n);
	}
	// sort right half of the stable pivot
	if (index < right) {
		quicksort(arr, index, right, n);
	}
}

int partition(int arr[], int left, int right, int n) {
	// choose a pivot
	int pivot = arr[(left + right) / 2];

	while(left <= right) {
		// find element that is greater than the pivot in the left subarray
		while(arr[left] < pivot) left++;

		// find element that is less than the pivot in the right subarray
		while(arr[right] > pivot) right--;

		// after these elementa have been chosen, swap em
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	return left;
}
