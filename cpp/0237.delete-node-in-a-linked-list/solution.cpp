// Created by Thom Mott at 2025/05/14 15:10
// leetgo: 1.4.13
// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    ListNode *t = node->next;
    node->next = node->next->next;
    delete t;
  }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode *head;
  LeetCodeIO::scan(cin, head);
  int node;
  LeetCodeIO::scan(cin, node);

  Solution *obj = new Solution();
  auto res = obj->deleteNode(head, node);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
