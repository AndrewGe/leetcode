Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
 
        int start = 0; // current start point of substring without dup  
        int maxlen = 0; // max length of substring found  
        int table[256]; // hash table for index of each char appeared  
        for (int i = 0;i < 256;i++) table[i] = -1; // if char not present, index is -1  
        int len = s.length();  
        for (int i = 0;i < len;i++) {  
            if (table[s[i]] != -1) {  
                while (start <= table[s[i]]) table[s[start++]] = -1;  
            }  
            if (i - start + 1 > maxlen) maxlen = i - start + 1;  
            table[s[i]] = i;  
        }  
        return maxlen;  
    */
    set<char> charSet;
    int result=0, left=0, right=0;
    
    for(; right<s.size(); right++){
        result=max(result, right-left);
        if (charSet.find(s[right]) != charSet.end() ){
            while(s[left]!=s[right]){
                charSet.erase(s[left]);
                left++;
            }
            left++;
        }
        else{
            charSet.insert(s[right]);
        }
    }
    // if the longest substring ends at the end of the string, result must be updated.
    result=max(result, right-left);
    return result;
      
        
    }
};
