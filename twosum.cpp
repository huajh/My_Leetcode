#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		
		int index1, index2;
		vector<int> indx(nums.size());
		iota(indx.begin(), indx.end(), 0);
		sort(indx.begin(), indx.end(), [&nums](int a, int b){return nums[a] < nums[b]; } );
		stack<int> sta;
		stack<int> sta_idx;
		sta.push(nums[indx[0]]);
		sta_idx.push(indx[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			int j = indx[i];

			while (sta.top() + nums[j] > target)
			{
				sta.pop();
				sta_idx.pop();
			}
			int cur = sta.top();
			if (cur + nums[j] == target)
			{
				int k = sta_idx.top();
				index1 = j < k ? j : k;
				index2 = j > k ? j : k;
				break;
			}
			
			if (cur + nums[j] < target && 2 * nums[j] <= target)
			{
				sta.push(nums[j]);
				sta_idx.push(j);
			}								
		}			
		return vector<int> {index1+1, index2+1};
	}
};


int main()
{
	Solution sol;
	vector<int> nums = { 3, 2, 4 };
	int target = 6;
	vector<int> ans = sol.twoSum(nums, target);

    return 0;
}
