class Solution {
public:
  void reverseHelper(vector<vector<int>> &grid, int left, int right, int &k) {
    int row = grid.size();
    int col = grid[0].size();

    int n = row * col;

    k = k % n;
    if (k == 0)
      return;

    while (left <= right) {
      swap(grid[left / col][left % col], grid[right / col][right % col]);
      left++;
      right--;
    }
  }
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int n = grid.size() * grid[0].size();
    reverseHelper(grid, 0, n - 1, k);
    reverseHelper(grid, 0, k - 1, k);
    reverseHelper(grid, k, n - 1, k);

    return grid;
  }
};