#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getLeftMaxArray(vector<int> &height, int &n) {
    vector<int> leftMax(n);
    leftMax[0] = height[0];

    for (int i = 1; i < n; i++) {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    return leftMax;
  }

  vector<int> getRightMaxArray(vector<int> &height, int &n) {
    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }
    return rightMax;
  }

  int trap(vector<int> &height) {
    int n = height.size();
    if (n == 0)
      return 0;

    vector<int> leftMax = getLeftMaxArray(height, n);
    vector<int> rightMax = getRightMaxArray(height, n);
    int sum = 0;
    int h = 0;

    for (int i = 0; i < n; i++) {
      h = min(leftMax[i], rightMax[i]) - height[i];
      sum += h;
    }
    return sum;
  }
};

int main() {
  Solution solution;

  // Example test case
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  cout << "Input height array: ";
  for (int h : height) {
    cout << h << " ";
  }
  cout << endl;

  int result = solution.trap(height);
  cout << "Total trapped rain water: " << result << endl; // Expected: 6

  return 0;
}
