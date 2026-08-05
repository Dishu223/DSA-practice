class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, x = m + n - 1;

    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[x] = nums1[i];
        i--;
      } else {
        nums1[x] = nums2[j];
        j--;
      }
      x--;
    }
    while (j >= 0) {
      nums1[x] = nums2[j];
      j--;
      x--;
    }
  }
};

/*
 * Time Complexity: O(m + n) - Single pass filling elements from right to left.
 * Space Complexity: O(1) - Constant space since merge is done directly in nums1.
 *
 * Summary:
 * Merged nums2 into nums1 in-place by comparing elements from the back of both arrays
 * and writing the larger element to the end of nums1 to avoid overwriting existing data.
 */