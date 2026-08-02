class Solution {
public:
  int countValidPrefixes(string s) {
    int i = 0;
    int zeros = 0;
    int ones = 0;
    int count = 0;

    while (i < s.length()) {
      if (s[i] == '0')
        zeros++;
      else
        ones++;
      if (abs(zeros - ones) <= 1)
        count++;
      i++;
    }
    return count;
  }
};