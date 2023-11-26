#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
   TreeNode *build(ListNode *head, ListNode *tail) {
      if (head == tail) return nullptr;
      if (head->next == tail) return new TreeNode(head->val);
      ListNode *slow = head, *fast = head;
      while (fast != tail && fast->next != tail) {
         slow = slow->next;
         fast = fast->next->next;
      }
      TreeNode *root = new TreeNode(slow->val);
      root->left = build(head, slow);
      root->right = build(slow->next, tail);
      return root;
   }
   TreeNode *sortedListToBST(ListNode *head) {
      return build(head, nullptr);
   }
};

class Solution {
  public:
   vector<int> inorder;
   TreeNode *build(int left, int right) {
      if (left > right) return nullptr;
      int mid = left + (right - left) / 2;
      TreeNode *root = new TreeNode(inorder[mid]);
      root->left = build(left, mid - 1);
      root->right = build(mid + 1, right);
      return root;
   }
   TreeNode *sortedListToBST(ListNode *head) {
      if (head == nullptr) return nullptr;

      for (int i = 0; head != nullptr; i++) {
         inorder.push_back(head->val);
         head = head->next;
      }
      return build(0, inorder.size() - 1);
   }
};

int main() {
   Solution s;

   return 0;
}
