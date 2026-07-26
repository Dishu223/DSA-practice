class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    int firstmax = nums[0];
    int secondMax = nums[1];
    int thirdMax = nums[2];

    int min = nums[n - 1];
    int secondMin = nums[n - 2];

    int onlyPos = firstmax * secondMax * thirdMax;
    int withNeg = min * secondMin * firstmax;

    int result = max(onlyPos, withNeg);
    return result;
  }
};