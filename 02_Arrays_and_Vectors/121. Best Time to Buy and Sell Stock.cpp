class Solution {
public:
  int maxProfit(vector<int> &prices) {

    int minimum = prices[0];
    int maxProfit = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++) {
      int cost = prices[i] - minimum;
      maxProfit = max(cost, maxProfit);
      minimum = min(minimum, prices[i]);
    }

    return maxProfit;
  }
};