// https://practice.geeksforgeeks.org/problems/replace-all-0s-with-5/1
int convertFive(int n) {
    // Your code here
    string s = to_string(n);
    
    for(int i = 0; i < s.length(); ++i) {
        if (s[i] == '0')
          s[i] = '5';
    }
    
    return atoi(s.c_str());
}
