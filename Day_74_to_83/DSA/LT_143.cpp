// Reorder List
// https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return; 

        vector<ListNode*> arr; 
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp);
            temp = temp->next;
        }

        int i = 0, j = arr.size() - 1;
        while (i < j) {
            arr[i]->next = arr[j];
            i++;

            if (i == j) break; 

            arr[j]->next = arr[i];
            j--;
        }
        arr[i]->next = nullptr;
    }
};