// Created by Thom Mott at 2025/05/14 15:23
// leetgo: 1.4.13
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head || !head->next && n > 1)
      return nullptr;

    ListNode *res = new ListNode(0, head);
    ListNode *tmp = res;

    for (int i = 0; i < n; i++) {
      head = head->next;
    }

    while (head) {
      head = head->next;
      tmp = tmp->next;
    }

    ListNode *toDel = tmp->next;
    tmp->next = tmp->next->next;
    delete (toDel);
    return res->next;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode *head;
  LeetCodeIO::scan(cin, head);
  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->removeNthFromEnd(head, n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
