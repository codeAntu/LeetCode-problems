class Solution {
  public String[] sortPeople(String[] names, int[] heights) {
    int n = names.length;
    String[] res = new String[n];
    List<int[]> list = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      list.add(new int[]{heights[i], i});
    }
    Collections.sort(list, (a, b) -> {
      if (a[0] == b[0]) {
        return names[a[1]].compareTo(names[b[1]]);
      }
      return b[0] - a[0];
    });
    for (int i = 0; i < n; i++) {
      res[i] = names[list.get(i)[1]];
    }
    return res;      
  }
}
