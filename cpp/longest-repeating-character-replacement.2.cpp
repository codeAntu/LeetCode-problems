#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int> count(26, 0);
      int maxCount = 0, start = 0, result = 0;

      for( int end = 0  ; end < s.length() ; end++ ){
        maxCount = max(maxCount, ++count[s[end] - 'A']);
        if(end - start - maxCount >= k){
          count[s[start] - 'A']--;
          start++;
        }else{
        result = max(result, end - start + 1);
        }
      }
        return result;
    }
};

int main() {
  Solution s;


  return 0;
}