#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int mostWordsFound(vector<string>& sentences) {
      int max = 0;
      int count = 0;
      for (string& s : sentences) {
         count = 1;
         for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == ' ' && s[i + 1] != ' ') {
               count++;
            }
         }
         max = count > max ? count : max;
      }
      return max;
   }
};


int main() {
   Solution s;


   return 0;
}