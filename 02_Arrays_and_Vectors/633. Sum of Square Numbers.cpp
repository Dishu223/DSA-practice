class Solution {
public:
  bool judgeSquareSum(int c) {
    long long left = 0;
    long long right = static_cast<long long>(sqrt(c));

    while (left <= right) {
      long long square_sum = left * left + right * right;
      if (square_sum == c)
        return true;
      else if (square_sum < c)
        left++;
      else
        right--;
    }
    return false;
  }
};