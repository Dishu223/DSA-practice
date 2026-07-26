class Solution {
public:
  int maxProduct(int n) {
    int maxDigit = INT_MIN;
    int secondMaxDigit = maxDigit;

    int temp = n;
    while (temp > 0) {
      int digit = temp % 10;
      if (maxDigit < digit) {
        secondMaxDigit = maxDigit;
        maxDigit = digit;
      } else if (secondMaxDigit < digit)
        secondMaxDigit = digit;
      temp /= 10;
    }
    return (maxDigit * secondMaxDigit);
  }
};