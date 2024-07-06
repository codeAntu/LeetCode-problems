#include <algorithm>
#include <climits>

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

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    ListNode *it = head->next->next;
    int preVal = head->val;
    int currVal = head->next->val;
    int minDist = INT_MAX;
    int maxDist = INT_MIN;
    int dist = 0;
    int first_ind = -1;
    int pre_ind = 0;

    while (it) {
      int nextVal = it->val;

      if ((currVal > preVal && currVal > nextVal) || (currVal < preVal && currVal < nextVal)) {
        if (first_ind == -1) {
          first_ind = dist;
          pre_ind = dist;
        } else {
          minDist = min(minDist, dist - pre_ind);
          pre_ind = dist;
        }
      }
      preVal = currVal;
      currVal = nextVal;
      dist++;
      it = it->next;
    }

    maxDist = pre_ind - first_ind;

    if (minDist == INT_MAX) {
      return {-1, -1};
    }

    return {minDist, maxDist};
  }
};

int main() {
  Solution s;

  return 0;
}