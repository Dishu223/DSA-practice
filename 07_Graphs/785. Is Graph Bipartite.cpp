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

/*
================================================================================
Approach Summary: Is Graph Bipartite (BFS 2-Coloring)
================================================================================
- Concept: A graph is bipartite if nodes can be colored using 2 colors such that 
  no two adjacent nodes share the same color (no odd-length cycles).
- Technique: BFS Graph 2-Coloring.
- Process: Maintain a `color` array initialized to -1. For each unvisited node, 
  enqueue it with color 1. During BFS, assign neighboring nodes color `1 - color[u]`. 
  If neighbor already has `color[v] == color[u]`, return false (conflict).
- Time Complexity: O(V + E)
- Space Complexity: O(V) for color vector and BFS queue.
================================================================================
*/