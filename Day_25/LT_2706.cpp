class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int firstIndex = 0, secondIndex = 1;
        if (prices[firstIndex] > prices[secondIndex]) {
            swap(firstIndex, secondIndex);
        }
        for (int i = 2; i < n; ++i) {
            if (prices[i] < prices[firstIndex]) {
                secondIndex = firstIndex;
                firstIndex = i;
            } else if (prices[i] < prices[secondIndex]) {
                secondIndex = i;
            }
        }
        if(money < (prices[firstIndex] + prices[secondIndex])) return money;
        else return (money - (prices[firstIndex] + prices[secondIndex]));
    }
};