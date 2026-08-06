class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {

    unordered_map<int, vector<pair<int, int>>> adj;

    for (auto &edge : times) {
      int u = edge[0];
      int v = edge[1];
      int w = edge[2];

      adj[u].push_back({v, w});
    }

    vector<int> result(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    result[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
      int d = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (d > result[node])
        continue;

      for (auto &vec : adj[node]) {
        int timeNode = vec.first;
        int wt = vec.second;

        if (d + wt < result[timeNode]) {
          result[timeNode] = d + wt;
          pq.push({d + wt, timeNode});
        }
      }
    }
    // result vector ready...
    int maxi = INT_MIN;
    result[0] = 0;
    for (int &i : result) {
      if (i == INT_MAX)
        return -1;
      maxi = max(maxi, i);
    }
    return maxi;
  }
};

/*
================================================================================
Approach Summary: Network Delay Time (Dijkstra's Algorithm)
================================================================================
- Problem: Find minimum time for all N nodes to receive a signal sent from node K.
- Technique: Single-Source Shortest Path using Dijkstra's Algorithm.
- Process: Compute shortest path distance from source node `k` to all other nodes 
  1 to N using min-heap priority queue. Find the maximum distance in the `result` vector. 
  If any node remains at `INT_MAX`, it is unreachable, so return -1; otherwise return the max distance.
- Time Complexity: O(E log V)
- Space Complexity: O(V + E) for adjacency list, distance array, and priority queue.
================================================================================
*/