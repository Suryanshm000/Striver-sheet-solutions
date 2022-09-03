// problem link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	TreeNode* build(vector<int>& inorder, int inStart, int inEnd,                           vector<int>& postorder, int postStart, int postEnd, map<int, int> &inMap)
	{
		// if no element is present
		if (postStart > postEnd || inStart > inEnd)
			return NULL;

		TreeNode* root = new TreeNode(postorder[postEnd]);

		// index of root in inorder
		int inRoot = inMap[root->val];
		// no. of elements on left side of inorder
		int numsLeft = inRoot - inStart;

		// in postorder arr poststart will tell left ele of inorder
		root->left = build(inorder, inStart, inRoot - 1, postorder,
		                   postStart, postStart + numsLeft - 1, inMap);
		root->right = build(inorder, inRoot + 1, inEnd,
		                    postorder, postStart + numsLeft, postEnd - 1, inMap);

		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		map<int, int> inMap;
		for (int i = 0; i < inorder.size(); i++)
			inMap[inorder[i]] = i;

		TreeNode* root = build(inorder, 0, inorder.size() - 1,
		                       postorder, 0, postorder.size() - 1, inMap);
		return root;
	}
};