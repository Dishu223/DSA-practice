class Solution {
public:
  int convertFive(int n) {
    if (n == 0)
      return 5;
    int temp = n;
    vector<int> digits;

    while (temp) {
      int digit = temp % 10;
      digits.push_back(digit);
      temp = temp / 10;
    }

    for (int i = 0; i <= digits.size() - 1; i++) {
      if (digits[i] == 0) {
        digits[i] = 5;
      }
    }

    reverse(digits.begin(), digits.end()); // [1,5,5,4]

    // [1,5,5,4] -> 1554

    int number_to_be_made = 0;

    int curr = digits.size() - 1;

    for (int i = 0; i < digits.size(); i++) {
      answer += pow(10, i) * digits[curr];
      curr--;
    }
    return answer;
  }
};