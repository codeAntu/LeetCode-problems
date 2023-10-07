#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int firstUniqChar(string s) {
      int arr[26] = { 0 };
      int i, len = s.length();
      for (i = 0; i < len; i++) {
         arr[s[i] - 'a']++;
      }
      for (i = 0;i < len; i++) {
         if (arr[s[i] - 'a'] == 1) return i;
      }
      return -1;
   }
};

int main() {
   Solution s;


   return 0;
}