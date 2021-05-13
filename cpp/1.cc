#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
	public:
	    vector<int> twoSum(vector<int>& nums, int target) 
	{
        int len = nums.size();
        std::vector<int> vec(2);
        for (int i=0; i<len; i++)
        {
            for (int j=i+1; j<len; j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    vec[0] = i;
                    vec[1] = j;
                    break;
                }
            }
        }
        return vec;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> vec{2,7,11,15};
	auto res = s.twoSum(vec, 9);
	for (const auto& r: res)
	{
		cout << r << endl;
	}
	return 0;
}
