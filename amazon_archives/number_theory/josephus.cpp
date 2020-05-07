// https://practice.geeksforgeeks.org/problems/josephus-problem/1
//
// https://www.youtube.com/watch?v=fZ3p2Iw-O2I
//

int josephus(int n, int k)
{
		// base case; if only 1 playa
		if (n == 1)
				return 1;
		/*
		 * [1] in every iteration, n dec by 1
		 * [2] and the sword is passed to (k-1) index
		 * [3] %n so that the indices remain in the boundds
		 * [4] +1 because index starts from 0
		 */
		return ((k + josephus(n-1, k) - 1)%n + 1);
}

