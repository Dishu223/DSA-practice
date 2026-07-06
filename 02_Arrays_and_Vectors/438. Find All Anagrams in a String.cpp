class Solution {
public:
  bool allZero(vector<int> &counter) {
    for (int i : counter) {
      if (i != 0)
        return false;
    }
    return true;
  }
  vector<int> findAnagrams(string s, string p) {
    vector<int> counter(26, 0);

    for (char &i : p) {
      counter[i - 'a']++;
    }

    int i = 0, j = 0;
    vector<int> result;
    int n = s.length();
    int k = p.length();

    while (j < n) {
      counter[s[j] - 'a']--;

      if (j - i + 1 == k) {
        if (allZero(counter))
          result.push_back(i);
        counter[s[i] - 'a']++;
        i++;
      }
      j++;
    }
    return result;
  }
};