// Created by Thom Mott at 2025/05/14 15:15
// leetgo: 1.4.13
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr) {
      while (curr->next && curr->val == curr->next->val) {
        curr = curr->next;
      }

      if (prev->next != curr) {
        prev->next = curr->next;
      } else {
        prev = prev->next;
      }
      curr = curr->next;
    }

    return dummy->next;
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
