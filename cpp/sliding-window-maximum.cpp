#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> maxInWindow;
        int start = 0 , end = 0;

        for(int i = 0 ; i< nums.size() ; i++){
          if(i >= k ){
            result.push_back(maxInWindow[start]);
            if(maxInWindow[start] == nums[i-k]){
              start++;
            }
          }

          while(start < end && maxInWindow[end-1] < nums[i]){
            end--;
          }
          maxInWindow[end++] = nums[i];

        }
        result.push_back(maxInWindow[start]);
        return result;

    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> maxInWindow;
        for (int i = 0; i < nums.size(); i++) {
          if (i >= k) {
            result.push_back(maxInWindow[0]);
            if (maxInWindow[0] == nums[i - k]) {
              maxInWindow.erase(maxInWindow.begin());
            }
          }
          while (!maxInWindow.empty() && maxInWindow.back() < nums[i]) {
            maxInWindow.pop_back();
          }
          maxInWindow.push_back(nums[i]);
        }      
        result.push_back(maxInWindow[0]);
        return result;
          
    }
};

int main() {
  Solution s;


  return 0;
}