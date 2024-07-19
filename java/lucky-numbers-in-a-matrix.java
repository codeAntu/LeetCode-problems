class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
      List<Integer> res = new ArrayList<>();
      int m = matrix.length;
      int n = matrix[0].length;
      List<Integer> rowMin = new ArrayList<>( );
      List<Integer> colMax = new ArrayList<>();

      for (int i = 0; i < m; i++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
          min = Math.min(min, matrix[i][j]);
        }
        rowMin.add(min);
      }

      for (int j = 0; j < n; j++) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
          max = Math.max(max, matrix[i][j]);
        }
        colMax.add(max);
      }

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (matrix[i][j] == rowMin.get(i) && matrix[i][j] == colMax.get(j)) {
            res.add(matrix[i][j]);
          }
        }
      }

      return res;

    }
}