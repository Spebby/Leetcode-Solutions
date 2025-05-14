// Created by Thom Mott at 2025/05/14 14:12
// leetgo: 1.4.13
// https://leetcode.cn/problems/remove-linked-list-elements/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (curr) {
      if (curr->val == val) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }

    return dummy.next;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode *head;
  LeetCodeIO::scan(cin, head);
  int val;
  LeetCodeIO::scan(cin, val);

  Solution *obj = new Solution();
  auto res = obj->removeElements(head, val);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
