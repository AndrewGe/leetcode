Write a function to find the longest common prefix string amongst an array of strings. 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if (strs.size()<1 || strs[0].size()<0) return result;
        for (int j=0; j<strs[0].size(); j++){
            char curChar = strs[0][j];
            bool match=true;
            for (int i=1; i<strs.size(); i++){
                if ( j>= strs[i].size() ||
                     curChar!=strs[i][j]){
                      match=false;    
                      break; 
                } 

            }
            if (match) {result.push_back(curChar);}
            else {break;}
        }
        return result;
        
    }
};
