
class Solution {
  public boolean[] isArraySpecial(int[] nums, int[][] queries) {
    int n = nums.length;
    int m = queries.length;
    boolean[] result = new boolean[m];
    int[] special = new int[n];

    int i = 0;
    int count = 0;
    while (i < n - 1) {
      while (i < n - 1 && nums[i] % 2 != nums[i + 1] % 2) {
        special[i] = count;
        i++;
      }
      special[i] = count;
      count++;
      i++;
    }

    if (i == n - 1) {
      special[i] = count;
    }

    for (int j = 0; j < m; j++) {
      if (special[queries[j][0]] == special[queries[j][1]]) {
        result[j] = true;
      } else {
        result[j] = false;
      }
    }
    
    return result;
  }
}

public class specialArray2 {

  public static void main(String args[]) {

    // [4,3,1,6]
    // [[0,2],[2,3]]

    Solution s = new Solution();
    int[] nums = { 4, 3, 1, 6 };
    int[][] queries = { { 0, 2 }, { 2, 3 } };

    boolean[] result = s.isArraySpecial(nums, queries);

    for (int i = 0; i < result.length; i++) {
      System.out.println(result[i]);
    }
  }

}
