You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* resultList = new ListNode(0);
        ListNode* scanList = resultList;
        
        ListNode* scanL1 = l1;
        ListNode* scanL2 = l2;
        
        int carrierNum = 0;
        
        while(scanL1!=NULL || scanL2 !=NULL ){
            int sumVal=0, val1=0, val2=0;
            
            if(scanL1 != NULL){
                val1= scanL1->val;
                scanL1 = scanL1->next;
            }
            
            if(scanL2 != NULL){
                val2= scanL2->val;
                scanL2 = scanL2->next;
            }
            
            sumVal = val1 + val2 + carrierNum;
            carrierNum = sumVal/10;
            scanList->val = sumVal %10;
            
            if (scanL1 !=NULL || scanL2 !=NULL || carrierNum>0){
                scanList->next  = new ListNode(carrierNum);
                scanList = scanList->next;
            }
            
        }
        
        
        return resultList;
    }
};
