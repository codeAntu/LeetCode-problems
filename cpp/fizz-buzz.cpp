#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> res(n);

    for (int i = 0; i < n;i++) {
      if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
        res[i] = "FizzBuzz";
      } else if ((i + 1) % 3 == 0) {
        res[i] = "Fizz";
      } else if ((i + 1) % 5 == 0) {
        res[i] = "Buzz";
      } else {
        res[i] = to_string(i + 1);
      }
    }

    return res;
  }
};

int main() {
  Solution s;


  return 0;
}
