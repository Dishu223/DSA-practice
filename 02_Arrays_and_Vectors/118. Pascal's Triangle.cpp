class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    for (int i = 0; i < numRows; i++) {
      vector<int> row(i + 1, 1);

      for (int j = 1; j < i; j++) {
        row[j] = result[i - 1][j - 1] + result[i - 1][j];
      }
      result.push_back(row);
    }
    return result;
  }
};

/*
 * Time Complexity: O(numRows^2) - Generating numRows rows where row i takes i
 * operations. Space Complexity: O(1) auxiliary space (O(numRows^2) to store the
 * returned output)..
 *
 * Summary:
 * Iteratively constructs each row of Pascal's Triangle by placing 1 at the
 * boundaries and summing adjacent elements from the previous row for middle
 * positions.
 */
