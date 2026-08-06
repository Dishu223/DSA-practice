class Solution {
public:
  void dfs(int u, unordered_map<int, vector<pair<int, int>>> &adj,
           vector<bool> &visited, int &result) {
    visited[u] = true;
    for (auto &P : adj[u]) {
      int v = P.first;
      int d = P.second;

      result = min(result, d);

      if (!visited[v])
        dfs(v, adj, visited, result);
    }
  }
  int minScore(int n, vector<vector<int>> &roads) {
    unordered_map<int, vector<pair<int, int>>> adj;

    for (auto &vec : roads) {
      int u = vec[0];
      int v = vec[1];
      int d = vec[2];

      adj[u].push_back({v, d});
      adj[v].push_back({u, d});
    }

    vector<bool> visited(n, false);

    int result = INT_MAX;

    dfs(1, adj, visited, result);

    return result;
  }
};

/*
================================================================================
Approach Summary: Minimum Score of a Path Between Two Cities (DFS Traversal)
================================================================================
- Key Insight: A path between city 1 and city n exists if they are in the same connected component. 
  The minimum score is simply the MINIMUM weight among ALL edges present in that entire component.
- Technique: Recursive DFS.
- Process: Build weighted undirected graph adjacency list `adj[u] = {v, weight}`. 
  Start DFS from node 1. For every edge `(u, v, d)` traversed during DFS, update 
  `result = min(result, d)`. Visit all reachable nodes in the component.
- Time Complexity: O(V + E)
- Space Complexity: O(V + E) for adjacency list, visited vector, and recursion stack.
================================================================================
*/