Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

class Solution {
    /* http://bangbingsyb.blogspot.com/2014/11/leetcode-regular-expression-matching.html
    DP 关键在于如何处理这个'*'号。

状态：和Mininum Edit Distance这类题目一样。
dp[i][j]表示s[0:i-1]是否能和p[0:j-1]匹配。

递推公式：由于只有p中会含有regular expression，所以以p[j-1]来进行分类。
p[j-1] != '.' && p[j-1] != '*'：dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
p[j-1] == '.'：dp[i][j] = dp[i-1][j-1]

而关键的难点在于 p[j-1] = '*'。由于星号可以匹配0，1，乃至多个p[j-2]。
1. 匹配0个元素，即消去p[j-2]，此时p[0: j-1] = p[0: j-3]
dp[i][j] = dp[i][j-2]

2. 匹配1个元素，此时p[0: j-1] = p[0: j-2]
dp[i][j] = dp[i][j-1]

3. 匹配多个元素，此时p[0: j-1] = { p[0: j-2], p[j-2], ... , p[j-2] } // p[0, ..., j-1] matches even after removing s[i-1] (>1 matches in total)
dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-2]==p[j-2])*/

public:
    bool isMatch(string s, string p) {
     
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
        dp[0][0] = true;
    
        for(int i=0; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if( p[j-1]!='*') {
                    if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='.' ))
                        dp[i][j] =  dp[i-1][j-1];
                }
                else if(j>1) {  //'*' cannot be the 1st element
                    if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') ) // remove one element from s, still may match: multiple matches (with preceding elements)
                        dp[i][j] = dp[i-1][j];
                    dp[i][j] =dp[i][j-1] || dp[i][j-2] || dp[i][j]; // match one dp[i][j-1] ('*'' is not counted); match zero dp[i][j-2]
                }
            }
        }
        return dp[m][n];
  
    
    //http://articles.leetcode.com/2011/09/regular-expression-matching.html
    //    return helper(s,p,0,0);
    }
    /* DP   
private:
    bool helper(string s, string p, int i, int j)
    {
        if(j == p.length()) {
            return i == s.length();
        }
        
        // next char is not '*': must match current character
        if(j == p.length() - 1 || p[j + 1] != '*') {
            if(i == s.length() || p[j] != '.' && p[j] != s[i]) {
                return false;
            } else {
                return helper(s,p,i+1,j+1);
            }
        }
        
        // next char is '*'
        // case:  "aaa" "a*a". Inside the loop, must call helper
        while(i < s.length() && (s[i] == p[j] || p[j] == '.')) {
            if(helper(s,p,i,j+2)) {
                return true;
            }
            ++i;
        }
        return helper(s,p,i,j+2);
    }

      */
    
};
