// problem link: https://leetcode.com/problems/diameter-of-binary-tree/

#include<bits/stdc++.h>
using namespace std;

int findHeight(TreeNode* root, int &dia) {
	if (root == NULL)    return 0;

	int lh = findHeight(root->left, dia);
	int rh = findHeight(root->right, dia);

	// diameter will be sum of left and right height of a node
	dia = max(dia, lh + rh);
	return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
	int dia = 0;
	findHeight(root, dia);
	return dia;
}
