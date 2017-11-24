#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* maximumNode = NULL;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		for( vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			TreeNode* node = new TreeNode(*it);
			//cout << "process:" << *it << endl;
			if( maximumNode == NULL)
			{
				maximumNode = node;	
			}
			else
			{
				insertTreeNode(maximumNode, node);
			}
			//cout << "iteration:" << endl;
			//printTree();
		}
		return maximumNode;
    }
	void insertTreeNode(TreeNode* &root, TreeNode* &node)
	{
		if( (node -> val) > (root -> val))
		{
			node -> left = root;
			root = node;
		}
		else if( root -> right == NULL)
		{
			root -> right = node;
		}
		else
		{
			insertTreeNode(root -> right, node);
		}
	}
	void printTree(){
	    vector<TreeNode*> tree;
	    tree.push_back(maximumNode);
		for( unsigned int i = 0; i < tree.size(); i++)
		{
			cout << (tree[i]) -> val << " ";
			if( (tree[i]) -> left != NULL)
			{
				tree.push_back( (tree[i]) -> left);
			}
			else if( (tree[i]) -> val != -1)
			{
				tree.push_back(new TreeNode(-1));
			}
			if( (tree[i]) -> right != NULL)
			{
				tree.push_back( (tree[i]) -> right);
			}
			else if( (tree[i]) -> val != -1)
			{
				tree.push_back(new TreeNode(-1));
			}
			cout << endl;
		}
	}
};

int main(){
	vector<int> test;
	test.push_back(3);
	test.push_back(2);
	test.push_back(1);
	test.push_back(4);
	test.push_back(6);
	test.push_back(0);
	test.push_back(5);
	Solution s;
	s.constructMaximumBinaryTree(test);
	return 0;
}
