class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_set<string>s;
        // inserting elements into the set
        for(int i = 0; i < n; i++)
            s.insert(words[i]);
        // checking for reverse elements
        int count = 0;
        for(int i = 0 ; i < n; i++)
        {
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            if(temp == words[i]) continue; // palindrome
            if(s.find(temp) != s.end())
            {
                count++;
                s.erase(words[i]);
            }
        }
        return count;
    }
};