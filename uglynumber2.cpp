#include<iostream>
#include<algorithm>
#include<malloc.h>
#include<vector>
using namespace std;

/*
int nthUglyNumber(int n) {
	if(n == 1) return 1;
	int* vec = (int*)malloc(n*sizeof(int));
	vec[0] = 1;
	int i = -1, j = -1, k = -1;
	int x=-1, y=-1, z=-1;
	for (int t = 1; t < n; t++) // t-th ugly number
	{
		int cur = vec[t - 1];
		while (x <= cur) x = vec[++i] * 2;
		while (y <= cur) y = vec[++j] * 3;
		while (z <= cur) z = vec[++k] * 5;
		if (x <= y && x <= z)
		{
			vec[t] = x;
		}
		else if (y <= x && y <= z)
		{
			vec[t] = y;
		}
		else if (z <= x && z <= y){
			vec[t] = z;
		}
	}
	int ans = vec[n - 1];
	free(vec);
	return ans;
};
*/

class Solution
{
public:
	int nthUglyNumber(int n) {
		if (n == 1) return 1;
		vector<int> vec;
		vec.push_back(1);
		int i = -1, j = -1, k = -1;
		int x = -1, y = -1, z = -1;
		for (int t = 1; t < n; t++) // t-th ugly number
		{
			int cur = vec[t - 1];
			while (x <= cur) x = vec[++i] * 2;
			while (y <= cur) y = vec[++j] * 3;
			while (z <= cur) z = vec[++k] * 5;
			if (x <= y && x <= z)
			{
				vec.push_back(x);
			}
			else if (y <= x && y <= z)
			{
				vec.push_back(y);
			}
			else if (z <= x && z <= y){
				vec.push_back(z);
			}
		}
		int ans = vec[n - 1];
		return ans;
	};
};

int main()
{
	Solution sol;
	int res = sol.nthUglyNumber(1000);
	cout << res << endl;
	std::vector<int> v;

    return 0;
}
