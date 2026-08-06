class Solution {
public:
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    unordered_map<int, vector<pair<int, int>>> adj;

    for (auto &edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
      adj[edge[1]].push_back({edge[0], edge[2]});
    }
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> result(V, INT_MAX);

    result[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
      int d = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (d > result[node])
        continue;

      for (auto &v : adj[node]) {
        int adjNode = v.first;
        int wt = v.second;

        if (d + wt < result[adjNode]) {
          result[adjNode] = d + wt;
          pq.push({d + wt, adjNode});
        }
      }
    }
    return result;
  }
};

/*
================================================================================
Approach Summary: Dijkstra's Shortest Path Algorithm
================================================================================
- Concept: Single-Source Shortest Path (SSSP) algorithm for non-negative edge weighted graphs.
- Technique: Greedily process nearest node using Min-Heap Priority Queue.
- Process: Maintain distance vector initialized to `INT_MAX`, set `result[src] = 0`. 
  Push `{0, src}` to priority queue `std::priority_queue<pair<int, int>, ..., greater<...>>`. 
  Pop element `{d, node}`. If `d > result[node]`, skip (outdated distance). 
  Otherwise relax edge `(node, adjNode, wt)`: if `d + wt < result[adjNode]`, update distance 
  and push `{d + wt, adjNode}`.
- Time Complexity: O(E log V)
- Space Complexity: O(V + E) for adjacency list, distance array, and priority queue.
================================================================================
*/