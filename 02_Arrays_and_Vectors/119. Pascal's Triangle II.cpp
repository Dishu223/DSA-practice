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

/*
 * Time Complexity: O(rowIndex^2) - Nested loops calculating values up to row index.
 * Space Complexity: O(1) auxiliary space (O(rowIndex) space for returning the result vector).
 *
 * Summary:
 * Generates the k-th index row of Pascal's Triangle in-place by updating a single 1D vector 
 * backwards from right to left to prevent overwriting values needed for calculation.
 */