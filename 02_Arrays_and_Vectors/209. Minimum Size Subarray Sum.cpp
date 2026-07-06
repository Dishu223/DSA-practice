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