bool cc(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];   // a[1] --> Profit  0r  numberOfUnitsPerBox 
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int maxProfit = 0;
        sort(boxTypes.begin(),boxTypes.end(),cc);
        for(int i = 0; i < boxTypes.size(); i++)
        {
            if(truckSize == 0) break;
            if(boxTypes[i][0] <= truckSize) 
            {
                maxProfit += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else      //if(boxTypes[i][0] > truckSize)
            {
                maxProfit += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }
        return maxProfit;
    }
};