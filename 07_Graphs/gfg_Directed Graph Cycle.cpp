class Solution {
public:
  bool isCyclic(int V, vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> adj;

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++) {
      for (int v : adj[u]) {
        indegree[v]++;
      }
    }

    queue<int> que;

    for (int u = 0; u < V; u++) {
      if (indegree[u] == 0)
        que.push(u);
    }

    int count = 0;

    while (!que.empty()) {
      int curr = que.front();
      count++;
      que.pop();
      for (int &v : adj[curr]) {
        indegree[v]--;
        if (indegree[v] == 0)
          que.push(v);
      }
    }
    if (count == V)
      return false;
    return true;
  }
};

/*
================================================================================
Approach Summary: Directed Graph Cycle Detection (Kahn's Algorithm - BFS)
================================================================================
- Concept: Topological sort is only possible on Directed Acyclic Graphs (DAGs). 
  If topological sort fails to process all V vertices, a cycle exists.
- Technique: Kahn's Algorithm (BFS-based Topological Sort).
- Process: Build adjacency map and indegree array. Push all nodes with indegree == 0 
  to queue. Perform BFS while counting popped nodes (`count++`) and decrementing 
  indegrees of neighbors. If `count == V`, graph is DAG (no cycle); otherwise return true (cycle detected).
- Time Complexity: O(V + E)
- Space Complexity: O(V + E) for adjacency list, indegree array, and queue.
================================================================================
*/