#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

// class Solution {
// public:
//   int carFleet(int target, vector<int>& position, vector<int>& speed) {
//     map<int, float> m;
//     int res = 0;
//     float curr = 0;
//     for (int i = 0; i < position.size(); i++) {
//       m[-position[i]] = (float)(target - position[i]) / speed[i];
//     }
//     for (auto it : m) {
//       if (it.second > curr) {
//         curr = it.second;
//         res++;
//       }
//     }
//     return res;
//   }
// };

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, float>> cars;
    int res = 0;
    float curr = 0;
    int size = position.size();
    for (int i = 0; i < size; i++) {
      cars.push_back({position[i], (float)(target - position[i]) / speed[i]});
    }
    sort(cars.begin(), cars.end());

    for (int i = size - 1; i >= 0; i--) {
      if (cars[i].second > curr) {
        curr = cars[i].second;
        res++;
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}