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