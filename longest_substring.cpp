// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. 
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cur = 0, longest=0,begin = 0;
        vector<int> pos(256,-1);
        for (int i=0;i<s.length();i++)
        {
            if (pos[s[i]]==-1) //first  
            {
                cur++;
            }else // not first
            {
                if (begin < pos[s[i]])  begin = pos[s[i]];
                cur = i - begin;
            }
            pos[s[i]] = i;
            if (longest < cur ) longest = cur;
        }
        return longest;
    }
};

int main()
{

    Solution sol;
    int res = sol.lengthOfLongestSubstring("zaabcaabcdab");
    cout<<res<<endl;
}
