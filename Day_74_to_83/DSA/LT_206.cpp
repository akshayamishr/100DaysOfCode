// Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* curr_ = head;
        // ListNode* prev_ = NULL;
        // ListNode* next_ = head;
        // while(curr_)
        // {
        //     next_ = curr_->next;
        //     curr_->next = prev_;
        //     prev_ = curr_;
        //     curr_ = next_;
        // }
        // return prev_;
        if(head == NULL || head->next == NULL) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};