#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


// incomplete solution

  class Solution {
  public:

    int claIndex(char c){
      if( c >= 'a' && c <= 'z' )
        return c - 'a';
      else
        return c - 'A' + 26;
    }

      string minWindow(string s, string t) {
        vector<int> count(52, 0);
        vector<int > temp(52, 0);
        int star =0 , end = t.length();
        int minWindow = INT_MAX;
        int starFrom = 0;
        int have = 0 , need = t.length();

        if( s.length() < t.length() )
          return "";

        for( int i = 0 ; i < t.length() ; i++ ){
          count[claIndex(t[i])]++;
        }

        while( end < s.length() || have == need ){
          if(have == need){
            if( end - start < minWindow ){
              minWindow = end - star;
              starFrom = star;
            }
            if( --temp[claIndex(s[star])] < count[claIndex(s[star])] )
              have--;
            star++;
          }else {
            int x = ++temp[claIndex(s[end])];
            if(x == count[claIndex(s[end])])
              have += x;
            end++;
          }
         
        }
        return minWindow == INT_MAX ? "" : s.substr(starFrom, minWindow);
      }
  };


class Solution {
public:
 int claIndex(char c){
      if( c >= 'a' && c <= 'z' )
        return c - 'a';
      else
        return c - 'A' + 26;
    }
    string minWindow(string s, string t) {
      vector<int>count(52 , 0);
      vector<int>hash(53 , 0);
      int start = 0 , end = 0 , startIndex = -1  , minWindow = INT_MAX , have = 0 , need = t.length();

      if(s == t){
        return t;
      }

      for(int i = 0 ; i < t.length() ; i++){
        count[claIndex(t[i])]++;    
      }

      while(end < s.length()){
        if(have == need ){
          if(minWindow > end - start  ){
            minWindow = end - start;
            startIndex = start;
          }
          have -= (hash[claIndex(s[start])] < count[claIndex(s[start])]);
          hash[claIndex(s[start])]--;
          start++;
        }else{
         have += (hash[claIndex(s[end])] == count[claIndex(s[end])]);
          hash[claIndex(s[end])]++;
          end++;
        }
      }
      return minWindow == INT_MAX ? "" : s.substr(startIndex , minWindow +1 );

    }
};

class Solution { 
public:
 int claIndex(char c){
      if( c >= 'a' && c <= 'z' )
        return c - 'a';
      else
        return c - 'A' + 26;
    }
    string minWindow(string s, string t) {
      vector<int>count(52 , 0);
      vector<int>hash(53 , 0);
      int start = 0 , end = 0 , startIndex = -1  , minWindow = INT_MAX , have = 0 , need = t.length();

      for( int i = 0 ; i < t.length() ; i++ ){
        count[claIndex(t[i])]++;
      }

      while( end < s.length() ){
        if( hash[claIndex(s[end])] < count[claIndex(s[end])] ){
          have++;
        }
        hash[claIndex(s[end])]++;
        end++;

        while( have == need ){
          if( end - start < minWindow ){
            minWindow = end - start;
            startIndex = start;
          }
          if( hash[claIndex(s[start])] <= count[claIndex(s[start])] ){
            have--;
          }
          hash[claIndex(s[start])]--;
          start++;
        }
      }

      return startIndex == -1 ? "" : s.substr(startIndex , minWindow);


    }
};


int main() {
  Solution s;


  return 0;
}
