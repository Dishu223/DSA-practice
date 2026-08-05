class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int window_start = 0;
    int min_size = INT_MAX;
    int sum = 0;

    for (int window_end = 0; window_end < nums.size(); window_end++) {
      sum += nums[window_end];
      while (sum >= target) {
        min_size = min(min_size, window_end - window_start + 1);
        sum -= nums[window_start];
        window_start++;
      }
    }
    return (min_size == INT_MAX) ? 0 : min_size;
  }
};

/*
 * Time Complexity: O(N) - Each element is visited at most twice (once by
 * window_end and once by window_start). Space Complexity: O(1) - Constant
 * auxiliary space..
 *
 * Summary:
 * Used a variable-size sliding window to expand window_end until sum >= target,
 * then shrank window_start to find the minimal contiguous subarray length
 * fulfilling the target condition.
 */
