class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

    int n = numCourses;

    unordered_map<int, vector<int>> adj;

    for (auto edge : prerequisites) {
      int u = edge[1];
      int v = edge[0];
      adj[u].push_back(v);
    }

    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
      for (int &v : adj[u]) {
        indegree[v]++;
      }
    }

    queue<int> que;
    int count = 0;

    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0)
        que.push(i);
    }

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
    return count == n ? true : false;
  }
};

/*
================================================================================
Approach Summary: Course Schedule (Cycle Detection via Kahn's BFS Topo Sort)
================================================================================
- Problem: Determine if all courses can be finished given prerequisite pairs [v, u] (u -> v).
- Technique: Kahn's Algorithm for Topological Sorting / Cycle Detection.
- Process: Construct directed graph `u -> v` where prerequisite `u` points to `v`. 
  Calculate indegrees. Enqueue nodes with indegree == 0. Run BFS, incrementing `count` 
  for each popped node and decrementing neighbors' indegrees. If `count == n`, 
  all courses can be taken (no cycle).
- Time Complexity: O(V + E) where V = numCourses, E = prerequisites.size().
- Space Complexity: O(V + E) for graph adjacency list, indegree vector, and queue.
================================================================================
*/