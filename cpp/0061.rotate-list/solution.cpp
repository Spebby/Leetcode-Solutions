// Created by Thom Mott at 2025/05/14 15:13
// leetgo: 1.4.13
// https://leetcode.com/problems/rotate-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next) {
      return head;
    }

    int size = 0;
    ListNode *explorer = head;
    while (explorer) {
      explorer = explorer->next;
      size++;
    }

    int steps = k % size;
    explorer = head;
    ListNode *tail = head;
    int c = 0;
    while (explorer->next) {
      if (c < steps) {
        tail = head;
      } else {
        tail = tail->next;
      }

      explorer = explorer->next;
      c++;
    }

    explorer->next = head;
    head = tail->next;
    tail->next = nullptr;

    return head;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode *head;
  LeetCodeIO::scan(cin, head);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->rotateRight(head, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
