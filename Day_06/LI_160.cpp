class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0,l2 = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1 != NULL || temp2 != NULL)
        {
            if(temp1 != NULL)
            {
                l1++;
                temp1 = temp1->next;
            }
            if(temp2 != NULL)
            {
                l2++;
                temp2 = temp2->next;
            }
        }
        if(l1>l2)
        {
            int d = l1-l2;
            temp1 = headA;
            temp2 = headB;
            for(int i = 1; i<= d; i++)
            {
                temp1 = temp1->next;
            }
            while(temp1 != temp2)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
        }
        else
        {
            int d = l2-l1;
            temp1 = headA;
            temp2 = headB;
            for(int i = 1; i<= d; i++)
            {
                temp2 = temp2->next;
            }
            while(temp1 != temp2)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
        }
    }
};