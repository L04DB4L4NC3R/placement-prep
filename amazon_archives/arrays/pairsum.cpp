// https://practice.geeksforgeeks.org/problems/pair-sum-in-vector/1
pair<int, int> customsum(pair<int, int> p1, pair<int, int> p2) {
    p2.second = p1.second + p2.second;
    return p2;
}
void sum(vector<pair<int,int>>v)
{
    long long sum=0;
    //Your code here
    pair<int, int> zer;
    zer.second = 0;
    cout << accumulate(v.begin(), v.end(), zer, customsum).second;
    cout<<endl;
}
