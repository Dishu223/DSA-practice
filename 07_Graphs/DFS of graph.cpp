class Solution {
public:
  void dfsHelper(int node, vector<vector<int>> &adj, vector<bool> &visited,
                 vector<int> &result) {
    visited[node] = true;
    result.push_back(node);

    for (int it : adj[node]) {
      if (!visited[it])
        dfsHelper(it, adj, visited, result);
    }
  }

  vector<int> dfs(vector<vector<int>> &adj) {

    vector<int> result;
    int n = adj.size();

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i])
        dfsHelper(i, adj, visited, result);
    }
    return result;
  }
};

/*
================================================================================
Approach Summary: DFS Traversal of Graph
================================================================================
- Technique: Recursive Depth-First Search (DFS).
- Process: Mark current node visited, add to result, and recursively visit all 
  unvisited neighbors. Outer loop from 0 to N-1 ensures disconnected components 
  are fully covered.
- Time Complexity: O(V + E) where V is vertices and E is edges.
- Space Complexity: O(V) for visited array, result vector, and recursion stack.
================================================================================
*/