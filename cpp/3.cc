class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> filter;
        int len = s.size();
        int idx = 0, res = 0;
        for (int i = 0; i < len; ++i) {
            if (len - i <= res) break;
            if (i != 0) filter.erase(s[i-1]);
            while (idx < len && filter.count(s[idx]) == 0) {
                filter.insert(s[idx]);
                ++idx;
            }
            res = max(res, idx - i);
        }
        return res;
    }
};
