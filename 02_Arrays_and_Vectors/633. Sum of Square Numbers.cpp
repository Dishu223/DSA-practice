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

/*
 * Time Complexity: O(sqrt(c)) - Two pointers move towards each other between 0
 * and sqrt(c). Space Complexity: O(1) - Constant auxiliary space..
 *
 * Summary:
 * Utilized a two-pointer approach from left=0 to right=sqrt(c) to efficiently
 * find if two square numbers sum up to c by adjusting pointers based on whether
 * current sum is smaller or larger than c.
 */
