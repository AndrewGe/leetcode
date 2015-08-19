Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        map<int,int>hmap;
        hmap.clear();
        for (int i=0;i<numbers.size();i++){
            hmap[numbers[i]]=i;
        }
        for (int i=0;i<numbers.size();i++){
            int searchVal = target-numbers[i];
            if (hmap.find(searchVal)!=hmap.end() && i!= hmap[searchVal]){
                res.push_back( min(i, hmap[searchVal ]) +1 );
                res.push_back( max(i, hmap[searchVal]) +1 );
                return res;
            }
        }
    }
};
