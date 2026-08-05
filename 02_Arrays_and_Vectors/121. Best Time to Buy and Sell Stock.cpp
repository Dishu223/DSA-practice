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

/*
 * Time Complexity: O(N) - Single pass iteration through the prices array of size N.
 * Space Complexity: O(1) - Constant auxiliary space used.
 *
 * Summary:
 * Tracked the minimum buy price seen so far while traversing stock prices,
 * updating the maximum potential profit at each step if sold on the current day.
 */