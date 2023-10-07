#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include"stack"
using namespace std;

class Solution {
public:
   vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> stk;

      for (int i = 0; i < asteroids.size();i++) {
         if (asteroids[i] > 0 || stk.empty())
            stk.push(asteroids[i]);
         else if (stk.top() > 0 && asteroids[i] < 0) {
            if (stk.top() == abs(asteroids[i]))
               stk.pop();
            else if (stk.top() < abs(asteroids[i])) {
               stk.pop();
               i--;
            }
         } else {
            stk.push(asteroids[i]);
         }
      }

      vector<int> ans(stk.size());
      for (int i = ans.size() - 1; i >= 0; i--) {
         ans[i] = stk.top();
         stk.pop();
      }

      return ans;
   }
};


int main() {
   Solution s;


   return 0;
}