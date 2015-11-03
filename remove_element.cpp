#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (auto i = nums.begin(); i != nums.end();)
		{
			if (*i == val)
			{
				i = nums.erase(i);
			}
			else{
				i++;
			}
		}
		return nums.size();
	}
};

void main()
{
	vector<int> nums = { 1, 3, 4, 2, 1, 1 };
	int val = 1;
	Solution sol;
	int ans = sol.removeElement(nums, val);
	cout << ans << endl;
}