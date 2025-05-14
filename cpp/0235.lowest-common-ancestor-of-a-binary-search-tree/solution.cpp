// Created by Thom Mott at 2025/05/14 15:04
// leetgo: 1.4.13
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (root && (!(root->val >= p->val) || !(root->val <= q->val))) {
      if (root->val < p->val && root->val < q->val) {
        root = root->right;
      } else if (root->val > p->val && root->val > q->val) {
        root = root->left;
      } else {
        break;
        // A = lca
      }
    }
    return root;
  }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode *root;
  LeetCodeIO::scan(cin, root);
  int p;
  LeetCodeIO::scan(cin, p);
  int q;
  LeetCodeIO::scan(cin, q);

  Solution *obj = new Solution();
  auto res = obj->lowestCommonAncestor(root, p, q);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
