// Task Schedular
// https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int>mp(26,0);
        for(auto it:tasks) mp[it-'A']++;  
        for(int i=0;i<26;++i){
            if(mp[i]!=0) pq.push(mp[i]); 
        }
        int time=0; 
        while(!pq.empty()){ 
            vector<int>left; 
            int cycle=n+1;  
            while(cycle and !pq.empty()){
                int maxi=pq.top(); 
                pq.pop(); 
                if(maxi>1){ 
                    left.push_back(maxi-1); 
                }
                ++time; 
                --cycle; 
            }
            for(auto it:left){
                pq.push(it); 
            }
            if(pq.empty())break; 
            time+=cycle; 
        }
        return time;
    }
};