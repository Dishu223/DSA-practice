class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;

    for (auto ast : asteroids) {
      bool isDestroyed = false;

      if (ast > 0)
        st.push(ast);
      else {
        while (!st.empty() && ast < 0 && st.top() > 0) {
          if (st.top() < abs(ast)) {
            st.pop();
          } else if (st.top() == abs(ast)) {
            st.pop();
            isDestroyed = true;
            break;
          } else {
            isDestroyed = true;
            break;
          }
        }
        if (!isDestroyed)
          st.push(ast);
      }
    }
    vector<int> result;
    int n = st.size();

    for (int i = 0; i < n; i++) {
      result.push_back(st.top());
      st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};