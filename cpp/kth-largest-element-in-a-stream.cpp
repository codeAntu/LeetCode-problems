#include "iostream"
#include "map"
#include "math.h"
#include "queue"
#include "set"
#include "vector"
using namespace std;

class KthLargest {
  public:
   multiset<int> s;
   int n;
   KthLargest(int k, vector<int>& nums) {
      n = k;
      for (int i = 0; i < nums.size(); i++) {
         s.insert(nums[i]);
      }
   }

   int add(int val) {
      if (s.size() >= n && val > *next(s.begin(), s.size() - n) || s.size() < n)
         s.insert(val);
      return *next(s.begin(), s.size() - n);
   }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {
  private:
   priority_queue<int, vector<int>, greater<int>> q;
   int n;

  public:
   KthLargest(int k, vector<int>& nums) {
      n = k;
      for (int x : nums) add(x);
   }
   int add(int val) {
      if (q.size() < n)
         q.push(val);
      else if (val > q.top()) {
         q.pop();
         q.push(val);
      }
      return q.top();
   }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
   return 0;
}
