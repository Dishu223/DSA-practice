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

/*
================================================================================
Approach Summary: Bipartite Graph Check (DFS 2-Coloring)
================================================================================
- Concept: Divide vertices into 2 independent sets such that every edge connects 
  a vertex in set 1 to a vertex in set 2.
- Technique: DFS Graph 2-Coloring.
- Process: First convert edge list to adjacency list map. Use color array (-1 uncolored). 
  Recursively assign `newColor = 1 - currColor` to neighbors. If neighbor `color[v] == color[curr]`, 
  return false immediately.
- Time Complexity: O(V + E)
- Space Complexity: O(V + E) for adjacency list map and DFS call stack.
================================================================================
*/