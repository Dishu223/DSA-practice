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

/*
================================================================================
Approach Summary: Count Unreachable Pairs of Nodes in Undirected Graph (DSU)
================================================================================
- Concept: Nodes in different connected components cannot reach each other. 
  For a component of size S with R remaining nodes overall, it forms `S * (R - S)` 
  unreachable pairs with all nodes outside its component.
- Technique: DSU for grouping connected components + Combinatorics.
- Process: Union all edges. Count size of each component in a hash map `mp[findParent(i)]++`. 
  Iterate through sizes S, computing `result += S * (remain - S)` and reducing `remain -= S`.
- Time Complexity: O(N + E * α(N))
- Space Complexity: O(N) for parent, rank, and component frequency map.
================================================================================
*/