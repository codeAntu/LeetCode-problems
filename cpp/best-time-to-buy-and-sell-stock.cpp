#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

//done

class Solution {
public:
   int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int maxnum = prices[n-1];
      int maxprofit = 0 ;
      for (int i = n - 1; i >= 0 ; i--)
      {
         if (prices[i] > maxnum)
            maxnum = prices[i];
         if(maxnum - prices[i] > maxprofit)
            maxprofit = maxnum - prices[i];

      }
      return maxprofit;
   }
};

//

int main() {
   Solution s;
   vector<int> arr{7,6,4,3,1};
   cout << s.maxProfit(arr);

   return 0;
}