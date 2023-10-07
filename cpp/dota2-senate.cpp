#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include"queue"
using namespace std;

class Solution {
public:
   string predictPartyVictory(string senate) {
      queue<int>  r, d;
      int n = senate.length();

      for (int i = 0; i < n; i++) {
         if (senate[i] == 'R') r.push(i);
         else d.push(i);
      }

      while (r.size() && d.size()) {
         if (r.front() < d.front()) r.push(r.front() + n);
         else d.push(d.front() + n);
         r.pop();
         d.pop();
      }
      if (r.size()) return "Radiant";
      return "Dire";
   }
};

int main() {
   Solution s;


   return 0;
}