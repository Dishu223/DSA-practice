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

/*
================================================================================
Approach Summary: BFS Traversal of Graph
================================================================================
- Technique: Queue-based Level-Order Traversal (Breadth-First Search).
- Process: Enqueue starting node, mark visited, process queued nodes, and 
  enqueue unvisited neighbors. Loop over all nodes 0 to N-1 to handle disconnected 
  components.
- Time Complexity: O(V + E) where V is vertices and E is edges.
- Space Complexity: O(V) for the queue, visited array, and output result vector.
================================================================================
*/