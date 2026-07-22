class Solution {
public:
  void combinationFinder(int index, vector<int> &candidates, int target,
                         vector<vector<int>> &result,
                         vector<int> &current_comb) {
    if (target == 0) {
      result.push_back(current_comb);
      return;
    }
    if (target < 0)
      return;

    for (int i = index; i < candidates.size(); i++) {
      if (i > index && candidates[i] == candidates[i - 1])
        continue;

      current_comb.push_back(candidates[i]);
      combinationFinder(i + 1, candidates, target - candidates[i], result,
                        current_comb);
      current_comb.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> current_comb;
    sort(candidates.begin(), candidates.end());
    combinationFinder(0, candidates, target, result, current_comb);
    return result;
  }
};