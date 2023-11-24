class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* tail = head;
        int len = 0, temp_idx = -1;
        while(temp != NULL)
        {
            len++;
            if(temp->next == NULL) tail = temp;
            temp = temp->next;
        }
        k %= len;
        if(k==0) return head;
        temp = head;
        for(int i = 1; i < len-k; i++)
        {
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};