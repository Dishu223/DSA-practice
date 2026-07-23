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