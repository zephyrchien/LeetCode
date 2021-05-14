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
    
    	vector<int> twoSum_2(vector<int>& nums, int target)
    	{
		    int len = nums.size();
		    std::vector<int> res(2);
		    std::unordered_map<int,int> map;

		    for (int i=0; i<len; i++)
		    {
		        map[nums[i]] = i;
		    }
		    auto not_found = map.end();
		    for (int i=0; i<len; i++)
		    {
		        auto found = map.find(target - nums[i]);
		        if (found != not_found && found->second != i)
		        {
		            res[0] = i;
		            res[1] = found->second;
		        }
		    }
        return res;
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
