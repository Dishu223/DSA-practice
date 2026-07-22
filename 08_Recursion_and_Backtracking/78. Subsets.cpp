class Solution {
public:
  // void findSubsets(int index, vector<int> nums, vector<int>& currentSubset,
  // vector<vector<int>>& allSubsets)
  // {
  //     if(index == nums.size())
  //     {
  //         allSubsets.push_back(currentSubset);
  //         return;
  //     }
  //     findSubsets(index+1, nums, currentSubset, allSubsets); //Don't include
  //     nums[index]

  //     currentSubset.push_back(nums[index]); //Include current num ->
  //     nums[index] findSubsets(index+1, nums, currentSubset, allSubsets);
  //     //Include...

  //     currentSubset.pop_back();
  // }
  // vector<vector<int>> subsets(vector<int>& nums) {
  // vector<int> currentSubsets;
  // vector<vector<int>> allSubsets;
  // findSubsets(0, nums, currentSubsets, allSubsets);
  // return allSubsets;

  void findSubsets(vector<int> &nums, int index, vector<int> current_subset,
                   vector<vector<int>> &result) {
    if (index == nums.size()) {
      result.push_back(current_subset);
      return;
    }

    findSubsets(nums, index + 1, current_subset, result);

    current_subset.push_back(nums[index]);
    findSubsets(nums, index + 1, current_subset, result);
    current_subset.pop_back();
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current_subset;

    findSubsets(nums, 0, current_subset, result);

    return result;
  }
};