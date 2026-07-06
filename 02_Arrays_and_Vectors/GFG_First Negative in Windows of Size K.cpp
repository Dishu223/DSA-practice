class Solution {
public:
  vector<int> firstNegInt(vector<int> &arr, int k) {
    // code here
    int n = arr.size();
    int i = 0, j = 0;
    vector<int> result;
    deque<int> deq;

    while (j < n) {

      if (arr[j] < 0)
        deq.push_back(arr[j]);
      if (j - i + 1 == k) {
        if (!deq.empty()) {
          result.push_back(deq.front());
        } else
          result.push_back(0);

        if (arr[i] < 0 && !deq.empty()) {
          deq.pop_front();
        }
        i++;
      }

      j++;
    }
    return result;
  }
};