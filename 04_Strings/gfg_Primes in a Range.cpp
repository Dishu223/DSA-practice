class Solution {
public:
  bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0)
        return false;
    }
    return true;
  }
  vector<int> primeRange(int l, int r) {

    vector<int> result;

    while (r >= l) {
      if (isPrime(r) && r != 1)
        result.push_back(r);
      r--;
    }

    reverse(result.begin(), result.end());

    return result;
  }
};