class Solution {
public:
  void findPermutations(vector<int> &nums, vector<int> &current_perm,
                        vector<bool> &used, vector<vector<int>> &result) {
    if (current_perm.size() == nums.size()) {
      result.push_back(current_perm);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == true)
        continue;

      used[i] = true;
      current_perm.push_back(nums[i]);
      findPermutations(nums, current_perm, used, result);
      current_perm.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    vector<int> current_perm;

    findPermutations(nums, current_perm, used, result);

    return result;
  }
};