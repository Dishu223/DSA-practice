////////  APPROACH 1 - DFS  /////////////

class Solution {
public:
  int n;
  void dfs(vector<vector<int>> &isConnected, int &node, vector<bool> &visited) {
    visited[node] = true;

    for (int v = 0; v < n; v++) {
      if (!visited[v] && isConnected[node][v] == 1)
        dfs(isConnected, v, visited);
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected) {
    n = isConnected.size();
    int count = 0;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(isConnected, i, visited);
        count++;
      }
    }
    return count;
  }
};

////////  APPROACH 2 - BFS  /////////////

class Solution {
public:
  void bfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
    queue<int> que;

    que.push(u);
    visited[u] = true;

    while (!que.empty()) {
      int curr = que.front();
      que.pop();

      for (int &v : adj[curr]) {
        if (!visited[v])
          bfs(adj, v, visited);
      }
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected) {
    unordered_map<int, vector<int>> adj;

    int n = isConnected.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        bfs(adj, i, visited);
        count++;
      }
    }
    return count;
  }
};

////////  APPROACH 2 - BFS without making own graph (without using adj!)
///////////

class Solution {
public:
  int n;
  void bfs(vector<vector<int>> &isConnected, int u, vector<bool> &visited) {
    n = isConnected.size();
    queue<int> que;

    que.push(u);
    visited[u] = true;

    while (!que.empty()) {
      int curr = que.front();
      que.pop();

      for (int v = 0; v < n; v++) {
        if (!visited[v] && isConnected[u][v] == 1)
          bfs(isConnected, v, visited);
      }
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected) {

    n = isConnected.size();

    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        bfs(isConnected, i, visited);
        count++;
      }
    }
    return count;
  }
};