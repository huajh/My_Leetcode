#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> vvec;
		if (root == NULL)
		{
			return vvec;
		}		
		vector<int> vec0;
		stack<TreeNode*> sta_l;
		stack<TreeNode*> sta_r;
		sta_l.push(root);
		vec0.push_back(root->val);
		vvec.push_back(vec0);
		int cnt = 0;
		while (!sta_l.empty() || !sta_r.empty())
		{
			cnt++;
			vector<int> vec;
			if (cnt%2 == 1)
			{							
				while (!sta_l.empty())
				{				
					TreeNode* cur = sta_l.top();
					sta_l.pop();					
					if (cur->right != NULL)
					{
						sta_r.push(cur->right);
						vec.push_back((cur->right)->val);
					}
					if (cur->left != NULL)
					{
						sta_r.push(cur->left);
						vec.push_back((cur->left)->val);
					}
				}							
			}
			else{
				while (!sta_r.empty())
				{
					TreeNode* cur = sta_r.top();
					sta_r.pop();					
					if (cur->left != NULL)
					{
						sta_l.push(cur->left);
						vec.push_back(cur->left->val);
					}
					if (cur->right != NULL){
						sta_l.push(cur->right);
						vec.push_back(cur->right->val);
					}
				}				
			}
			if (!vec.empty())
			{
				vvec.push_back(vec);
			}			
		}
		return vvec;
	}
};
