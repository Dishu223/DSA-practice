class Solution {
public:
public:
  long long factorial(long long n) {
    if (n == 0 || n == 1)
      return 1;

    return n * factorial(n - 1);
  }

  bool isStrong(int n) {

    int temp = n;
    long long sum = 0;

    while (temp) {
      int digit = temp % 10;
      sum += factorial(digit);
      temp /= 10;
    }
    return sum == n;
  }
};
