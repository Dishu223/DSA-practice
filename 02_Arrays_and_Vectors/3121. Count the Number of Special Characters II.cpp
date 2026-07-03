class Solution {
public:
  int numberOfSpecialChars(string word) {
    vector<int> lowerIndex(26, -1);
    vector<int> upperIndex(26, -1);

    int count = 0;

    for (int i = 0; i < word.size(); i++) {
      if (islower(word[i]))
        lowerIndex[word[i] - 'a'] = i;
      else {
        if (upperIndex[word[i] - 'A'] == -1)
          upperIndex[word[i] - 'A'] = i;
      }
    }

    for (int i = 0; i < 26; i++) {
      if (lowerIndex[i] < upperIndex[i] && lowerIndex[i] != -1 &&
          upperIndex[i] != -1)
        count++;
    }
    return count;
  }
};