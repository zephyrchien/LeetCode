#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> two_sum(vector<int>& nums, int target) {
            unordered_map<int,int> table;
            for (int i = 0; i < nums.size(); ++i) {
                auto value = nums[i];
                auto it = table.find(target - value);
                if (it != table.end()) {
                    return {i, it->second};
                }
                table.insert({value, i});
            }
            return {};
        }
};

int main(int argc, char *argv[]) 
{
    vector<int> input{2,7,11,15};
    const int target = 9;
    Solution s;
    for (auto x: s.two_sum(input, target)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
