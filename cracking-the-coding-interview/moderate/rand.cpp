/* 
17.11 Implement a method rand7() given randSQ.That is, given a method that
generates a random number between 0 and 4 (inclusive), write a method that
generates a random number between 0 and 6 (inclusive).
*/

#include <iostream>
using namespace std;

int rand5() {
	return rand() % 5;
}

int rand7() {
	return rand5() + rand5()%3;
}

int main() {
	// srand avoid pseudorandom values
	// like randomize()
	srand(time(NULL));
	cout << rand5() << endl;
	cout << rand7();
	return 0;
}
