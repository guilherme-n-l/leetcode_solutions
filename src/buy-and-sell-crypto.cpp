// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = numeric_limits<int>::min(), min = prices[0];

        for (int &i : prices)
            profit = std::max(profit, i - min),
                min = std::min(min, i);

        return profit;
    }
};
