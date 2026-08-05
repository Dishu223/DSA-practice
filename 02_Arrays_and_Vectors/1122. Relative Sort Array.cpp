class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    map<int, int> mp;

    for (int &a : arr1)
      mp[a]++;

    int i = 0;

    for (int &b : arr2) {
      while (mp[b]--)
        arr1[i++] = b;
    }

    for (auto &it : mp) {
      int freq = it.second;
      while (freq > 0) {
        arr1[i++] = it.first;
        freq--;
      }
    }
    return arr1;
  }
};

/*
 * Time Complexity: O(N log K + M) - Where N is arr1 size, K is unique elements
 * in arr1 (stored in std::map), and M is arr2 size. Space Complexity: O(K) -
 * Auxiliary space for storing element frequency map..
 *
 * Summary:
 * Counted frequencies of arr1 elements in a ordered map, populated arr1 using
 * the exact relative order defined in arr2, then appended remaining elements in
 * ascending order directly from the map.
 */
