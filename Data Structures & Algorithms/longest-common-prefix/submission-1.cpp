class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];

       for(int i=1;i<strs.size();i++){

       string temp = strs[i];
        
        int j=0;
        while(j< min(prefix.length(),temp.length())){
            if(prefix[j]!=temp[j]){
                break;
            }
            j++;
        }
        prefix = prefix.substr(0,j);
       }

        return prefix;
    }
};