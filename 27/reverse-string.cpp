#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   void reverseString(vector<char>& s) {
      int len = s.size();

      for (int i = 0; i < len / 2; i++)
      {
         swap(s[i], s[len - 1 - i]);
      }

   }
};

int main() {
   Solution s;


   return 0;
}