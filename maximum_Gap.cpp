#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<iostream>

using namespace std;

#define max(a,b) (((a)>(b))? (a):(b))
#define min(a,b) (((a)<(b))? (a):(b))

int maximumGap(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 2) return 0;

	int max_n = 0x80000000, min_n = 0x7fffffff;
	for (int i = 0; i < numsSize; i++)
	{
		max_n = max(max_n, nums[i]);
		min_n = min(min_n, nums[i]);
	}
	int gap = ceil((double)(max_n - min_n) / (numsSize - 1));
	int* bucket_min = (int*)malloc((numsSize - 1)*sizeof(int));
	int* bucket_max = (int*)malloc((numsSize - 1)*sizeof(int));

	for (int i = 0; i < numsSize - 1; i++)
	{
		bucket_max[i] = 0x80000000;
		bucket_min[i] = 0x7fffffff;
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == min_n || nums[i] == max_n) continue;
		int idx = (nums[i] - min_n) / gap;
		bucket_min[idx] = min(bucket_min[idx], nums[i]);
		bucket_max[idx] = max(bucket_max[idx], nums[i]);
	}

	int before = min_n;
	int ans = 0;
	for (int i = 0; i < numsSize - 1; i++)
	{
		if ((bucket_max[i] == 0x80000000) && (bucket_min[i] == 0x7fffffff)) continue;
		ans = max(ans, bucket_min[i] - before);
		before = bucket_max[i];
	}
	ans = max(ans, max_n - before);
	free(bucket_min);
	free(bucket_max);
	return ans;

}


class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int numsSize = nums.size();
		if (nums.empty() || numsSize < 2) return 0;
		
		int max_n = 0x80000000, min_n = 0x7fffffff;
		for (int i = 0; i < numsSize; i++)
		{
			max_n = max(max_n, nums[i]);
			min_n = min(min_n, nums[i]);
		}
		int gap = ceil((double(max_n - min_n) / (numsSize - 1)));

		vector<int> bucket_min, bucket_max;
		for (int i = 0; i < numsSize - 1; i++)
		{			
			bucket_max.push_back(0x80000000);
			bucket_min.push_back(0x7fffffff);
		}
		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] == min_n || nums[i] == max_n) continue;
			int idx = (nums[i] - min_n) / gap;
			bucket_min[idx] = min(bucket_min[idx], nums[i]);
			bucket_max[idx] = max(bucket_max[idx], nums[i]);
		}

		int before = min_n;
		int ans = 0;
		for (int i = 0; i < numsSize - 1; i++)
		{
			if ((bucket_max[i] == 0x80000000) && (bucket_min[i] == 0x7fffffff)) continue;
			ans = max(ans, bucket_min[i] - before);
			before = bucket_max[i];
		}
		ans = max(ans, max_n - before);

		return ans;

	}
};

void main()
{
	int nums[8] = {3,4,5,2,1,1,8,9};
	int ans = maximumGap(nums, 8);
	Solution sol;
	vector<int> vec = { 3, 4, 5, 2, 1, 1, 8, 9 };
	int ans2 = sol.maximumGap(vec);
	cout << ans2 << " " << ans2 << endl;
} 