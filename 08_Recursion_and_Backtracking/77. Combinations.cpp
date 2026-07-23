class Solution {
public:
  void combinationFinder(int start_num, int n, int k, vector<int> &current_comb,
                         vector<vector<int>> &result) {
    if (current_comb.size() == k) {
      result.push_back(current_comb);
      return;
    }

    for (int i = start_num; i <= n; i++) {
      current_comb.push_back(i);
      combinationFinder(i + 1, n, k, current_comb, result);
      current_comb.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current_comb;

    combinationFinder(1, n, k, current_comb, result);

    return result;
  }
};