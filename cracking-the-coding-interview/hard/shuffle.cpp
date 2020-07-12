/*
 
18.2
Write a method to shuffle a deck of cards. It must be a perfect shuffle—in other
words, each of the 52! permutations of the deck has to be equally likely. Assume that
you are given a random number generator which is perfect.

*/

#include <iostream>
using namespace std;

void shuffle(int arr[], int n) {
	int index;
	srand(time(NULL));
	for (int i = 1; i < n; ++i) {
		index = rand() % i;
		swap(arr[i], arr[index]);
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << endl;
	}

}

int main() {
	int cards[] = {1,2,3,4,5,6,7,8,9,10};
	shuffle(cards, sizeof(cards)/sizeof(int));
	return 0;
}
