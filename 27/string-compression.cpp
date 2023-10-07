#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "string"
using namespace std;

class Solution {
public:
   int compress(vector<char>& chars) {
      int len = chars.size(), count = 1, ind = 0;
      int i;
      for (i = 1; i <= len; i++)
      {
         count = 1;

         while (i < len && chars[i] == chars[i - 1]) {
            count++;
            i++;
         }

         chars[ind++] == chars[i - 1];
         if (count > 1) {
            string s = std::to_string(count);
            for (char c : s) {
               chars[ind] = c;
               ind++;
            }
         }
      }
      return ind;
   }
};

int main() {
   Solution s;


   return 0;
}