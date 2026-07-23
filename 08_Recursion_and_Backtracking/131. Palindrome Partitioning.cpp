class Solution {
public:
  bool isPalindrome(string s, int left, int right) {
    while (left <= right) {
      if (s[left] != s[right])
        return false;
      left++;
      right--;
    }
    return true;
  }
  void partitionHelper(int index, string s, vector<string> &current_part,
                       vector<vector<string>> &result) {
    if (index == s.length()) {
      result.push_back(current_part);
      return;
    }

    for (int end = index; end < s.length(); end++) {
      if (isPalindrome(s, index, end)) {
        string substring = s.substr(index, end - index + 1);
        current_part.push_back(substring);
        partitionHelper(end + 1, s, current_part, result);
        current_part.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current_part;

    partitionHelper(0, s, current_part, result);

    return result;
  }
};