class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool is_cycle = false;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) 
            {
                is_cycle = true;
                break;
            }
        }
            if(is_cycle == false) return NULL;
            else
            {
                ListNode *temp = head;
                while(temp != slow)
                {
                    temp = temp->next;
                    slow = slow->next;
                }
            }
        return slow;
    }
};