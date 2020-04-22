#include <iostream>
#include <chrono>
#define NUM 100
#define NIL -1

using namespace std; 
using namespace std::chrono;

double arr[NUM];

void initialize() {
	for(int i = 0; i < NUM; ++i) {
		arr[i] = NIL;
	}
} 

double fib(int x) {
		if (arr[x] != NIL) {
			return arr[x];
		}
		if (x == 0 || x == 1) {
				return x;
		} else {
				arr[x] =  fib(x-1) + fib(x-2);
				return arr[x];
		}
}

int main() {
		auto start = high_resolution_clock::now();
		initialize();
		for(int i = 0; i < NUM; ++i) {
  	  cout << fib(i) << " ";
		}	
		auto stop = high_resolution_clock::now();
		cout << endl << "TIME OF EXECUTION: " << endl;
		cout << duration_cast<microseconds>(stop - start).count();
		return 0;
}
