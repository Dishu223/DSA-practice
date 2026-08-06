class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {

    int n = numCourses;
    vector<int> result;

    unordered_map<int, vector<int>> adj;

    vector<int> indegree(n, 0);
    for (auto edge : prerequisites) {
      int u = edge[0];
      int v = edge[1];
      adj[v].push_back(u);

      indegree[u]++;
    }

    queue<int> que;

    for (int u = 0; u < n; u++) {
      if (indegree[u] == 0)
        que.push(u);
    }

    int count = 0;

    while (!que.empty()) {
      int curr = que.front();
      result.push_back(curr);
      count++;
      que.pop();

      for (int &v : adj[curr]) {
        indegree[v]--;
        if (indegree[v] == 0)
          que.push(v);
      }
    }
    if (count == n)
      return result;
    return {};
  }
};

/*
================================================================================
Approach Summary: Course Schedule II (Topological Order via Kahn's Algorithm)
================================================================================
- Problem: Return the valid ordering of courses to take to finish all courses.
- Technique: Kahn's Algorithm (BFS Topological Sort).
- Process: Build graph `v -> u` (prerequisite `v` to course `u`). Track indegrees. 
  Enqueue 0-indegree courses. Run BFS pushing popped elements into `result` vector. 
  If `count == n`, return `result`; otherwise return empty array `{}`.
- Time Complexity: O(V + E) where V = numCourses, E = prerequisites.size().
- Space Complexity: O(V + E) for adjacency list, indegree array, queue, and result vector.
================================================================================
*/