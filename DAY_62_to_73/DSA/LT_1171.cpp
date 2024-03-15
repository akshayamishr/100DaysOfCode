/**
Remove Zero Sum Consecutive Nodes from Linked List
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
         ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* current=dummy;
        while(current!=nullptr) {
            ListNode* ptr=current->next;
            int sum=0;
            while(ptr!=nullptr) {
                sum+= ptr->val;
                if(sum==0) {
                    current->next=ptr->next;
                }
                ptr=ptr->next;
            }
            current=current->next;
        }
        return dummy->next;
    }
};