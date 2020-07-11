/*
 
18.9
Numbers are randomly generated and passed to a method. Write a program to
find and maintain the median value as new values are generated.

*/

#include <iostream>
#define MAX_ITERATIONS 1000
#define MAX_RANDOM 100000
using namespace std;

struct sortbysecond {
	bool operator()(pair<int, int> const& a, pair<int, int> const& b) const {
		return a.second > b.second;
	}
};

float randomnum() {
	return rand() % MAX_RANDOM;
}

pair<int, int> running_mode = pair<int, int>(0, 0);

// [1] get the random number
// [2] generate new mean
// [3] enter num in the frequency array
// [4] Keep a pair of the max mode and its frequency and update it whenever freq array sees a larger value
// [5] use this formula to get the median: < mean - mode = 3(mean - median) >
// therefore < median = (2*mean + mode)/3
// [6] update running mean and mode
void getrunningmedian(double running_mean, int freq[]) {
	static int count = 0;
	if (++count == MAX_ITERATIONS) {
		return;
	}
	int rnd = randomnum();
	running_mean = ((count * running_mean) + rnd)/(count + 1);

	freq[rnd]++; // register frequency
	// calculate the new mode
	if (freq[rnd] > running_mode.second) {
		running_mode.second = freq[rnd];
		running_mode.first = rnd;
	} else {
	}

	int median = (2 * running_mean + running_mode.first) / 3;

	cout << median << endl;
	getrunningmedian(running_mean, freq);
}

int main() {
	int freq[MAX_RANDOM];
	double running_mean = 0;
	srand(time(NULL)); // for randomizing
	getrunningmedian(running_mean, freq);
	return 0;
}
