///// DFS /////

class Solution {
public:
  void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited,
           stack<int> &st) {
    visited[u] = true;

    for (int &v : adj[u]) {
      if (!visited[v]) {
        dfs(adj, v, visited, st);
      }
    }
    st.push(u);
  }
  vector<int> topoSort(int V, vector<vector<int>> &edges) {
    // code here

    unordered_map<int, vector<int>> adj;

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
    }
    vector<bool> visited(V, false);
    vector<int> result;
    stack<int> st;

    for (int i = 0; i < V; i++) {
      if (!visited[i])
        dfs(adj, i, visited, st);
    }
    while (!st.empty()) {
      int curr = st.top();
      st.pop();
      result.push_back(curr);
    }
    return result;
  }
};

///// BFS - KAHN'S ALGORITHM /////

class Solution {
public:
  vector<int> topoSort(int V, vector<vector<int>> &edges) {

    unordered_map<int, vector<int>> adj; // GRAPH BANA LIYA!
    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++) {
      for (int v : adj[u])
        indegree[v]++;
    }

    queue<int> que;

    for (int u = 0; u < V; u++) {
      if (indegree[u] == 0)
        que.push(u);
    }

    // BFS KARENGE NORMAL WALA!
    vector<int> result;

    while (!que.empty()) {
      int curr = que.front();
      result.push_back(curr);
      que.pop();
      for (int &v : adj[curr]) {
        indegree[v]--;
        if (indegree[v] == 0)
          que.push(v);
      }
    }
    return result;
  }
};