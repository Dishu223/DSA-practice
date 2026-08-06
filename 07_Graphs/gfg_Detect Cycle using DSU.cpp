class Solution {
public:
  vector<int> parent;
  vector<int> rank;

  int find(int x) {
    if (x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }

  void Union(int x, int y) {
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

  bool detectCycle(int V, vector<int> adj[]) {

    parent.resize(V);
    rank.resize(V);

    for (int i = 0; i < V; i++) {
      parent[i] = i;
      rank[i] = 1;
    }

    for (int u = 0; u < V; u++) {
      for (int &v : adj[u]) {
        if (u < v) {
          int parent_u = find(u);
          int parent_v = find(v);

          if (parent_u == parent_v)
            return true;
          Union(u, v);
        }
      }
    }
    return false;
  }
};

/*
================================================================================
Approach Summary: Detect Cycle in Undirected Graph using DSU
================================================================================
- Concept: Disjoint Set Union (DSU) can detect cycles in undirected graphs. If an edge 
  connects two nodes that ALREADY belong to the same parent set, a cycle exists.
- Technique: DSU with Path Compression (`parent[x] = find(parent[x])`) and Union by Rank.
- Process: Initialize each node's parent to itself and rank to 1. For each edge `(u, v)` 
  with `u < v` (to avoid checking undirected edges twice): find parent of `u` and `v`. 
  If `parent_u == parent_v`, return true (cycle detected). Otherwise call `Union(u, v)`.
- Time Complexity: O(E * α(V)) where α is the inverse Ackermann function (nearly O(E)).
- Space Complexity: O(V) for parent and rank arrays.
================================================================================
*/