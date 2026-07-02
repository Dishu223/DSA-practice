class Solution {
public:
  int lengthOfLastWord(string s) {
    int count = 0;
    int temp = 0;

    for (char ch : s) {
      if (ch != ' ') {
        count++;
        temp = count;
      } else
        count = 0;
    }
    return temp;
  }
};