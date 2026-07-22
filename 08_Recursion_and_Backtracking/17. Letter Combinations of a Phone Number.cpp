class Solution {
public:
  void combinationFinder(int index, string digits,
                         unordered_map<char, string> &phone_map,
                         vector<string> &result, string &current_comb) {
    if (index == digits.size()) {
      result.push_back(current_comb);
      return;
    }

    char curr_digit = digits[index];
    string letters = phone_map.at(curr_digit);

    for (char letter : letters) {
      current_comb.push_back(letter);
      combinationFinder(index + 1, digits, phone_map, result, current_comb);
      current_comb.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    string current_comb;
    unordered_map<char, string> phone_map = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    combinationFinder(0, digits, phone_map, result, current_comb);
    return result;
  }
};