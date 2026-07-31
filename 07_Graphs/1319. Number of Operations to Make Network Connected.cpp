class Solution {
public:
  vector<int> parent;
  vector<int> rank;

  int find(int x) {
    if (x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }

  void unionn(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
      return;
    if (rank[x_parent] > rank[y_parent])
      parent[y_parent] = x_parent;
    else if (rank[y_parent] > rank[x_parent])
      parent[x_parent] = y_parent;
    else {
      parent[x_parent] = y_parent;
      rank[y_parent]++;
    }
  }
  int makeConnected(int n, vector<vector<int>> &connections) {

    if (connections.size() < n - 1)
      return -1;

    parent.resize(n);
    rank.resize(n, 0);

    for (int i = 0; i < n; i++)
      parent[i] = i;
    int components = n;

    for (auto &edges : connections) {
      int x = edges[0];
      int y = edges[1];

      int x_parent = find(x);
      int y_parent = find(y);

      if (x_parent == y_parent)
        continue;
      else {
        unionn(x_parent, y_parent);
        components--;
      }
    }
    return components - 1;
  }
};