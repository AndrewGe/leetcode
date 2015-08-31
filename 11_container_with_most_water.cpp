Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 

class Solution {
public:
// similar problems: (1) twosum (sorted), (2) maximum retangle in histogram, (3) buy stocks, 
    int maxArea(vector<int> &height) {
        int start=0, end=height.size()-1;
        int maxVal=INT_MIN;
        while(start<end){
            int contain = min(height[start], height[end])*(end-start);
            maxVal = max(maxVal, contain);
            
            if (height[start]<height[end]){
                start++;
            }
            else {
                end--;
            }
        }
        return maxVal;
        
    }
};
