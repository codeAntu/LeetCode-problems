#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// done 
class Solution {
public:
   vector<int> getRow(int rowIndex) {
      vector<int> ans;
      ans.push_back(1);

      for (int i = 0; i < rowIndex; i++)
      {
         for (int j = ans.size() - 1; j > 0; j--)
         {
            ans[j] = ans[j] + ans[j - 1];
         }
         ans.push_back(1);
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}