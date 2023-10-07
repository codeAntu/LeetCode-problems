#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
// done

class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
      string tmp = "" , result = strs[0];

      for (int i = 1; i < strs.size(); i++)
      {
         tmp = "";
         for (int j = 0; j < strs[i].length() || j < result.length(); j++)
         {
            if (result[j] != strs[i][j])
            {
               break;
            }
            tmp += (strs[0][j]);
         }
         result = tmp;
      }
      return result;
   }
};


int main() {
   Solution s;
   vector<string> strs = { "dog","racecar","car" };
   string aaa;


   cout << s.longestCommonPrefix(strs);


   return 0;
}