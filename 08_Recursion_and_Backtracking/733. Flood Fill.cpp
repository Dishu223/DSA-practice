class Solution {
public:
  void dfs_helper(vector<vector<int>> &image, int r, int c, int originalColor,
                  int newColor) {
    if (c < 0 || r < 0 || r >= image.size() || c >= image[0].size() ||
        image[r][c] != originalColor)
      return;
    image[r][c] = newColor;

    dfs_helper(image, r, c - 1, originalColor, newColor);
    dfs_helper(image, r - 1, c, originalColor, newColor);
    dfs_helper(image, r, c + 1, originalColor, newColor);
    dfs_helper(image, r + 1, c, originalColor, newColor);
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int originalColor = image[sr][sc];

    if (originalColor != color)
      dfs_helper(image, sr, sc, originalColor, color);
    return image;
  }
};