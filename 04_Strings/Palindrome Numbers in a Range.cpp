class Solution {
public:
  bool isPalindrome(int n) {
    int temp = n;
    vector<int> digits;

    while (temp) {
      int digit = temp % 10;
      digits.push_back(digit);
      temp /= 10;
    }

    int left = 0;
    int right = digits.size() - 1;

    while (left <= right) {
      if (digits[left] != digits[right])
        return false;
      left++;
      right--;
    }
    return true;
  }

  vector<int> printPalindromes(int m, int n) {
    // code here

    vector<int> result;

    while (m <= n) {
      if (isPalindrome(m))
        result.push_back(m);
      m++;
    }
    return result;
  }
};