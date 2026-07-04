class Solution {
public:
  vector<vector<int>>
  filterOccupiedIntervals(vector<vector<int>> &occupiedIntervals, int freeStart,
                          int freeEnd) {

    if (occupiedIntervals.empty())
      return {};

    int n = occupiedIntervals.size();
    vector<vector<int>> merged;

    sort(occupiedIntervals.begin(), occupiedIntervals.end());

    merged.push_back(occupiedIntervals[0]);

    for (int i = 1; i < n; i++) {
      if (occupiedIntervals[i][0] <= merged.back()[1] + 1)
        merged.back()[1] = max(merged.back()[1], occupiedIntervals[i][1]);
      else
        merged.push_back(occupiedIntervals[i]);

    } // merged all the overlapping and touching intervals //

    vector<vector<int>> result;

    for (auto &interval : merged) {
      if (interval[1] < freeStart || interval[0] > freeEnd)
        result.push_back(interval);
      else {
        if (interval[0] < freeStart)
          result.push_back({interval[0], freeStart - 1});
        if (interval[1] > freeEnd)
          result.push_back({freeEnd + 1, interval[1]});
      }
    }

    return result;
  }
};