class Solution {
public:
  vector<int> shortestPath(int V, vector<vector<int>> &edges, int src,
                           int dest) {
    // Optimization: using vector instead of unordered_map for faster adjacency
    // list access
    vector<vector<pair<int, int>>> adj(V + 1);

    for (auto &edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
      adj[edge[1]].push_back({edge[0], edge[2]});
    }

    // Step 1: Run Dijkstra starting from 'dest'
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> result(V + 1, INT_MAX);

    result[dest] = 0;
    pq.push({0, dest});

    while (!pq.empty()) {
      int d = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (d > result[node])
        continue;

      for (auto &vec : adj[node]) {
        int adjNode = vec.first;
        int wt = vec.second;

        if (d + wt < result[adjNode]) {
          result[adjNode] = d + wt;
          pq.push({d + wt, adjNode});
        }
      }
    }

    // If src is unreachable from dest, no path exists
    if (result[src] == INT_MAX) {
      return {-1};
    }

    // Step 2: Greedily build the lexicographically smallest path from 'src'
    vector<int> path;
    int curr = src;
    path.push_back(curr);

    while (curr != dest) {
      int nextNode = -1;
      for (auto &vec : adj[curr]) {
        int adjNode = vec.first;
        int wt = vec.second;

        if (result[curr] == result[adjNode] + wt) {
          if (nextNode == -1 || adjNode < nextNode)
            nextNode = adjNode;
        }
      }
      curr = nextNode;
      path.push_back(curr);
    }

    return path;
  }
};

/*
================================================================================
Approach Summary: Lexicographically Smallest Shortest Path (Reverse Dijkstra + Tracing)
================================================================================
- Problem: Find shortest path from `src` to `dest`. If multiple shortest paths exist, 
  return the lexicographically smallest path.
- Technique: 2-Step Approach (Reverse Dijkstra + Greedy Forward Path Reconstruction).
- Step 1: Run Dijkstra starting from `dest` to calculate shortest distance from `dest` 
  to every node.
- Step 2: Trace forward starting from `src`. At node `curr`, select neighboring node `adjNode` 
  satisfying edge relaxation condition `result[curr] == result[adjNode] + wt`. If multiple neighbors 
  satisfy this, pick the smallest neighbor node index `adjNode < nextNode` for lexicographical tie-breaking.
- Time Complexity: O(E log V)
- Space Complexity: O(V + E) for adjacency list vector, distance vector, and priority queue.
================================================================================
*/