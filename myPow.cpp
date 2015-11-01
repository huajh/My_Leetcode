#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double ans = 1.0;		
		if (n < 0)	x = 1. / x;	
		int bit_n = abs(n);
		while (bit_n>0)
		{
			if (bit_n & 1) ans = ans * x;
			x *= x;
			bit_n >>=1;
		}
		return ans;
	}
};

void main()
{
	Solution sol;
	double x = 1.323;
	int max_n = 0x7fffffff, min_n = 0x80000000;
	int n = 10;
	double ans0 = pow(x, n);
	double ans = sol.myPow(x, n);
	cout << ans0 << "\t"<<ans << endl;
}
