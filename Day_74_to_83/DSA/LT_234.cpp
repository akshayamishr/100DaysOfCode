// Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/description/?envType=daily-question&envId=2024-03-22

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr_ = head;
        ListNode* prev_ = NULL;
        ListNode* next_ = head;
        while(curr_)
        {
            next_ = curr_->next;
            curr_->next = prev_;
            prev_ = curr_;
            curr_ = next_;
        }
        return prev_;
    }
    bool isPalindrome(ListNode* head) {
       ListNode* slow = head, *fast = head;
       while(fast->next && fast->next->next)
       {
           slow = slow->next;
           fast = fast->next->next;
       } 
        ListNode* new_head = reverseList(slow->next);
        ListNode* a = head, *b = new_head;
        while(b)
        {
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};