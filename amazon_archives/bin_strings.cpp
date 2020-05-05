/* 
 * https://practice.geeksforgeeks.org/problems/binary-string-1587115620/1
 *
 * string = 10010100001001

binary string count:
4 = 10010100001001
3 = 10100001001
2 = 100001001
1 = 1001
*/
long binarySubstring(int n, string a){
    
    // Your code here
    int ctr = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            ctr++;
        }
    }
    return ctr * (ctr - 1) / 2;
}
