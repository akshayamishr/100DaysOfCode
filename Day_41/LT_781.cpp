class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int ans =  0;
        for(int i = 0; i < answers.size(); i++)
        {
            if(m.find(answers[i] + 1) != m.end())  // current color exists in the map
            {
                m[answers[i] + 1]++;
                if(m[answers[i] + 1]  >= answers[i] + 1)  // if we have found all rabbits of current color
                    m.erase(answers[i] + 1);
            }
            else    // starting the group of current coloras it does not exists int the map
            {
                ans += answers[i] + 1;
                if(answers[i] == 0) continue;  // edge case
                m[answers[i] + 1] = 1;
            }
        }
        return ans;
    }
};
