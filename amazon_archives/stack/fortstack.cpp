// https://practice.geeksforgeeks.org/problems/sort-a-stack/1
void SortedStack :: sort()
{
   //Your code here
   vector<int> v;
   int top;
   while(!s.empty()) {
       top = s.top();
       s.pop();
       v.push_back(top);
   }
   std::sort(v.begin(), v.end());
   for(auto i : v) {
       s.push(i);
   }
}
