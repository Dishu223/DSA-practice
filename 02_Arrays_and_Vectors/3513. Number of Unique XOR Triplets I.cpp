class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    int n = nums.size();
    if (n == 1 || n == 2)
      return n;
    bool found = false;
    int i = 0;
    while (!found) {
      if (pow(2, i) > n)
        return pow(2, i);
      i++;
    }
    return false;
  }
};