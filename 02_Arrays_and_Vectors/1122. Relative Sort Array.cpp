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