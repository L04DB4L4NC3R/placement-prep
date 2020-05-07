// https://practice.geeksforgeeks.org/problems/occurences-of-2-as-a-digit/1
long long int numberOf2sinRange(long long int number)
{
// Your code goes here
  string s;
  for(int i = 2; i <= number; ++i) {
      s += to_string(i);
  }
  return count(s.begin(), s.end(), '2');
}
