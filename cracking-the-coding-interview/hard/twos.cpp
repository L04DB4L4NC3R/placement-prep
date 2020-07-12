/*
 
18.4 Write a method to count the number of 2s that appear in all the numbers
between 0 and n (inclusive).
EXAMPLE
Input: 25
Output: 9 (2,12,20,21,22,23, 24 and 25. Note that 22 counts for two 2s.)

*/

// NOTE: had to see solution
// approach:
/*
 * consider digits of the number. for example number = 625403
 * [1] go digit by digit
 * [2] if digit < 2 then return count -> round down to the nearest 10^(d+1) / 10 {eg: for 2 its 60000)
 * [3] if digit > 2 then round up to the nearest 10^(d+1) / 10
 * [4] if digit = 2 then first case + right size of number + 1
 */

#include <iostream>
#include <math.h>
using namespace std;

int count2s_in_digitplace(int num, int d) {
	int powerof10 = pow(10, d);
	int nextpowerof10 = pow(10, d+1);
	int right = num % powerof10;

	int roundDown = num - (num % nextpowerof10);
	int roundUp = roundDown + nextpowerof10;

	int digit = (num / powerof10) % 10;

	if (digit < 2) {
		return roundDown/10;
	} else if (digit == 2) {
		return roundDown/10 + right + 1;
	} else {
		return roundUp/10;
	}
}

int main() {
	int number = 25;
	int count = 0;

	int n = to_string(number).length();

	for(int d = 0; d < n; ++d) {
		count += count2s_in_digitplace(number, d);
	}
	cout << count;
	return 0;
}
