#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// done
class Solution {
public:
   vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans;
      for (int i = 0; i < numRows; i++)
      {
         ans.push_back(vector<int>(i + 1, 1));

         for (int j = 1; j < i; j++)
         {
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
         }
      }
      return ans;
   }
};

int printvec(vector<vector<int>> vec) {
   cout << " ananta" << endl;
   for (int i = 0; i < vec.size(); i++)
   {
      for (int j = 0; j < vec[i].size(); j++)
      {
         cout << vec[i][j] << "  ";
      }
      cout << endl;
   }

   return 0;
}



int main() {
   Solution s;


   s.generate(5);


   return 0;
}