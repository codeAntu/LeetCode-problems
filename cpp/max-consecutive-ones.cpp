#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;




int main() {
   Solution s;
   vector<int> arr = { 1,1,0,1,1,1 };

   cout << s.findMaxConsecutiveOnes(arr);

   return 0;
}