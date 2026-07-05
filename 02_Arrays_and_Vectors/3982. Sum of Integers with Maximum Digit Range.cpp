class Solution {
public:
  int maxDigitRange(vector<int> &nums) {
    vector<int> ranges(nums.size());
    int digit = 0;
    int max_range = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int maxi = 0;
      int mini = 9;
      int temp = nums[i];
      while (temp > 0) {
        digit = temp % 10;
        maxi = max(maxi, digit);
        mini = min(mini, digit);
        temp /= 10;
      }
      ranges[i] = maxi - mini;
      max_range = max(max_range, maxi - mini);
    }

    for (int i = 0; i < nums.size(); i++) {
      if (ranges[i] == max_range)
        sum += nums[i];
    }
    return sum;
  }
};