class Solution {
public:
  int findMaxInMatrix(vector<vector<int>> &grid, int row, int col) {
    int currMax = INT_MIN;

    for (int i = row; i <= row + 2; i++) {
      for (int j = col; j <= col + 2; j++) {
        currMax = max(currMax, grid[i][j]);
      }
    }
    return currMax;
  }
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int n = grid.size();

    vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2)); // result

    for (int row = 0; row < n - 2; row++) {
      for (int col = 0; col < n - 2; col++) {
        maxLocal[row][col] = findMaxInMatrix(grid, row, col);
      }
    }
    return maxLocal;
  }
};