class Solution {
public:
  int climbStairs(int n) {
    ////////////////////////////////////////// //Normal
    ///method!////////////////////////

    // base case
    vector<int> dp(n + 1, -1);
    if (n <= 2) {
      return n;
    }

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];

    ///////////////////////  //RECURSIVE METHOD -> WILL TIMEOUT
    ///THOUGH!////////////////////////

    // if(n == 1 || n == 2) return n;

    // return climbStairs(n-1) + climbStairs(n-2);
  }
};