/*

Author : Rohit Yadav
Date : 06/05/2024
Problem : print all nodes that dont have sibling
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1
Video Solution : NA

*/
Node *solve(Node *root, vector<int> &ans)
{
  if (root == NULL)
  {
    return NULL;
  }

  Node *left = solve(root->left, ans);
  Node *right = solve(root->right, ans);

  if (left != NULL && right == NULL)
  {
    ans.push_back(left->data);
  }
  if (right != NULL && left == NULL)
  {
    ans.push_back(right->data);
  }
  return root;
}

vector<int> noSibling(Node *node)
{
  // code here
  vector<int> ans;
  Node *root = solve(node, ans);
  sort(ans.begin(), ans.end());

  if (ans.size() == 0)
  {
    return {-1};
  }
  return ans;
}