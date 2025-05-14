// Created by Thom Mott at 2025/05/14 15:17
// leetgo: 1.4.13
// https://leetcode.com/problems/palindrome-linked-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *t = head;
    return isPalindrome(&t, t);
  }

  bool isPalindrome(ListNode **L, ListNode *R) {
    if (!R)
      return true;

    bool res = isPalindrome(L, R->next);
    if ((*L)->val != R->val || !res) {
      return false;
    } else {
      (*L) = (*L)->next;
      return true;
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode *head;
  LeetCodeIO::scan(cin, head);

  Solution *obj = new Solution();
  auto res = obj->isPalindrome(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
