class Solution {
public:
  void fillCounts(string word, int count[26]) {
    for (char &ch : word)
      count[ch - 'a']++;
  }
  vector<string> commonChars(vector<string> &words) {
    int count[26] = {0};
    int n = words.size();

    fillCounts(words[0], count);

    for (int i = 1; i < n; i++) {
      int temp[26] = {0};
      fillCounts(words[i], temp);

      for (int j = 0; j < 26; j++) {
        count[j] = min(count[j], temp[j]);
      }
    }
    vector<string> result;

    for (int i = 0; i < 26; i++) {
      int c = count[i];

      while (c--) {
        result.push_back(string(1, i + 'a'));
      }
    }
    return result;
  }
};