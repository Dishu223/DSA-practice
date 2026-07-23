class Solution {
public:
  void permutationFinder(vector<int> &nums, vector<bool> &used,
                         vector<int> &current_comb,
                         vector<vector<int>> &result) {
    if (current_comb.size() == nums.size()) {
      result.push_back(current_comb);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;

      used[i] = true;
      current_comb.push_back(nums[i]);
      permutationFinder(nums, used, current_comb, result);
      current_comb.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current_comb;
    vector<bool> used(nums.size(), false);

    sort(nums.begin(), nums.end());

    permutationFinder(nums, used, current_comb, result);

    return result;
  }
};