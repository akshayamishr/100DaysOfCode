// Merge In Between Linked Lists
// https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list1;
        ListNode* temp3 = list2;

        int i = 0;
        while(i < a-1){
            temp1 = temp1->next;
            i++;
        }
        
        temp2 = temp1;
        i = a;
        while(i <= b){
            temp2 = temp2->next;
            i++;
        }

        temp1->next = temp3;

        while(temp3->next != NULL)
            temp3= temp3->next;


        
        temp3->next = temp2->next;

        return list1;
    }
};