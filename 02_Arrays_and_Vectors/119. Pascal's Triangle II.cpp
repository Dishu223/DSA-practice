class Solution {
public:
  vector<int> getRow(int rowIndex) {

    vector<int> currRow(rowIndex + 1, 1);

    for (int i = 0; i < rowIndex; i++) {
      for (int j = i; j > 0; j--) {
        currRow[j] = currRow[j] + currRow[j - 1];
      }
    }
    return currRow;
  }
};