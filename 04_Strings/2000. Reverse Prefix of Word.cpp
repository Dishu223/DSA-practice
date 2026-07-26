class Solution {
public:
  string reversePrefix(string word, char ch) {
    // APPROACH 1 //
    ////////////////

    int j = word.find(ch);

    reverse(word.begin(), word.begin() + j + 1);

    return word;

    // APPROACH 2 //
    ////////////////

    // int idx = 0;

    // while(idx < word.length())
    // {
    //     if(word[idx] == ch)
    //         break;
    //     idx++;
    // }
    // if(word[idx] != ch)
    //     return word;

    // reverse(word.begin(), word.begin() + idx + 1);
    // return word;
  }
};