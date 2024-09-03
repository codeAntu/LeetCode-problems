#include <string>

#include "iostream"


using namespace std;

class Solution {
public:
  int getLucky(string s, int k) {
    string num = "";

    for (char c : s) {
      int n = c - 'a' + 1;
      num.append(to_string(n));
    }

    for (int i = 0; i < k; i++) {
      int n = 0;

      for (char c : num) {
        n += c - '0' ;
      }

      num = to_string(n);
    }

    return stoi(num);
  }
};

int main() {
  Solution s;

  cout << s.getLucky("zzzj", 2);

  return 0;
}