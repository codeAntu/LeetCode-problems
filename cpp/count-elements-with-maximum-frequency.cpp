#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      unordered_map<int, int> freq;
      int maxFreq = 0;
      int  maxFreqElements = 0;

      for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
      }

      for (auto it = freq.begin(); it != freq.end(); it++) {
        if(it->second > maxFreq) {
          maxFreq = it->second;
          maxFreqElements = 1;
        } else if (it->second == maxFreq) {
          maxFreqElements++;
        }
      }
      return maxFreqElements * maxFreq;
      
    }
};

int main() {
  Solution s;


  return 0;
}