// Created by Thom Mott at 2025/05/14 15:14
// leetgo: 1.4.13
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *a = head;
    while (a->next) {
      if (a->val == a->next->val) {
        a->next = a->next->next;
      } else {
        a = a->next;
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
  auto res = obj->deleteDuplicates(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
