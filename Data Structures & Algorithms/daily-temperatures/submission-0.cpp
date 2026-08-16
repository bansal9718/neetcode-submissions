class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n= temperatures.size();
        vector<int>ans(n);

        for(int i=0;i<n-1;i++){
            int cnt=0;
             for(int j=i+1;j<n;j++){
                cnt++;
                if(temperatures[j]>temperatures[i]){
                ans[i]=cnt;
                break;
                }
            }
        }

        return ans;
    }
};
