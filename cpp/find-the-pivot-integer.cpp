

#include <cinttypes>
#include <iostream>


class Solution {
public:
  int pivotInteger(int n) {
    int pivot = 1;
    int left = 0;
    int right = 0;

    for(int i = 1 ; i<= n ; i++){
      right+= i;
    }
  
    while (pivot <= n) {
      left += pivot;

      if(left == right) {
        return pivot;
      }
      right -= pivot;
      pivot++;
    }
    return -1;
  }
};

int main() {
  Solution s;
  std::cout << s.pivotInteger(8) << std::endl;
  return 0;
}