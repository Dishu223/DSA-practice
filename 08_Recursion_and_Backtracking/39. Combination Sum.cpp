class Solution {
public:
  void findCombination(int index, int target, vector<int> &candidates,
                       vector<vector<int>> &result, vector<int> &current_try) {
    if (target == 0) {
      result.push_back(current_try);
      return;
    }
    if (target < 0)
      return;

    for (int i = index; i < candidates.size(); i++) {
      current_try.push_back(candidates[i]);
      findCombination(i, target - candidates[i], candidates, result,
                      current_try);
      current_try.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> current_try;

    findCombination(0, target, candidates, result, current_try);

    return result;
  }
};