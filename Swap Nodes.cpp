// https://leetcode.com/problems/swap-nodes-in-pairs/submissions/

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
    ListNode* swapUtil(ListNode* head){
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* next = head->next;
        ListNode* temp = next->next;
        next->next = head;
        head->next = swapUtil(temp);
        return next;
    }
    
    ListNode* swapPairs(ListNode* head) {
        head = swapUtil(head);
        return head;
    }
};
