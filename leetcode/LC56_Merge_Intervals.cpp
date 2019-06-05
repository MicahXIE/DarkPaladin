// problem: https://leetcode.com/problems/merge-intervals/
// http://www.cplusplus.com/reference/vector/vector/back/
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        
        // https://www.geeksforgeeks.org/sorting-a-vector-in-c/
        std::sort(intervals.begin(), intervals.end(), 
                  [](const Interval& a, const Interval& b){
                        return a.start < b.start;
                    });
        
        vector<Interval> ans;        
        for (const auto& interval : intervals) {
            if (ans.empty() || interval.start > ans.back().end) {
                ans.push_back(interval);
            } else {
                ans.back().end = max(ans.back().end, interval.end);
            }
        }
        
        return ans;
    }
};