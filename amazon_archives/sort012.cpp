// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
void sort012(int a[], int n)
{
    // coode here 
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            sum1++;
        } else if (a[i] == 2) {
            sum2++;
        }
    }
    int zeroes = n - sum1 - sum2;

    
    for(int i = 0; i < n; ++i) {
        if (i < zeroes) {
            a[i] = 0;
        } else if (i < zeroes + sum1) {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
    }
}
