///  cc -> custom comparator
class cc{  
    public:
    bool operator()(const ListNode* a, const ListNode* b){
        return (a->val > b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cc>min_pq;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL) min_pq.push(lists[i]);;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(!min_pq.empty())
        {
            ListNode* curr = min_pq.top();
            min_pq.pop();
            if(curr->next) min_pq.push(curr->next);
            temp->next = curr;
            temp = temp->next;
        }
        return dummy->next;
    }
};