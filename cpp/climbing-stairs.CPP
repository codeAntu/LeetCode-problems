#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

//done
class Solution {
public:
   int climbStairs(int n) {
      int first= 1 , secound = 1 , temp;
      for (int i = 0; i < n-1; i++)
      {
        temp = secound;
        secound = first + secound;
        first = temp;
      }  
      return secound;
   }
};
// class Solution {
// public:
//    int climbStairs(int n) {
    
//       return fibo(1,1,n);
      
//    }

//    int fibo(int a , int b , int n){
//        if (n == 1)
//          return 1;
//       return a + fibo(b,a+b,--n);
//    }
// };




int main() {
   Solution s;
   cout << s.climbStairs(6);

   return 0;
}