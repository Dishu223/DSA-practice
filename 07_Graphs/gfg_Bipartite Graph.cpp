class Solution {
public:
  bool checkBipartite(unordered_map<int, vector<int>> &adj, int curr,
                      vector<int> &color, int currColor) {
    color[curr] = currColor;
    for (int &v : adj[curr]) {
      if (color[v] == color[curr])
        return false;

      if (color[v] == -1) {
        int newColor = 1 - currColor;
        if (checkBipartite(adj, v, color, newColor) == false)
          return false;
      }
    }
    return true;
  }

  bool isBipartite(int V, vector<vector<int>> &edges) {

    unordered_map<int, vector<int>> adj;
    vector<int> color(V, -1);

    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < V; i++) {
      if (color[i] == -1) {
        if (checkBipartite(adj, i, color, 1) == false)
          return false;
      }
    }
    return true;
  }
};