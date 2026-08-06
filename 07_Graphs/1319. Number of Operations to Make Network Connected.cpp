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

/*
================================================================================
Approach Summary: Number of Operations to Make Network Connected (DSU)
================================================================================
- Key Insight: To connect N nodes into 1 connected component, at least N - 1 edges 
  are required. If total connections < N - 1, return -1.
- Technique: Disjoint Set Union (DSU) Component Counting.
- Process: Initialize `components = n`. For each edge `(u, v)`, check if `find(u) != find(v)`. 
  If different sets, perform `unionn(u, v)` and decrement `components--`. 
  Minimum operations needed to connect all components is `components - 1`.
- Time Complexity: O(E * α(V))
- Space Complexity: O(V) for DSU parent and rank arrays.
================================================================================
*/