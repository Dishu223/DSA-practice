class Solution {
public:
  vector<int> parent;
  vector<int> rank;

  int findParent(int x) {
    if (x == parent[x])
      return x;
    return parent[x] = findParent(parent[x]);
  }

  void Union(int x, int y) {
    int x_parent = findParent(x);
    int y_parent = findParent(y);

    if (x_parent == y_parent)
      return;
    if (rank[x_parent] < rank[y_parent])
      parent[x_parent] = y_parent;
    else if (rank[x_parent] > rank[y_parent])
      parent[y_parent] = x_parent;
    else {
      parent[y_parent] = x_parent;
      rank[x_parent]++;
    }
  }

  long long countPairs(int n, vector<vector<int>> &edges) {

    parent.resize(n);
    rank.resize(n, -1);

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
      parent[i] = i;

    for (auto &edge : edges) {
      int x = edge[0];
      int y = edge[1];

      Union(x, y);
    }
    for (int i = 0; i < n; i++) {
      int daddy = findParent(i);
      mp[daddy]++;
    }

    long long remain = n;
    long long result = 0;

    for (auto &it : mp) {
      int curr_parent = it.first;
      int size = it.second;

      result += size * (remain - size);
      remain -= size;
    }
    return result;
  }
};