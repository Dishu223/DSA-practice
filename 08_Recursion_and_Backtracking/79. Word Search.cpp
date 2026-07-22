class Solution {
public:
  bool wordSearch(int word_index, int r, int c, vector<vector<char>> &board,
                  string word) {
    if (word_index == word.length())
      return true;
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
        board[r][c] != word[word_index])
      return false;

    char temp = board[r][c];
    board[r][c] = '*';

    bool found = wordSearch(word_index + 1, r - 1, c, board, word) ||
                 wordSearch(word_index + 1, r, c - 1, board, word) ||
                 wordSearch(word_index + 1, r, c + 1, board, word) ||
                 wordSearch(word_index + 1, r + 1, c, board, word);
    board[r][c] = temp;
    return found;
  }
  bool exist(vector<vector<char>> &board, string word) {
    int r = board.size();
    int c = board[0].size();

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (wordSearch(0, i, j, board, word))
          return true;
      }
    }
    return false;
  }
};