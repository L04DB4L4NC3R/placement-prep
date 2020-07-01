#include <iostream>
using namespace std;

// func prototypes
void mergesort(int arr[], int helper[], int low, int high, int n);
void merge(int arr[], int helper[], int low, int middle, int high, int n);

// initializer
void mergesort(int arr[], int n) {
	int helper[n];
	mergesort(arr, helper, 0, n-1, n);
	printf("DONE\n");
}

// driver function
void mergesort(int arr[], int helper[], int low, int high, int n) {
	if (low < high) {

		// compute the middle of the array
		// i.e. to split by
		int middle = (low + high)/2;

		// sort the left side
		mergesort(arr, helper, low, middle, n);

		// sort the right side
		mergesort(arr, helper, middle + 1, high, n);

		// merge the two parts
		merge(arr, helper, low, middle, high, n);
	}
}

// merging left and right parts
void merge(int arr[], int helper[], int low, int middle, int high, int n) {
	// copy all elements to the helper array
	for (int i = low; i <= high; ++i) {
		helper[i] = arr[i];
	}

	int helperLeft = low;
	int helperRight = middle + 1;
	int current = low;

	// loop and compare both the arrays' elements to see chuch one is smaller
	while (helperLeft <= middle && helperRight <= high) {

		// if left side is less than the right side then copy it into the original array
		// else copy the right one to the original array
		if (helper[helperLeft] <= helper[helperRight]) {
			arr[current] = helper[helperLeft++];
		} else {
			arr[current] = helper[helperRight++];
		}
		current++;
	}

	// copy the remaining elements on the left hand side
	// no need to copy the right ones since they are already there
	int remaining = middle - helperLeft;
	for (int i = 0; i <= remaining; ++i) {
		arr[current + i] = helper[helperLeft + i];
	}
}
