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