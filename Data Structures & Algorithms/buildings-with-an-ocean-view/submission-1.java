class Solution {
    public int[] findBuildings(int[] heights) {
       
        int maxHeight=-1;
        int n = heights.length;
        List<Integer> ans = new ArrayList<>();

        for (int i = n - 1; i >= 0; i--) {
           
            if(maxHeight==-1) {
                maxHeight=heights[i];
            ans.add(i);
            }
            if (maxHeight!=-1 && maxHeight < heights[i]) {
                maxHeight=heights[i];
                ans.add(i);
            }
        }

        Collections.reverse(ans);
        int []res = ans.stream().mapToInt(Integer::intValue)
                .toArray();

                return res;
    }
}