 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 


class Solution {
public:
//http://fisherlei.blogspot.com/2013/01/leetcode-zigzag-conversion.html  Draw example of 3, 4, 5. 
    string convert(string s, int nRows) {
       if(nRows <= 1) return s;  
      string result;  
      if(s.size() ==0) return result;  
      for(int i =0; i< nRows; i++)  
      {  
        for(int j =0, index =i; index < s.size();   
            j++, index = (2*nRows-2)*j +i)  
        {  
          result.append(1, s[index]);  //red element
           if(i ==0 || i == nRows-1)   //green element
           {            
             continue;  
           }  
           if(index+(nRows- i-1)*2 < s.size())  
           {  
             result.append(1, s[index+(nRows- i-1)*2]);  
           }  
         }  
       }  
       return result;  
    }
};

