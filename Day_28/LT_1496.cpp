class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> s={"0 0"};
        int x = 0, y = 0;
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == 'N') y++;
            else if(path[i] == 'S') y--;
            else if(path[i] == 'E') x++;
            else x--;

            string a = to_string(x);
            string b = "";
            b += (a += (" " + to_string(y)) );
            cout << b << endl;
            if(s.count(b)) return true;
            else s.insert(b);
        }
        return false;
    }
};