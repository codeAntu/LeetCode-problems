#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   string tictactoe(vector<vector<int>>& moves) {
      int arr[3][3] = { 0 };
      int sum1, sum2, sum3 = 0, sum4 = 0, i;
      for (i = 0; i < moves.size(); i++)
      {
         int r = moves[i][0], c = moves[i][1];
         if (i % 2 == 0)
            arr[r][c] = 1;
         else
            arr[r][c] = 5;
      }
      for (int j = 0; j < 3; j++)
      {
         sum1 = sum2 = 0;
         for (int k = 0; k < 3; k++)
         {
            sum1 += arr[j][k];
            sum2 += arr[k][j];
            if (k == j)
               sum3 += arr[j][k];
            if (k + j == 2)
               sum4 += arr[j][k];
         }
         if (sum1 == 3) return "A";
         else if (sum1 == 15) return "B";
         if (sum2 == 3) return "A";
         else if (sum2 == 15) return "B";
      }
      if (sum3 == 3) return "A";
      else if (sum3 == 15) return "B";
      if (sum4 == 3) return "A";
      else if (sum4 == 15) return "B";
      return i == 9 ? "Draw" : "Pending";
   }
};

class Solution {
public:
   string tictactoe(vector<vector<int>>& moves) {
      int p1[8] = { 0 }, p2[8] = { 0 };
      int  n = moves.size();
      for (int i = 0; i < n; i++)
      {
         int* p = i & 1 ? p2 : p1;
         int r = moves[i][0];
         int c = moves[i][1];
         p[r]++;
         p[c + 3]++;
         if (r == c) p[6]++;
         if (r + c == 2) p[7]++;
      }
      for (int i = 0; i < 8; i++)
      {
         if (p1[i] == 3) return "A";
         if (p2[i] == 3) return "B";
      }
      return n == 9 ? "Draw" : "Pending";
   }
};

class Solution {
public:
   string tictactoe(vector<vector<int>>& moves) {
      int a[8] = { 0 }, b[8] = { 0 };
      int len = moves.size();
      for (int i = 0; i < len; i++) {
         int r = moves[i][0], c = moves[i][1];
         int* player = i & 1 ? b : a;
         player[r]++;
         player[c + 3]++;
         if (r == c) player[6]++;
         if (r == 2 - c) player[7]++;
      }

      for (int i = 0; i < 8;i++) {
         if(a[i] == 3) return "A";
         if(b[i] == 3) return "B";
      }
      return len == 9 ? "Draw" : "Pending";
   }
};

int main() {
   Solution s;

   int arr[3][3] = { 0 };

   cout << arr[1][2];
   return 0;
}