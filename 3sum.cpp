#include <iostream>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3)
        {
            return ans;
        }

        sort(nums.begin(), nums.end(), less<int>()); // O(nlogn) ascend

        auto last = nums.end();
        for (auto i = nums.begin(); i < nums.end() - 2; i++)
        {
            if (i > nums.begin() && *i == *(i - 1))
                continue;
            auto j = i + 1;
            auto k = last - 1;
            while (j < k)
            {
                if (*i + *j + *k > 0)
                {
                    k--;
                    while (*k == *(k + 1) && j < k)
                        k--;
                }
                else if (*i + *j + *k < 0)
                {
                    j++;
                    while (*j == *(j - 1) && j < k)
                        j++;
                }
                else
                {
                    ans.push_back({*i, *j, *k});
                    j++;
                    k--;
                    while (*j == *(j - 1) && j < k)
                        j++;
                    while (*k == *(k + 1) && j < k)
                        k--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vec;
    vec.reserve(100);
    //-1 0 1 2 -1 -4
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(-4);    

    Solution sol;

    vector<vector<int>> ans;
    ans = sol.threeSum(vec);
    return 0;
}
