class Solution {
public:
  double helper(double x, long long n) {
    if (n == 0)
      return 1.0;

    double half = pow(x, n / 2);

    if (n % 2 == 0)
      return half * half;
    else
      return half * half * x;
  }
  double myPow(double x, int n) {
    long long long_n = n;

    if (n < 0) {
      x = 1 / x;
      long_n = -long_n;
    }
    return helper(x, long_n);
  }
};