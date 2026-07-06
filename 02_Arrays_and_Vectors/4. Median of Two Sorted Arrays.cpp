class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    if (nums2.size() < nums1.size())
      return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size();
    int n = nums2.size();

    int l = 0, h = m;

    while (l <= h) {
      int partition1 = l + (h - l) / 2;
      int partition2 = (m + n + 1) / 2 - partition1;

      int x1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
      int x3 = (partition1 == m) ? INT_MAX : nums1[partition1];

      int x2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
      int x4 = (partition2 == n) ? INT_MAX : nums2[partition2];

      if (x1 <= x4 && x2 <= x3) {
        if ((m + n) % 2 == 0)
          return (max(x1, x2) + min(x3, x4)) / 2.0;
        return max(x1, x2);
      } else if (x1 > x4)
        h = partition1 - 1;
      else
        l = partition1 + 1;
    }
    return -1;
  }
};

// HARD //
// HARD //
// HARD //
// HARD //
// HARD //