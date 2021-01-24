#include <iostream>
#include <vector>


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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int size = preorder.size();
		if (size == 0) return NULL;

		int root_val = preorder[0];

		TreeNode* root = new TreeNode(root_val);

		int index = 0;
		for (; index<size; index++)
		{
			if (inorder[index] == root_val)
			{
				break;
			}
		}
		vector<int> preorder_l(preorder.begin() + 1, preorder.begin() + index + 1);
		vector<int> inorder_l(inorder.begin(), inorder.begin() + index);
		root->left = buildTree(preorder_l, inorder_l);

		vector<int> preorder_r(preorder.begin() + index + 1, preorder.end());
		vector<int> inorder_r(inorder.begin() + index + 1, inorder.end());
		root->right = buildTree(preorder_r, inorder_r);

		return root;
	}
};


//int main()
//{
//	Solution sl;
//	vector<int> preorder{ 3, 9, 20, 15, 7 };
//	vector<int> inorder{ 9, 3, 15, 20, 7 };
//	sl.buildTree(preorder, inorder);
//
//	return 0;
//}