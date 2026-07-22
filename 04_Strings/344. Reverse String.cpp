class Solution {
public:
  void helper(vector<char> &s, int left, int right) {
    if (left >= right)
      return;
    swap(s[left], s[right]);

    helper(s, left + 1, right - 1);
  }
  void reverseString(vector<char> &s) {
    // int left=0, right=s.size()-1;
    // while(left < right)
    // {
    //     swap(s[left], s[right]);
    //     left++;
    //     right--;
    // }

    helper(s, 0, s.size() - 1);
  }
};