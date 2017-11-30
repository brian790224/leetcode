#include<cstdlib>
#include<iostream>
#include<vector>

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if( t1 == NULL)
			return t2;
		else if( t2 == NULL)
			return t1;
		else
		{
			t1 -> val += t2 -> val; 
		}
		t1 -> left = mergeTrees(t1 -> left, t2 -> left);
		t1 -> right = mergeTrees(t1 -> right, t2 -> right);
		return t1;
    }
	void printTree(TreeNode* node)
	{
		vector<TreeNode*> temp;
		TreeNode* tempNode;
		temp.push_back(node);
		while(temp.size() != 0)
		{
			for( int i = temp.size(); i > 0; i--)
			{
				tempNode = temp.front();
				cout << tempNode -> val << " ";
				temp.erase(temp.begin());
				if( tempNode -> left != NULL)
					temp.push_back(tempNode -> left);
				else if( tempNode -> val != 0)
					temp.push_back(new TreeNode(0));
				if( tempNode -> right != NULL)
					temp.push_back(tempNode -> right);
				else if( tempNode -> val != 0)
					temp.push_back(new TreeNode(0));
			}
			cout << endl;
		}
	}
};

int main(){
	vector<TreeNode*> temp;
	temp.push_back(new TreeNode(1));
	temp.push_back(new TreeNode(3));
	temp.push_back(new TreeNode(2));
	temp.push_back(new TreeNode(5));
	temp[0] -> left = temp[1];
	temp[0] -> right = temp[2];
	temp[1] -> left = temp[3];
	temp.push_back(new TreeNode(2));
	temp.push_back(new TreeNode(1));
	temp.push_back(new TreeNode(3));
	temp.push_back(new TreeNode(4));
	temp.push_back(new TreeNode(7));
	temp[4] -> left = temp[5];
	temp[4] -> right = temp[6];
	temp[5] -> right = temp[7];
	temp[6] -> right = temp[8];
	Solution s;
	s.printTree(temp[0]);
	s.printTree(temp[4]);
	s.printTree(s.mergeTrees( temp[0], temp[4]));
}
