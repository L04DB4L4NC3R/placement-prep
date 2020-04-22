#include <iostream>
#include <chrono>
#define NUM 100

using namespace std; 
using namespace std::chrono;

int fib(int x) {
		if (x == 0 || x == 1) {
				return x;
		} else {
				return fib(x-1) + fib(x-2);
		}
}

int main() {
				auto start = high_resolution_clock::now();
				for(int i = 0; i < NUM; ++i) {
								cout << fib(i) << " ";
				}	
				auto stop = high_resolution_clock::now();
				cout << endl << "TIME OF EXECUTION: " << endl;
				cout << duration_cast<microseconds>(stop - start).count();
				return 0;
}
