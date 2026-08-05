class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {

    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      }
      digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};

/*
 * Time Complexity: O(N) - Traversing digits array from right to left once.
 * Space Complexity: O(1) auxiliary space (or O(N) in worst case when adding
 * leading 1 for all 9s).
 *
 * Summary:
 * Incremented the large integer represented by digits by starting from the
 * least significant digit, setting 9s to 0 until a digit less than 9 is
 * incremented, handling carry overflow by prepending 1.
 */
