class Solution {
public:
  void BFS(int node, vector<vector<int>> &adj, vector<bool> &visited,
           vector<int> &result) {
    queue<int> que;

    que.push(node);
    visited[node] = true;
    result.push_back(node);

    while (!que.empty()) {
      int u = que.front();
      que.pop();

      for (int i : adj[u]) {
        if (!visited[i]) {
          que.push(i);
          visited[i] = true;
          result.push_back(i);
        }
      }
    }
  }
  vector<int> bfs(vector<vector<int>> &adj) {
    // code here

    vector<int> result;
    int n = adj.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i])
        BFS(i, adj, visited, result);
    }
    return result;
  }
};