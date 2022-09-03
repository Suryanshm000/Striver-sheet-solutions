// problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap)
	{
		// if no element exist
		if (preStart > preEnd || inStart > inEnd)
			return NULL;

		// preorder start will be root
		TreeNode* root = new TreeNode(preorder[preStart]);

		int inRoot = inMap[root->val];
		// no. of elements in inorder on left side of root
		int numsLeft = inRoot - inStart;

		root->left = build(preorder, preStart + 1, preStart +
		                   numsLeft, inorder, inStart, inRoot - 1, inMap);

		root->right = build(preorder, preStart + numsLeft + 1,
		                    preEnd, inorder, inRoot + 1, inEnd, inMap);

		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		map<int, int> inMap;
		// index of inorder values
		for (int i = 0; i < inorder.size(); i++)
			inMap[inorder[i]] = i;

		TreeNode* root = build(preorder, 0, preorder.size() - 1,
		                       inorder, 0, inorder.size() - 1, inMap);
		return root;
	}
};