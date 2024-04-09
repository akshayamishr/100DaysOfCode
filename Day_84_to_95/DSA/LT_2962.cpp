//  Count Subarrays Where Max Element Appears at Least K Times
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>freq;

        int  maxi= *max_element(nums.begin(),nums.end());
        int i=0,j=0;
        ll ans=0;

        while(j < n){
            freq[nums[j]]++;
            while(freq[maxi] >= k){
                ans += n-j;
                freq[nums[i]]--;
                i++;
            }
            j++;   
        }
        
        return ans;
    }
};