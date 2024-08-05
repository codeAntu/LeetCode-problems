#include <string>
#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> m;

    for (int i = 0; i < arr.size(); i++) {
      m[arr[i]]++;
    }

    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
      if (m[arr[i]] == 1) count++;

      if (count == k) return arr[i];
    }

    return "";
  }
};
int main() {
  Solution s;

  return 0;
}