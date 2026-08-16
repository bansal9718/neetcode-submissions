class Solution {
    public int[] findBuildings(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        List<Integer> ans = new ArrayList<>();

        for (int i = n - 1; i >= 0; i--) {
            if (st.isEmpty()) {
                st.push(heights[i]);
                ans.add(i);
            }
            if (!st.isEmpty() && st.peek() < heights[i]) {
                st.push(heights[i]);
                ans.add(i);
            }
        }

        Collections.reverse(ans);
        int []res = ans.stream().mapToInt(Integer::intValue)
                .toArray();

                return res;
    }
}