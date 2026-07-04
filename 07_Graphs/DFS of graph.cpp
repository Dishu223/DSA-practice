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