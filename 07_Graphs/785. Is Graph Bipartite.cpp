class Solution {
public:
  bool checkBipartiteBFS(vector<vector<int>> &adj, int curr, vector<int> &color,
                         int currColor) {
    queue<int> que;
    que.push(curr);

    color[curr] = currColor;

    while (!que.empty()) {
      int u = que.front();
      que.pop();

      for (int &v : adj[u]) {
        if (color[v] == color[u])
          return false;
        else if (color[v] == -1) {
          color[v] = 1 - color[u];
          que.push(v);
        }
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>> &adj) {
    int V = adj.size();

    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
      if (color[i] == -1) {
        if (checkBipartiteBFS(adj, i, color, 1) == false)
          return false;
      }
    }
    return true;
  }
};