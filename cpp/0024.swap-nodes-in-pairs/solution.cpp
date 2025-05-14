// Created by Thom Mott at 2025/05/14 15:08
// leetgo: 1.4.13
// https://leetcode.com/problems/swap-nodes-in-pairs/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *a = head;
    ListNode *b = head->next;

    while (a && b) {
      int t = a->val;
      a->val = b->val;
      b->val = t;

      a = b->next;
      if (b->next) {
        b = b->next->next;
      }
    }

    return head;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode *head;
  LeetCodeIO::scan(cin, head);

  Solution *obj = new Solution();
  auto res = obj->swapPairs(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
