// 17.7 Given any integer, print an English phrase that describes the integer (e.g., "OneThousand, Two Hundred Thirty Four").

#include <iostream>
#include <cstring>
using namespace std;

string ones[] = {" One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
string tens[] = {" Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
string twos[] = {" Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};

string eng(int x) {
	int digit;
	int prev = -1;
	int place = 0;
	string s;
	while (x != 0) {
		digit = x%10 - 1;
		if (digit == -1) {
			place++;
			x = x/10;
			continue;
		}
		switch (place) {
			case 0:
				s = s + ones[digit];
				prev=digit;
				break;
			case 1:
				s = prev!=-1 && digit==0? twos[prev]:tens[digit] + s;
				break;
			case 2:
				s = ones[digit] + " Hundered" + s;
				break;
			case 3:
				s = ones[digit] + " Thousand" + s;
				break;
			case 4:
				s = tens[digit] + " Thousand" + s;
				break;
		}
		place++;
		x = x/10;
	}
	return s;
}

int main() {
	int s;
	cin >> s;
	cout << eng(s);
	return 0;
}
