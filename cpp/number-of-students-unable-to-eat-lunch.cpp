#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int n = students.size();
    int m = sandwiches.size();
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
      if (students[i] == sandwiches[j]) {
        i++;
        j++;
      } else {
        i++;
      }
    }
    return n - j;
  }
};

int main() {
  Solution s;

  return 0;
}