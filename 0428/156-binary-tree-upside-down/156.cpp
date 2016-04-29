#include <stack>
#include <iostream>

/**
 * Definition for a binary tree node.
 struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root || !root->left) return root;
    
    TreeNode* cur_left = root->left;
    TreeNode* cur_right = root->right;
    TreeNode* new_root = upsideDownBinaryTree(cur_left);
    cur_left->right = root; //although it's cleaned in last recursion, we will apply new value here
    cur_left->left = cur_right;
    
    root->left = nullptr; //remeber to clean the new right most node, at last the root will become right most node
    root->right = nullptr;
    return new_root;
  }

};

int main() {
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(2);
  TreeNode* c= new TreeNode(3);
  a->left = c;
  a->right = b;

  Solution s;
  auto x = s.upsideDownBinaryTree(a);
  cout << x->val;
  cout << x->left->val;
  cout << x->right->val;
  

  delete a;
  delete b;
  delete c;
  return 0;
}
