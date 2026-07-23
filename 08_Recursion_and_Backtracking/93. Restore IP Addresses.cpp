class Solution {
public:
  bool isValidSegment(string &segment) {
    if (segment.empty() || segment.length() > 3)
      return false;
    if (segment[0] == '0' && segment.length() > 1)
      return false;
    int val = stoi(segment);
    if (val >= 0 && val <= 255)
      return true;
    return false;
  }
  void ipFinder(int start_index, int dot_count, string &s, string current_ip,
                vector<string> &result) {
    if (dot_count == 4) {
      if (start_index == s.length()) {
        result.push_back(current_ip);
      }
      return;
    }

    int chars_left = s.length() - start_index;
    int parts_left = 4 - dot_count;
    if (chars_left < parts_left || chars_left > parts_left * 3)
      return;

    for (int l = 1; l <= 3 && start_index + l <= s.length(); l++) {
      string segment = s.substr(start_index, l);
      if (isValidSegment(segment)) {
        string next_ip =
            current_ip.empty() ? segment : current_ip + "." + segment;

        ipFinder(start_index + l, dot_count + 1, s, next_ip, result);
      }
    }
  }
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    ipFinder(0, 0, s, "", result);
    return result;
  }
};