class Solution {
public:
  typedef pair<int, pair<int, int>> P;

  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    vector<vector<int>> directions = {{1, 0},  {0, 1},   {1, 1},  {-1, 0},
                                      {0, -1}, {-1, -1}, {-1, 1}, {1, -1}};

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> result(n, vector<int>(m, INT_MAX));

    if (m == 0 || n == 0 || grid[0][0] != 0)
      return -1;

    auto isSafe = [&](int x, int y) {
      return x >= 0 && x < m && y >= 0 && y < n;
    };

    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, {0, 0}});
    result[0][0] = 0;

    while (!pq.empty()) {
      int d = pq.top().first;
      pair<int, int> node = pq.top().second;
      int x = node.first;
      int y = node.second;

      pq.pop();

      for (auto dir : directions) {
        int x_ = x + dir[0];
        int y_ = y + dir[1];

        int dist = 1;

        if (isSafe(x_, y_) && grid[x_][y_] == 0 && d + dist < result[x_][y_]) {
          pq.push({d + dist, {x_, y_}});
          result[x_][y_] = d + dist;
        }
      }
    }
    if (result[m - 1][n - 1] == INT_MAX)
      return -1;
    return result[m - 1][n - 1] + 1;
  }
};