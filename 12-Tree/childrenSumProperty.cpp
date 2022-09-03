// problem link: https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723

#include<bits/stdc++.h>
using namespace std;


void changeTree(BinaryTreeNode < int > * root) {
	// Write your code here.
	if (root == NULL)
		return;

	int childSum = 0;
	if (root->left)
		childSum += root->left->data;
	if (root->right)
		childSum += root->right->data;

	// if root value is lesser than increase
	if (root->data <= childSum)
		root->data = childSum;
	// root value is greater then change any of child value = root value
	else
	{
		if (root->left)
			root->left->data = root->data;
		else if (root->right)
			root->right->data = root->data;
	}

	// move to left and right to do above logic
	changeTree(root->left);
	changeTree(root->right);

	// again come and check the children sum
	int total = 0;
	if (root->left)
		total += root->left->data ;
	if (root->right)
		total += root->right->data;
	// if root is not a leaf node
	if (root->left || root->right)
		root->data = total;
}