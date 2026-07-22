class Solution {
public:
  void findSubsets(int index, vector<int> &nums, vector<int> &curr_subset,
                   vector<vector<int>> &result) {
    result.push_back(curr_subset);

    for (int i = index; i < nums.size(); i++) {
      if (i > index && nums[i] == nums[i - 1])
        continue;
      curr_subset.push_back(nums[i]);
      findSubsets(i + 1, nums, curr_subset, result);
      curr_subset.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> curr_subset;

    sort(nums.begin(), nums.end());

    findSubsets(0, nums, curr_subset, result);

    return result;
  }
};