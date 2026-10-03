/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//T.C : O(n)
//S.C : O(1) Auxiliary space
class Solution {
public:
    ListNode* curr;

    bool solve(ListNode* head) {
        if(!head)
            return true;
        
        if(!solve(head->next) || head->val != curr->val) {
            return false;
        }

        curr = curr->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        curr = head;

        return solve(head);
    }
};