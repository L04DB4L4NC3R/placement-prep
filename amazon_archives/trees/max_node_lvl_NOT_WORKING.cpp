// https://practice.geeksforgeeks.org/problems/maximum-node-level/1
int maxNodeLevel(Node *root)
{
   if (!root)
     return -1;
   queue<Node *> q;

   q.push(root);
   int l = 0, maxcnt = 0, maxlvl = 0, n = 0;
   Node *t;
   while(!q.empty()) {
       // take queue size.
       // check if size > maxcnt
       n = q.size();
       if (maxcnt < n) {
           maxcnt = n;
           maxlvl = l;
       }
       // pop from queue and add children
       while(n > 0) {
           t = q.front();
           q.pop();
           n--;
           if (t -> left) {
               q.push(t -> left);
           }
           if (t -> right) {
               q.push(t -> right);
           }
       }
       // increment level
       l++;
   }
   return maxlvl;
}

/* NOTE: The following code is not working:
void solve(Node *ref, unordered_map<int, int> &m, int lvl) {
    if(!ref)
      return;
    m[lvl]++;
    solve(ref -> left, m, lvl + 1);
    solve(ref -> right, m, lvl + 1);
}
int maxNodeLevel(Node *root)
{
 // Add your code here
 unordered_map<int, int> m;
 solve(root, m, 0);
 int maxval = INT_MIN, minlvl = 0;
 for(auto i : m) {
     if (i.second > maxval) {
         maxval = i.second;
         minlvl = i.first;
     }
 }
 return minlvl;
}
*/
