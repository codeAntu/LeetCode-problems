#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      vector<int> count(26, 0);
      vector<int> temp(26, 0);
      int star = 0 , end = 0;

      if( s1.length() > s2.length() )
        return false;

      for(end = 0 ; end < s1.length() -1 ; end++){
        count[s1[end] - 'a']++;
        temp[s2[end] - 'a']++;
      }

      count[s1[end] - 'a']++;

      while ( end < s2.length()){
        temp[s2[end] - 'a']++;
        end++;

        if( temp == count )
          return true;
        temp[s2[star] - 'a']--;
        star++;
      
      }

      return false;
    
    }
};



int main() {
  Solution s;


  return 0;
}