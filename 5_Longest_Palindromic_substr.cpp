Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

class Solution {
    
//http://www.cnblogs.com/easonliu/p/4454213.html two cases: (1) mix > i + p[j], p[i] starts with p[j]; (2) mix < i+ p[j], p[i] starts with (mix-i)
    
public:
    /*
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {

  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  
  int maxLen = 0;
  int centerIndex = 0;
  
  
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
     // Find the maximum element in P.
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }

    
  }
 
  
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
  */
   
string longestPalindrome(string s) {

        string s1;
        s1.resize(2 * s.length() + 2);
        int idx = 0;
        s1[idx++] = '$';
        s1[idx++] = '#';
        for (char a : s) {
            s1[idx++] = a;
            s1[idx++] = '#';
        }
       
        vector<int> p(s1.length(), 0);
        int res = 0, maxLen=0;
        for (int id = 0, i = 1; i < s1.length(); ++i) {
            if (i < id + p[id]) p[i] = min(p[2 * id - i], id + p[id] - i);
            else p[i] = 1;
            while (i + p[i]<s1.length() &&  s1[i + p[i]] == s1[i - p[i]]) ++p[i];
            if (id + p[id] < i + p[i]) id = i;
            if (p[i] >maxLen){
               res = i;
               maxLen=p[i];
            } 
        }
        return s.substr( ( res-1-(maxLen-1) )/2, maxLen - 1); // (res-1)/2 is the original index, (maxLen-1) is the length of the Palindrome (center at (res-1)/2). Therefore, (res-1)/2 - (maxLen-1)/2 is the index in the original string. 
  
  
  
}
};
