// Created by Thom Mott at 2025/05/14 15:11
// leetgo: 1.4.13
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) {
    if (!head || !head->next)
      return nullptr;

    ListNode *slow = new ListNode(0, head);
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = slow->next->next;
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
  auto res = obj->deleteMiddle(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
